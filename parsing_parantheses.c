/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:34:38 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/29 22:52:29 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	found_match(char *str)
{
	while (*str)
	{
		if (*str == ')')
			return (1);
		str++;
	}
	return (0);
}

void	parsing(char *str)
{
	int		paranthese1;
	int		paranthese2;
	int		single_quotes;
	int		double_quotes;
	char	*tmp;

	paranthese1 = 0;
	paranthese2 = 0;
	single_quotes = 0;
	double_quotes = 0;
	tmp = str;
	while (*tmp)
	{
		if (*tmp == '(')
		{
			if (!found_match(tmp))
			{
				printf("syntax error\n");
				return ;
			}
			paranthese1++;
		}
		else if (*tmp == ')')
			paranthese2++;
		else if (*tmp == '\'')
			single_quotes++;
		else if (*tmp == '"')
			double_quotes++;
		tmp++;
	}
	if (paranthese1 != paranthese2 || single_quotes % 2 || double_quotes % 2)
	{
		printf("syntax error\n");
		return ;
	}
}
