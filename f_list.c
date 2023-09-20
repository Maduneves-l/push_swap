/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:32:38 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 17:41:31 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//file com todas as funções de listas

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*current;

    if(!*lst)
        return ;
	while (*lst)
	{
		current = (*lst)->next;
		free(*lst);
		*lst = current;
	}
	lst = NULL;
}

t_list	*ft_lstnew(int n)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->num = n;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
