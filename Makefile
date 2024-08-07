CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinlude/

NAME = push_swap

FILES = \
	src/ft_stack.c \
	src/push_swap.c \
	src/main.c

OBJS = ${FILES:.c=.o}

PRINTF = ft_printf


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -C $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF)/libftprintf.a -o $(NAME)

clean:
	@make -C $(PRINTF) clean
	rm -f $(OBJS)

fclean: clean
	@make -C $(PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
