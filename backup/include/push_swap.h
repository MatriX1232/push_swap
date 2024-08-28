/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:06:41 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 13:52:12 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int		size;
	t_node	*top;
}	t_stack;

void	sa(t_stack *stackA);
void	sb(t_stack *stackB);
void	ss(t_stack *stackA, t_stack *stackB);

t_stack	*ft_init_stack(t_stack *stack);
void	ft_create_node(t_stack *stack, int val);
void	ft_print_stack(t_stack *stack, char *custom_message);
void	ft_free_stack(t_stack *stack);

#endif
