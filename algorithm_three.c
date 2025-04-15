/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:00 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 16:09:03 by rexposit         ###   ########.fr       */
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

void	sort_three(int **stack_a, int size)
{
	if (is_sorted(*stack_a, size))
		return ;
	else if (((*stack_a)[0] < (*stack_a)[1]) && ((*stack_a)[0] < (*stack_a)[2]))
	{
		reverse_rotate_a(stack_a, size);
		swap_a(stack_a, size);
	}
	else if (((*stack_a)[0] > (*stack_a)[1]) && ((*stack_a)[0] < (*stack_a)[2]))
		swap_a(stack_a, size);
	else if (((*stack_a)[0] > (*stack_a)[2]) && ((*stack_a)[0] < (*stack_a)[1]))
	{
		rotate_a(stack_a, size);
		rotate_a(stack_a, size);
	}
	else if (((*stack_a)[0] > (*stack_a)[1]) && ((*stack_a)[1] < (*stack_a)[2]))
	{
		rotate_a(stack_a, size);
	}
	else if (((*stack_a)[0] > (*stack_a)[1]) && ((*stack_a)[1] > (*stack_a)[2]))
	{
		rotate_a(stack_a, size);
		swap_a(stack_a, size);
	}
}
