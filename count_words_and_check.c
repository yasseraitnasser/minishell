/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_and_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:59:58 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/18 21:07:13 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_what_is_next(char *str, char c)
{
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str == c || *str == '\0')
			return (-1);
		else
			return (0);
		str++;
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
			str++;
		if (*str)
		{
			if (check_what_is_next(++str, c))
				return (-1);
			count++;
		}
	}
	return (count);
}
