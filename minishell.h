/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:20:50 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/23 16:13:44 by yait-nas         ###   ########.fr       */
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
	struct s_line_splited	*next;
}	t_line_splited;

int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *str, char c);
int		count_words_and_check(char *str, char c);
int		check_what_is_next(char *str, char c);
int		parsing(char *str);
void	free_matrix(char **line_splited);
void	set_up_for_execution(t_line_splited **head, char **line_splited);
void	ft_extract_redirections_cmd(t_line_splited *empty_node, char *str);
void	fill_up_blank(t_line_splited *empty_node, int redirection_type, char *tmp);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	ft_lstadd_back1(t_line_splited **lst, t_line_splited *new);
void	ft_lstadd_back2(t_redirection **lst, t_redirection *new);
t_line_splited	*ft_lstlast1(t_line_splited *lst);
t_redirection	*ft_lstlast2(t_redirection *lst);
char	**ft_normal_split(char const	*s, char c);

#endif
