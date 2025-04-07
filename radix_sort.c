/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 03:59:39 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/08 00:55:52 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_value(int *stack, int size)
{
	int	i = 0;
	int	max = stack[0];

	while (++i < size)
	{
		if (stack[i] > max)
			max = stack[i];
	}
	return (max);
}

int	*convert_to_indexed(int *stack, int size)
{
	int	i;
	int	j;
	int	index;
	int	*stack_indexed;

	stack_indexed = malloc(size * sizeof(int));
	if (!stack_indexed)
		return (NULL);
	ft_memcpy(stack_indexed, stack, size * sizeof(int));
	i = 0;
	j = 0;
	while (i < size)
	{
		index = 0;
		j = 0;
		while (j < size)
		{
			if (stack[i] > stack[j])
				index++;
			j++;
		}
		stack_indexed[i] = index;
		i++;
	}
	return (stack_indexed);
}

void	radix_sort(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	max_bits;

	max_bits = 0;
	while (*stack_a[*size_a - 1] >> max_bits)
		max_bits++;

}
