/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:26:02 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 16:14:43 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int **stack_a, int size)
{
	int	aux;

	if (!*stack_a || size < 2)
		return ;
	aux = *stack_a[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = aux;
	ft_printf("sa\n");
}

void	swap_b(int **stack_b, int size)
{
	int	aux;

	if (!*stack_b || size < 2)
		return ;
	aux = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = aux;
	ft_printf("sb\n");
}

void	swap_ab(int **stack_a, int **stack_b, int size_a, int size_b)
{
	if (!*stack_a || !*stack_b || size_a < 2 || size_b < 2)
		return ;
	swap_a(stack_a, size_a);
	swap_b(stack_b, size_b);
	ft_printf("ss\n");
}

void	push_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*new_a;
	int	*new_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b || *size_b == 0)
		return ;
	new_a = malloc((*size_a + 1) * sizeof(int));
	if (!new_a)
		return ;
	ft_memmove(new_a + 1, *stack_a, (*size_a) * sizeof(int));
	new_a[0] = (*stack_b)[0];
	free(*stack_a);
	*stack_a = new_a;
	(*size_a)++;
	new_b = malloc((*size_b - 1) * sizeof(int));
	if (!new_b)
		return ;
	ft_memmove(new_b, *stack_b + 1, (*size_b - 1) * sizeof(int));
	free(*stack_b);
	*stack_b = new_b;
	(*size_b)--;
	ft_printf("pa\n");
}

void	push_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*new_a;
	int	*new_b;

	if (!stack_a || !*stack_a || *size_a == 0)
		return ;
	new_b = malloc((*size_b + 1) * sizeof(int));
	if (!new_b)
		return ;
	ft_memmove(new_b + 1, *stack_b, (*size_b) * sizeof(int));
	free(*stack_b);
	*stack_b = new_b;
	(*stack_b)[0] = (*stack_a)[0];
	(*size_b)++;
	new_a = malloc((*size_a - 1) * sizeof(int));
	if (!new_a)
		return ;
	ft_memmove(new_a, *stack_a + 1, (*size_a - 1) * sizeof(int));
	free(*stack_a);
	*stack_a = new_a;
	(*size_a)--;
	ft_printf("pb\n");
}
