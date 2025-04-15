/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:08:24 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 16:15:33 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_stack(int *stack, int size, int *min_index)
{
	int	i;
	int	min_value;

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

void	push_min_to_b_case4(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	min_index;

	find_min_stack(*stack_a, *size_a, &min_index);
	if (min_index == 0)
		push_b(stack_a, stack_b, size_a, size_b);
	else if (min_index == 1)
	{
		rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 2)
	{
		rotate_a(stack_a, *size_a);
		rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 3 || min_index == 4)
	{
		reverse_rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
}

void	push_min_to_b_case5(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	min_index;

	find_min_stack(*stack_a, *size_a, &min_index);
	if (min_index == 0 || min_index == 1)
		push_min_to_b_case4(stack_a, stack_b, size_a, size_b);
	else if (min_index == 2)
	{
		rotate_a(stack_a, *size_a);
		rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 3)
	{
		reverse_rotate_a(stack_a, *size_a);
		reverse_rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
	else if (min_index == 4)
	{
		reverse_rotate_a(stack_a, *size_a);
		push_b(stack_a, stack_b, size_a, size_b);
	}
}

void	sort_five(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	if (*size_a == 4)
	{
		push_min_to_b_case4(stack_a, stack_b, size_a, size_b);
		sort_three(stack_a, *size_a);
		push_a(stack_a, stack_b, size_a, size_b);
	}
	else if (*size_a == 5)
	{
		push_min_to_b_case5(stack_a, stack_b, size_a, size_b);
		push_min_to_b_case4(stack_a, stack_b, size_a, size_b);
		sort_three(stack_a, *size_a);
		push_a(stack_a, stack_b, size_a, size_b);
		push_a(stack_a, stack_b, size_a, size_b);
	}
}
