NAME = 	minishell
LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

SRCS =	main.c execution/execution.c
OBJS = 	$(SRCS:.c=.o)
CC = cc
CFLAGS = 	-Wall -Wextra -Werror -MMD -MP -std=c99 -I$(LIBFT_DIR)
LDFLAGS =	-L$(LIBFT_DIR) -lft
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

FORCE:

clean:
	rm -f $(OBJS) $(DEPS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

debug: fclean
	$(MAKE) -C $(LIBFT_DIR) debug
	$(MAKE) all CFLAGS="$(CFLAGS) -g"

.PHONY: all clean fclean re

-include $(DEPS)