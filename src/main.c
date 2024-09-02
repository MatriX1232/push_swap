/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:33:22 by shovsepy          #+#    #+#             */
/*   Updated: 2024/09/02 20:41:45 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	**ft_malloc_stack(t_list **stack)
{
	stack = (t_list **) malloc(1 * sizeof(t_list));
	if (!stack)
		ft_print_error("Cannot allocate memory!\n");
	*stack = NULL;
	return (stack);
}

static void	ft_init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);
}

static void	sort_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) < 6)
		sort_simple(a, b);
	else
		sort_radix(a, b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (EXIT_FAILURE);
	ft_check_args(argc, argv);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_malloc_stack(stack_a);
	stack_b = ft_malloc_stack(stack_b);
	ft_init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		ft_free_nodes(stack_a);
		ft_free_nodes(stack_b);
		return (EXIT_SUCCESS);
	}
	sort_stack(stack_a, stack_b);
	ft_free_nodes(stack_a);
	ft_free_nodes(stack_b);
	return (EXIT_SUCCESS);
}

