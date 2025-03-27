/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:06 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 17:35:16 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"

static void	print_one_point(t_vf2d *point, char *message)
{
	//fonction de debug a supp
	printf("%s[%f , %f]\n", message, point->x, point->y);
}

static float	calc_dist(t_vf2d point1, t_vf2d point2)
{
	return (sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y)));
}

static t_bool	is_int(float nb)
{
	float	diff;

	diff = (float)(int)nb - nb;
	if (-0.001 < diff && diff < 0.001)
		return (TRUE);
	return (FALSE);
}

static t_bool	is_wall(t_vf2d *point, t_data *data)
{
	print_one_point(point, "Is wall ?\n");
	if ((point->x <= 0 || point->y <= 0 || point->x >= data->map->x_max || \
			point->y >= data->map->y_max))
		return (TRUE);
	if (is_int(point->x))
	{
		if (data->map->grid[(int)point->y][(int)point->x] == 1  || \
			data->map->grid[(int)point->y][(int)point->x] == -1)
			return (TRUE);
		if (data->map->grid[(int)point->y][(int)point->x + 1] == 1 || \
			data->map->grid[(int)point->y][(int)point->x + 1] == -1)
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

static t_bool	set_next_point_horizontal(t_vf2d *next_point, t_vf2d *current_pos, t_data *data)
{
	float	delta_y;

	print_one_point(current_pos, "Deput de la phase\n");
	printf("On a : data.view_angle = %f et en deg : %f et pi = %f\n", data->view_angle, ((data->view_angle * 180) / M_PI), M_PI);

	if (-0.1 < cos(data->view_angle) && cos(data->view_angle) < 0.1)
	{
		next_point->x = current_pos->x;
		if (sin(data->view_angle) > 0 && is_int(current_pos->y))
			next_point->y = current_pos->y - 1;
		else if (sin(data->view_angle) > 0)
			next_point->y = (float)(int)current_pos->y;
		else
			next_point->y = (float)(int)current_pos->y + 1;
		printf("next_point_y = %f\n", next_point->y);
		printf("next_point_x = %f\n", next_point->x);
		return (is_wall(next_point, data));
	}
	if (data->view_angle < M_PI)
	{
		if (is_int(current_pos->y))
			next_point->y = next_point->y - 1;
		else
			next_point->y = (float)(int)current_pos->y;
	}
	else
	{
		if (is_int(current_pos->y))
			next_point->y = next_point->y + 1;
		else
			next_point->y = (float)(int)current_pos->y + 1;
	}
	delta_y = current_pos->y - next_point->y;
	next_point->x = current_pos->x + delta_y / tan(data->view_angle);
	printf("next_point_y = %f\n", next_point->y);
	printf("next_point_x = %f\n", next_point->x);
	printf("delta = %f\t", delta_y);
	printf("tan = %f\n", tan(data->view_angle));
	return (is_wall(next_point, data));
}

t_end_ray	end_ray_horizontal(t_data *data)
{
	t_vf2d		current_point;
	t_vf2d		next_point;
	t_end_ray	last_point;

	printf("On a : data.view_angle = %f et en deg : %f et pi = %f\n", data->view_angle, ((data->view_angle * 180) / M_PI), M_PI);
	if (- 0.1 < sin(data->view_angle) && sin(data->view_angle) < 0.1)
	{
		last_point.x = 0;
		last_point.y = 0;
		last_point.dist = 1000;
		printf("on est la\n");
		return (last_point);
	}
	current_point = data->player_pos;
	print_one_point(&current_point, "Initialisation\n");
	int i = 0;
	while (set_next_point_horizontal(&next_point, &current_point, data) == FALSE && ++i <= 20)
	{
		current_point = next_point;
		printf("No\n");
	}
	if (i == 21)
		printf("Atttention--------------------------------------------------------------------------------\n");
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, data->player_pos);
	return (last_point);
}

t_end_ray	set_pos_to_end_ray(t_data *data)
{
	
	t_end_ray	end_ray_h;
	//t_end_ray	end_ray_v;
	

	end_ray_h = end_ray_horizontal(data);
	return (end_ray_h);
	//end_ray_v = en_ray_vertical(map, pos_player, angle);
	// if (end_ray_h.dist < end_ray_v.dist)
	// 	return (end_ray_h);
	// return(end_ray_v);
}

// static void	check_max_range_vertical(t_vf2d *next_point, t_vf2d current_pos, \
// 									t_data *data, t_bool is_almost_vertical)
// {
// 	if (is_almost_vertical == TRUE)
// 	{
// 		if (data->angle < M_PI)
// 		{
// 			next_point.x == data->player_pos.x;
// 			next_point.x == 1;
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
// 		next_point.x = (float)(int)pos_player.x;
// 		delta_x = pos_player.x - next_point.x;
// 	}
// 	else
// 	{
// 		next_point.x = (float)(int)pos_player.x + 1;
// 		delta_x = next_point.x - pos_player.x;
// 	}
// 	next_point.y = pos_player + delta_x * tan(angle);
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