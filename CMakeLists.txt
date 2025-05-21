cmake_minimum_required(VERSION 3.10)

project(cpp-ds VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DCMAKE_EXPORT_COMPILE_COMMANDS=1)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/template
)

file(GLOB SOURCES "example/*.cpp")

add_executable(
    cpp-ds
    ${SOURCES}
)

