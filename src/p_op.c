/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:22:54 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/08 12:52:22 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_stack *stack_to, t_stack *stack_from)
{
	t_node	*tmp;
	t_node	*head_to;
	t_node	*head_from;

	if (ft_lstsize(stack_from) == 0)
		return (-1);
	head_to = stack_to->top;
	head_from = stack_from->top;
	tmp = head_from;
	head_from = head_from->next;
	stack_from->top = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		stack_to->top = head_to;
	}
	else
	{
		tmp->next = head_to;
		stack_to->top = tmp;
	}
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
