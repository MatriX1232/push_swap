CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinlude/

NAME = push_swap

FILES = \
	src/lst_utils.c \
	src/s_op.c \
	src/p_op.c \
	src/r_op.c \
	src/rr_op.c \
	src/simple_sort_3.c \
	src/simple_sort_4.c \
	src/simple_sort_5.c \
	src/simple_sort.c \
	src/radix_sort.c \
	src/utils.c \
	src/ft_argv_init.c \
	src/main.c

PRINTF = ft_printf

OBJS = ${FILES:.c=.o}

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
