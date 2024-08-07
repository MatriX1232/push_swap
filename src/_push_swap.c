/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:20:08 by msolinsk          #+#    #+#             */
/*   Updated: 2024/08/07 14:30:59 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Stack operations
void push(t_stack *stack, int value) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(t_stack *stack) {
    if (is_empty(stack)) {
        return -1; // Or handle error appropriately
    }
    t_node *temp = stack->top;
    int value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    return value;
}

void swap(t_stack *stack) {
    if (stack_size(stack) < 2) return;
    t_node *first = stack->top;
    t_node *second = stack->top->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void rotate(t_stack *stack) {
    if (stack_size(stack) < 2) return;
    t_node *first = stack->top;
    t_node *last = stack->top;
    while (last->next) {
        last = last->next;
    }
    stack->top = first->next;
    first->next = NULL;
    last->next = first;
}

void reverse_rotate(t_stack *stack) {
    if (stack_size(stack) < 2) return;
    t_node *prev = NULL;
    t_node *current = stack->top;
    while (current->next) {
        prev = current;
        current = current->next;
    }
    current->next = stack->top;
    stack->top = current;
    prev->next = NULL;
}

// Utilities
t_stack *create_stack() {
    t_stack *stack = malloc(sizeof(t_stack));
    stack->top = NULL;
    return stack;
}

void free_stack(t_stack *stack) {
    while (!is_empty(stack)) {
        pop(stack);
    }
    free(stack);
}

bool is_empty(t_stack *stack) {
    return stack->top == NULL;
}

int stack_size(t_stack *stack) {
    int size = 0;
    t_node *current = stack->top;
    while (current) {
        size++;
        current = current->next;
    }
    return size;
}

// Push_swap operations
void sa(t_stack *a) { swap(a); printf("sa\n"); }
void sb(t_stack *b) { swap(b); printf("sb\n"); }
void ss(t_stack *a, t_stack *b) { swap(a); swap(b); printf("ss\n"); }
void pa(t_stack *a, t_stack *b) { if (!is_empty(b)) { push(a, pop(b)); printf("pa\n"); } }
void pb(t_stack *a, t_stack *b) { if (!is_empty(a)) { push(b, pop(a)); printf("pb\n"); } }
void ra(t_stack *a) { rotate(a); printf("ra\n"); }
void rb(t_stack *b) { rotate(b); printf("rb\n"); }
void rr(t_stack *a, t_stack *b) { rotate(a); rotate(b); printf("rr\n"); }
void rra(t_stack *a) { reverse_rotate(a); printf("rra\n"); }
void rrb(t_stack *b) { reverse_rotate(b); printf("rrb\n"); }
void rrr(t_stack *a, t_stack *b) { reverse_rotate(a); reverse_rotate(b); printf("rrr\n"); }

// Helper functions
int find_median(t_stack *stack, int size) {
    int *arr = malloc(size * sizeof(int));
    t_node *current = stack->top;
    for (int i = 0; i < size; i++) {
        arr[i] = current->value;
        current = current->next;
    }
    // Simple bubble sort to find the median
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int median = arr[size / 2];
    free(arr);
    return median;
}

void sort_three(t_stack *a) {
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->top->next->next->value;

    if (first > second && second < third && first < third) sa(a);
    else if (first > second && second > third) { sa(a); rra(a); }
    else if (first > second && second < third && first > third) ra(a);
    else if (first < second && second > third && first < third) { sa(a); ra(a); }
    else if (first < second && second > third && first > third) rra(a);
}

void quicksort(t_stack *a, t_stack *b, int size) {
    if (size <= 3) {
        if (size == 2 && a->top->value > a->top->next->value) sa(a);
        else if (size == 3) sort_three(a);
        return;
    }

    int median = find_median(a, size);
    int pushed_to_b = 0;

    for (int i = 0; i < size; i++) {
        if (a->top->value <= median) {
            pb(a, b);
            pushed_to_b++;
        } else {
            ra(a);
        }
    }

    quicksort(a, b, size - pushed_to_b);
    for (int i = 0; i < pushed_to_b; i++) {
        pa(a, b);
    }
    quicksort(a, b, pushed_to_b);
}

int	ft_tab_len(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

int main(int argc, char **argv)
{
	t_stack *a = create_stack();
	t_stack *b = create_stack();
	char	**parms;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <list of integers>\n", argv[0]);
		return (EXIT_FAILURE);
	}

	parms = ft_split(argv[1], ' ');
	for (int i = ft_tab_len(parms) - 1; i >= 0; i--)
	{
		push(a, ft_atoi(parms[i]));
		// ft_printf("%d\n", ft_atoi(parms[i]));
	}

	int size = stack_size(a);
	quicksort(a, b, size);
	free_stack(a);
	free_stack(b);

	return (EXIT_SUCCESS);
}
