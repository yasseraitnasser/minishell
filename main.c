#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

void	ft_error(char *str)
{
	free(str);
	printf("syntax error\n");
	exit(EXIT_FAILURE);
}

int	count_words_and_check(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (*str == '|' || *str == '&')
		ft_error(str);
	while (str[i])
	{
		if (str[i] == '|' || str[i] == '&')
		{
			if (str[i + 1])
			{
				if (str[i + 1] != '|' && str[i + 1] != '&')
					count++;
				//if (str[i - 1] == '|' || str[i - 1] == '&')
					//ft_error(str);
					// dont forget to trim :)
			}
			else
				ft_error(str);
		}
		i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;

	str = ft_strtrim(str, " ");
	result = malloc(count_words_and_check(str) * sizeof(char *) + 1);
	if (!result)
		return (result);
}

void	parcing(char *str)
{
	char	**cmd_splited;

	cmd_splited = ft_split(str);
}

int main()
{
	char	*str;

	str = readline("-> ~ ");
	if (!str)
		exit(EXIT_SUCCESS);
	parcing(str);
	//printf("%s\n", str);
	//execution
	free(str);
	return (0);
}
