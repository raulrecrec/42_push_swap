/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotates.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:48:39 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 15:51:07 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int **stack_a, int size_a)
{
	int	aux;

	if (!*stack_a || size_a <= 1)
		return ;
	aux = (*stack_a)[0];
	ft_memmove(*stack_a, *stack_a + 1, (size_a - 1) * sizeof(int));
	(*stack_a)[size_a - 1] = aux;
	ft_printf("ra\n");
}

void	rotate_b(int **stack_b, int size_b)
{
	int	aux;

	if (!*stack_b || size_b <= 1)
		return ;
	aux = (*stack_b)[0];
	ft_memmove(*stack_b, *stack_b + 1, (size_b - 1) * sizeof(int));
	(*stack_b)[size_b - 1] = aux;
	ft_printf("rb\n");
}

void	rotate_ab(int **stack_a, int **stack_b, int size_a, int size_b)
{
	if ((!*stack_a || size_a <= 1) && (!*stack_b || size_b <= 1))
		return ;
	rotate_a(stack_a, size_a);
	rotate_b(stack_b, size_b);
	ft_printf("rr\n");
}
