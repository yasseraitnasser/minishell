/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:53:09 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/29 15:53:30 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	if_next_char_is_true(char *str, int i, int *count)
{
	if (str[i + 1] != '|' && str[i + 1] != '&')
		(*count)++;
	else
	{
		if (str[i - 1] == '|' || str[i - 1] == '&')
			ft_error(str);
	}
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
				if_next_char_is_true(str, i, &count);
			else
				ft_error(str);
		}
		i++;
	}
	return (count);
}

char	*ultimate_alloc(int *i, char **result, int index)
{
	char	*result_index;

	result_index = malloc((*i) + 1);
	if (!result_index)
	{
		while (--index >= 0)
			free(result[index]);
		free(result);
		return (NULL);
	}
	*i = 0;
	return (result_index);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		index;

	str = ft_strtrim(str, " ");
	result = malloc(count_words_and_check(str) * sizeof(char *) + 1);
	if (!result)
		return (result);
	index = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '|' && str[i] != '&')
			i++;
		result[index] = ultimate_alloc(&i, result, index);
		while (*str && *str != '|' && *str != '&')
			result[index][i++] = *(str++);
		result[index][i] = '\0';
		index++;
		while (*str && (*str == '&' || *str == '|'))
			str++;
	}
	result[index] = NULL;
	return (result);
}

void	parsing(char *str)
{
	char	**cmd_splited;

	cmd_splited = ft_split(str);
	while (*cmd_splited)
	{
		printf("%s\n", *cmd_splited);
		cmd_splited++;
	}
}
