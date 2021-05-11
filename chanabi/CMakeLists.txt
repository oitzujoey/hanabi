
cmake_minimum_required(VERSION 3.10)

project(chanabi
        VERSION 0
        DESCRIPTION "C version of Hanabi"
        HOMEPAGE_URL https://github.com/oitzujoey/engine-1
        LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	add_compile_options(-ansi -pedantic-errors -Werror -Wall -Wstrict-prototypes -DDEBUG -g -O0)
else()
	add_compile_options(-ansi -O3)
endif()

add_compile_options(-DLINUX)

add_executable(chanabi)

# target_compile_options(chanabi PRIVATE -DSOMETHING)

# target_link_options(chanabi PRIVATE -fsanitize=address)

add_subdirectory(source)

target_link_libraries(chanabi)
