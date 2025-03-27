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

void    draw_line(t_mlx_data *inf, t_vf2d point1, t_vf2d point2, int color)
{
    double    dx;
    double    dy;
    float    len;

    dx = point2.x - point1.x;
    dy = point2.y - point1.y;
    len = sqrtf(dx * dx + dy * dy);
    dx /= len;
    dy /= len;
    while (len > 0)
    {
        set_pixel(inf, point1.x += dx, point1.y += dy, color);
        len--;
    }
}

void	draw_square(t_mlx_data *inf, t_vi2d position, int tile_size, int color)
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

void	draw_circle(t_mlx_data *inf, t_vf2d pos, int diam, int color)
{
	float	x_first;
	float	y_first;
	int		x_added;
	int 	y_added;
	float	distance;

	y_added = 0;
	x_first = pos.x*diam - diam/2;
	y_first = pos.y*diam - diam/2;
	while (y_added < diam)
	{
		x_added = 0;
		while (x_added < diam)
		{
            distance = sqrt((x_added - diam/2) * (x_added - diam/2) \
							+ (y_added - diam/2) * (y_added - diam/2));
			if (!(distance > (diam/8)) || !(distance < diam))
			{
				set_pixel(inf, x_first + x_added, y_first + y_added, color);
			}
			++x_added;
		}
		++y_added;
	}
}
