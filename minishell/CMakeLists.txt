cmake_minimum_required(VERSION 3.19)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c libft_func.c minishell.h preparser.c parser.c t_list_funcs.c redirects.c stack_init.c ft_split.c libft_func2.c parser_utils.c)
