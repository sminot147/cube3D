/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:22 by sminot            #+#    #+#             */
/*   Updated: 2025/04/08 12:18:35 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"
#include "define.h"

/**
 * @brief set on which wall the ray stopped
 */
t_end_ray	set_wall(t_end_ray point, t_data *data)
{
	if (is_int(point.x))
	{
		if (data->map->grid[(int)point.y][(int)point.x] == 1)
			point.wall = EAST;
		if (data->map->grid[(int)point.y][(int)point.x - 1] == 1)
			point.wall = WEST;
	}
	if (is_int(point.y))
	{
		if (data->map->grid[(int)point.y][(int)point.x] == 1)
			point.wall = SOUTH;
		if (data->map->grid[(int)point.y - 1][(int)point.x] == 1)
			point.wall = NORTH;
	}
	return (point);
}

/**
 * @brief Calcul the next horizontal intersections between line of the grid 
 * and the ray
 * 
 * @return TRUE if the ray reach a wall, FALSE otherwise
 */
static t_bool	set_next_point_horizontal(t_vf2d *next_point, \
							t_vf2d *current_pos, t_data *data, float angle)
{
	float	delta_y;

	if (-0.001 < cos(angle) && cos(angle) < 0.001)
	{
		next_point->x = current_pos->x;
		if (sin(angle) > 0 && is_int(current_pos->y))
			next_point->y = current_pos->y - 1;
		else if (sin(angle) > 0)
			next_point->y = (float)(int)current_pos->y;
		else
			next_point->y = (float)(int)current_pos->y + 1;
		return (is_wall(next_point, data));
	}
	if (sin(angle) > 0)
	{
		if (is_int(current_pos->y))
			next_point->y = current_pos->y - 1;
		else
			next_point->y = (float)(int)current_pos->y;
	}
	else
		next_point->y = (float)(int)current_pos->y + 1;
	delta_y = current_pos->y - next_point->y;
	next_point->x = current_pos->x + delta_y / tan(angle);
	return (is_wall(next_point, data));
}

/**
 * @brief look all horizontal intersections between line of the grid and the ray
 * 
 * @return the first horizontal intersection
 */
t_end_ray	end_ray_horizontal(t_data *data, float angle)
{
	t_vf2d		current_point;
	t_vf2d		next_point;
	t_end_ray	last_point;

	current_point = data->player_pos;
	while (set_next_point_horizontal(&next_point, &current_point, data, angle) \
			== FALSE)
	{
		current_point = next_point;
	}
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, data->player_pos);
	last_point.dist *= cos(angle - data->view_angle);
	return (last_point);
}

/**
 * @brief Treat all ray of ray casting
 */
static t_end_ray	end_ray(t_data *data, float angle)
{
	t_end_ray	end_ray_h;
	t_end_ray	end_ray_v;

	if (-0.001 < sin(angle) && sin(angle) < 0.001)
		return (set_wall(end_ray_vertical(data, angle), data));
	if (-0.001 < cos(angle) && cos(angle) < 0.001)
		return (set_wall(end_ray_horizontal(data, angle), data));
	end_ray_h = end_ray_horizontal(data, angle);
	end_ray_v = end_ray_vertical(data, angle);
	if (end_ray_h.dist < end_ray_v.dist)
		return (set_wall(end_ray_h, data));
	return (set_wall(end_ray_v, data));
}

/**
 * @brief Call different part of ray casting
 */
void	trace_ray_casting(t_data *data)
{
	float		i;
	float		angle;
	t_end_ray	end_ray1;

	i = -FIELD_OF_VIEW * 0.5;
	while (i <= FIELD_OF_VIEW * 0.5)
	{
		angle = data->view_angle + (i * M_PI / 180);
		end_ray1 = end_ray(data, angle);
		render_ray3d(i, &end_ray1, data);
		i += (float)FIELD_OF_VIEW / (float)NB_RAY;
	}
}
