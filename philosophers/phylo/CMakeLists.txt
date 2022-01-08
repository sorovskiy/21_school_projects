cmake_minimum_required(VERSION 3.20)
project(phylosophers C)

set(CMAKE_C_STANDARD 99)

#add_executable(phylosophers phylo.c)
add_executable(phylosophers main.c phylo.h utils.c init.c)
#add_executable(phylosophers main2.c)
#add_executable(phylosophers main3.c)