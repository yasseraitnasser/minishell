/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:18:24 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/29 16:10:32 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "minishell.h"

int	main(void)
{
	char	*str;

	str = readline("-> ~ ");
	if (!str || !(*str))
		exit(EXIT_SUCCESS);
	parsing(str);
	free(str);
	return (0);
}
