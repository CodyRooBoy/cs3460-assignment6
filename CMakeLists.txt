cmake_minimum_required(VERSION 3.10)
project(ConwaysLife)

set(CMAKE_CXX_STANDARD 20)

set(HEADER_FILES LifeSimulator.hpp Renderer.hpp RendererConsole.hpp Pattern.hpp PatternAcorn.hpp PatternBlinker.hpp PatternBlock.hpp PatternGlider.hpp PatternPulsar.hpp PatternGosperGliderGun.hpp rlutil.h)
set(SOURCE_FILES LifeSimulator.cpp RendererConsole.cpp PatternAcorn.cpp PatternBlinker.cpp PatternBlock.cpp PatternGlider.cpp PatternPulsar.cpp PatternGosperGliderGun.cpp)
set(UNIT_TEST_FILES TestGameOfLife.cpp)

add_executable(ConwaysLife ${SOURCE_FILES} main.cpp)

if (MSVC)
    target_compile_options(ConwaysLife PRIVATE /W4 /permissive-)
else()
    target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic )
endif()

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.15.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(UnitTestRunner ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES})
target_link_libraries(UnitTestRunner gtest gtest_main)

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES} main.cpp)
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()
    add_custom_target(
        ClangFormat
        COMMAND ${CLANG_FORMAT}
        -i
        -style=file
        ${SOURCE_FILES_PATHS})

    add_dependencies(ConwaysLife ClangFormat)
    add_dependencies(UnitTestRunner ClangFormat)
endif()