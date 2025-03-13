/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:08 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/13 15:54:20 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "42_ft_printf/ft_printf.h"
# include "42_libft/libft.h"

// push_swap.c 
void		push_swap(int *stack_a, int size);
long long	ft_atoll(const char *nptr);
void		validate_arguments(int argc, char **argv);
void		clean_exit(int **stack);
void		check_duplicates(int **stack, int size);
int			*argv_to_int(int argc, char **argv);

// stack_moves.c
int			swap_a(int *stack_a, int size);
int			swap_b(int *stack_b, int size);
int			swap_ab(int *stack_a, int *stack_b, int size_a, int size_b);
int			push_a(int **stack_a, int **stack_b, int size_a, int size_b);
int			push_b(int **stack_a, int **stack_b, int size_a, int size_b);
void		rotate_a(int *stack_a, int size_a);
void		rotate_b(int *stack_b, int size_b);
void		rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);
void		reverse_rotate_a(int *stack_a, int size_a);
void		reverse_rotate_b(int *stack_b, int size_b);
void		reverse_rotate_ab(int *stack_a, int *stack_b, int size_a, int size_b);

// algorithm_utils.c
int			is_sorted(int *stack, int size)

#endif