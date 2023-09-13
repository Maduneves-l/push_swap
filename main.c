/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:13:09 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/12 16:44:07 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
	{
		write(2, " Error: Invalid number of arguments\n", 36);
		exit(EXIT_FAILURE);
	}
	number_to_list(av, &stack_a);
    if(need_push(&stack_a))
    {
        
    }
	free(stack_a);
	free(stack_b);
}

//função que verifica se os argumentos já
//estão organizados (if need push)
int	need_push(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
