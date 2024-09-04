/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/09/04 23:55:14 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//		Puts error message in stderr (standard error)
void	ft_print_error(char *msg, char **parms, int malloc)
{
	ft_putstr_fd(msg, 2);
	if (malloc == 1)
		ft_free(parms);
	exit(EXIT_FAILURE);
}

/*
	Returns 1 if stack is sorted
	Returns 0 if stack is not sorted
*/
int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

/*
	Returns a distance from start to node with index.
	Index is passed as an parameter in function
*/
int	get_dis(t_list **stack, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

static void	ft_move_with_dis(t_list **stack, t_list *head, int dis, int tmp)
{
	if (dis <= (ft_lstsize(head) / 2))
	{
		while (dis > 0)
		{
			ra(stack);
			dis--;
		}
	}
	else
	{
		while (tmp > 0)
		{
			rra(stack);
			tmp--;
		}
	}
}

/*
	The function moves node at the specified distance from the head of
		linked list to the top of the list.

	It is done by rotating and reverse rotating the stack,
	to achive this node movement

	If distance if lesser that half of stack size,
	it means that the node is in first half.
	Else it's in the second half
*/
void	make_top(t_list **stack, int distance)
{
	t_list	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *stack;
	tmp = ft_lstsize(head) - distance;
	ft_move_with_dis(stack, head, distance, tmp);
}
