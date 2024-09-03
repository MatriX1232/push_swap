/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/09/03 12:13:31 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

// Stack
typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

// FT_LSTUTILS.C
t_list	*ft_lstnew(int val);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstadd_back(t_list **stack, t_list *new);
void	printList(t_list *head);
int		ft_lstsize(t_list *head);

// FT_UTILS.C
void	ft_error(char *msg);
void	ft_parse_parameters(int argc, char **argv);
int		is_sorted(t_list **stack);
int		get_dis(t_list **stack, int index);
void	make_top(t_list **stack, int distance);
void	ft_free_nodes(t_list **stack);
void	ft_free(char **str);
void	ft_print_error(char *msg);
int		get_min_index(t_list **stack, int val);

/*
FT_SIMPLE_SORT.C FT_RADIX_SORT.C
FT_SORT_5.C
FT_SIMPLE_SORT_4.C
FT_SIMPLE_SORT_3.C
FT_INDEXING.C
*/
void	sort_radix(t_list **a, t_list **b);
void	simple_sort(t_list **a, t_list **b);
void	ft_index_nodes(t_list **stack);

void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b);
void	sort_simple(t_list **a, t_list **b);

// *_OP.C
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

int		ra(t_list **a);
int		rb(t_list **b);
int		rr(t_list **a, t_list **b);

int		rra(t_list **a);
int		rrb(t_list **b);
int		rrr(t_list **a, t_list **b);

int		sa(t_list **a);
int		sb(t_list **b);
int		ss(t_list **a, t_list **b);

#endif
