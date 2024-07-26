/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_with_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <yait-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:45:30 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/26 22:24:19 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*word(char *s, int i, char c)
{
	char	*p;
	int		j;

	p = malloc(i + 1);
	if (!p)
		return (NULL);
	j = 0;
	while (*s && *s != c)
	{
		if (*s == '"')
		{
			p[j++] = *s;
			s++;
			while (*s && *s != '"')
			{
				p[j] = *s;
				s++;
				j++;
			}
		}
		p[j++] = *s;
		s++;
	}
	p[j] = '\0';
	return (p);
}

static void	to_be_continued(char **strings, char *s, char c)
{
	int	string_index;
	int	i;

	string_index = 0;
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != c)
		{
			if (s[i] == '"')
			{
				i++;
				while (s[i] && s[i] != '"')
					i++;
			}
			i++;
		}
		strings[string_index++] = word(s, i, c);
		s += i;
		if (*s)
			s++;
	}
	strings[string_index] = NULL;
}

char	**ft_split_with_pipe(char	*s, char c)
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
