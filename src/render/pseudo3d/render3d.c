#include "define.h"
#include "struct.h"
#include "cube.h"

/*
idee screen height = 1
dist = 0 -> line size = height
dist = 10 -> line size = height / 10 ?
*/
void	render_ray3d(int ray_index, t_end_ray *ray, t_data *data)
{
	int		screen_midpoint;
	int		pixel_x;
	size_t	wall_top;
	size_t	wall_bottom;
	size_t	half_wall_height;

	screen_midpoint = (HEIGHT) * 0.5;
	half_wall_height = ((HEIGHT) / ray->dist) * 0.5;
	wall_bottom = screen_midpoint + half_wall_height;
	wall_top = screen_midpoint - half_wall_height;
	pixel_x = ray_index * WIDTH / FIELD_OF_VIEW * 2;
	draw_line(data->mlx_inf, (t_vf2d){pixel_x, wall_bottom}, 
							(t_vf2d){pixel_x, wall_top}, RED);
}

void	render_surface(int screen_midpoint_y, t_data *data)
{
	int			color;
	t_mlx_data	*info;

	info = data->mlx_inf;
	color = data->map->ceiling_color;
	set_pixels(info, RED, info->size_len * screen_midpoint_y);
	set_pixels(info, YELLOW, info->size_len * screen_midpoint_y);
}
