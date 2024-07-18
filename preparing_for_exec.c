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
	t_redirection	*tmp;
	int		i;
	int		j;

	result = NULL;
	tmp = malloc(sizeof(t_redirection));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == '<')
		{
			i++;
			if (str[i] == '<')
			{
				tmp->redirection_type = 2;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] != '>' && str[i + j] != '|')
					j++;
				tmp->file_limiter = malloc(j + 1);
				if (!(tmp->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&&  str[i] != '>' && str[i] != '|')
					tmp->file_limiter[j++] = str[i++];
				tmp->file_limiter[j] = '\0';
			}
			else
			{
				tmp->redirection_type = 1;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] != '>' && str[i + j] != '|')
					j++;
				tmp->file_limiter = malloc(j + 1);
				if (!(tmp->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] != '>' && str[i] != '|')
					tmp->file_limiter[j++] = str[i++];
				tmp->file_limiter[j] = '\0';
			}
		}
		else if (str[i] == '>')
		{
			i++;
			if (str[i] == '>')
			{
				tmp->redirection_type = 4;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] != '>' && str[i + j] != '|')
					j++;
				tmp->file_limiter = malloc(j + 1);
				if (!(tmp->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] != '>' && str[i] != '|')
					tmp->file_limiter[j++] = str[i++];
				tmp->file_limiter[j] = '\0';
			}
			else
			{
				tmp->redirection_type = 3;
				while (str[i] == ' ')
					i++;
				j = 0;
				while (str[i + j] && str[i + j] != ' ' && str[i + j] != '<'
					&& str[i + j] != '>' && str[i + j] != '|')
					j++;
				tmp->file_limiter = malloc(j + 1);
				if (!(tmp->file_limiter))
					return (NULL);
				j = 0;
				while (str[i] && str[i] != ' ' && str[i] != '<'
					&& str[i] != '>' && str[i] != '|')
					tmp->file_limiter[j++] = str[i++];
				tmp->file_limiter[j] = '\0';
			}
		}
		write(1, "fuck\n", 5);
		ft_lstadd_back2(&result, tmp);
		i++;
	}
	return (result);
}

t_line_splited	*ft_extract_redirections_cmd(char *str)
{
	t_line_splited	*result;

	result = malloc(sizeof(t_line_splited));
	if (!result)
		return (NULL);
	result->redirection = link_redirections(str);
	//result->cmd = ft_split(rest_of_the_cake, ' '); to do to do to do
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
		tmp = ft_extract_redirections_cmd(ft_strdup(line_splited[i]));
		ft_lstadd_back1(head, tmp);
		i++;
	}
}
