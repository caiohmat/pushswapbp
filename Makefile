.PHONY:	clean fclean re all

LIBFT	:= libft
NAME	:= push_swap
CFLAGS	:= -Wall -Wextra -Werror -o
CC	:= gcc
SRCS	:= ft_isvalid.c \
			ft_exit.c \
			push_swap.c

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