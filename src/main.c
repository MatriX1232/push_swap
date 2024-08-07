/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:32:01 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/07 17:41:46 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Function to reverse the order of elements in stack a
// void reverse_stack(t_push_swap *ps)
// {
//     int size = ps->a->top + 1;
//     // Move all elements to stack b and then back to stack a
//     for (int i = 0; i < size; i++)
//     {
//         pb(ps);
//     }
//     for (int i = size - 1; i >= 0; i--)
//     {
//         pa(ps);
//     }
// }

int ft_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("BAD ARGUMENTS!\n");
		ft_printf("Usage: %s <int int int>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	char	**parm = ft_split(argv[1], ' ');
    int stack_size = ft_tab_len(parm);
    int	initial_stack[stack_size];

	int	i = 0;
	while (i < stack_size)
	{
		initial_stack[i] = ft_atoi(parm[i]);
		i++;
	}
	t_push_swap *ps = (t_push_swap *)malloc(sizeof(t_push_swap));
    ps->a = init_stack(stack_size);
    ps->b = init_stack(stack_size);
    ps->operations = (char **)malloc(1000 * sizeof(char *));
    ps->op_count = 0;

    for (int i = stack_size - 1; i >= 0; i--)
        push(ps->a, initial_stack[i]);

    sort(ps);

	printf("Sorted stack: ");
    for (int i = 0; i <= ps->a->top; i++)
        printf("%d ", ps->a->data[i]);
    printf("\n");

    // Reverse the sorted stack
    // reverse_stack(ps);

    free_push_swap(ps);
	for (int i=ft_tab_len(parm); i >= 0; i--)
		free(parm[i]);
	free(parm);
    return 0;
}
