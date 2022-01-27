.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror -o
CC	:= gcc
SRCS	:= srcs/ft_isvalid.c \
			srcs/ft_exit.c \
			srcs/ft_simplify.c\
			srcs/stacks.c\
			commands/push.c\
			commands/swap.c\
			srcs/push_swap.c

all	: $(NAME)

$(NAME)	: $(SRCS)
	make  -C $(LIBFT)
	$(CC) $(CFLAGS) $(NAME) $(SRCS) -Llibft -lft

clean	:
		make clean -C $(LIBFT)
fclean	:
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re	: fclean all