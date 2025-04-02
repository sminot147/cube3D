#include "define.h"
#include "struct.h"
#include "cube.h"
#include "utils.h"

void	render_ray3d(float ray_index, t_end_ray *ray, t_data *data)
{
	int	pixel_x;
	int	wall_edge[2];
	int	half_wall_height;
	int	image_x;

	ray_index = FIELD_OF_VIEW - (ray_index + FIELD_OF_VIEW * 0.5);
	if (ray->dist < 1)
		ray->dist = 1;
	half_wall_height = (HEIGHT / ray->dist) * 1;
	wall_edge[0] = HALF_HEIGHT + half_wall_height;
	wall_edge[1] = HALF_HEIGHT - half_wall_height;
	pixel_x = (ray_index * (WIDTH / FIELD_OF_VIEW + 1));
	image_x = get_image_xposition(ray);
	draw_texture(image_x, pixel_x, wall_edge, data);
	// color = ((int)((16 - ray->dist) * 16) << ray->wall * 8);
	// draw_line(data->mlx_inf, (t_vf2d){pixel_x, wall_edge[0]}, 
							// (t_vf2d){pixel_x, wall_edge[1]}, color);
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

/*
Idee ca va etre de render la ligne du mur toucher par le ray,
*/
