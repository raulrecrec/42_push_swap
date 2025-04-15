/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverse_rotates.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:49 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 15:51:20 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(int **stack_a, int size_a)
{
	int	aux;

	if (!*stack_a || size_a <= 1)
		return ;
	aux = (*stack_a)[size_a - 1];
	ft_memmove(*stack_a + 1, *stack_a, (size_a - 1) * sizeof(int));
	(*stack_a)[0] = aux;
	ft_printf("rra\n");
}

void	reverse_rotate_b(int **stack_b, int size_b)
{
	int	aux;

	if (!*stack_b || size_b <= 1)
		return ;
	aux = (*stack_b)[size_b - 1];
	ft_memmove(*stack_b + 1, *stack_b, (size_b - 1) * sizeof(int));
	(*stack_b)[0] = aux;
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(int **stack_a, int **stack_b, int size_a, int size_b)
{
	if ((!*stack_a || size_a <= 1) && (!*stack_b || size_b <= 1))
		return ;
	reverse_rotate_a(stack_a, size_a);
	reverse_rotate_b(stack_b, size_b);
	ft_printf("rrr\n");
}
