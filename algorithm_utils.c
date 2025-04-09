/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:00 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/09 12:23:44 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	find_min_stack(int *stack, int size, int *min_index)
{
	int	i;
	int min_value;

	min_value = stack[0];
	*min_index = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] < min_value)
		{
			min_value = stack[i];
			*min_index = i;
		}
		i++;
	}
}

void	sort_three(int *stack_a, int size)
{
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])) // caso 2
	{
		reverse_rotate_a(stack_a, size);
		swap_a(stack_a, size);
	}
	else if ((stack_a[0] > stack_a[1]) && (stack_a[0] < stack_a[2])) // caso 3
		swap_a(stack_a, size);
	else if ((stack_a[0] > stack_a[2]) && (stack_a[0] < stack_a[1])) // caso 4
	{
		rotate_a(stack_a, size);
		swap_a(stack_a, size);
	}
	else if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])) // caso 5
	{
		rotate_a(stack_a, size);
	}
	else if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2])) // caso 6
	{
		rotate_a(stack_a, size);
		swap_a(stack_a, size);
	}
}

void	push_min_to_b_case4(int **stack_a, int **stack_b, int *size_a, int *size_b, int min_index)
{
	if (min_index == 0)
		push_b(stack_a, stack_b, size_a, size_b);
	else if (min_index == 1)
	{
		swap_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 2)
	{
		rotate_a(*stack_a, *size_a);
		swap_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 3 || min_index == 4)
	{
		reverse_rotate_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
}


void	push_min_to_b_case5(int **stack_a, int **stack_b, int *size_a, int *size_b, int min_index)
{
	if (min_index == 0)
		push_b(stack_a, stack_b, size_a, size_b);
	else if (min_index == 1)
	{
		swap_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 2)
	{
		rotate_a(*stack_a, *size_a);
		swap_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 3)
	{
		reverse_rotate_a(*stack_a, *size_a);
		reverse_rotate_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 4)
	{
		reverse_rotate_a(*stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
}

void	sort_five(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	min_index;

	if (*size_a == 4)
	{
		find_min_stack(*stack_a, *size_a, &min_index);
		push_min_to_b_case4(stack_a, stack_b, size_a, size_b, min_index);
		sort_three(*stack_a, *size_a);
		push_a(stack_a, stack_b, size_a, size_b);
	}
	else if (*size_a == 5)
	{
		find_min_stack(*stack_a, *size_a, &min_index);
		push_min_to_b_case5(stack_a, stack_b, size_a, size_b, min_index);
		find_min_stack(*stack_a, *size_a, &min_index);
		push_min_to_b_case4(stack_a, stack_b, size_a, size_b, min_index);
		sort_three(*stack_a, *size_a);
		push_a(stack_a, stack_b, size_a, size_b);
		push_a(stack_a, stack_b, size_a, size_b);
	}
}

