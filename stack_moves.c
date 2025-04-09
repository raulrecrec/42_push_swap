/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:26:02 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/08 02:17:45 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(int *stack_a, int size)
{
	int	aux;

	if (!stack_a || size < 2)
		return (0);
	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
	ft_printf("sa\n");
	return (1);
}
int	swap_b(int *stack_b, int size)
{
	int	aux;

	if (!stack_b || size < 2)
		return (0);
	aux = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = aux;
	ft_printf("sb\n");
	return (1);
}
int	swap_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if (!stack_a || !stack_b || size_a < 2 || size_b < 2)
		return (0);
	swap_a(stack_a, size_a);
	swap_b(stack_b, size_b);
	ft_printf("ss\n");
	return (1);
}

int	push_a(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*aux;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b || *size_b == 0)
		return (0);
	aux = malloc((*size_a + 1) * sizeof(int));
	if (!aux)
		return (0);
	ft_memmove(aux + 1, *stack_a, (*size_a) * sizeof(int));
	free(*stack_a);
	*stack_a = aux;
	(*stack_a)[0] = (*stack_b)[0];
	(*size_a)++;
	if (*size_b == 1)
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	else
	{
		aux = malloc((*size_b - 1) * sizeof(int));
		if (!aux)
			return (0);
		ft_memmove(aux, *stack_b + 1, (*size_b - 1) * sizeof(int));
		free(*stack_b);
		*stack_b = aux;
	}
	(*size_b)--;
	ft_printf("pa\n");
	return (1);
}

int	push_b(int **stack_a, int **stack_b, int *size_a, int *size_b)
{
	int	*aux;

	if (!stack_a || !*stack_a || *size_a == 0)
		return (0);
	aux = malloc((*size_b + 1) * sizeof(int));
	if (!aux)
		return (0);
	ft_memmove(aux + 1, *stack_b, (*size_b) * sizeof(int));
	free(*stack_b);
	*stack_b = aux;
	(*stack_b)[0] = (*stack_a)[0];
	(*size_b)++;
	if (*size_a == 1)
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	else
	{
		aux = malloc((*size_a - 1) * sizeof(int));
		if (!aux)
			return (0);
		ft_memmove(aux, *stack_a + 1, (*size_a - 1) * sizeof(int));
		free(*stack_a);
		*stack_a = aux;
	}
	(*size_a)--;
	ft_printf("pb\n");
	return (1);
}


void	rotate_a(int *stack_a, int size_a)
{
	int	aux;

	if (!stack_a || size_a <= 1)
		return ;
	aux = stack_a[0];
	ft_memmove(stack_a, stack_a + 1, (size_a - 1) * sizeof(int));
	stack_a[size_a - 1] = aux;
	ft_printf("ra\n");
}

void	rotate_b(int *stack_b, int size_b)
{
	int	aux;

	if (!stack_b || size_b <= 1)
		return ;
	aux = stack_b[0];
	ft_memmove(stack_b, stack_b + 1, (size_b - 1) * sizeof(int));
	stack_b[size_b - 1] = aux;
	ft_printf("rb\n");
}

void	rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if ((!stack_a || size_a <= 1) && (!stack_b || size_b <= 1))
		return ;
	rotate_a(stack_a, size_a);
	rotate_b(stack_b, size_b);
	ft_printf("rr\n");
}

void	reverse_rotate_a(int *stack_a, int size_a)
{
	int	aux;

	if (!stack_a || size_a <= 1)
		return ;
	aux = stack_a[size_a - 1];
	ft_memmove(stack_a + 1, stack_a, (size_a - 1) * sizeof(int));
	stack_a[0] = aux;
	ft_printf("rra\n");
}

void	reverse_rotate_b(int *stack_b, int size_b)
{
	int	aux;

	if (!stack_b || size_b <= 1)
		return ;
	aux = stack_b[size_b - 1];
	ft_memmove(stack_b + 1, stack_b, (size_b - 1) * sizeof(int));
	stack_b[0] = aux;
	ft_printf("rrb\n");
}

void	reverse_rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b)
{
	if ((!stack_a || size_a <= 1) && (!stack_b || size_b <= 1))
		return ;
	reverse_rotate_a(stack_a, size_a);
	reverse_rotate_b(stack_b, size_b);
	ft_printf("rrr\n");
}