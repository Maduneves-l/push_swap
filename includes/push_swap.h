/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:08 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/20 18:21:02 by mneves-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;


void 	print(t_list *stack);

//utils.c
void				number_to_list(char **av, t_list **list);
int					check_int(char *s);
int					check_repeat(t_list **list, int n);
long long			ft_atoi(char *s);
void				error(t_list *list);

//f_list.c
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int n);
t_list				*ft_lstlast(t_list *lst);



//moves.c
void    do_swap(t_list ** stack, char flag);
void    do_push(t_list **stack_a, t_list **stack_b, char c);
void    do_rotate(t_list ** stack, char c);
void    rev_rotate(t_list **stack, char c);

//moves_2.c
void    ss_swap(t_list **stack_a, t_list **stack_b, char flag);
void    rr_rotate(t_list **stack_a, t_list **stack_b, char c);
void    rrr_rotate(t_list **stack_a, t_list **stack_b, char c);
#endif