NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = main.c parser.c utils.c dblist.c operations.c radix_utils.c radix_bin.c insert.c

LIBFT_PATH = libft1


LIBFT = $(LIBFT_PATH)/libft.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all
	clear

.PHONY: all clean fclean re