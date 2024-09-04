/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/09/04 13:40:31 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
	This function is used to find the next min (that hasn't been indexed yet)
	Index == -1 is the indicade of node that hasn't been indexed yet.
*/
static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		contains_min;

	contains_min = 0;
	min = NULL;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if (head->index == -1)
			{
				if (!contains_min || head->value < min->value)
				{
					min = head;
					contains_min = 1;
				}
			}
			head = head->next;
		}
	}
	return (min);
}

//		Used to index all of nodes in linked list
void	ft_index_nodes(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
