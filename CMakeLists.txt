cmake_minimum_required(VERSION 3.21)
project(linuxtyper C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -lxdo)

set(SOURCE_FILES main.c)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")
add_executable(linuxtyper ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(linuxtyper ${GTK3_LIBRARIES} xdo)
