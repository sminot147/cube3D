#include "cube.h"
#include "define.h"

int	mouse_move(int x, int y, void *param)
{
	t_data		*data;
	t_mlx_data	*info;

	(void)y;
	data = (t_data *)param;
	info = data->mlx_inf;
	if (data->mouse_pos.x < x)
	{
		data->view_angle += 0.05;
		if (data->view_angle >= RADIANT_MAX)
			data->view_angle = 0;
	}
	else if (data->mouse_pos.x > x)
	{
		data->view_angle -= 0.05;
		if (data->view_angle <= 0)
			data->view_angle = RADIANT_MAX;
	}
	mlx_mouse_move(info->mlx, info->win, WIDTH*0.5, HEIGHT*0.5);
	return (0);
}
