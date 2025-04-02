#include "define.h"
#include "struct.h"
#include "cube.h"
#include "utils.h"

int		get_image_xposition(t_end_ray *ray)
{
	float	pose_in_axe;

	pose_in_axe = 0;
	if (ray->wall == EAST || ray->wall == WEST)	
		pose_in_axe = ray->x;
	else if (ray->wall == NORTH || ray->wall == SOUTH)
		pose_in_axe = ray->y;
	pose_in_axe = pose_in_axe * IMAGE_SIZE;
	return (pose_in_axe);
}

void	draw_texture(int img_x, int x, int y_edge[2], t_data *data)
{
	int			wall_size;
	int			addr_y;
	int			y;
	int			color;
	t_mlx_data	*inf;
	t_img		img;

	img = data->face[NORTH];
	y = 0;
	inf = data->mlx_inf;
	wall_size = y_edge[0] - y_edge[1];
	while (y < wall_size)
	{
		addr_y = y * 64 / wall_size;
		color = *(int *)(img.addr + \
				(addr_y * img.size_line + img_x * (img.bpp / 8)));
		set_pixel(inf, x, y + y_edge[1], color);
		++y;
	}
}
