cmake_minimum_required(VERSION 3.15)
project(linux_common)

FILE(GLOB_RECURSE BASE_SRC base/*)
FILE(GLOB_RECURSE COMMON_SRC common/*)
add_library(${PROJECT_NAME} STATIC
        ${BASE_SRC}
        ${COMMON_SRC}
        BaseConvert/baseConvertor.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -g -O3 -std=c++0x)
target_compile_definitions(${PROJECT_NAME} PRIVATE _LINUX_OS_ RAPIDJSON_HAS_STDSTRING USE_GMLOGAPI)

target_include_directories(${PROJECT_NAME} PRIVATE
        /usr/include
        /usr/local/include
        .
        )

target_link_directories(${PROJECT_NAME} PRIVATE
        /usr/lib64
        /usr/local/lib64
        .)

target_link_libraries(${PROJECT_NAME} PRIVATE
        -pthread)

install (TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION /home/ralph/CLionProjects/linux_common/)
