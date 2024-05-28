/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:58:40 by yait-nas          #+#    #+#             */
/*   Updated: 2023/11/18 18:35:01 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	char_is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*duplicator(char const *s, size_t start, size_t end)
{
	size_t	index;
	char	*trimmed;

	index = 0;
	if (start == ft_strlen(s) || s[0] == '\0')
	{
		trimmed = malloc(1);
		if (trimmed)
			trimmed [0] = '\0';
		return (trimmed);
	}
	trimmed = malloc(end - start + 2);
	if (trimmed)
	{
		while (start <= end)
			trimmed[index++] = s[start++];
		trimmed[index] = '\0';
	}
	return (trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	long long	end;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && char_is_in_set(s1[start], set) == 1)
		start++;
	while (end >= 0 && char_is_in_set(s1[end], set) == 1)
		end--;
	return (duplicator(s1, start, end));
}
