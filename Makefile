NAME = 	minishell

SRCS =	parse/read_prompt.c
OBJS = 	$(SRCS:.c=.o)
CC = cc
CFLAGS = 	-Wall -Wextra -Werror -MMD -MP -std=c99
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lreadline

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	$(MAKE) all CFLAGS="$(CFLAGS) -g"

.PHONY: all clean fclean re

-include $(DEPS)