LIBFT		= ./libft/libft.a
SRCS	= push_swap.c
OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

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