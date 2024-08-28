/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_op.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:55:12 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 13:53:57 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_stack *stack)
{
	t_node	*head;
	t_node	*next;
	int		tmp;
	int		tmp_idx;

	head = stack->top;
	next = head->next;
	if (ft_lstsize(stack) < 2)
		return (-1);
	if (!head && !next)
		ft_print_error("No head and next");
	tmp = head->value;
	tmp_idx = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp;
	next->index = tmp_idx;
	return (0);
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
