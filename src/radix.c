/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:14:06 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/27 17:00:40 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		len;
	int		maxbits;

	i = -1;
	len = ft_lstsize(*stack_a);
	put_index(stack_a, len);
	maxbits = get_maxbits(stack_a);
	while (++i < maxbits)
	{
		j = -1;
		while (++j < len)
		{
			tmp = *stack_a;
			if ((tmp->index >> i & 1) == 1)
				do_rotate(stack_a, 'a');
			else
				do_push(stack_b, stack_a, 'b');
		}
		while (ft_lstsize(*stack_b) != 0)
			do_push(stack_a, stack_b, 'a');
	}
}

int	get_maxbits(t_list **stack_a)
{
	int	i;

	i = 0;
	find_max(*stack_a);
	while (global_list()->max != 0 && ++i)
		global_list()->max = global_list()->max >> 1;
	return (i);
}

void	find_max(t_list *stack_a)
{
	global_list()->max = INT_MIN;
	while (stack_a)
	{
		if (global_list()->max < stack_a->index)
			global_list()->max = stack_a->index;
		stack_a = stack_a->next;
	}
}

t_list	*global_list(void)
{
	static t_list	list;

	return (&list);
}

void	put_index(t_list **stack, int len)
{
	int		min;
	t_list	*tmp;
	int		i;

	i = -1;
	while (++i < len)
	{
		min = INT_MAX;
		tmp = *stack;
		while (tmp)
		{
			if (min > tmp->num && tmp->index == -1)
				min = tmp->num;
			tmp = tmp->next;
		}
		tmp = *stack;
		while (min != tmp->num)
			tmp = tmp->next;
		tmp->index = i;
	}
}
