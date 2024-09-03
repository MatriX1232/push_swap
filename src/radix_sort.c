/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:34 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/03 12:11:56 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_get_maximum_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_b;

	head = *stack;
	max = head->index;
	max_b = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_b) != 0)
		max_b++;
	return (max_b);
}

void	sort_radix(t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		size;
	int		max_b;
	t_list	*top_a;

	top_a = *a;
	size = ft_lstsize(top_a);
	max_b = ft_get_maximum_bits(a);
	i = 0;
	while (i < max_b)
	{
		j = 0;
		while (j++ < size)
		{
			top_a = *a;
			if (((top_a->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (ft_lstsize(*b) != 0)
			pa(a, b);
		i++;
	}
}
