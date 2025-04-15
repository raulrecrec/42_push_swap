/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:05 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 15:37:07 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int **stack_a, int size_a)
{
	int	*stack_b;
	int	size_b;

	size_b = 0;
	stack_b = malloc(0);
	if (!stack_b)
		return ;
	if (size_a == 2)
		swap_a(stack_a, size_a);
	else if (size_a == 3)
		sort_three(stack_a, size_a);
	else if (size_a > 3 && size_a <= 5)
		sort_five(stack_a, &stack_b, &size_a, &size_b);
	else if (size_a > 5)
		radix_sort(stack_a, &stack_b, &size_a, &size_b);
	free(stack_b);
}

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	validate_arguments(argc, argv);
	stack_a = argv_to_int(argc, argv);
	if (is_sorted(stack_a, argc - 1))
	{
		free(stack_a);
		return (0);
	}
	push_swap(&stack_a, argc - 1);
	if (stack_a)
		free(stack_a);
}
