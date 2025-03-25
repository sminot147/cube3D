#include "cube.h"

void	set_pixel(t_mlx_data *inf, int x, int y, int color)
{
	char *dst;

	if (x < 0 || x >= MINI_W || y < 0 || y >= MINI_H)
		return;
	dst = inf->data + (y * inf->size_len + x * (inf->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_cube(t_mlx_data *inf, t_vec2d position, int tile_size, int color)
{
	int	x_first;
	int	y_first;
	int	x_added;
	int y_added;

	x_added = 0;
	x_first = position.x * tile_size;
	y_first = position.y * tile_size;
	while (x_added < tile_size)
	{
		y_added = 0;
		while (y_added < tile_size)
		{
			set_pixel(inf, x_first + x_added, y_first + y_added, color);
			++y_added;
		}
		++x_added;
	}
}
