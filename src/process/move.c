/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:10:56 by sminot            #+#    #+#             */
/*   Updated: 2025/05/06 12:45:32 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "define.h"
#include <math.h>

/**
 * @brief Checks if a given position is inside a wall on the map.
 * 
 * @param pos The position to check, represented as a 2D vector (t_vf2d).
 * @param map The 2D grid map where walls are represented by non-zero values.
 * @return t_bool True if the position is inside a wall, False otherwise.
 */
static t_bool	is_in_wall(t_vf2d pos, int **map)
{
	t_bool	flag;
	float	collision_var;

	collision_var = 0.3;
	flag = FALSE;
	if (map[(int)(pos.y + collision_var)][(int)pos.x])
		flag = TRUE;
	else if (map[(int)(pos.y - collision_var)][(int)pos.x])
		flag = TRUE;
	else if (map[(int)pos.y][(int)(pos.x + collision_var)])
		flag = TRUE;
	else if (map[(int)pos.y][(int)(pos.x - collision_var)])
		flag = TRUE;
	else if (map[(int)(pos.y + collision_var)][(int)(pos.x - collision_var)])
		flag = TRUE;
	else if (map[(int)(pos.y + collision_var)][(int)(pos.x + collision_var)])
		flag = TRUE;
	else if (map[(int)(pos.y - collision_var)][(int)(pos.x - collision_var)])
		flag = TRUE;
	else if (map[(int)(pos.y - collision_var)][(int)(pos.x + collision_var)])
		flag = TRUE;
	return (flag);
}

/**
 * @brief Calcul and moves the player if the new position is valid.
 * 
 * @param data data structure with player and map info.
 * @param angle Angle offset from the player's view angle.
 */
t_bool	try_move(t_data *data, float angle)
{
	t_vf2d	test_pos;
	t_map	*map;

	map = data->map;
	test_pos = data->player_pos;
	test_pos.x += 0.1 * cos(data->view_angle + angle);
	test_pos.y -= 0.1 * sin(data->view_angle + angle);
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos = test_pos;
		return (TRUE);
	}
	return (FALSE);
}

/**
 * @brief Adjusts the player's view angle based on horizontal mouse movement.
 * 
 * @param x Current x-coordinate of the mouse.
 * @param y Current y-coordinate of the mouse (unused).
 * @param param Pointer to the game data structure.
 */
int	mouse_move(int x, int y, void *param)
{
	t_data		*data;

	(void)y;
	data = (t_data *)param;
	if (WIDTH * 0.5 < x)
	{
		data->view_angle -= 0.015;
		data->mouse_pos.x = x;
		if (data->view_angle <= 0)
		{
			data->view_angle = M_PI * 2;
		}
	}
	else if (WIDTH * 0.5 > x)
	{
		data->view_angle += 0.015;
		data->mouse_pos.x = x;
		if (data->view_angle >= M_PI * 2)
		{
			data->view_angle = 0;
		}
	}
	return (0);
}

void	arrow_angle_update(t_data *data, int left, int right)
{
	if (left && right)
	{
		return ;
	}
	else if (left)
	{
		data->view_angle += 0.05;
		if (data->view_angle >= M_PI * 2)
		{
			data->view_angle = 0;
		}
	}
	else if (right)
	{
		data->view_angle -= 0.05;
		if (data->view_angle <= 0)
		{
			data->view_angle = M_PI * 2;
		}
	}
}
