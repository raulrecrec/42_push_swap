/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:26:36 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/15 15:37:05 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(int **stack)
{
	if (stack && *stack)
	{
		free(*stack);
	}
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

void	check_duplicates(int **stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*stack)[i] == (*stack)[j])
				clean_exit(stack);
			j++;
		}
		i++;
	}
}

int	*argv_to_int(int argc, char **argv)
{
	int			i;
	int			*stack_a;
	long long	num;

	stack_a = malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		clean_exit(NULL);
	i = 1;
	while (i < argc)
	{
		num = ft_atoll(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			clean_exit(&stack_a);
		stack_a[i - 1] = (int)num;
		i++;
	}
	check_duplicates(&stack_a, argc - 1);
	return (stack_a);
}

long long	ft_atoll(const char *nptr)
{
	long long	res;
	long long	sig;

	res = 0;
	sig = 1;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sig = -sig;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (sig * res);
}

void	validate_arguments(int argc, char **argv)
{
	int			i;
	int			j;
	long long	check_int;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			clean_exit(NULL);
		if (argv[i][1] && (argv[i][j] == '-' || argv[i][j] == '+')
			&& ft_isdigit(argv[i][j + 1]))
			j++;
		check_int = ft_atoll(argv[i]);
		if (check_int > 2147483647 || check_int < -2147483648)
			clean_exit(NULL);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				clean_exit(NULL);
			j++;
		}
		i++;
	}
}
