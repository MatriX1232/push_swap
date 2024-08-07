CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

NAME = push_swap

FILES = \
	push_swap.c \
	src/ft_s_utils.c \
	src/ft_utils.c

OBJS = ${FILES:.c=.o}

FT_PRINTF = ft_printf/


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF)/libftprintf.a -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(FT_PRINTF) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(FT_PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re
