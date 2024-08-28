/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:45:47 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 13:59:48 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

// Stack operations
int			push(t_stack *stack_to, t_stack *stack_from);
int			pop(t_stack *stack);
int			swap(t_stack *stack);
int			rotate(t_stack *stack);
int			reverse_rotate(t_stack *stack);

// Utilities
t_stack		*create_stack(void);
void		free_stack(t_stack *stack);
bool		is_empty(t_stack *stack);
int			stack_size(t_stack *stack);

// Push_swap operations
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

//	Radix algorithm
void		sort_radix(t_stack *a, t_stack *b);
void		sort_simple(t_stack *a, t_stack *b);
void		sort_3(t_stack *stack);
void		sort_4(t_stack *a, t_stack *b);
void		sort_5(t_stack *a, t_stack *b);

//	FT_LST_UTILS
int			ft_lstsize(t_stack *stack);
t_node		*ft_lstlast(t_stack *stack);
t_node		*ft_lstnew(int val);
void		ft_lstadd_front(t_stack *stack, t_node *new);
void		ft_lstadd_back(t_stack *stack, t_node *new);

//	UTILS
int			is_sorted(t_stack *stack);
int			get_dis(t_stack *stack, int idx);
int			get_min_index(t_stack *stack, int val);
void		ft_print_error(char *str);
int			ft_check_args(int argc, char *argv[]);
void		ft_free(char **parms);
void		index_stack(t_stack *stack);
void		ft_free_stack(t_stack *stack);
void		ft_print_stack(t_stack *stack);

#endif
