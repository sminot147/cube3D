#include "struct.h"
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

	flag = 0;
	if (map[(int)(pos.y + 0.1)][(int)pos.x])
		flag = 1;
	else if (map[(int)(pos.y - 0.1)][(int)pos.x])
		flag = 1;
	else if (map[(int)pos.y][(int)(pos.x + 0.1)])
		flag = 1;
	else if (map[(int)pos.y][(int)(pos.x - 0.1)])
		flag = 1;
	else if (map[(int)(pos.y + 0.1)][(int)(pos.x - 0.1)])
		flag = 1;
	else if (map[(int)(pos.y + 0.1)][(int)(pos.x + 0.1)])
		flag = 1;
	else if (map[(int)(pos.y - 0.1)][(int)(pos.x - 0.1)])
		flag = 1;
	else if (map[(int)(pos.y - 0.1)][(int)(pos.x + 0.1)])
		flag = 1;
	return (flag);
}

/**
 * @brief Calcul and moves the player if the new position is valid.
 * 
 * @param data data structure with player and map info.
 * @param angle Angle offset from the player's view angle.
 */
void	try_move(t_data *data, float angle)
{
	t_vf2d	test_pos;
	t_map	*map;

	map = data->map;
	test_pos = data->player_pos;
	test_pos.y += 0.1 * sin(data->view_angle + angle);
	test_pos.x += 0.1 * cos(data->view_angle + angle);
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos = test_pos;
	}
}
