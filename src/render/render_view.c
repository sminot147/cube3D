#include "cube.h"
#include "utils.h"

static void	fill_img(t_data *data);

void	render_view(t_data *data)
{
	t_mlx_data *inf;

	inf = data->mlx_inf;
	ft_bzero(inf->data, inf->size_len * inf->bpp);
	fill_img(data);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
}

static void	fill_img(t_data *data)
{
	int	tile_size;

	tile_size = data->tile_size;
	draw2d_map(tile_size, data->map, data->mlx_inf);
	draw2d_camera(data->map, data->mlx_inf, data, tile_size);
}

/*
typedef    struct s_end_ray
{
    float    x;
    float    y;
    float    dist;
}    t_end_ray;
tracer point entre end_ray et player (soustraire end_ray par player) ou inverse
*/
