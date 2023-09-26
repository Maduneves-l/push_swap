/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:45:28 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/26 12:45:46 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->num;
	b = (*stack)->next->num;
	c = (*stack)->next->next->num;
	if (a < b && b > c && a < c)
	{
		do_swap(stack, 'a');
		do_rotate(stack, 'a');
	}
	if (a > b && b < c && a < c)
		do_swap(stack, 'a');
	if (a < b && b > c && a > c)
		rev_rotate(stack, 'a');
	if (a > b && b < c && a > c)
		do_rotate(stack, 'a');
	if (a > b && b > c && a > c)
	{
		do_rotate(stack, 'a');
		do_swap(stack, 'a');
	}
}
