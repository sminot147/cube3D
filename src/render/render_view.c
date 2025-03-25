#include "cube.h"
/*
	update_render_vars
	fill_pixel_buffer
	clear_window
	display_buffer
*/

void	render_view(t_data *data)
{
	t_mlx_data *inf;
	t_vec2d	player_pos;
	inf = data->inf;

	
	mlx_put_image_to_window(inf->mlx, inf->win, inf->img, 0, 0);
}

/*
draw line from playpos to all around avec 1 degre en plus a chaque fois
si la line touche un carre, la ligne s arrete


ensuite voir pour reduire les ligne sur un seul angle de 140degres

deplacement camera
*/
