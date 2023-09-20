/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:49:11 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 18:12:48 by mneves-l         ###   ########.fr       */
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

void    do_rotate(t_list ** stack, char c)
{
    t_list *tmp;
    if(!stack || !*stack)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = NULL;
    ft_lstadd_back(stack, tmp);
    if (c == 'a')
        write(1, "ra\n", 3);
    if (c == 'b')
        write(1, "rb\n", 3);
    
}

void    rev_rotate(t_list **stack, char c)
{
    t_list *last;
    t_list *cursor;
    if(!stack || !*stack)
        return ;
    cursor = *stack;
    last = ft_lstlast(*stack);
    while(cursor->next != last)
        cursor = cursor->next;
    cursor->next = NULL;
    ft_lstadd_front(stack, last);
        
    if (c == 'a')
        write(1, "rra\n", 4);
    else if (c == 'b')
        write(1, "rrb\n", 4);
}