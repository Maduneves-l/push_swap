/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:13:09 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/26 14:47:53 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_case(int ac, t_list **stack_a, t_list **stack_b)
{
	if (ac == 3)
		do_swap(stack_a, 'a');
	else if (ac == 4)
		make_3(stack_a);
	else if (ac == 5 || ac == 6)
		make_4_5(stack_a, stack_b);
	else 
		make_100(stack_a, stack_b, ac);
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

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		exit(EXIT_FAILURE);
	number_to_list(av, &stack_a);
	print(stack_a);
	if (need_sort(&stack_a))
		choose_case(ac, &stack_a, &stack_b);
	print(stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
void	print(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		printf("num = %d\n", tmp->num);
		tmp = tmp->next;
	}
}
