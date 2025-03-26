#include "struct.h"

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

void	try_move_front(t_data *data)
{
	t_vf2d	test_pos;
	t_map	*map;

	map = data->map;
	test_pos = data->player_pos;
	test_pos.y -= 0.1;
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos.y = test_pos.y;
	}
}

void	try_move_left(t_data *data)
{
	t_vf2d	test_pos;
	t_map	*map;

	test_pos = data->player_pos;
	test_pos.x -= 0.1;
	map = data->map;
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos.x = test_pos.x;
	}
}

void	try_move_back(t_data *data)
{
	t_vf2d	test_pos;
	t_map	*map;

	map = data->map;
	test_pos = data->player_pos;
	test_pos.y += 0.1;
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos.y = test_pos.y;
	}
}

void	try_move_right(t_data *data)
{
	t_vf2d	test_pos;
	t_map	*map;

	map = data->map;
	test_pos = data->player_pos;
	test_pos.x += 0.1;
	if (!is_in_wall(test_pos, map->grid))
	{
		data->player_pos.x = test_pos.x;
	}
}
