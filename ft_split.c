/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <yait-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:30 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/31 14:13:40 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	c_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*word(char *s, char **strings, int index, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * (c_char(s, c) + 1));
	if (!p)
	{
		if (index)
		{
			while (index--)
				free(strings[index]);
		}
		free(strings);
		return (NULL);
	}
	while (s[i] != c && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static void	to_be_continued(char **strings, char *s, char c)
{
	int	string_index;

	string_index = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			strings[string_index] = word(s, strings, string_index, c);
			if (!strings[string_index])
				return ;
			string_index++;
		}
		while (*s && *s != c)
			s++;
	}
	strings[string_index] = NULL;
}

char	**ft_split(char	*s, char c)
{
	char	**strings;
	int		count;

	count = count_words_and_check(s, c);
	if (count == -1)
	{
		printf("syntax error\n");
		return (NULL);
	}
	strings = malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	to_be_continued(strings, s, c);
	return (strings);
}
