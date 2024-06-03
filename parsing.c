/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 14:15:05 by yait-nas          #+#    #+#             */
/*   Updated: 2024/06/03 19:26:28 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_matrix(char **line_splited)
{
	int	i;

	i = 0;
	while (line_splited[i])
	{
		free(line_splited[i]);
		i++;
	}
	free(line_splited);
}

int	quotes_handler(char *str, char c, int *i)
{
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
	if (!(str[*i]))
		return (1);
	return (0);
}

int	redirection_handler(char *str, char c, int *i)
{
	(*i)++;
	if (str[*i] == c)
		(*i)++;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '<' || str[*i] == '|' || str[*i] == '>' || str[*i] == ';' || str[*i] == '\0')
		return (1);
	return (0);
}

int	something_is_wrong(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			if (quotes_handler(str, '"', &i))
				return (1);
		if (str[i] == '\'')
			if (quotes_handler(str, '\'', &i))
				return (1);
		if (str[i] == '<')
			if (redirection_handler(str, '<', &i))
				return (1);
		if (str[i] == '>')
			if (redirection_handler(str, '>', &i))
				return (1);
		i++;
	}
	return (0);
}

void	parsing(char **line_splited)
{
	int	i;

	if (line_splited)
	{
		i = 0;
		while (line_splited[i])
		{
			if (something_is_wrong(line_splited[i]))
			{
				printf("syntax error\n");
				free_matrix(line_splited);
				return ;
			}
			i++;
		}
	}
}
