NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
READLINE = -lreadline
FILES = main.c ft_strtrim.c ft_strlen.c ft_strdup.c \
	error.c parsing.c

FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) $(READLINE) -o $(NAME)

clean:
	rm -f $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all
