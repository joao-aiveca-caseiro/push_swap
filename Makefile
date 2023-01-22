LIBFT		= ./libft/libft.a
SRCS	= push_swap.c\
		 arg_checking.c\
		 instructions.c\
		 sort_small.c\
		 temp_instructions.c\
		 sort_big.c\
		 sort_big_utils.c\
		 utils.c\
		 optimizer.c
OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${MAKE} all -C ./libft
			${CC} ${CFLAGS} ${OBJS} ${LIBFT} -o ${NAME} 

all:		$(NAME)

clean:
			${RM} ${OBJS}
			${MAKE} clean -C ./libft

fclean:		clean
			${RM} $(NAME)
			${MAKE} fclean -C ./libft 

re:			fclean all
