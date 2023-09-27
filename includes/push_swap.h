/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneves-l <mneves-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:09:08 by mneves-l          #+#    #+#             */
/*   Updated: 2023/09/27 17:02:16 by mneves-l         ###   ########.fr       */
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
	int				index;
	int				max;
	int				min;
	struct s_list	*next;
}					t_list;

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
void				do_swap(t_list **stack, char flag);
void				do_push(t_list **dest, t_list **src, char c);
void				do_rotate(t_list **stack, char c);
void				rev_rotate(t_list **stack, char c);

//moves_d.c
void				ss_swap(t_list **stack_a, t_list **stack_b, char flag);
void				rr_rotate(t_list **stack_a, t_list **stack_b, char c);
void				rrr_rotate(t_list **stack_a, t_list **stack_b, char c);

//sort_3.c
void				make_3(t_list **stack);

//sort_5.c
void				make_4_5(t_list **stack_a, t_list **stack_b);
void				organize(int count, int o, t_list **stack_a,
						t_list **stack_b);
int					find_small(t_list *stack);
int					ft_lstsize(t_list *lst);
int					need_sort(t_list **list);

//main.c
void				choose_case(int ac, t_list **stack_a, t_list **stack_b);
void				print(t_list *stack);

//radix.c
void				radix(t_list **stack_a, t_list **stack_b);
int					get_maxbits(t_list **stack_a);
void				find_max(t_list *stack_a);
t_list				*global_list(void);
void				put_index(t_list **stack, int len);
#endif