/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 12:17:21 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 14:12:40 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"

static t_bool	is_wall(t_vf2d *point, t_data *data)
{
	if ((point.x <= 0 || point.y <= 0 || point->x >= data->map->x_max || \
			point.y >= data->map->y_max))
		return (TRUE);
	if ((float)(int)point.x == point.x)
	{
		if (grid[(int)point.y][(int)point.x] == 1 || \
			grid[(int)point.y][(int)point.x] == -1)
			return (TRUE);
		if (grid[(int)point.y + 1][(int)point.x] == 1 || \
			grid[(int)point.y + 1][(int)point.x] == -1)
			return (TRUE);
	}
	else if ((float)(int)point.y == point.y)
	{
		if (grid[(int)point.y][(int)point.x] == 1  || \
			grid[(int)point.y][(int)point.x] == -1)
			return (TRUE);
		if (grid[(int)point.y][(int)point.x + 1] == 1 || \
			grid[(int)point.y][(int)point.x + 1] == -1)
			return (TRUE);
	}
	return (FALSE);
}

// static void	check_max_range_vertical(t_vf2d *next_point, t_vf2d current_pos, \
// 									t_data *data, t_bool is_almost_vertical)
// {
// 	if (is_almost_vertical == TRUE)
// 	{
// 		if (data->angle < M_PI)
// 		{
// 			next_point->x == data->player_pos.x;
// 			next_point->x == 1;
// 		}
// 	}
// 	else
// 	{

// 	}
// }

// static void	set_next_point_vertical(t_vf2d *next_point, t_vf2d current_pos, \
// 									float angle, t_map *map)
// {
// 	float	delta_x;

// 	if ((M_PI / 2 - 0.1 < angle && M_PI / 2 + 0.1) || \
// 		(3 * M_PI / 2 - 0.1 < angle && angle < 3 * M_PI / 2 + 0.1))
// 		check_max_range_vertical(next_point, pos_player, data, TRUE);
// 	else if ((M_PI) / 2 < angle && angle < (3 * M_PI / 2))
// 	{
// 		next_point->x = (float)(int)pos_player.x;
// 		delta_x = pos_player.x - next_point->x;
// 	}
// 	else
// 	{
// 		next_point->x = (float)(int)pos_player.x + 1;
// 		delta_x = next_point->x - pos_player.x;
// 	}
// 	next_point->y = pos_player + delta_x * tan(angle);
// }

// t_end_ray	set_pos_to_end_ray_vertical(t_vf2d pos_player, float angle, t_data data)
// {
// 	t_vf2d		next_point;
// 	t_end_ray	last_point;

// 	set_first_point(&next_point, pos_player, angle, data);
// 	while (is_wall(next_point, map) == FALSE)
// 	{
// 		next_point.y += 1 * tan(angle);
// 		next_point.x + 1;
// 	}
// 	last_point.x = next_point.x;
// 	last_point.y = next_point.y;
// 	last_point.dist = calc_dist(next_point, pos_player);
// 	return (last_point);
// }

static void	set_next_point_horizontal(t_vf2d *next_point, t_vf2d *current_pos, t_data *data)
{
	float	delta_y;

	if (data->angle < M_PI)
	{grid[(int)point.y][(int)point.x + 1] == 1
	else
	{
		if ((float)(int)current_pos->y == current_pos->y)
			next_point->y = next_point->y + 1;
		else
			next_point->y = (float)(int)current_pos->y + 1;
	}
	delta_y = next_point->y - current_pos->y;
	next_point->x = delta_y / tan(data->angle);
}

t_end_ray	set_pos_to_end_ray_horizontal(t_map *map, t_vf2d pos_player, t_data *data)
{
	t_vf2d		current_point;
	t_vf2d		next_point;
	t_end_ray	last_point;

	if (- 0.1 < sin(data->angle) && sin(data->angle) < 0.1)
	{
		last_point.x = 0;
		last_point.y = 0;
		last_point.dist = 1000;
	}
	current_point = pos_player;
	set_next_point_horizontal(next_point, current_point, data);
	while (is_wall(next_point, map) == FALSE)
	{
		set_next_point_horizontal(next_point, current_point, data);
	}
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, pos_player);
	return (last_point);
}
