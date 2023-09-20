/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:11 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 11:32:53 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//funçãp que faz um swap (troca) dos dois primeiros
//nodes da lista, se tiver pelo menos dois
void    do_swap(t_list ** stack, char flag)
{
    t_list  *second;
    second = (*stack)->next;
    if(*stack == NULL || (*stack)->next == NULL)
        return ;
    (*stack)->next = second->next;
    second ->next = *stack;
    *stack = second;
    if (flag == 'a')
         write(1, "sa\n", 3);
    else if(flag == 'b')
         write(1, "sb\n", 3);
}

void    ss_swap(t_list **stack_a, t_list **stack_b, char flag)
{
    do_swap(stack_a, flag);
    do_swap(stack_b, flag);
    if(flag == 's')
        write(1, "ss\n", 3);
}

void    do_push(t_list **dest, t_list **src, char c)
{
    t_list *tmp;
    
    if(!*src || !src)
        return ;
    tmp = *src;
    *src = (*src)->next;
    ft_lstadd_front(dest, tmp);
    if (c == 'a')
        write(1, "pa\n", 3);
    else if (c == 'b')
        write(1, "pb\n", 3);
}