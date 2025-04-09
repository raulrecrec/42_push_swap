/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:05 by rexposit          #+#    #+#             */
/*   Updated: 2025/04/08 02:10:55 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int size_a)
{
	int	*stack_b;
	int	size_b;
	int	*indexed;

	if (is_sorted(stack_a, size_a))
		return ;
	size_b = 0;
	stack_b = malloc(0);
	if (!stack_b)
		return ;
	if (size_a == 2)
		swap_a(stack_a, size_a);
	else if (size_a == 3)
		sort_three(stack_a, size_a);
	else if (size_a > 3 && size_a <= 5)
		sort_five(&stack_a, &stack_b, &size_a, &size_b);
	else if (size_a > 5)
	{
		indexed = convert_to_indexed(stack_a, size_a);
		if (!indexed)
		{
			free(stack_b);
			return ;
		}
		radix_sort(&indexed, &stack_b, &size_a, &size_b);
		free(indexed);
	}
	for (int i = 0; i < size_a; i++)
	ft_printf("%d ", stack_a[i]);
	ft_printf("\n");
	free(stack_b);
}


void	clean_exit(int **stack)
{
	if (stack && *stack)
	{
		free(*stack);
		*stack = NULL;
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
	j = 0;
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

int	main(int argc, char **argv)
{
	int	*stack_a;

	if (argc < 2)
		exit(EXIT_FAILURE);
	validate_arguments(argc, argv);
	stack_a = argv_to_int(argc, argv);
	if (is_sorted(stack_a, argc - 1))
	{
		free(stack_a);
		return (0);
	}
	push_swap(stack_a, argc - 1);
	free(stack_a);
	return (0);
}
