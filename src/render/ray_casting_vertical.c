/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:43:48 by sminot            #+#    #+#             */
/*   Updated: 2025/03/29 20:48:28 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"

void	print_one_point(t_vf2d *point, char *message)
{
	//fonction de debug a supp
	printf("%s[%f , %f]\n", message, point->x, point->y);
}

float	calc_dist(t_vf2d point1, t_vf2d point2)
{
	//tu en a pas deja une ? nop, mais j ai la meme sur une ligne dans une func
	return (sqrt((point2.x - point1.x) * (point2.x - point1.x) + \
				(point2.y - point1.y) * (point2.y - point1.y)));
}

t_bool	is_int(float nb)
{
	float	diff;

	diff = (float)(int)nb - nb;
	if (-0.0001 < diff && diff < 0.0001)
		return (TRUE);
	return (FALSE);
}

t_bool	is_wall(t_vf2d *point, t_data *data, float angle)
{
	if ((point->x <= 0 || point->y <= 0 || point->x >= data->map->x_max || \
			point->y >= data->map->y_max))
		return (TRUE);
	if (is_int(point->x))
	{
		if (data->map->grid[(int)point->y][(int)point->x] == 1 || \
			data->map->grid[(int)point->y][(int)point->x] == -1)
			return (TRUE);
		if (data->map->grid[(int)point->y][(int)point->x - 1] == 1 || \
			data->map->grid[(int)point->y][(int)point->x - 1] == -1)
			return (TRUE);
	}
	else if (is_int(point->y))
	{
		if (data->map->grid[(int)point->y][(int)point->x] == 1 || \
			data->map->grid[(int)point->y][(int)point->x] == -1)
			return (TRUE);
		if (data->map->grid[(int)point->y - 1][(int)point->x] == 1 || \
			data->map->grid[(int)point->y - 1][(int)point->x] == -1)
			return (TRUE);
	}
	return (FALSE);
}

static t_bool	set_next_point_vertical(t_vf2d *next_point, \
							t_vf2d *current_pos, t_data *data, float angle)
{
	float	delta_x;

	if (-0.001 < sin(angle) && sin(angle) < 0.001)
	{
		next_point->y = current_pos->y;
		if (cos(angle) > 0)
			next_point->x = (float)(int)current_pos->x + 1;
		else if (is_int(current_pos->x))
			next_point->x = current_pos->x - 1;
		else
			next_point->x = (float)(int)current_pos->x;
		return (is_wall(next_point, data, angle));
	}
	if (cos(angle) < 0)
	{
		if (is_int(current_pos->x))
			next_point->x = next_point->x - 1;
		else
			next_point->x = (float)(int)current_pos->x;
	}
	else
		next_point->x = (float)(int)current_pos->x + 1;
	delta_x = current_pos->x - next_point->x;
	next_point->y = current_pos->y + delta_x * tan(angle);
	return (is_wall(next_point, data, angle));
}

t_end_ray	end_ray_vertical(t_data *data, float angle)
{
	t_vf2d		current_point;
	t_vf2d		next_point;
	t_end_ray	last_point;

	current_point = data->player_pos;
	while (set_next_point_vertical(&next_point, &current_point, data, angle) \
						== FALSE)
	{
		current_point = next_point;
	}
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, data->player_pos);
	return (last_point);
}
