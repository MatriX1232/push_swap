/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:23:49 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/09 16:29:06 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_get_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

static void	ft_initialize_stack(int argc, char *argv[], t_stack *stack)
{
	int 	i;
	char	**parms;
	t_node	*new;

	new = NULL;
	if (argc == 2)
	{
		i = 0;
		parms = ft_split(argv[1], ' ');
	}
	else
	{
		i = 1;
		parms = argv;
	}
	while (parms[i])
	{
		new = ft_lstnew(new, ft_atoi(parms[i]));
		ft_printf("<NODE> %d", new->value);
		ft_lstadd_back(stack, new);
		i++;
	}
	ft_printf("Here\n");
	index_stack(stack);
	if (argc == 2)
		ft_free(parms);
}

static void	ft_sort_stack(t_stack *a, t_stack *b)
{
	if (ft_lstsize(a) < 6)
		sort_simple(a, b);
	else
		sort_radix(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// if (argc != 2)
	// {
	// 	ft_print_error("BAD ARGUMENTS!");
	// 	ft_print_error("USAGE: ./push_swap <LIST OF NUMBERS>");
	// }
	stack_a = (t_stack *) malloc(1 * sizeof(t_stack));
	stack_b = (t_stack *) malloc(1 * sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (EXIT_FAILURE);
	stack_a = NULL;
	stack_b = NULL;
	if (ft_check_args(argc, argv) != 1)
		return (EXIT_FAILURE);
	ft_initialize_stack(argc, argv, stack_a);
	if (is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (EXIT_SUCCESS);
	}
	ft_sort_stack(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (EXIT_SUCCESS);
}
