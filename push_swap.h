/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:08 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/05 18:46:25 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "42_ft_printf/ft_printf.h"
# include "42_libft/libft.h"

// Función principal donde el main enviará el stack a
void	push_swap(int *stack_a, int size);

// Operaciones permitidas en el stack
void	swap_a(int *stack, int size);
void	swap_b(int *stack, int size);
void	swap_ab(int *stack_a, int *stack_b, int size_a, int size_b);

void	push_a(int *stack_a, int *size_a, int *stack_b, int *size_b);
void	push_b(int *stack_b, int *size_b, int *stack_a, int *size_a);

void	rotate_a(int *stack, int size);
void	rotate_b(int *stack, int size);
void	rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);

void	reverse_rotate_a(int *stack, int size);
void	reverse_rotate_b(int *stack, int size);
void	reverse_rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);

#endif