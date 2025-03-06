/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:05 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/06 17:24:57 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int size);

int	clean_exit(void)
{
	ft_printf("Error\n");
	return (EXIT_FAILURE);
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
	if (argc < 2)
		clean_exit();
	if (!validate_arguments(argc, argv))
		clean_exit();
	return (1);
}
