/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:06 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 19:42:02 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "cube.h"
#include "define.h"

void	print_one_point(t_vf2d *point, char *message); /////////////////////////////////////sup

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
		return (is_wall(next_point, data, angle));
	}
	if (angle < M_PI)
	{
		if (is_int(current_pos->y))
			next_point->y = next_point->y - 1;
		else
			next_point->y = (float)(int)current_pos->y;
	}
	else
		next_point->y = (float)(int)current_pos->y + 1;
	delta_y = current_pos->y - next_point->y;
	next_point->x = current_pos->x + delta_y / tan(angle);
	return (is_wall(next_point, data, angle));
}

t_end_ray	end_ray_horizontal(t_data *data, float angle)
{
	t_vf2d		current_point;
	t_vf2d		next_point;
	t_end_ray	last_point;

	if (- 0.001 < sin(angle) && sin(angle) < 0.001)
	{
		last_point.x = 0;
		last_point.y = 0;
		last_point.dist = sqrt((data->map->x_max + 1) * (data->map->x_max + 1) + \
								(data->map->y_max + 1) * (data->map->y_max + 1));
		return (last_point);
	}
	current_point = data->player_pos;
	int i = 0; //debug
	print_one_point(&current_point, "Init horizontal : ");
	while (set_next_point_horizontal(&next_point, &current_point, data, angle) == FALSE && ++i <= 20)
	{
		current_point = next_point;
		print_one_point(&next_point, "step horizontal : ");
	}
	print_one_point(&next_point, "Fin horizontal : ");
	if (i > 19)
		printf("C'est normal ???????????????????????????????????????????????????????????????????????????????????");
	last_point.x = next_point.x;
	last_point.y = next_point.y;
	last_point.dist = calc_dist(next_point, data->player_pos);
	return (last_point);
}

static t_end_ray	end_ray(t_data *data, float angle)
{
	
	t_end_ray	end_ray_h;
	t_end_ray	end_ray_v;
	

	end_ray_h = end_ray_horizontal(data, angle);
	end_ray_v = end_ray_vertical(data, angle);
	if (end_ray_h.dist < end_ray_v.dist)
 		return (end_ray_h);
	return(end_ray_v);
}

/*----------------------------------------------------------------------------------------------*/
void	draw2d_line1(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2)
{
	t_vf2d	convert1;
	t_vf2d	convert2;

	convert1.x = point1.x * ts;
	convert1.y = point1.y * ts;
	convert2.x = point2.x * ts;
	convert2.y = point2.y * ts;
	draw_line(inf, convert1, convert2, GREEN);
}

void	draw2d_line2(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2)
{
	t_vf2d	convert1;
	t_vf2d	convert2;

	convert1.x = point1.x * ts;
	convert1.y = point1.y * ts;
	convert2.x = point2.x * ts;
	convert2.y = point2.y * ts;
	draw_line(inf, convert1, convert2, YELLOW);
}

void	draw2d_line3(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2)
{
	t_vf2d	convert1;
	t_vf2d	convert2;

	convert1.x = point1.x * ts;
	convert1.y = point1.y * ts;
	convert2.x = point2.x * ts;
	convert2.y = point2.y * ts;
	draw_line(inf, convert1, convert2, BLACK);
}

void	trace_ray_casting(t_data *data, t_mlx_data *inf, int ts)
{
	int			i;
	t_end_ray	end_ray1;
	t_vf2d		end_ray2;
	float		angle;;
	
	i = - FIELD_OF_VIEW / 2;
	while (++i < FIELD_OF_VIEW / 2)
	{
		angle = data->view_angle + (i * M_PI / 180);
		printf("On a angle = %f\n", angle * 180 / M_PI);
		end_ray1 = end_ray(data, angle);
		end_ray2.x = end_ray1.x;
		end_ray2.y = end_ray1.y;
		draw2d_line(inf, ts, end_ray2, data->player_pos);
	}


// angle = data->view_angle;
// end_ray1 = end_ray_vertical(data, angle);
// end_ray2.x = end_ray1.x;
// end_ray2.y = end_ray1.y;
// print_one_point(&end_ray2, "Veritacal Yellow : ");
// draw2d_line2(inf, ts, end_ray2, data->player_pos);
// printf("On a dist = %f\n", end_ray1.dist);
// end_ray1 = end_ray_horizontal(data, angle);
// end_ray2.x = end_ray1.x;
// end_ray2.y = end_ray1.y;
// draw2d_line1(inf, ts, end_ray2, data->player_pos);
// print_one_point(&end_ray2, "Horizontal GREEN : ");
// end_ray1 = end_ray(data, angle);
// end_ray2.x = end_ray1.x;
// end_ray2.y = end_ray1.y;
// draw2d_line3(inf, ts, end_ray2, data->player_pos);
// print_one_point(&end_ray2, "End BLACK : ");
}