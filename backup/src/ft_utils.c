/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:19:05 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/18 16:54:17 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_init_stack(t_stack *stack)
{
	stack = (t_stack *) malloc(1 * sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	ft_printf("Created stack!\n");
	return (stack);
}

void	ft_create_node(t_stack *stack, int val)
{
	t_node	*last;
	t_node	*new;

	new = (t_node *) malloc(1 * sizeof(t_node));
	if (!new)
		return ;
	ft_printf("Malloce'd t_node\n");
	last = stack->top;
	while (last->next != NULL)
		last = last->next;
	ft_printf("Got last element!\n");
	new->value = val;
	new->next = NULL;
	new->index = last->index + 1;
	last->next = new;
	stack->size++;
}

void	ft_print_stack(t_stack *stack, char *custom_message)
{
	t_node	*first;

	write(1, custom_message, ft_strlen(custom_message));
	write(1, "\n", 1);
	ft_printf("Stack size: %d\n", stack->size);
	first = stack->top;
	while (first->next != NULL)
	{
		ft_printf("[%d]		%d", first->index, first->value);
		first = first->next;
	}
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*to_free;

	node = stack->top;
	while (node != NULL)
	{
		to_free = node;
		node = node->next;
		free(to_free);
	}
	free(stack);
}
