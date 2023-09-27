/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:20:27 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/27 17:11:51 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_4_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*curr;
	int		pos;

	curr = *stack_a;
	if (ft_lstsize(*stack_a) == 5)
	{
		pos = find_small(curr);
		organize(pos, 5, stack_a, stack_b);
		curr = *stack_a;
	}
	pos = find_small(curr);
	organize(pos, 4, stack_a, stack_b);
	if (need_sort(stack_a))
		make_3(stack_a);
	while (*stack_b)
		do_push(stack_a, stack_b, 'a');
}

void	organize(int count, int o, t_list **stack_a, t_list **stack_b)
{
	if (count > 2)
	{
		if (o == 5)
			count = 5 - count;
		if (o == 4)
			count = 4 - count;
		while (count)
		{
			rev_rotate(stack_a, 'a');
			count--;
		}
	}
	else
	{
		while (count)
		{
			do_rotate(stack_a, 'a');
			count--;
		}
	}
	do_push(stack_b, stack_a, 'b');
}

int	find_small(t_list *stack)
{
	t_list	*tmp;
	t_list	*small;
	int		i;

	i = 0;
	small = stack;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num < small->num)
			small = tmp;
		tmp = tmp->next;
	}
	tmp = stack;
	while (tmp != small)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

//função que verifica se os argumentos já
//estão organizados (if need push)
int	need_sort(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
