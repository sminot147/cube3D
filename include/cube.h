#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "struct.h"

# include <math.h>
# include <fcntl.h>

void	parse_map(char *map_name, t_data *data);

/*---------------------------------------------------------------------------*/
/*                              fill_map.c                                   */
/*---------------------------------------------------------------------------*/

void	creat_and_fill_map(t_lststr **lst_map, t_data *data);
void	init_data(t_data *data);
void	render_view(t_data *data);

/* ************************************************************************** */
/*								PROCESS										  */
/* ************************************************************************** */

void	process_input(t_data *data);

/*		MOVE		*/
void	try_move(t_data *data, float angle);

/*		MOUSE		*/
int	mouse_move(int x, int y, void *param);

/* ************************************************************************** */
/*								RENDER	           							  */
/* ************************************************************************** */

void	draw2d_map(int ts, t_map *map, t_mlx_data *inf);
void	draw2d_camera(t_map *map, t_mlx_data *inf, t_data *data, int ts);

void	set_pixel(t_mlx_data *inf, int x, int y, int color);
void	draw_square(t_mlx_data *inf, t_vi2d position, int tile_size, int color);
void	draw_circle(t_mlx_data *inf, t_vf2d position, int diam, int color);
void    draw_line(t_mlx_data *inf, t_vf2d point1, t_vf2d point2, int color);

#endif
