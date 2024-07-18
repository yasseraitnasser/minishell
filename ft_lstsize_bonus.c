/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:40:18 by yait-nas          #+#    #+#             */
/*   Updated: 2023/11/27 19:59:18 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp -> next;
	}
	return (i);
}
/*
#include<stdio.h>
int main()
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;


	char *s1 = "yasser";
	char *s2 = "yasser";
	char *s3 = "yasser";


	node1 = ft_lstnew(s1);
	node2 = ft_lstnew(s2);
	node3 = ft_lstnew(s3);

	node1 -> next = node2;
	node2 -> next = node3;
	printf("%d",ft_lstsize(node1));
}*/
