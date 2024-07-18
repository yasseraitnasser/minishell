/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing_for_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:00:58 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/17 21:05:44 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redirection	*link_redirections(char *str)
{
	t_redirection	*result;
	int		i;
	int		j;

	result = malloc(sizeof(t_redirection));
	if (!result)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			i++;
			if (str[i] == '<')
			{
				result->redirection_type = 2;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] && str[i + j] != '>' && str[i + j] != '|')
					j++;
				result->file_limiter = malloc(j + 1);
				if (!(result->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] && str[i] != '>' && str[i] != '|')
					result->file_limiter[j++] = str[i++];
				result->file_limiter[j] = '\0';
			}
			else
			{
				result->redirection_type = 1;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] && str[i + j] != '>' && str[i + j] != '|')
					j++;
				result->file_limiter = malloc(j + 1);
				if (!(result->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] && str[i] != '>' && str[i] != '|')
					result->file_limiter[j++] = str[i++];
				result->file_limiter[j] = '\0';
			}
				i++;
		}
		else if (str[i] == '>')
		{
			i++;
			if (str[i] == '>')
			{
				result->redirection_type = 4;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] && str[i + j] != '>' && str[i + j] != '|')
					j++;
				result->file_limiter = malloc(j + 1);
				if (!(result->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] && str[i] != '>' && str[i] != '|')
					result->file_limiter[j++] = str[i++];
				result->file_limiter[j] = '\0';
			}
			else
			{
				result->redirection_type = 3;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] && str[i + j] != '>' && str[i + j] != '|')
					j++;
				result->file_limiter = malloc(j + 1);
				if (!(result->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] && str[i] != '>' && str[i] != '|')
					result->file_limiter[j++] = str[i++];
				result->file_limiter[j] = '\0';
			}
		}
		i++;
	}
	return (result);
}

t_line_splited	*ft_extract_redirections(char *str)
{
	t_line_splited	*result;

	result = malloc(sizeof(t_line_splited));
	if (!result)
		return (NULL);
	result->redirection = link_redirections(str);
	result->cmd = ft_split(rest_of_the_cake, ' ');
	return (result);
}

void	preparing_for_execution(t_line_splited **head, char **line_splited)
{
	int		i;
	t_line_splited	*tmp;

	if (!line_splited)
		return ;
	*head = NULL;
	i = 0;
	while (line_splited[i])
	{
		tmp = malloc(sizeof(t_line_splited));
		tmp = ft_extract_redirections_cmd(ft_strdup(line_splited[i]));
		ft_lstadd_back(head, tmp);
		i++;
	}
}
