/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:05 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/07 13:16:19 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int size);

int	clean_exit(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int check_duplicates(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*argv_to_int(int argc, char **argv)
{
	int	i;
	int	*stack_a;
	
	stack_a = malloc((argc - 1) * sizeof(int));
	if (!stack_a)
		clean_exit();
	i = 1;
	while (i < argc)
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (!check_duplicates(stack_a, argc - 1))
		clean_exit();
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

int	validate_arguments(int argc, char **argv)
{
	int			i;
	int			j;
	long long	check_int;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		if (argv[i][1] && (argv[i][j] == '-' || argv[i][j] == '+') && ft_isdigit(argv[i][j + 1]))
			j++;
		check_int = ft_atoll(argv[i]);
		if (check_int > 2147483647 || check_int < -2147483648)
			return (0);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	if (!validate_arguments(argc, argv))
		clean_exit();
	stack_a = argv_to_int(argc, argv);
	return (1);
}
