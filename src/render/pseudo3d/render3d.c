#include "define.h"
#include "struct.h"
#include "cube.h"
#include "utils.h"

static void	draw_thick_line(t_mlx_data *inf, t_vf2d point1, \
				t_vf2d point2, int color);
void	render_ray3d(int ray_index, t_end_ray *ray, t_data *data)
{
	int		color;
	int		pixel_x;
	size_t	wall_top;
	size_t	wall_bottom;
	size_t	half_wall_height;

	ray_index += FIELD_OF_VIEW * 0.5;
	half_wall_height = ((HEIGHT) / ray->dist) * 0.5;
	wall_bottom = HEIGHT*0.5 + half_wall_height;
	wall_top = HEIGHT*0.5 - half_wall_height;
	pixel_x = ray_index * (WIDTH / FIELD_OF_VIEW + 1);
	color = (int)((16 - ray->dist) * 16) << 16;
	draw_thick_line(data->mlx_inf, (t_vf2d){pixel_x, wall_bottom}, 
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

static void	draw_thick_line(t_mlx_data *inf, t_vf2d point1, \
				t_vf2d point2, int color)
{
	int	x;
	int	i;
	int	bot_wall;
	int	top_wall;

	x = point1.x;
	i = -(WIDTH / FIELD_OF_VIEW) - 1;
	bot_wall = point1.y;
	top_wall = point2.y;
	while (x + i < x + (WIDTH / FIELD_OF_VIEW) + 1)
	{
		draw_line(inf, (t_vf2d){x + i, bot_wall}, \
					(t_vf2d){x + i, top_wall}, color);
		++i;
	}
}
