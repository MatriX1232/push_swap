/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:55:47 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/02 16:49:17 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_print_stack(t_list **stack)
{
	t_list	*head;

	if (!stack || !(*stack))
		return ;
	head = *stack;
	while (head != NULL)
	{
		ft_printf("%d\n", head->value);
		head = head->next;
	}
}

int	get_min_index(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_simple(t_list **a, t_list **b)
{
	int	size;

	if (is_sorted(a))
		return ;
	if (ft_lstsize(*a) == 0 || ft_lstsize(*a) == 1)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
