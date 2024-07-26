/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_for_execution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:36:21 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/26 22:19:21 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_file_name(char *tmp)
{
	int		i;
	char	*file_name;

	i = 0;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '<'
		&& tmp[i] != '>' && tmp[i] != '|')
		i++;
	file_name = malloc(i + 1);
	if (!file_name)
		return (NULL);
	i = 0;
	while (*tmp && *tmp != ' ' && *tmp != '<'
		&& *tmp != '>' && *tmp != '|')
	{
		file_name[i++] = *tmp;
		*tmp = ' ';
		tmp++;
	}
	file_name[i] = '\0';
	return (file_name);
}

void	fill_up_blank(t_line_splited *empty_node, int redirection_t, char *tmp)
{
	t_redirection	*redirection;

	if (*tmp == '<' || *tmp == '>')
	{
		*tmp = ' ';
		tmp++;
	}
	while (*tmp == ' ')
		tmp++;
	redirection = malloc(sizeof(t_redirection));
	if (!redirection)
		return ;
	redirection->redirection_type = redirection_t;
	redirection->file_limiter = get_file_name(tmp);
	redirection->next = NULL;
	ft_lstadd_redirection(&(empty_node->redirection), redirection);
}

void	ft_extract_redirections_cmd(t_line_splited *empty_node, char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == '<')
		{
			*(tmp++) = ' ';
			if (*tmp == '<')
				fill_up_blank(empty_node, 2, tmp);
			else
				fill_up_blank(empty_node, 1, tmp);
		}
		if (*tmp == '>')
		{
			*(tmp++) = ' ';
			if (*tmp == '>')
				fill_up_blank(empty_node, 4, tmp);
			else
				fill_up_blank(empty_node, 3, tmp);
		}
		tmp++;
	}
	empty_node->cmd = ft_normal_split(str, ' ');
	free(str);
}

void	set_up_for_execution(t_line_splited **head, char **line_splited)
{
	int				i;
	t_line_splited	*tmp;

	*head = NULL;
	if (!line_splited)
		return ;
	i = 0;
	while (line_splited[i])
	{
		tmp = malloc(sizeof(t_line_splited));
		if (!tmp)
			return ;
		tmp->redirection = NULL;
		tmp->cmd = NULL;
		tmp->next = NULL;
		ft_extract_redirections_cmd(tmp, ft_strdup(line_splited[i]));
		ft_lstadd_line_splited(head, tmp);
		i++;
	}
}
