#include <ae/stack_frame_state.h>
/* Дополнительные модули */
#include <ae/static_assert.h>
#include <ae/constructor.h>
#include <ae/nullptr.h>

/**
 * @brief Статическая проверка на количество сохраняемых состояний стековых фреймов.
 *
 * Этот макрос выполняет статическую проверку, чтобы гарантировать, что
 * количество сохраняемых состояний стековых фреймов (`AE_STACK_FRAME_STATES_MAX`)
 * больше нуля. Если это условие не выполняется, будет сгенерировано сообщение
 * об ошибке компиляции с текстом "number of saved stack frame states is zero".
 *
 * @note Статические проверки используются для выявления ошибок на этапе компиляции,
 *       что позволяет предотвратить возможные ошибки во время выполнения.
 *
 * @param AE_STACK_FRAME_STATES_MAX Максимальное количество состояний стековых фреймов.
 * @pre `AE_STACK_FRAME_STATES_MAX` должно быть определено и иметь значение больше 0.
 */
ae_static_assert(AE_STACK_FRAME_STATES_MAX, "number of saved stack frame states is zero");

/**
 * @var m_stack_frame_states
 * @brief Массив состояний стековых фреймов.
 *
 * Этот массив используется для хранения состояний стековых фреймов в многопоточном
 * окружении. Каждый элемент массива представляет собой указатель на структуру
 * `ae_stack_frame_state_t`, которая содержит информацию о состоянии конкретного
 * стекового фрейма.
 *
 * @note Массив объявлен как `THREAD_LOCAL`, что означает,
 *       что каждый поток имеет свою собственную копию этого массива.
 *
 * @see ae_stack_frame_state_t
 * @see AE_STACK_FRAME_STATES_MAX
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_stack_frame_state_t *m_stack_frame_states[AE_STACK_FRAME_STATES_MAX] = {};

/**
 * @var m_stack_frame_state
 * @brief Объявление указателя на стек фреймов.
 *
 * Данная переменная `m_stack_frame_state` представляет собой указатель на
 * указатель типа `ae_stack_frame_state_t`, который используется для хранения
 * состояния стеков фреймов. Она инициализируется значением `nullptr`, что
 * указывает на отсутствие активного состояния фрейма в момент инициализации.
 *
 * @note Переменная объявлена с атрибутом `THREAD_LOCAL`, что означает,
 *       что каждый поток будет иметь свою собственную копию этой переменной.
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_stack_frame_state_t **m_stack_frame_state = nullptr;

bool
ae_stack_frame_state_is_begin()
{
    return m_stack_frame_state == &m_stack_frame_states[0];
}

bool
ae_stack_frame_state_is_end()
{
    return m_stack_frame_state == &m_stack_frame_states[AE_STACK_FRAME_STATES_MAX];
}

ae_stack_frame_state_t *
ae_stack_frame_state_next()
{
    if (!ae_stack_frame_state_is_end())
    {
        m_stack_frame_state++;
    }
    return *m_stack_frame_state;
}

ae_stack_frame_state_t *
ae_stack_frame_state_prev()
{
    if (!ae_stack_frame_state_is_begin())
    {
        m_stack_frame_state--;
    }
    return *m_stack_frame_state;
}

ae_stack_frame_state_t *
ae_stack_frame_state_push(ae_stack_frame_state_t *stack_frame_state)
{
    *m_stack_frame_state = stack_frame_state;
    ae_stack_frame_state_next();
    return stack_frame_state;
}

/**
 * @brief Инициализирует состояние кадра стека локального потока.
 *
 * Эта функция автоматически выполняется перед функцией `main()`,
 * благодаря `constructor`.
 *
 * Он инициализирует указатель `m_stack_frame_state`
 * установив его так, чтобы он указывал на массив `m_stack_frame_states`,
 * подготовка состояния кадра локального стека потока к использованию.
 *
 * Поскольку эта функция использует `constructor`,
 * это гарантирует, что `m_stack_frame_state` каждого потока правильно
 * инициализируется перед любым другим кодом, который может его использовать.
 *
 * @see m_stack_frame_state
 * @see m_stack_frame_states
 */
ae_constructor(ae_stack_frame_state_init)
{
    m_stack_frame_state = m_stack_frame_states;
}