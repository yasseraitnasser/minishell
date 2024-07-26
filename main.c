/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/26 22:25:16 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char			*str;
	char			**line_splited;
	t_line_splited	*head;

	(void)argv;
	(void)env;
	if (argc == 1)
	{
		while (1)
		{
			str = readline("> ");
			if (!str || !ft_strcmp(str, "exit"))
				break ;
			if (parsing(str))
			{
				line_splited = ft_split_with_pipe(str, '|');
				set_up_for_execution(&head, line_splited);
				free_matrix(line_splited);
				free_everything(head);
			}
			free(str);
		}
	}
	else
		write(2, "eat those arguments :)\n", 23);
}
