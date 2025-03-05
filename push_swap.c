/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:38:05 by rexposit          #+#    #+#             */
/*   Updated: 2025/03/05 20:15:29 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *stack_a, int size);

int	validar_argumentos(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (0);
		if (argv[i][1] && (argv[i][j] == '-' || argv[i][j] == '+') && ft_isdigit(argv[i][j + 1]))
			j++;
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
	{
		ft_printf("Error: no hay numeros para ordenar\n");
		return (0);
	}
	if (!validar_argumentos(argc, argv))
	{
		ft_printf("Error: el stack tiene un formato incorrecto\n");
		return (0);
	}
	return (1);
}
