#include "struct.h"
#include "define.h"

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

	flag = FALSE;
	if (map[(int)(pos.y + 0.1)][(int)pos.x])
		flag = TRUE;
	else if (map[(int)(pos.y - 0.1)][(int)pos.x])
		flag = TRUE;
	else if (map[(int)pos.y][(int)(pos.x + 0.1)])
		flag = TRUE;
	else if (map[(int)pos.y][(int)(pos.x - 0.1)])
		flag = TRUE;
	else if (map[(int)(pos.y + 0.1)][(int)(pos.x - 0.1)])
		flag = TRUE;
	else if (map[(int)(pos.y + 0.1)][(int)(pos.x + 0.1)])
		flag = TRUE;
	else if (map[(int)(pos.y - 0.1)][(int)(pos.x - 0.1)])
		flag = TRUE;
	else if (map[(int)(pos.y - 0.1)][(int)(pos.x + 0.1)])
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
		data->view_angle -= 0.03;
		data->mouse_pos.x = x;
		if (data->view_angle <= 0)
		{
			data->view_angle = RADIANT_MAX;
		}
	}
	else if (WIDTH * 0.5 > x)
	{
		data->view_angle += 0.03;
		data->mouse_pos.x = x;
		if (data->view_angle >= RADIANT_MAX)
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
		data->view_angle += 0.1;
		if (data->view_angle <= 0)
		{
			data->view_angle = RADIANT_MAX;
		}
	}
	else if (right)
	{
		data->view_angle -= 0.1;
		if (data->view_angle >= RADIANT_MAX)
		{
			data->view_angle = 0;
		}
	}
}
