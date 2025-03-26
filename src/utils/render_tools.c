#include "cube.h"
#include "define.h"

void	set_pixel(t_mlx_data *inf, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= MINI_W || y < 0 || y >= MINI_H)
		return;
	dst = inf->data + (y * inf->size_len + x * (inf->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw2d_cube(t_mlx_data *inf, t_vi2d position, int tile_size, int color)
{
	int	x_first;
	int	y_first;
	int	x_added;
	int y_added;

	y_added = 0;
	x_first = position.x * tile_size;
	y_first = position.y * tile_size;
	while (y_added < tile_size)
	{
		x_added = 0;
		while (x_added < tile_size)
		{
			set_pixel(inf, x_first + x_added, y_first + y_added, color);
			++x_added;
		}
		++y_added;
	}
}

void	draw2d_circle(t_mlx_data *inf, t_vf2d pos, int diam, int color)
{
	float	x_first;
	float	y_first;
	int		x_added;
	int 	y_added;
	float	distance;

	y_added = 0;
	x_first = pos.x * diam;
	y_first = pos.y * diam;
	while (y_added < diam)
	{
		x_added = 0;
		while (x_added < diam)
		{
            distance = sqrt((x_added - diam / 2) * (x_added - diam / 2) \
							+ (y_added - diam / 2) * (y_added - diam / 2));
			if (!(distance > (diam / 2)) || !(distance < diam))
				set_pixel(inf, x_first + x_added, y_first + y_added, color);
			++x_added;
		}
		++y_added;
	}
}

void	draw2d_map(int ts, t_map *map, t_mlx_data *inf)
{
	int		cur_x;
	int		cur_y;
	int		**grid;

	cur_y = 0;
	grid = map->map;
	while (cur_y <= map->y_max)
	{
		cur_x = 0;
		while (cur_x <= map->x_max)
		{
			if (grid[cur_y][cur_x] == 0)
			{
				draw2d_cube(inf, (t_vi2d){cur_x, cur_y}, ts, WHITE);
			}
			else if (grid[cur_y][cur_x] == 1)
			{
				draw2d_cube(inf, (t_vi2d){cur_x, cur_y}, ts, BLUE);
			}
			++cur_x;
		}
		++cur_y;
	}
}

void	draw2d_camera(t_map *map, t_mlx_data *inf, t_data *data, int ts)
{
	draw2d_circle(inf, data->player_pos, ts, GREEN);
	// calc_view(inf, player_pos, ts, data);
}
