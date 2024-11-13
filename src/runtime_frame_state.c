#include <ae/runtime_frame_state.h>
/* Дополнительные модули */
#include <ae/static_assert.h>
#include <ae/attribute.h>
#include <ae/nullptr.h>

ae_static_assert(AE_RUNTIME_FRAME_STATE_MAX,
                 "The maximum frame state value exceeds the allowed limit.");

/**
 * @brief Массив для хранения состояния фреймов выполнения.
 *
 * Массив `m_runtime_frame_states` содержит указатели на объекты типа `ae_jump_buffer_t`,
 * которые используются для хранения состояний фреймов во время выполнения программы.
 * Размер массива определяется константой `AE_RUNTIME_FRAME_STATE_MAX`.
 *
 * @note Этот массив инициализируется пустыми указателями (`nullptr`).
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_jump_buffer_t *m_runtime_frame_states[AE_RUNTIME_FRAME_STATE_MAX] = {};

/**
 * @brief Указатель на указатель на объект типа `ae_jump_buffer_t`,
 *        используемый для хранения состояния текущего фрейма выполнения в отдельном потоке.
 *
 * Переменная `m_runtime_frame_state` представляет собой указатель на указатель,
 * который хранит состояние фрейма выполнения для текущего потока.
 * Это позволяет каждому потоку иметь своё собственное состояние фрейма.
 *
 * Атрибут `THREAD_LOCAL` гарантирует, что каждый поток
 * будет иметь свою собственную копию этого указателя,
 * обеспечивая потокобезопасность.
 *
 * @note Этот механизм полезен в многозадачных приложениях,
 *       где каждый поток может иметь своё состояние,
 *       и важно сохранить независимость состояний между потоками.
 */
AE_ATTRIBUTE(THREAD_LOCAL)
ae_jump_buffer_t **m_runtime_frame_state = nullptr;

bool
ae_runtime_frame_state_is_begin()
{
    return m_runtime_frame_state == &m_runtime_frame_states[0];
}

bool
ae_runtime_frame_state_is_end()
{
    return m_runtime_frame_state == &m_runtime_frame_states[AE_RUNTIME_FRAME_STATE_MAX];
}

ae_jump_buffer_t *
ae_runtime_frame_state_next()
{
    if (!ae_runtime_frame_state_is_end())
    {
        m_runtime_frame_state++;
    }
    return *m_runtime_frame_state;
}

ae_jump_buffer_t *
ae_runtime_frame_state_prev()
{
    if (!ae_runtime_frame_state_is_begin())
    {
        m_runtime_frame_state--;
    }
    return *m_runtime_frame_state;
}

ae_jump_buffer_t *
ae_runtime_frame_state_push(ae_jump_buffer_t *frame_state)
{
    *m_runtime_frame_state = frame_state;
    ae_runtime_frame_state_next();
    return frame_state;
}

/**
 * @brief Конструктор для инициализации состояния фрейма выполнения.
 *
 * Данный макрос `ae_compiler_constructor` используется для определения функции,
 * которая будет вызвана на этапе инициализации объекта.
 *
 * В данном случае, функция `ae_runtime_frame_state_init` инициализирует
 * указатель `m_runtime_frame_state` значением `m_runtime_frame_states`,
 * то есть присваивает массив состояний фреймов текущему состоянию выполнения.
 *
 * Это действие гарантирует, что при инициализации фрейм
 * будет корректно настроен для работы с состояниями выполнения.
 *
 * @note Макрос `ae_compiler_constructor` используется для того, чтобы гарантировать
 *       вызов функции инициализации на этапе старта программы или при создании объекта.
 */
ae_compiler_constructor(ae_runtime_frame_state_init)
{
    m_runtime_frame_state = m_runtime_frame_states;
}

/**
 * @brief Деструктор для очистки состояния фрейма выполнения.
 *
 * Данный макрос `ae_compiler_destructor` используется для определения функции,
 * которая будет вызвана на этапе уничтожения объекта.
 *
 * В данном случае, функция очищает указатель `m_runtime_frame_state`,
 * присваивая ему значение `nullptr`, что предотвращает утечку ресурсов
 * и гарантирует, что указатель больше не указывает на старые данные.
 *
 * @note Макрос `ae_compiler_destructor` используется для того, чтобы гарантировать
 *       вызов функции очистки на этапе завершения работы с объектом или при его уничтожении.
 */
ae_compiler_destructor(ae_runtime_frame_state_deinit)
{
    m_runtime_frame_state = nullptr;
}
