/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:47 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 15:20:10 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min_index(t_stack *stack, int val)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	size;

	if (is_sorted(a))
		return ;
	if (ft_lstsize(a) == 0 || ft_lstsize(a) == 1)
		return ;
	size = ft_lstsize(a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
