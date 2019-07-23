cmake_minimum_required(VERSION 3.5.1)
project(logger)
enable_testing()
set(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(include)

file(GLOB SOURCES "src/Logger.cpp" "tests/gtest.cpp")

add_executable(run_code "main.cpp" "src/Logger.cpp")
add_executable(LoggerTest ${SOURCES})

target_link_libraries(LoggerTest ${GTEST_LIBRARIES} pthread)

set(LoggerTest LoggerTest)
add_custom_command(
     TARGET LoggerTest
     COMMENT "Run tests"
     POST_BUILD 
     COMMAND LoggerTest
)
