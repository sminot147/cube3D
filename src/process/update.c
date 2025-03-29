#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	need_visual_update(t_data *data);
static t_bool	change_mapsize(t_data *data, int zoom);

/**
 * @brief Updates the game state based on user input and renders the view.
 * 
 * @param param Pointer to the main data structure (cast to void*).
 * @return Always returns 0.
 */
int	update_action(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (wait_fps())
		return (0);
	if (need_visual_update(data))
		render_view(data);
	return (0);
}

/**
 * @brief Update moves & check if a visual update will be required
 * 
 * @param data Pointer to the main data structure.
 * @return Return (TRUE) or (FALSE) if a visual update is needed or not
 */
static t_bool	need_visual_update(t_data *data)
{
	t_bool		flag;

	flag = FALSE;
	if (!isequal_vi2d(data->mouse_pos, (t_vi2d){HALF_WIDTH, HALF_HEIGHT}))
	{
		data->mouse_pos = (t_vi2d){HALF_WIDTH, HALF_HEIGHT};
		mlx_mouse_move(data->mlx_inf->mlx, data->mlx_inf->win, \
					HALF_WIDTH, HALF_HEIGHT);
		flag = TRUE;
	}
	if (data->key[NORTH] && try_move(data, 0))
		flag = TRUE;
	if (data->key[WEST] && try_move(data, M_PI * 0.5))
		flag = TRUE;
	if (data->key[SOUTH] && try_move(data, M_PI))
		flag = TRUE;
	if (data->key[EAST] && try_move(data, -M_PI * 0.5))
		flag = TRUE;
	if (data->key[RIGHT_ARROW] || data->key[LEFT_ARROW])
		flag = TRUE;
	if (data->key[RIGHT_ARROW] || data->key[LEFT_ARROW])
		arrow_angle_update(data, data->key[LEFT_ARROW], data->key[RIGHT_ARROW]);
	if (change_mapsize(data, data->key[SPACE]))
		flag = TRUE;
	return (flag);
}

static t_bool	change_mapsize(t_data *data, int zoom)
{
	static t_bool	last_input;

	if ((int)last_input == (int)zoom)
	{
		return (FALSE);
	}
	else if (!zoom)
	{
		data->tile_size = (WIDTH / 6) / (data->map->x_max + 1);
	}
	else
	{
		data->tile_size = WIDTH / (data->map->x_max + 1);
	}
	last_input = zoom;
	return (TRUE);
}
