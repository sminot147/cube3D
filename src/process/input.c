#include "cube.h"
#include "utils.h"
#include "define.h"

static int	key_press(int keycode, void *param);
static int	key_release(int keycode, void *param);
static int	close_program(void *param);
static int	update_action(void *param);

/**
 * @brief Processes input events, sets up hooks, and loop events.
 * 
 * @param data Pointer to the main data structure.
 */
void	process_input(t_data *data)
{
	t_mlx_data	*inf;

	inf = data->mlx_inf;
	mlx_hook(inf->win, 2, 1L << 0, key_press, data);
	mlx_hook(inf->win, 3, 1L << 1, key_release, data);
	mlx_hook(inf->win, 6, 1L << 6, mouse_move, data);
	mlx_hook(inf->win, 17, 0L<< 0, close_program, data);
	mlx_loop_hook(inf->mlx, update_action, data);
	mlx_loop(data->mlx_inf->mlx);
}

/**
 * @brief Updates the game state based on user input and renders the view.
 * 
 * @param param Pointer to the main data structure (cast to void*).
 * @return Always returns 0.
 */
static int	update_action(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (wait_fps())
		return (0);
	if (data->key[NORTH])
		try_move(data, 0);
	if (data->key[WEST])
		try_move(data, M_PI * 0.5);
	if (data->key[SOUTH])
		try_move(data, M_PI);
	if (data->key[EAST])
		try_move(data, -M_PI * 0.5);
	data->tile_size = data->minimap_size / (data->map->x_max + 1);
	render_view(data);
	return (0);
}


/**
 * @brief Handles key press events and updates the corresponding key state.
 * 
 * @param keycode The keycode of the pressed key.
 * @param param Pointer to the main data structure (cast to void*).
 * @return Always returns 0.
 */

static int	key_press(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_w)
		data->key[NORTH] = 1;
	else if (keycode == XK_a)
		data->key[WEST] = 1;
	else if (keycode == XK_s)
		data->key[SOUTH] = 1;
	else if (keycode == XK_d)
		data->key[EAST] = 1;
	else if (keycode == XK_space)
		data->minimap_size = WIDTH;
	return (0);
}

/**
 * @brief Handles key release events and updates the corresponding key state.
 * 
 * @param keycode The keycode of the released key.
 * @param param Pointer to the main data structure (cast to void*).
 * @return Always returns 0.
 */
static int	key_release(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == XK_Escape)
		close_program(data);
	else if (keycode == XK_w)
		data->key[NORTH] = 0;
	else if (keycode == XK_a)
		data->key[WEST] = 0;
	else if (keycode == XK_s)
		data->key[SOUTH] = 0;
	else if (keycode == XK_d)
		data->key[EAST] = 0;
	else if (keycode == XK_space)
		data->minimap_size = WIDTH / 6;
	return (0);
}

/**
 * @brief Closes the program and frees allocated resources.
 * 
 * @param param Pointer to the main data structure (cast to void*).
 * @return Always returns 0.
 */
static int	close_program(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	exit_free_with_msg("Exit Success", data, 0);
	return (0);
}
