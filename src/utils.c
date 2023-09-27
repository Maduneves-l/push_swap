/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:08:43 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/25 14:19:18 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//função que verifica se o argumento passado é um int válido,
//se não tem números repetidos e depois organiza os números na lista (stack_a)
void	number_to_list(char **av, t_list **list)
{
	long long	n;
	int			i;

	i = 0;
	while (av[++i])
	{
		if (check_int(av[i]))
		{
			n = ft_atoi(av[i]);
			if (n > INT_MAX || n < INT_MIN)
				error(*list);
			if (check_repeat(list, n))
				error(*list);
			ft_lstadd_back(list, ft_lstnew(n));
		}
		else
			error(*list);
	}
}

//função para verificar se é um número aceitável,
//sem sinais a mais ou letras

int	check_int(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

//função para verificar se o número colocada na lista
//é repetido, entao compara o atual com os que já estão na lista
int	check_repeat(t_list **list, int n)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->num != n)
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}

//função que transforma char para int
long long	ft_atoi(char *s)
{
	long long	i;
	long long	res;
	long long	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i])
	{
		res *= 10;
		res += s[i] - 48;
		i++;
	}
	return (sign * res);
}

//função para casos de erros
void	error(t_list *list)
{
	ft_lstclear(&list);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
