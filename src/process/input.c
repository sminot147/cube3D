#include "cube.h"
#include "utils.h"
#include "define.h"

static int	key_press(int keycode, void *param);
static int	mouse_move(int keycode, void *param);
static int	close_program(void *param);
static int	update_view(void *param);

void	process_input(t_data *data)
{
	t_mlx_data	*inf;

	inf = data->inf;
	mlx_hook(inf->win, 2, 1L << 0, key_press, data);
	mlx_hook(inf->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(inf->win, 17, 0L<< 0, close_program, data);
	mlx_loop_hook(inf->mlx, update_view, data);
	mlx_loop(data->inf->mlx);
}

static int	update_view(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (wait_fps())
		return (0);
	render_view(data);	
	return (0);
}

static int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		close_program(data);
	else if (keycode == XK_w)
		try_move_front(data);
	else if (keycode == XK_a)
		try_move_left(data);
	else if (keycode == XK_s)
		try_move_back(data);
	else if (keycode == XK_d)
		try_move_right(data);
	return (0);
}

static int	mouse_move(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)keycode;
	(void)data;
	/*
	a voir
	*/
	return (0);
}

static int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;

	exit_free_with_msg("Exit Success", data, 0);
	return (0);
}
