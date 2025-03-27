/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_vertical.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:43:48 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 19:43:01 by sminot           ###   ########.fr       */
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
	//tu en a pas deja une ?
	return (sqrt((point2.x - point1.x) * (point2.x - point1.x) + \
				(point2.y - point1.y) * (point2.y - point1.y)));
}

t_bool	is_int(float nb)
{
	float	diff;

	diff = (float)(int)nb - nb;
	if (-0.000001 < diff && diff < 0.000001)
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
		if (data->map->grid[(int)point->y][(int)point->x] == 1  || \
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
		else if (is_int(current_pos->y))
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

	if (- 0.001 < cos(angle) && cos(angle) < 0.001)
	{
		last_point.x = 0;
		last_point.y = 0;
		last_point.dist = sqrt((data->map->x_max + 1) * (data->map->x_max + 1) + \
								(data->map->y_max + 1) * (data->map->y_max + 1));
		return (last_point);
	}
	current_point = data->player_pos;
	print_one_point(&current_point, "Init vertical : ");
	int i = 0; //debug
	while (set_next_point_vertical(&next_point, &current_point, data, angle) == FALSE && ++i <= 20)
	{
		current_point = next_point;
		print_one_point(&next_point, "step vertical : ");
	}
	print_one_point(&next_point, "Fin vertical : ");
	if (i > 19)
		printf("C'est normal ???????????????????????????????????????????????????????????????????????????????????");
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, data->player_pos);
	return (last_point);
}
