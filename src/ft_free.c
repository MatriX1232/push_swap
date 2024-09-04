/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:51:49 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/04 12:51:37 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//			Check for length of array
static int	ft_get_tab_len(char **parms)
{
	int	len;

	len = 0;
	while (parms[len])
		len++;
	return (len);
}

//		Free each of ther pointers and array
void	ft_free(char **parms)
{
	int	len;

	len = ft_get_tab_len(parms);
	while (len >= 0)
		free(parms[len--]);
	free(parms);
}

//		Free the whole linked list (stack / nodes)
void	ft_free_nodes(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}
