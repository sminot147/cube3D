#include "cube.h"
#include "utils.h"
#include "define.h"

static void	draw2d_grid(t_mlx_data *inf, int ts, t_map *map);
static void	draw2d_line(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2);

void	draw2d_map(int ts, t_map *map, t_mlx_data *inf)
{
	size_t	cur_x;
	size_t	cur_y;
	int		**grid;

	cur_y = 0;
	grid = map->grid;
	while (cur_y <= map->y_max)
	{
		cur_x = 0;
		while (cur_x <= map->x_max)
		{
			if (grid[cur_y][cur_x] == 0)
			{
				draw_square(inf, (t_vi2d){cur_x, cur_y}, ts, WHITE);
			}
			else if (grid[cur_y][cur_x] == 1)
			{
				draw_square(inf, (t_vi2d){cur_x, cur_y}, ts, BLUE);
			}
			++cur_x;
		}
		++cur_y;
	}
	draw2d_grid(inf, ts, map);
}

void	draw2d_camera(t_map *map, t_mlx_data *inf, t_data *data, int ts)
{
	t_vf2d	angle_pos;

	angle_pos.x = data->player_pos.x + 1 * cos(data->view_angle);
	angle_pos.y = data->player_pos.y + 1 * sin(data->view_angle);
	draw2d_line(inf, ts, angle_pos, data->player_pos);
	draw_circle(inf, data->player_pos, ts, GREEN);
	// calc_view(inf, player_pos, ts, data); ?
}

static void	draw2d_grid(t_mlx_data *inf, int ts, t_map *map)
{
	size_t	i;

	i = 0;
	while (i <= map->y_max + 1)
	{
		draw_line(inf, (t_vf2d){0, ts*i}, \
					(t_vf2d){(map->x_max+1) * ts, ts*i}, BLACK);
		++i;
	}
	i = 0;
	while (i <= map->x_max + 1)
	{
		draw_line(inf, (t_vf2d){ts*i, 0},
					(t_vf2d){ts*i, (map->y_max+1) * ts}, BLACK);
		++i;
	}
}

static void	draw2d_line(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2)
{
	t_vf2d	convert1;
	t_vf2d	convert2;

	convert1.x = point1.x * ts;
	convert1.y = point1.y * ts;
	convert2.x = point2.x * ts;
	convert2.y = point2.y * ts;
	draw_line(inf, convert1, convert2, RED);
}
