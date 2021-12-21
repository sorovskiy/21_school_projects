NAME	=	libftprintf.a

FILES	=	ft_printf.c ft_printf_utils.c

HEAD	=	ft_printf.h

OBJ		=	${FILES:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I ${HEAD}

.PHONY	:	all clean fclean re

all		:	${NAME}

${NAME}	:	${OBJ} ${HEAD}
	@ar rcs ${NAME} $?

%.o		:	%.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

clean	:
	@rm -f ${OBJ} ${OBJ_B}

fclean	:	clean
	@rm -f ${NAME}

re		:	fclean all