/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 13:23:49 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/27 16:27:45 by msolinsk         ###   ########.fr       */
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

static t_stack	*ft_init_stack()
{
	t_stack	*stack;

	stack = (t_stack *) malloc(1 * sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	return (stack);
}

static void	ft_fill_stack(int argc, char *argv[], t_stack *stack)
{
	int 	i;
	char	**parms;
	t_node	*new;

	i = 0;
	if (argc == 2)
		parms = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		parms = argv;
	}
	while (parms[i])
	{
		new = ft_lstnew(ft_atoi(parms[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
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
	stack_a = ft_init_stack();
	stack_b = ft_init_stack();
	if (!stack_a || !stack_b)
		return (EXIT_FAILURE);
	if (ft_check_args(argc, argv) != 1)
		return (EXIT_FAILURE);
	ft_fill_stack(argc, argv, stack_a);
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
