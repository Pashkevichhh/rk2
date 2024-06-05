cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SheepProject)

# Add the executable for the main application
add_executable(SheepProject main.cpp Sheep.cpp)

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Enable testing
enable_testing()

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add the test executable
add_executable(SheepTest tests.cpp Sheep.cpp)
target_link_libraries(SheepTest gtest_main)

# Add tests
add_test(NAME SheepTest COMMAND SheepTest)
