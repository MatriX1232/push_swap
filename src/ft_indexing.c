/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:12:27 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 17:31:08 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_node	*ft_get_next_mininum(t_stack *stack)
{
	t_node	*head;
	t_node	*min;
	int		min_index;

	head = stack->top;
	min = NULL;
	min_index = 0;
	if (!head)
		return (NULL);
	while (head)
	{
		if ((head->index == -1) && (!min_index || head->value < min->value))
		{
			min = head;
			min_index = 1;
		}
		head = head->next;
	}
	return (min);
}

void	ft_index_stack(t_stack *stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = ft_get_next_mininum(stack);
	while (head)
	{
		head->index = index;
		head = ft_get_next_mininum(stack);
		index++;
	}

}
