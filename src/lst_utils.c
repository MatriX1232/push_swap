/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:16:10 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/27 16:28:43 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	int		size;
	t_node	*head;

	size = 0;
	head = stack->top;
	while (head != NULL)
	{
		head = head->next;
		size++;
	}
	return (size);
}

t_node	*ft_lstlast(t_stack *stack)
{
	t_node	*head;

	if (!stack || !stack->top)
		return (NULL);
	head = stack->top;
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_node	*ft_lstnew(int val)
{
	t_node	*node;

	node = (t_node *) malloc(1 * sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = val;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_stack *stack, t_node *new)
{
	new->next = stack->top;
	stack->top = new;
}

void	ft_lstadd_back(t_stack *stack, t_node *new)
{
	t_node	*last;

	if (!new)
		return ;
	if (stack->top)
	{
		last = ft_lstlast(stack);
		new->next = NULL;
		last->next = new;
	}
	else
	{
		stack->top = new;
		stack->top->next = NULL;
	}
}
