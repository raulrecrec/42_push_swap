/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:45:31 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/07 19:49:21 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(const char *label, int *stack, int size)
{
	ft_printf("%s: ", label);
	for (int i = 0; i < size; i++)
		ft_printf("%d ", stack[i]);
	ft_printf("\n");
}

int main()
{
	int *stack_a = malloc(5 * sizeof(int));
	int *stack_b = malloc(5 * sizeof(int));
	
	int temp_a[] = {1, 2, 3, 4, 5};
	int temp_b[] = {6, 7, 8, 9, 10};
	
	for (int i = 0; i < 5; i++)
	{
		stack_a[i] = temp_a[i];
		stack_b[i] = temp_b[i];
	}
	
	int size_a = 5, size_b = 5;

	ft_printf("===== TESTEANDO MOVIMIENTOS =====\n\n");

	// 🟢 SWAP A
	print_stack("Antes de swap_a", stack_a, size_a);
	swap_a(stack_a, size_a);
	print_stack("Después de swap_a", stack_a, size_a);
	ft_printf("\n");

	// 🟢 SWAP B
	print_stack("Antes de swap_b", stack_b, size_b);
	swap_b(stack_b, size_b);
	print_stack("Después de swap_b", stack_b, size_b);
	ft_printf("\n");

	// 🟢 SWAP AB
	print_stack("Antes de swap_ab", stack_a, size_a);
	print_stack("Antes de swap_ab (B)", stack_b, size_b);
	swap_ab(stack_a, stack_b, size_a, size_b);
	print_stack("Después de swap_ab", stack_a, size_a);
	print_stack("Después de swap_ab (B)", stack_b, size_b);
	ft_printf("\n");

	// 🟢 PUSH A (mueve de B a A)
	print_stack("Antes de push_a", stack_a, size_a);
	print_stack("Antes de push_a (B)", stack_b, size_b);
	push_a(&stack_a, &stack_b, size_a, size_b);
	size_a++;
	size_b--;
	print_stack("Después de push_a", stack_a, size_a);
	print_stack("Después de push_a (B)", stack_b, size_b);
	ft_printf("\n");

	// 🟢 PUSH B (mueve de A a B)
	print_stack("Antes de push_b", stack_a, size_a);
	print_stack("Antes de push_b (B)", stack_b, size_b);
	push_b(&stack_a, &stack_b, size_a, size_b);
	size_a--;
	size_b++;
	print_stack("Después de push_b", stack_a, size_a);
	print_stack("Después de push_b (B)", stack_b, size_b);
	ft_printf("\n");

	// 🟢 ROTATE A
	print_stack("Antes de rotate_a", stack_a, size_a);
	rotate_a(stack_a, size_a);
	print_stack("Después de rotate_a", stack_a, size_a);
	ft_printf("\n");

	// 🟢 ROTATE B
	print_stack("Antes de rotate_b", stack_b, size_b);
	rotate_b(stack_b, size_b);
	print_stack("Después de rotate_b", stack_b, size_b);
	ft_printf("\n");

	// 🟢 ROTATE AB
	print_stack("Antes de rotate_ab", stack_a, size_a);
	print_stack("Antes de rotate_ab (B)", stack_b, size_b);
	rotate_ab(stack_a, stack_b, size_a, size_b);
	print_stack("Después de rotate_ab", stack_a, size_a);
	print_stack("Después de rotate_ab (B)", stack_b, size_b);
	ft_printf("\n");

	// 🟢 REVERSE ROTATE A
	print_stack("Antes de reverse_rotate_a", stack_a, size_a);
	reverse_rotate_a(stack_a, size_a);
	print_stack("Después de reverse_rotate_a", stack_a, size_a);
	ft_printf("\n");

	// 🟢 REVERSE ROTATE B
	print_stack("Antes de reverse_rotate_b", stack_b, size_b);
	reverse_rotate_b(stack_b, size_b);
	print_stack("Después de reverse_rotate_b", stack_b, size_b);
	ft_printf("\n");

	// 🟢 REVERSE ROTATE AB
	print_stack("Antes de reverse_rotate_ab", stack_a, size_a);
	print_stack("Antes de reverse_rotate_ab (B)", stack_b, size_b);
	reverse_rotate_ab(stack_a, stack_b, size_a, size_b);
	print_stack("Después de reverse_rotate_ab", stack_a, size_a);
	print_stack("Después de reverse_rotate_ab (B)", stack_b, size_b);
	ft_printf("\n");

	free(stack_a);
	free(stack_b);
	return (0);
}