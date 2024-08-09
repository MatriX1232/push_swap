/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:07:13 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 15:20:16 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_5(t_stack *a, t_stack *b)
{
	int	dis;

	dis = get_dis(a, get_min_index(a, -1));
	if (dis == 1)
		ra(a);
	else if (dis == 2)
	{
		ra(a);
		ra(a);
	}
	else if (dis == 3)
	{
		rra(a);
		rra(a);
	}
	else if (dis == 4)
		rra(a);
	if (is_sorted(a))
		return ;
	pb(a, b);
	sort_4(a, b);
	pa(a, b);
}
