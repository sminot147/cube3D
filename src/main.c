/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:31:18 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 16:37:59 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
/* 
static void	check_arg(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	(void)ac;
	(void)av;
	check_arg(ac, av);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_with_msg("Allocation", EXIT_FAILURE);
	parse_map(av[1], map);
	init_data(map, &data);
	while (TRUE)
	{
		render_view(&data);
		// process_input();
	}
	return (1);
}

static void	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		exit_with_msg("Wrong number of argument", EXIT_FAILURE);
	}
	i = ft_strlen(av[1]) - 4;
	if (i < 0 || ft_memcmp(av[1] + i, ".cub", 4))
	{
		exit_with_msg("Map is not a .cub", EXIT_FAILURE);
	}
}
*/

int	main(int ac, char **av)
{
	t_data	data;
	t_map	*map;

	(void)ac;
	(void)av;
	map = NULL;
	init_data(map, &data);
	render_view(&data);
	while (TRUE)
	{
		// process_input();
	}
	return (1);
}
