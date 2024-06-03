/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:20:50 by yait-nas          #+#    #+#             */
/*   Updated: 2024/06/02 18:56:43 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *str, char c);
int		count_words_and_check(char *str, char c);
int		check_what_is_next(char *str);
void	parsing(char **line_splited);
void	free_matrix(char **line_splited);

#endif
