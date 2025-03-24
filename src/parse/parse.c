/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:31 by sminot            #+#    #+#             */
/*   Updated: 2025/03/24 18:40:35 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	parse_map(char *map_name, t_map *map)
{
	int	fd;

	//creat_map(map_name, map);
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		putstr_fd("Error\nMap not open\n", 2);
		//free_map(map);
		exit(EXIT_FAILURE);
	}
	//fill_map(fd, map);
	if (close(fd))
	{
		putstr_fd("Error\nMap refuse to close\n", 2);
		//free_map(map);
		exit(EXIT_FAILURE);
	}
	(void)map;
}
