NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
READLINE = -lreadline
FILES = main.c ft_strcmp.c ft_split_with_pipe.c count_words_and_check.c \
	parsing.c set_up_for_execution.c ft_lstadd_line_splited.c \
	ft_strdup.c ft_lstadd_redirection.c ft_strlen.c \
	ft_normal_split.c clean_up.c

FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) $(READLINE) -o $(NAME)

clean:
	rm -f $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all
