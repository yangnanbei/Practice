cmake_minimum_required(VERSION 3.16)
project(tiny_tertriz)

set(CXX_STANDARD 17)

aux_source_directory(. src)
add_executable(tiny_tertriz ${src})
