/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:17:34 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/04 14:24:19 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	Returns the maximum number of bits required to represent
	the index of any node in the stack
*/
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

static void	if_one(t_list **a, t_list **b, t_list *top_a, int i)
{
	if (((top_a->index >> i) & 1) == 1)
		ra(a);
	else
		pb(a, b);
}

//	Push the rest of nodes in stack b to the stack a
static void	ft_push_rest_to_a(t_list **a, t_list **b)
{
	while (ft_lstsize(*b) != 0)
		pa(a, b);
}

/*
	This is radix sorting alhorithm.
	It performes indexing using base-2 (binary) system.

	This is non-comparative intiger sorting algorithm.
	It means that it doesn't compare the values of the nodes to sort them.
	It uses the binary representation of their index.
*/
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
		while (j < size)
		{
			top_a = *a;
			if_one(a, b, top_a, i);
			j++;
		}
		ft_push_rest_to_a(a, b);
		i++;
	}
}
