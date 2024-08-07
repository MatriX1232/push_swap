/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:06:44 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/18 14:22:38 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_printf("Bad usage\n");
		exit(EXIT_FAILURE);
	}
	(void)argv;

	t_stack	*stack;

	stack = NULL;
	stack = ft_init_stack(stack);

	for (int i=0; i < 10; i++)
		ft_create_node(stack, i);

	ft_print_stack(stack, NULL);

	ft_free_stack(stack);


	return (0);
}
