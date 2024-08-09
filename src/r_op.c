/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:36:21 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/08 12:44:10 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*end;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack->top;
	end = ft_lstlast(stack);
	stack->top = head->next;
	head->next = NULL;
	end->next = head;
	return (0);
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
