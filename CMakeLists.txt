cmake_minimum_required(VERSION 3.10)
project(VirtualMachine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz
)
# Для Windows: Предотвращаем переопределение параметров компилятора/линкера родительского проекта
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Отключаем обработку предупреждений как ошибок для Google Test
target_compile_options(gtest PRIVATE -Wno-error=maybe-uninitialized)

# Отключаем обработку предупреждений о неинициализированных переменных как ошибок
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-error=maybe-uninitialized")

# Включаем поддержку тестирования в проекте
enable_testing()

# Добавляем исполняемые файлы для тестов
add_executable(tests tests.cpp Sheep.cpp)
target_link_libraries(tests gtest_main)

# Включаем модуль GoogleTest, который предоставляет функции для автоматического обнаружения и выполнения тестов.
include(GoogleTest)

# Настраиваем автоматическое обнаружение и выполнение тестов в исполняемом файле tests
gtest_discover_tests(tests)
