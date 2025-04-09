/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 03:59:39 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/08 02:22:21 by rexposit         ###   ########.fr       */
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
			if (stack_indexed[i] > stack_indexed[j])
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
	int	*indexed;
	int	i;
	int	j;
	int	bit;
	int	max_bits;

	indexed = convert_to_indexed(*stack_a, *size_a);
	if (!indexed)
		return ;

	max_bits = 0;
	while ((get_max_value(indexed, *size_a) >> max_bits) != 0)
		max_bits++;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < *size_a)
		{
			bit = (indexed[0] >> i) & 1;
			if (bit == 0)
			{
				push_b(stack_a, stack_b, size_a, size_b);
				// reflejar movimiento también en indexed
				ft_memmove(indexed, indexed + 1, (*size_a) * sizeof(int));
			}
			else
			{
				rotate_a(*stack_a, *size_a);
				// rotamos también indexed
				int tmp = indexed[0];
				ft_memmove(indexed, indexed + 1, (*size_a - 1) * sizeof(int));
				indexed[*size_a - 1] = tmp;
			}
			j++;
		}
		while (*size_b > 0)
			push_a(stack_a, stack_b, size_a, size_b);
		i++;
	}
	free(indexed);
}
