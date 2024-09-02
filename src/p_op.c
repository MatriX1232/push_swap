/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:22:54 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/02 11:05:49 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_list **a, t_list **b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
