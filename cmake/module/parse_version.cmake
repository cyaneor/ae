# -------------------------------------------------------------------------------------- #
# Конфигурация версии проекта                                                            #
#                                                                                        #
# Этот скрипт преобразует версию проекта в список компонентов (мажорная, минорная и      #
# патч версии), сохраняет их в кэше и добавляет как макросы для использования в коде.    #
# Данная конфигурация позволяет получать версию проекта в различных частях сборки.       #
# -------------------------------------------------------------------------------------- #

# Заменяет точки в версии проекта на точки с запятыми.
# Например, "1.2.3" -> "1;2;3".
string(REPLACE "." ";" AE_VERSION_LIST ${PROJECT_VERSION})

# Получаем первый элемент списка (основная версия) и сохраняем в AE_VERSION_MAJOR.
list(GET AE_VERSION_LIST 0 AE_VERSION_MAJOR)

# Получаем второй элемент списка (минорная версия) и сохраняем в AE_VERSION_MINOR.
list(GET AE_VERSION_LIST 1 AE_VERSION_MINOR)

# Получаем третий элемент списка (патч версия) и сохраняем в AE_VERSION_PATCH.
list(GET AE_VERSION_LIST 2 AE_VERSION_PATCH)

# Сохраняем основную версию в кэш для последующего использования в CMake,
# и делаем это доступным как переменную кэша, добавляя FORCE,
# чтобы переопределить возможные ранее заданные значения.
set(AE_VERSION_MAJOR ${AE_VERSION_MAJOR} CACHE STRING "vm major version component" FORCE)

# Сохраняем минорную версию в кэш.
set(AE_VERSION_MINOR ${AE_VERSION_MINOR} CACHE STRING "vm minor version component" FORCE)

# Сохраняем патч-версию в кэш.
set(AE_VERSION_PATCH ${AE_VERSION_PATCH} CACHE STRING "vm patch version component" FORCE)

# Добавляем значения версий как определённые макросы,
# доступные для компиляции (compile definitions).
#
# Это позволит использовать их как AE_VERSION_MAJOR,
# AE_VERSION_MINOR и AE_VERSION_PATCH в коде.
list(APPEND AE_TARGET_PRIVATE_COMPILE_DEFINITIONS
        AE_VERSION_MAJOR=${AE_VERSION_MAJOR}
        AE_VERSION_MINOR=${AE_VERSION_MINOR}
        AE_VERSION_PATCH=${AE_VERSION_PATCH}
)

# Очищаем временные переменные AE_VERSION_MAJOR, AE_VERSION_MINOR и AE_VERSION_PATCH,
# так как они больше не нужны в глобальном пространстве CMake.
unset(AE_VERSION_MAJOR)
unset(AE_VERSION_MINOR)
unset(AE_VERSION_PATCH)
