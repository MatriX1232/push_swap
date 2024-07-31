/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:45:47 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/31 13:58:51 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// typedef struct	s_node
// {
// 	int		val;
// 	int		index;
// 	t_node	*next;
// }	t_node;

// typedef struct s_stack
// {
// 	t_node	*start;
// 	int		size;
// }	t_stack;

#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node {
	int value;
	struct s_node *next;
} t_node;

typedef struct s_stack {
	t_node *top;
} t_stack;

// Stack operations
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);
void    reverse_rotate(t_stack *stack);

// Utilities
t_stack *create_stack();
void    free_stack(t_stack *stack);
bool    is_empty(t_stack *stack);
int     stack_size(t_stack *stack);

// Push_swap operations
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// Quicksort algorithm
void    quicksort(t_stack *a, t_stack *b, int size);
void    sort_three(t_stack *a);

#endif
