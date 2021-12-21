NAME	=	push_swap

SRCS	=	main.c ft_split.c sort_for_3_and_5.c sort_stack_b.c stack.c t_list_funcs.c ps_utils.c bulka_sort.c \
            pa_pb_operations.c ra_rb_rr_operations.c rra_rrb_rrr_operations.c sa_sb_ss_operations.c \
            sort_stack_b_utils.c

HEADER	=	push_swap.h

OBJS	=	${SRCS:%.c=%.o}

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I${HEADER}

RM		=	 rm -f

.PHONY:		all clean fclean re

all:		${NAME}

%.o: 		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}  ${HEADER}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
