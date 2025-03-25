#include "cube.h"
/*
	update_render_vars
	fill_pixel_buffer
	clear_window
	display_buffer
*/
int	print_line(t_mlx_inf *inf, t_vec2d wall_s, t_vec2d wall_e);
void	add_pixel(t_mlx_inf *inf, int x, int y);

void	render_view(t_data *data)
{
	t_mlx_inf *inf;
	t_vec2d	player_pos;
	inf = data->inf;

	t_vec2d wall_s = {1000, 500};
	t_vec2d wall_e = {600, 700};
	inf->img = mlx_new_image(inf->mlx, 1920, 1080);
	inf->data = mlx_get_data_addr(inf->img, &inf->bpp, &inf->sl, &inf->endian);
	print_line(	inf, wall_s, wall_e);
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
}

int	print_line(t_mlx_inf *inf, t_vec2d wall_s, t_vec2d wall_e)
{
	double	dx;
	double	dy;
	float	len;

	dx = wall_s.x - wall_e.x;
	dy = wall_s.y - wall_e.y;
	len = sqrtf(dx * dx + dy * dy);
	dx /= len;
	dy /= len;
	while (len > 0)
	{
		add_pixel(inf, wall_s.x += dx, wall_s.y += dy);
		len--;
	}
	return (0);
}

void	add_pixel(t_mlx_inf *inf, int x, int y)
{
	int	pixel_index;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		pixel_index = (y * inf->sl) + (x * (inf->bpp / 8));
		*(unsigned int *)(inf->data + pixel_index) = 0xFFFFFF;
	}
}
