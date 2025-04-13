/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 03:59:39 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/12 23:36:26 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int *stack, int size)
{
	int	i;
	int	max_value;
	int max_bits;

	i = 0;
	max_value = stack[0];
	while (++i < size)
	{
		if (stack[i] > max_value)
			max_value = stack[i];
	}
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	*convert_to_indexed(int *stack, int size)
{
	int	i;
	int	j;
	int	index;
	int	*copy;
	int	*indexed;

	copy = malloc(size * sizeof(int));
	indexed = malloc(size * sizeof(int));
	if (!copy || !indexed)
		return (NULL);
	ft_memcpy(copy, stack, size * sizeof(int));
	i = 0;
	while (i < size)
	{
		index = 0;
		j = 0;
		while (j < size)
		{
			if (copy[i] > copy[j])
				index++;
			j++;
		}
		indexed[i] = index;
		i++;
	}
	free(copy);
	return (indexed);
}

void	radix_sort(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*indexed;
	int	i;
	int	j;
	int	bit;
	int	max_bits;
	int	size;

	indexed = convert_to_indexed(*stack_a, *size_a);
	if (!indexed)
		return ;
	free(*stack_a);
	*stack_a = indexed;
	max_bits = get_max_bits(*stack_a, *size_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = *size_a;
		while (j < size)
		{
			bit = ((*stack_a)[0] >> i) & 1;
			if (bit == 0)
				push_b(stack_a, stack_b, size_a, size_b);
			else
				rotate_a(stack_a, *size_a);
			j++;
		}
		while (*size_b > 0)
			push_a(stack_a, stack_b, size_a, size_b);
		i++;
	}
}
