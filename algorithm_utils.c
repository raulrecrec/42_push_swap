/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:45:00 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/01 16:12:28 by rexposit         ###   ########.fr       */
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

void	find_min_stack(int *stack, int size, int *min_value, int *min_idex)
{
	int	i;

	*min_value = stack[0];
	*min_idex = 0;
	i = 1;
	while (i < size)
	{
		if (stack[i] < *min_value)
		{
			*min_value = stack[i];
			*min_idex = i;
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

void	sort_five(int *stack_a, int size)
{
	
}
