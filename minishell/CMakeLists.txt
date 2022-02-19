cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c libft_func.c minishell.h preparser.c)
