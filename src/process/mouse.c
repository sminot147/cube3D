#include "cube.h"
#include "utils.h"
#include "define.h"

int	mouse_move(int x, int y, void *param)
{
	t_data		*data;
	t_mlx_data	*inf;

	data = (t_data *)param;
	if (data->mouse_pos.x < x)
	{
		data->view_angle += 0.1;
		if (data->view_angle >= 360)
			data->view_angle = 0;
	}
	else if (data->mouse_pos.x > x)
	{
		data->view_angle -= 0.1;
		if (data->view_angle <= 0)
			data->view_angle = 360;
	}
	printf("view_angle:[%f]\n", data->view_angle);
	return (0);
}

/*
mlx_mouse_get_pos
mlx_mouse_hidw
*/

/*
idee:
prendre la mouse position;
soustraire / additionner la precedente position
pour update la current_view;
*/
