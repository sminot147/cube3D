#include "struct.h"

static t_bool	is_in_wall(t_vf2d new_pos, int **map)
{
	return (map[(int)new_pos.y][(int)new_pos.x]);
}

void	try_move_front(t_data *data)
{
	t_vf2d	new_pos;
	t_map	*map;

	map = data->map;
	new_pos = data->player_pos;
	new_pos.y -= 1;
	if ((float)(int)new_pos.x == new_pos.x)
		;// border
	if (!is_in_wall(new_pos, map->grid))
	{
		data->player_pos = new_pos;
	}
}

void	try_move_left(t_data *data)
{
	t_vf2d	new_pos;
	t_map	*map;

	new_pos = data->player_pos;
	new_pos.x -= 1;
	if ((float)(int)new_pos.x == new_pos.x)
		;// border
	map = data->map;
	if (!is_in_wall(new_pos, map->grid))
	{
		data->player_pos = new_pos;
	}
}

void	try_move_back(t_data *data)
{
	t_vf2d	new_pos;
	t_map	*map;

	map = data->map;
	new_pos = data->player_pos;
	new_pos.y += 1;
	if ((float)(int)new_pos.y == new_pos.y)
		;// border
	if (!is_in_wall(new_pos, map->grid))
	{
		data->player_pos = new_pos;
	}
}

void	try_move_right(t_data *data)
{
	t_vf2d	new_pos;
	t_map	*map;

	map = data->map;
	new_pos = data->player_pos;
	new_pos.x += 1;
	if ((float)(int)new_pos.x == new_pos.x)
		;// border
	if (!is_in_wall(new_pos, map->grid))
	{
		data->player_pos = new_pos;
	}
}
