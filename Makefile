NAME = 	minishell
SRCS =	main.c
OBJS = 	$(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c99
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)