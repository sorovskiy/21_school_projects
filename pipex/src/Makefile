# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ephantom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/01 17:43:42 by ephantom          #+#    #+#              #
#   Updated: 2021/12/17 15:45:33 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex

SRCS_A	=	main.c ft_split.c pipex_utils.c

SRCS_B	=	main_bonus.c ft_split_bonus.c pipex_utils_bonus.c ft_here_doc_bonus.c get_next_line_bonus.c ft_open_file_bonus.c

OBJS_A	=	${SRCS_A:%.c=%.o}

OBJS_B	=	${SRCS_B:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	 rm -f

.PHONY:		all clean fclean re bonus

all:		${NAME}

%.o: 		%.c
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS_A}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS_A}

bonus:
			@make OBJS_A="$(OBJS_B)" all

clean:		
			${RM} ${OBJS_A} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
