/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:54:30 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/28 13:54:34 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/push_swap.h"

// t_stack *init_stack(int size)
// {
// 	t_stack	*stack;

// 	stack = (t_stack *)malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->data = (int *)malloc(size * sizeof(int));
// 	stack->top = -1;
// 	return stack;
// }

// void push(t_stack *stack, int value)
// {
//     stack->data[++stack->top] = value;
// }

// int pop(t_stack *stack)
// {
//     return stack->data[stack->top--];
// }

// void sa(t_push_swap *ps)
// {
//     if (ps->a->top > 0)
//     {
//         int temp = ps->a->data[ps->a->top];
//         ps->a->data[ps->a->top] = ps->a->data[ps->a->top - 1];
//         ps->a->data[ps->a->top - 1] = temp;
//         add_operation(ps, "sa");
//     }
// }

// void sb(t_push_swap *ps)
// {
//     if (ps->b->top > 0)
//     {
//         int temp = ps->b->data[ps->b->top];
//         ps->b->data[ps->b->top] = ps->b->data[ps->b->top - 1];
//         ps->b->data[ps->b->top - 1] = temp;
//         add_operation(ps, "sb");
//     }
// }

// void ss(t_push_swap *ps)
// {
//     sa(ps);
//     sb(ps);
//     add_operation(ps, "ss");
// }

// void pa(t_push_swap *ps)
// {
//     if (ps->b->top >= 0)
//     {
//         push(ps->a, pop(ps->b));
//         add_operation(ps, "pa");
//     }
// }

// void pb(t_push_swap *ps)
// {
//     if (ps->a->top >= 0)
//     {
//         push(ps->b, pop(ps->a));
//         add_operation(ps, "pb");
//     }
// }

// void ra(t_push_swap *ps)
// {
//     if (ps->a->top > 0)
//     {
//         int temp = ps->a->data[ps->a->top];
//         for (int i = ps->a->top; i > 0; i--)
//             ps->a->data[i] = ps->a->data[i - 1];
//         ps->a->data[0] = temp;
//         add_operation(ps, "ra");
//     }
// }

// void rb(t_push_swap *ps)
// {
//     if (ps->b->top > 0)
//     {
//         int temp = ps->b->data[ps->b->top];
//         for (int i = ps->b->top; i > 0; i--)
//             ps->b->data[i] = ps->b->data[i - 1];
//         ps->b->data[0] = temp;
//         add_operation(ps, "rb");
//     }
// }

// void rr(t_push_swap *ps)
// {
//     ra(ps);
//     rb(ps);
//     add_operation(ps, "rr");
// }

// void rra(t_push_swap *ps)
// {
//     if (ps->a->top > 0)
//     {
//         int temp = ps->a->data[0];
//         for (int i = 0; i < ps->a->top; i++)
//             ps->a->data[i] = ps->a->data[i + 1];
//         ps->a->data[ps->a->top] = temp;
//         add_operation(ps, "rra");
//     }
// }

// void rrb(t_push_swap *ps)
// {
//     if (ps->b->top > 0)
//     {
//         int temp = ps->b->data[0];
//         for (int i = 0; i < ps->b->top; i++)
//             ps->b->data[i] = ps->b->data[i + 1];
//         ps->b->data[ps->b->top] = temp;
//         add_operation(ps, "rrb");
//     }
// }

// void rrr(t_push_swap *ps)
// {
//     rra(ps);
//     rrb(ps);
//     add_operation(ps, "rrr");
// }
