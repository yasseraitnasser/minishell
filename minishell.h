/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:20:50 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/17 21:04:57 by yait-nas         ###   ########.fr       */
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

typedef struct s_redirection
{
	int	redirection_type;
	char	*file_limiter;
	struct s_redirection	*next;
}	t_redirection;

typedef struct s_line_splited
{
	char	**cmd;
	t_redirection	*redirection;
	struct s_line	*next;
}	t_line_splited;

int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *str, char c);
int		count_words_and_check(char *str, char c);
int		check_what_is_next(char *str);
void	parsing(char **line_splited);
void	free_matrix(char **line_splited);
void	preparing_for_execution(t_line_splited **head, char **line_splited);
char	*ft_strdup(const char *s1);

#endif
