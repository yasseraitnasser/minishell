/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/30 19:00:29 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*str;
	char	**line_splited;

	(void)argv;
	(void)env;
	if (argc == 1)
	{
		while (1)
		{
			str = readline("> ");
			if (!str || !ft_strcmp(str, "exit"))
				break ;
			//parsing(str);
			line_splited = ft_split(str, '|');
			while (line_splited && *line_splited)
			{
				printf("%s\n", *line_splited);
				line_splited++;
			}
			free(str);
		}
	}
	else
		write(2, "eat those arguments :)\n", 23);
}
