NAME	=	libft.a

FILES	=	ft_putnbr_fd.c ft_putendl_fd.c \
			ft_putchar_fd.c ft_putstr_fd.c \
			ft_atoi.c ft_bzero.c ft_isalnum.c \
			ft_memcpy.c ft_memchr.c ft_memcmp.c \
			ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_isprint.c ft_memset.c ft_strlen.c \
			ft_strnstr.c ft_strdup.c ft_substr.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_strlcpy.c ft_strlcat.c ft_calloc.c \
			ft_strchr.c ft_strrchr.c ft_strncmp.c \
			ft_toupper.c ft_tolower.c ft_memmove.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c

FILES_B	=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

HEAD	=	libft.h

OBJ		=	${FILES:%.c=%.o}

OBJ_B	=	${FILES_B:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -I ${HEAD}

.PHONY	:	all clean fclean re bonus

all		:	${NAME}

${NAME}	:	${OBJ} ${HEAD}
	@ar rcs ${NAME} $?

%.o		:	%.c ${HEAD}
	${CC} ${CFLAGS} -c $< -o $@

bonus	:
	@make OBJ='${OBJ_B}' all
	
clean	:
	@rm -f ${OBJ} ${OBJ_B}

fclean	:	clean
	@rm -f ${NAME}

re		:	fclean all