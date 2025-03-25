#include "cube.h"

void	load_map(t_data *data)
{
	t_map	*map;
	int		tile_size;

	map = data->map;
	tile_size = MINI_W / 64; // replace 64 par x_max
	draw_cube(data->inf, (t_vec2d){0, 0}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){0, 1}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){0, 2}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){0, 3}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){5, 5}, tile_size, 0xFF0000);
	draw_cube(data->inf, (t_vec2d){10, 10}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){10, 11}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){10, 12}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){10, 13}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){20, 14}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){20, 15}, tile_size, 0xFFFFFF);
	draw_cube(data->inf, (t_vec2d){30, 5}, tile_size, 0xFFFFFF);
}
