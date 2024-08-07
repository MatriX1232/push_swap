/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:31:02 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/17 16:42:33 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *stackA)
{
	int		tmp;
	t_node	*first;

	first = stackA->top;
	if (first != NULL && first->next != NULL)
	{
		tmp = first->value;
		first->value = first->next->value;
		first->next->value = tmp;
	}
}

void	sb(t_stack *stackB)
{
	int		tmp;
	t_node	*first;

	first = stackB->top;
	if (first != NULL && first->next != NULL)
	{
		tmp = first->value;
		first->value = first->next->value;
		first->next->value = tmp;
	}
}

void	ss(t_stack *stackA, t_stack *stackB)
{
	sa(stackA);
	sb(stackB);
}
