/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:08 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/05 18:29:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "42_ft_printf/ft_printf.h"

// Prototipos de funciones principales
void    push_swap(int *stack_a, int size);
void    parse_arguments(int argc, char **argv, int **stack, int *size);
void    swap_a(int *stack, int size);
void    push_a(int *stack_a, int *size_a, int *stack_b, int *size_b);
void    rotate_a(int *stack, int size);
void    reverse_rotate_a(int *stack, int size);

#endif