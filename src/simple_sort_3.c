/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 11:54:02 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 15:20:31 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	if_one(t_stack *stack)
{
	ra(stack);
	sa(stack);
	rra(stack);
}

static void	if_two(t_stack *stack, int min)
{
	t_node	*head;

	head = stack->top;
	if (head->next->index == min)
		sa(stack);
	else
		rra(stack);
}

static void	if_three(t_stack *stack, int min)
{
	t_node	*head;

	head = stack->top;
	if (head->next->index == min)
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_3(t_stack *stack)
{
	t_node	*head;
	int		min;
	int		min_next;

	head = stack->top;
	min = get_min_index(stack, -1);
	min_next = get_min_index(stack, min);
	if (is_sorted(stack))
		return ;
	if (head->index == min && head->next->index != min_next)
		if_one(stack);
	else if (head->index == min_next)
		if_two(stack, min);
	else
		if_three(stack, min);
}
