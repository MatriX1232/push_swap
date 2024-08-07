/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:31:29 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/07 17:41:14 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void add_operation(t_push_swap *ps, char *operation)
// {
//     ps->operations[ps->op_count] = ft_strdup(operation);
//     ps->op_count++;
// }

// void sa(t_push_swap *ps)
// {
//     swap(ps->a);
//     add_operation(ps, "sa");
// 	ft_printf("sa\n");
// }

// void pa(t_push_swap *ps)
// {
//     if (ps->b->top >= 0)
//     {
//         push(ps->a, pop(ps->b));
//         add_operation(ps, "pa");
// 		ft_printf("pa\n");
//     }
// }

// void pb(t_push_swap *ps)
// {
//     if (ps->a->top >= 0)
//     {
//         push(ps->b, pop(ps->a));
//         add_operation(ps, "pb");
// 		ft_printf("pb\n");
//     }
// }

// void ra(t_push_swap *ps)
// {
//     rotate(ps->a);
//     add_operation(ps, "ra");
// 	ft_printf("ra\n");
// }

// void rra(t_push_swap *ps)
// {
//     reverse_rotate(ps->a);
//     add_operation(ps, "rra");
// 	ft_printf("rra\n");
// }

// void sort(t_push_swap *ps)
// {
//     quick_sort(ps, 0, ps->a->top);
// }

// void quick_sort(t_push_swap *ps, int low, int high)
// {
//     if (low < high)
//     {
//         int pivot_index = partition(ps, low, high);
//         quick_sort(ps, low, pivot_index - 1);
//         quick_sort(ps, pivot_index + 1, high);
//     }
// }

// int partition(t_push_swap *ps, int low, int high)
// {
//     int pivot = ps->a->data[high];
//     int i = low - 1;
//     for (int j = low; j < high; j++)
//     {
//         if (ps->a->data[j] < pivot)
//         {
//             i++;
//             int temp = ps->a->data[i];
//             ps->a->data[i] = ps->a->data[j];
//             ps->a->data[j] = temp;
//             add_operation(ps, "sa");
// 			// ft_printf("sa\n");
//         }
//     }
//     int temp = ps->a->data[i + 1];
//     ps->a->data[i + 1] = ps->a->data[high];
//     ps->a->data[high] = temp;
//     add_operation(ps, "sa");
// 	// ft_printf("sa\n");
//     return i + 1;
// }

void add_operation(t_push_swap *ps, char *operation)
{
    // ps->operations[ps->op_count] = ft_strdup(operation);
    // ps->op_count++;
	(void)ps;
	ft_printf("%s\n", operation);
}

void sort_chunk(t_push_swap *ps, int size)
{
    // Sort elements in the chunk by repeatedly moving minimum to stack b
    while (ps->a->top >= 0)
    {
        int min_index = 0;
        for (int i = 1; i <= ps->a->top; i++)
        {
            if (ps->a->data[i] < ps->a->data[min_index])
                min_index = i;
        }
        while (ps->a->data[ps->a->top] != ps->a->data[min_index])
        {
            if (ps->a->top - min_index <= size / 2)
                ra(ps);
            else
                rra(ps);
        }
        pb(ps);
    }
}

void rebuild_stack_a(t_push_swap *ps, int size)
{
	(void)size;
    while (ps->b->top >= 0)
        pa(ps);
}

void reverse_stack(t_push_swap *ps)
{
    int size = ps->a->top + 1;
    for (int i = 0; i < size; i++)
    {
        pb(ps);
    }
    for (int i = 0; i < size; i++)
    {
        pa(ps);
    }
}

void sort(t_push_swap *ps)
{
    int chunk_size = 20; // Example chunk size, adjust as needed
    while (ps->a->top >= 0)
    {
        sort_chunk(ps, chunk_size);
        rebuild_stack_a(ps, chunk_size);
    }
    reverse_stack(ps); // Reverse the stack to get ascending order
}

void free_push_swap(t_push_swap *ps)
{
    free(ps->a->data);
    free(ps->b->data);
    free(ps->a);
    free(ps->b);
    for (int i = 0; i < ps->op_count; i++)
        free(ps->operations[i]);
    free(ps->operations);
    free(ps);
}
