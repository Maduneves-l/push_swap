/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:21:17 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/26 18:34:10 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_100(t_list **stack_a, t_list **stack_b, int ac)
{
	int *arr;
	int len;
	int max;
    t_piece piece;

	max = ft_lstsize(*stack_a);
	len = ft_lstsize(max) / number_pieces(max);
	arr = creat_arr(stack_a, ac);
    get_values(&piece, arr, len, 1);
    while(ft_lstsize(*stack_a) > 3)
    {
        if(exist_piece(stack_a, piece))
            push_piece(stack_a, stack_b, piece, number_pieces(max));
        else
            get_values(&piece, arr, len, 2); 
    }
    free(arr);
    if(need_sort(stack_a))
        make_3(stack_a);
    while(ft_lstsize(*stack_b) > 0)
        push_back_a(stack_a, stack_b);
    
}

void    push_back_a(t_list **stack_a, t_list **stack_b)
{
    
}

