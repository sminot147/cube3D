#include "cube.h"
#include "utils.h"
#include "define.h"

static void	draw2d_grid(t_mlx_data *inf, int ts, t_map *map);

/**
 * @brief Draws the 2D representation of the map.
 * 
 * @param ts Tile size in pixels.
 * @param map Pointer to the map structure containing the grid and dimensions.
 * @param inf Pointer to the MLX data structure for rendering.
 */
void	draw2d_map(int ts, t_map *map, t_mlx_data *inf)
{
	size_t	cur_x;
	size_t	cur_y;
	int		**grid;

	cur_y = 0;
	grid = map->grid;
	while (cur_y <= map->y_max)
	{
		cur_x = 0;
		while (cur_x <= map->x_max)
		{
			if (grid[cur_y][cur_x] == 0)
			{
				draw_square(inf, (t_vi2d){cur_x, cur_y}, ts, WHITE);
			}
			else if (grid[cur_y][cur_x] == 1)
			{
				draw_square(inf, (t_vi2d){cur_x, cur_y}, ts, BLUE);
			}
			++cur_x;
		}
		++cur_y;
	}
	draw2d_grid(inf, ts, map);
}

/**
 * @brief Draws the 2D representation of the camera and player view.
 * 
 * @param map Pointer to the map structure.
 * @param inf Pointer to the MLX data structure for rendering.
 * @param data Pointer to the data structure
 * @param ts Tile size in pixels.
 */
void	draw2d_camera(t_map *map, t_mlx_data *inf, t_data *data, int ts)
{
	t_vf2d	angle_pos;

	angle_pos.x = data->player_pos.x  + cos(data->view_angle);
	angle_pos.y = data->player_pos.y - sin(data->view_angle);
	draw2d_line(inf, ts, angle_pos, data->player_pos);
	draw_circle(inf, data->player_pos, ts, GREEN);
	trace_ray_casting(data, inf, ts);
}

/**
 * @brief Draws the grid of the minimap.
 * 
 * @param inf Pointer to the MLX data structure for rendering.
 * @param ts Tile size in pixels.
 * @param map Pointer to the map structure containing the grid and dimensions.
 */
static void	draw2d_grid(t_mlx_data *inf, int ts, t_map *map)
{
	size_t	i;

	i = 0;
	while (i <= map->y_max + 1)
	{
		draw_line(inf, (t_vf2d){0, ts*i}, \
					(t_vf2d){(map->x_max+1) * ts, ts*i}, BLACK);
		++i;
	}
	i = 0;
	while (i <= map->x_max + 1)
	{
		draw_line(inf, (t_vf2d){ts*i, 0},
					(t_vf2d){ts*i, (map->y_max+1) * ts}, BLACK);
		++i;
	}
}

/**
 * @brief Draws and convert a line between two points in 2D space.
 * 
 * @param inf Pointer to the MLX data structure for rendering.
 * @param ts Tile size in pixels.
 * @param point1 The starting point of the line in grid coordinates.
 * @param point2 The ending point of the line in grid coordinates.
 */
void	draw2d_line(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2)
{
	t_vf2d	convert1;
	t_vf2d	convert2;

	convert1.x = point1.x * ts;
	convert1.y = point1.y * ts;
	convert2.x = point2.x * ts;
	convert2.y = point2.y * ts;
	draw_line(inf, convert1, convert2, RED);
}
