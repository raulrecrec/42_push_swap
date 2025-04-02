/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 03:59:39 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/02 05:06:16 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
