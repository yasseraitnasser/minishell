/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:44:02 by yait-nas          #+#    #+#             */
/*   Updated: 2024/06/02 19:00:07 by yait-nas         ###   ########.fr       */
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
			line_splited = ft_split(str, '|');
			parsing(line_splited);
			free(str);
		}
	}
	else
		write(2, "eat those arguments :)\n", 23);
}
