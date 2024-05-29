/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:20:50 by yait-nas          #+#    #+#             */
/*   Updated: 2024/05/29 16:10:55 by yait-nas         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
void	ft_error(char *str);
void	parsing(char *str);
char	**ft_split(char *str);
char	*ultimate_alloc(int *i, char **result, int index);
int		count_words_and_check(char *str);
void	if_next_char_is_true(char *str, int i, int *count);

#endif
