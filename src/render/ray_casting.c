
#include "struct.h"
#include "cube.h"
#include "define.h"

void	print_one_point(t_vf2d *point, char *message); /*-------------------------------------------*/ //sup

t_end_ray	set_wall(t_end_ray point, t_data *data)
{
	if ((point.x <= 0 || point.y <= 0 || point.x >= data->map->x_max || \
			point.y >= data->map->y_max))
		printf("Sure about it ??????????????\n"); //normalement on est jamais la;
	if (is_int(point.x))
	{
		if (data->map->grid[(int)point.y][(int)point.x] == 1 || \
			data->map->grid[(int)point.y][(int)point.x] == -1)
			printf("EAST\n");point.wall = EAST;
		if (data->map->grid[(int)point.y][(int)point.x - 1] == 1 || \
			data->map->grid[(int)point.y][(int)point.x - 1] == -1)
			printf("WEST\n");point.wall = WEST;
	}
	else if (is_int(point.y))
	{
		if (data->map->grid[(int)point.y][(int)point.x] == 1 || \
			data->map->grid[(int)point.y][(int)point.x] == -1)
			printf("SOUTH\n");point.wall = SOUTH;
		if (data->map->grid[(int)point.y - 1][(int)point.x] == 1 || \
			data->map->grid[(int)point.y - 1][(int)point.x] == -1)
			printf("NORTH\n");point.wall = NORTH;
	}
	printf("\n");
	return (point);
}

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
	return (is_wall(next_point, data, angle));
}

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
	return (last_point);
}

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

void	trace_ray_casting(t_data *data, t_mlx_data *inf, int ts)
{
	int			i;
	float		angle;
	t_end_ray	end_ray1;
	t_vf2d		end_ray2;

	i = -FIELD_OF_VIEW / 2;
	while (i <= FIELD_OF_VIEW / 2)
	{
		angle = data->view_angle + (i * M_PI / 180);
		end_ray1 = end_ray(data, angle);
		end_ray2.x = end_ray1.x;
		end_ray2.y = end_ray1.y;
		draw2d_line(inf, ts, end_ray2, data->player_pos);
		i++;
	}
}

/*----------------------------------------------------------------------------------------------
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

void	trace_ray_casting1(t_data *data, t_mlx_data *inf, int ts)
{
	int			i;
	t_end_ray	end_ray1;
	t_vf2d		end_ray2;
	//float		angle;
	static float angle = 0;

	//angle = data->view_angle;
	//angle = 45;
	printf("angle = %f\n", angle * 180 / M_PI);
	if (!(-0.001 < cos(angle) && cos(angle) < 0.001))
	{
		end_ray1 = end_ray_vertical(data, angle);
		end_ray2.x = end_ray1.x;
		end_ray2.y = end_ray1.y;
		print_one_point(&end_ray2, "Veritacal Yellow : ");
		draw2d_line2(inf, ts, end_ray2, data->player_pos);
	}
	if (!(-0.001 < sin(angle) && sin(angle) < 0.001))
	{
		end_ray1 = end_ray_horizontal(data, angle);
		end_ray2.x = end_ray1.x;
		end_ray2.y = end_ray1.y;
		draw2d_line1(inf, ts, end_ray2, data->player_pos);
		print_one_point(&end_ray2, "Horizontal GREEN : ");
	}
	end_ray1 = end_ray(data, angle);
	end_ray2.x = end_ray1.x;
	end_ray2.y = end_ray1.y;
	draw2d_line3(inf, ts, end_ray2, data->player_pos);
	print_one_point(&end_ray2, "End BLACK : ");
	angle += M_PI / 180;
	if (angle > 6.28 || angle < -6.28)
		angle = 0;
	usleep(1);
}

------------------------------------------------------------------------------------------------------------*/