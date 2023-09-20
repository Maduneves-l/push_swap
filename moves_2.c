/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:47:07 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 18:20:12 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ss_swap(t_list **stack_a, t_list **stack_b, char flag)
{
    do_swap(stack_a, flag);
    do_swap(stack_b, flag);
    if(flag == 's')
        write(1, "ss\n", 3);
}
void    rr_rotate(t_list **stack_a, t_list **stack_b, char c)
{
    do_rotate(stack_a, c);
    do_rotate(stack_b, c);
    if(c == 'r')
        write(1, "rr\n", 3);
}

void    rrr_rotate(t_list **stack_a, t_list **stack_b, char c)
{
    rev_rotate(stack_a, c);
    rev_rotate(stack_b, c);
    if (c == 'rr')
        write(1, "rrr\n", 4);
}
