/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_and_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:59:58 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/23 16:13:18 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_what_is_next(char *str, char c)
{
	if (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == c || *str == '\0')
			return (-1);
		else
			return (0);
	}
	return (-1);
}

int	count_words_and_check(char *str, char c)
{
	int	count;

	count = 1;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == c)
			return (-1);
		while (*str && *str != c)
		{
			if (*str == '"')
			{
				str++;
				while (*str && *str != '"')
					str++;
			}
			str++;
		}
		if (*str)
		{
			if (check_what_is_next(++str, c))
				return (-1);
			count++;
		}
	}
	return (count);
}
