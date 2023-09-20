/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:13:09 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 18:15:36 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int i;
	i = 0;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
	{
		write(2, " Error: Invalid number of arguments\n", 36);
		exit(EXIT_FAILURE);
	}
	while(i < 4)
	{
		ft_lstadd_back(&stack_b, ft_lstnew(i));
		i++;
	}
	number_to_list(av, &stack_a);
	printf("stack_b:\n");
	print(stack_b);
	printf("stack_a:\n");
	print(stack_a);
	do_swap(&stack_a, 'a');
	printf("stack_a:\n");
	print(stack_a);
	printf("stack_b:\n");
	print(stack_b);
	do_push(&stack_a, &stack_b, 'a');
	printf("stack_a:\n");
	print(stack_a);
	printf("stack_b:\n");
	print(stack_b);
	do_rotate(&stack_a, 'a');
	printf("stack_a:\n");
	print(stack_a);
	printf("stack_b:\n");
	print(stack_b);
	rev_rotate(&stack_b, 'b');
	printf("stack_b:\n");
	print(stack_b);
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

void 	print(t_list *stack)
{
	t_list *tmp;
	tmp = stack;
 	while(tmp)
	{
		printf("num = %d\n", tmp->num);
		tmp = tmp->next;
	}
}
