NAME =			libft.a

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -MMD -MP
SRCS =			ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_bzero.c ft_isascii.c \
				ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_tolower.c ft_toupper.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
				ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c \
				ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
				ft_lstmap.c error_handling.c
OBJS =			$(SRCS:.c=.o)
DEPS =			$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcT $(NAME) $(OBJS)
	ar -rcT $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean
	$(MAKE) all CFLAGS="$(CFLAGS) -g"

.PHONY: all clean fclean re debug

-include $(DEPS)