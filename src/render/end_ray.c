/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:17:21 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 12:17:29 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"

static void	set_first_point_vertical(t_vf2d *next_point, t_vf2d pos_player, \
									float angle, t_map *map)
{
	float	delta_x;

	if ((M_PI / 2 - 0.1 < angle && M_PI / 2 + 0.1) || \
		(3 * M_PI / 2 - 0.1 < angle && angle < 3 * M_PI / 2 + 0.1))
		pos_max(next_point, map);
	if ((M_PI) / 2 < angle && angle < (3 * M_PI / 2))
	{
		next_point->x = (float)(int)pos_player.x;
		delta_x = pos_player.x - next_point->x;
	}
	else
	{
		next_point->x = (float)(int)pos_player.x + 1;
		delta_x = next_point->x - pos_player.x;
	}
	next_point->y = pos_player + delta_x * tan(angle);
}

t_end_ray	set_pos_to_end_ray_vertical(t_map *map, t_vf2d pos_player, float angle)
{
	t_vf2d		next_point;
	t_end_ray	last_point;

	set_first_point(&next_point, pos_player, angle);
	while (is_wall(next_point, map) == FALSE)
	{
		next_point.y += 1 * tan(angle);
		next_point.x + 1;
	}
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, pos_player);
	return (last_point);
}

static void	set_first_point_horizontal(t_vf2d next_point, t_vf2d pos_player, float angle)
{
	float	delta_y;

	if (angle < M_PI)
	{
		next_point.y = (float)(int)pos_player.y ;
		delta_y = pos_player.y - next_point.y;
	}
	else
	{
		next_point.y = (float)(int)pos_player.y + 1;
		delta_y = next_point.y - pos_player.y;
	}
	next_point.x = pos_player + delta_y / tan(angle);
}

t_end_ray	set_pos_to_end_ray_horizontal(t_map *map, t_vf2d pos_player, float angle)
{
	t_vf2d		next_point;
	t_end_ray	last_point;

	// set_first_point(&next_point, pos_player, angle);
	// while (is_wall(next_point, map) == FALSE)
	// {
	// 	next_point.y += 1 * tan(angle);
	// 	next_point.x + 1;
	// }
	// last_point.x = next_point.x;
	// last_point.y = next_point.y;
	// last_point.dist = calc_dist(next_point, pos_player);
	return (last_point);
}