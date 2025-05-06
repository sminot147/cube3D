/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:26:17 by vgarcia           #+#    #+#             */
/*   Updated: 2025/05/06 13:56:40 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	new_visual_update(t_data *data);
static t_bool	change_mapsize(t_data *data, int zoom);
static t_bool	check_visual_orientation(t_data *data);

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
	if (new_visual_update(data))
		render_view(data);
	return (0);
}

/**
 * @brief Update moves & check if a visual update will be required
 * 
 * @param data Pointer to the main data structure.
 * @return Return (TRUE) or (FALSE) if a visual update is needed or not
 */
static t_bool	new_visual_update(t_data *data)
{
	t_bool		flag;

	flag = FALSE;
	if (data->key[NORTH] && try_move(data, 0))
		flag = TRUE;
	if (data->key[WEST] && try_move(data, M_PI * 0.5))
		flag = TRUE;
	if (data->key[SOUTH] && try_move(data, M_PI))
		flag = TRUE;
	if (data->key[EAST] && try_move(data, -M_PI * 0.5))
		flag = TRUE;
	if (data->key[R_ARROW] || data->key[L_ARROW])
		flag = TRUE;
	if (change_mapsize(data, data->key[SPACE]))
		flag = TRUE;
	if (check_visual_orientation(data))
		flag = TRUE;
	return (flag);
}

/**
 * @brief Check if a visual update concerning the player orientation
 * 
 * @param data Pointer to the main data structure.
 * @return Return (TRUE) or (FALSE) if a visual update is needed or not
 */
static t_bool	check_visual_orientation(t_data *data)
{
	t_bool		flag;

	flag = FALSE;
	if (!isequal_vi2d(data->mouse_pos, (t_vi2d){WIDTH * 0.5, HEIGHT * 0.5}))
	{
		data->mouse_pos = (t_vi2d){WIDTH * 0.5, HEIGHT * 0.5};
		mlx_mouse_move(data->mlx_inf->mlx, data->mlx_inf->win, \
					WIDTH * 0.5, HEIGHT * 0.5);
		flag = TRUE;
	}
	if (data->key[R_ARROW] || data->key[L_ARROW])
	{
		arrow_angle_update(data, data->key[L_ARROW], data->key[R_ARROW]);
		flag = TRUE;
	}
	return (flag);
}

/**
 * @brief Adjusts the tile size of the map based on zoom input and map dim.
 *
 * @param data Pointer to the main data structure containing map information.
 * @param zoom Zoom level input.
 * @return t_bool return true or false if there is an update needed.
 */
static t_bool	change_mapsize(t_data *data, int zoom)
{
	static t_bool	last_input;
	size_t			max;
	size_t			min_dimension;

	max = ft_max(data->map->x_max, data->map->y_max);
	min_dimension = ft_min(WIDTH, HEIGHT);
	if ((int)last_input == (int)zoom)
	{
		return (FALSE);
	}
	else if (!zoom)
	{
		data->tile_size = (min_dimension * 0.167) / (max + 1);
	}
	else
	{
		data->tile_size = min_dimension / (max + 1);
	}
	last_input = zoom;
	return (TRUE);
}
