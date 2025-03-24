/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:31:18 by sminot            #+#    #+#             */
/*   Updated: 2025/03/24 18:00:04 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		putstr_fd("Error\nWrong number of argument\n", 2);
		exit(EXIT_FAILURE);
	}
	i = ft_strlen(av[1]) - 4;
	if (i < 0 || ft_memcmp(av[1] + i, ".cub", 4))
	{
		putstr_fd("Error\nMap is not a .cub\n", 2);
		exit(EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	check_arg(ac, av);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
	{
		putstr_fd("Error\nDuring a malloc\n", 2);
		exit(EXIT_FAILURE);
	}
	parse_map(av[1], map);
}
