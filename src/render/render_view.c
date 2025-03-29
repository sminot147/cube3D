#include "cube.h"
#include "utils.h"
#include "define.h"

static void	fill_img(t_data *data);

/**
 * @brief Clean and redraw the window
 * @param data Pointer to the main data structure.
 */
void	render_view(t_data *data)
{
	t_mlx_data *inf;

	inf = data->mlx_inf;
	ft_bzero(inf->data, inf->size_line * HEIGHT);
	fill_img(data);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
}

/**
 * @brief Fills the image by rendering the 2D map and camera view.
 * @param data Pointer to the main data structure.
 */
static void	fill_img(t_data *data)
{
	int	tile_size;

	tile_size = data->tile_size;
	render_surface(HEIGHT * 0.5, data);
	trace_ray_casting(data, data->mlx_inf, data->tile_size);
	draw2d_map(tile_size, data->map, data->mlx_inf);
	draw2d_camera(data->mlx_inf, data, tile_size);
}
