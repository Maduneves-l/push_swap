/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:49:05 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/26 17:55:02 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_pieces(int len)
{
	int	pieces;

	pieces = 1;
	if (len == 100)
		pieces = 2;
	else if (len == 500)
		pieces = 5;
	return (pieces);
}

void	sort_arr(int **arr, int ac)
{
	int	i;
	int	j;
	int	tmp;

	j = 1;
	while (j > 0)
	{
		i = 0;
		j = 0;
		while (i < (ac - 1))
        {
            if((*arr)[i] > (*arr)[i + 1])
            {
                tmp = (*arr)[i];
                (*arr)[i] = (*arr)[i + 1];
                (*arr)[i + 1] = tmp;
                j++;   
            }
            i++;
        }
	}
}

int	*creat_arr(t_list **stack_a, int ac)
{
	int		*array;
	t_list	*tmp;
	int		i;
		retrun NULL;

	tmp = *stack_a;
	array = malloc(ac * sizeof(int));
	i = 0;
	if (!array)
	while (tmp)
	{
		array[i] = tmp;
		tmp = tmp->next;
		i++;
	}
	sort_arr(&array, ac);
	return (array);
}

void    get_values(t_piece *piece, int *arr, int len, int flag)
{
    if(flag == 1)
    {
        piece->i_min = 0;
        piece->i_max = len; 
    }
    else 
    {
        piece->i_min = len;
        piece->i_max = piece->i_min + len;
    }
    piece->min = arr[piece->i_min];
    piece->max = arr[piece->i_max];
}

int    exist_piece(t_list **stack_a, t_piece piece)
{
    t_list *tmp;
    tmp = *stack_a;

    while(tmp)
    {
        if(tmp->num >= piece.min && tmp->num <= piece.max)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

void    push_piece(t_list **stack_a, t_list **stack_b, t_piece pc, int nb)
{
    if(*stack_a)
    {
        if((*stack_a)->num >= pc.min && (*stack_a)->num <= pc.max)
            do_push(stack_b, stack_a, 'b');
        else
        {
            if(nb == 2)
            {
                do_push(stack_b, stack_a, 'b');
                do_rotate(stack_b, 'b');
            }
            else
                do_rotate(stack_a, 'a');
        }
    }
}