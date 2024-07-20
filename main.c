/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/20 23:12:16 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**line_splited;
	t_line_splited	*head;
	t_redirection	*tmp;
	char	**cmd;

	(void)argv;
	(void)env;
	if (argc == 1)
	{
		while (1)
		{
			str = readline("> ");
			if (!str || !ft_strcmp(str, "exit"))
				break ;
			line_splited = ft_split(str, '|');
			if (parsing(line_splited))
			{
				set_up_for_execution(&head, line_splited);
				while (head)
				{
					printf("*****************\n");
					tmp = head->redirection;
					while (tmp)
					{
						printf("%d\n", tmp->redirection_type);
						printf("%s\n", tmp->file_limiter);
						tmp = tmp->next;
					}
					printf("*****************\n");
					cmd = head->cmd;
					while (*cmd)
					{
						printf("%s\n", *cmd);
						cmd++;
					}
					head = head->next;
					printf("*****************\n");
				}
			}
			free(str);
		}
	}
	else
		write(2, "eat those arguments :)\n", 23);
}
