/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:36:21 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/20 21:31:48 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_up_blank(t_line_splited *empty_node, int redirection_t, char *tmp)
{
	t_redirection	*redirection;
	int		i;
	char	*file_lim;

	if (*tmp == '<' || *tmp == '>')
	{
		*tmp = ' ';
		tmp++;
	}
	while (*tmp == ' ')
		tmp++;
	redirection = malloc(sizeof(t_redirection));
	if (!redirection)
		return ; // work to do befor returning
	redirection->redirection_type = redirection_t;
	i = 0;
	while (tmp[i] && tmp[i] != ' ' && tmp[i] != '<'
		&& tmp[i] != '>' && tmp[i] != '|')
		i++;
	file_lim = malloc(i + 1);
	if (!file_lim)
		return ; // work here as well :)
	i = 0;
	while (*tmp && *tmp != ' ' && *tmp != '<'
		&& *tmp != '>' && *tmp != '|')
	{
		file_lim[i++] = *tmp;
		*tmp = ' ';
		tmp++;
	}
	file_lim[i] = '\0';
	redirection->file_limiter = file_lim;
	redirection->next = NULL;
	ft_lstadd_back2(&(empty_node->redirection), redirection);
}

void	ft_extract_redirections_cmd(t_line_splited *empty_node, char *str)
{
	char	*tmp;

	tmp = str;
	while (*tmp)
	{
		if (*tmp == '<')
		{
			*tmp = ' ';
			tmp++;
			if (*tmp == '<')
				fill_up_blank(empty_node, 2, tmp);
			else
				fill_up_blank(empty_node, 1, tmp);
		}
		if (*tmp == '>')
		{
			*tmp = ' ';
			tmp++;
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
	int		i;
	t_line_splited	*tmp;

	*head = NULL;
	i = 0;
	while (line_splited[i])
	{
		tmp = malloc(sizeof(t_line_splited));
		if (!tmp)
			return ; // alote to do befor returning
		tmp->redirection = NULL;
		tmp->cmd = NULL;
		tmp->next = NULL;
		ft_extract_redirections_cmd(tmp, ft_strdup(line_splited[i]));
		ft_lstadd_back1(head, tmp);
		i++;
	}
}
