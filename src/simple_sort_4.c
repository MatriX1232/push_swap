/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:00:58 by msolinsk          #+#    #+#             */
/*   Updated: 2024/09/02 12:12:22 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_4(t_list **a, t_list **b)
{
	int	dis;

	if (is_sorted(a))
		return ;
	dis = get_dis(a, get_min_index(a, -1));
	if (dis == 1)
		ra(a);
	else if (dis == 2)
	{
		ra(a);
		ra(a);
	}
	else if (dis == 3)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_3(a);
	pa(a, b);
}
