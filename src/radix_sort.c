/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:34 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 13:52:56 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	get_max_bits(t_stack *stack)
{
	int		max;
	int		bits_max;
	t_node	*head;

	max = 0;
	bits_max = 0;
	head = stack->top;
	while (head != NULL)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> bits_max) != 0)
		bits_max++;
	return (bits_max);
}

void	sort_radix(t_stack *a, t_stack *b)
{
	int		i;
	int		j;
	int		size;
	int		b_max;

	i = 0;
	size = ft_lstsize(a);
	b_max = get_max_bits(a);
	while (i < b_max)
	{
		j = 0;
		while (j++ < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_lstsize(b) != 0)
			pa(a, b);
		i++;
	}
}
