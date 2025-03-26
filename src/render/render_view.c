#include "cube.h"

static void	fill_img(t_data *data);
/*
	update_render_vars
	calculate_points_position
	fill_pixel_buffer
	clear_window
	display_buffer
*/

void	render_view(t_data *data)
{
	t_mlx_data *inf;

	inf = data->inf;
	fill_img(data);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
}

static void	fill_img(t_data *data)
{
	int	tile_size;

	tile_size = MINI_W / (data->map->x_max + 1);
	draw2d_map(tile_size, data->map, data->inf);
	draw2d_camera(data->map, data->inf, data, tile_size);
}

/*
draw line from playpos to all around avec 1 degre en plus a chaque fois
si la line touche un carre, la ligne s arrete


ensuite voir pour reduire les ligne sur un seul angle de 140degres

deplacement camera
*/
