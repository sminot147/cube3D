#include "define.h"
#include "struct.h"
#include "cube.h"
#include "utils.h"

void	render_ray3d(float ray_index, t_end_ray *ray, t_data *data)
{
	int	color;
	int	pixel_x;
	int	wall_top;
	int	wall_bottom;
	int	half_wall_height;

	ray_index = FIELD_OF_VIEW - (ray_index + FIELD_OF_VIEW * 0.5);
	if (ray->dist < 1)
		ray->dist = 1;
	half_wall_height = (HEIGHT / ray->dist) * 1;
	wall_bottom = HALF_HEIGHT + half_wall_height;
	wall_top = HALF_HEIGHT - half_wall_height;
	pixel_x = (ray_index * (WIDTH / FIELD_OF_VIEW + 1));
	color = ((int)((16 - ray->dist) * 16) << ray->wall * 8);
	draw_line(data->mlx_inf, (t_vf2d){pixel_x, wall_bottom}, 
							(t_vf2d){pixel_x, wall_top}, color);
}

void	render_surface(int screen_midpoint_y, t_data *data)
{
	int		color;
	int		size_line;
	char	*addr;

	addr = data->mlx_inf->data;
	size_line = data->mlx_inf->size_line;
	color = data->map->ceiling_color;
	set_pixels(data->mlx_inf, color, \
		size_line * screen_midpoint_y, addr);
	color = data->map->floor_color;
	set_pixels(data->mlx_inf, color, \
		size_line * screen_midpoint_y, addr + size_line * screen_midpoint_y);
}
