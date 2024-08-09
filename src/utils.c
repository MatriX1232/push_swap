/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 12:00:14 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 16:20:31 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*head;

	head = stack->top;
	while (head && head->next != NULL)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_dis(t_stack *stack, int idx)
{
	int		dis;
	t_node	*head;

	dis = 0;
	head = stack->top;
	while (head)
	{
		if (head->index == idx)
			break ;
		head = head->next;
		dis++;
	}
	return (dis);
}

void	index_stack(t_stack *stack)
{
	int		index;
	t_node	*head;

	index = 0;
	head = stack->top;
	while (head)
	{
		head->index = index;
		index++;
		head = head->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*head;
	t_node	*tmp;

	head = stack->top;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_print_error(char *str)
{
	write(1, "\033[91m", 6);
	write(1, "ERROR: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	write(1, "\033[39m", 6);
}
