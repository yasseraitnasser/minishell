/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/17 09:18:50 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**line_splited;
	//t_line_splited	*head;
	int	i = 0;

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
			parsing(line_splited);
			//preparing_for_execution(&head, line_splited);
			write(1, "fuck\n", 5);
			while (line_splited[i])
			{
				printf("%s\n", line_splited[i]);
				i++;
			}
			free_matrix(line_splited);
			free(str);
		}
	}
	else
		write(2, "eat those arguments :)\n", 23);
}
