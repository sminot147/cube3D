#ifndef STRUCT_H
# define STRUCT_H

#include <unistd.h>

typedef enum e_bool
{
	FALSE ,
	TRUE
}	t_bool;

typedef enum e_direction
{
	NORTH ,
	EAST ,
	SOUTH ,
	WEST
}	t_direction;

typedef struct s_map
{
	int ceiling_color;
	int floor_color;
	size_t	x_max;
	size_t	y_max;
	int		**grid;
}	t_map;

typedef struct s_end_ray
{
	float		x;
	float		y;
	float		dist;
	t_direction	wall;
}	t_end_ray;

typedef	struct s_vi2d
{
	int x;
	int y;
}	t_vi2d;

typedef	struct s_vf2d
{
	float x;
	float y;
}	t_vf2d;

typedef struct	s_mlx_inf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		endian;
	int		size_line;
}	t_mlx_data;

typedef struct s_data
{
	int			tile_size;
	int			key[7];
	float		view_angle;
	int			minimap_size;
	t_vi2d		mouse_pos;
	t_vf2d		player_pos;
	t_map		*map;
	t_mlx_data	*mlx_inf;
}	t_data;

/*---------------------------------------------------------------------------*/
/*                               lst_str.c                                   */
/*---------------------------------------------------------------------------*/

typedef struct s_lst_str
{
	char				*content;
	struct s_lst_str	*next;
}	t_lststr;

/*---------------------------------------------------------------------------*/
/*                                parse.c                                    */
/*---------------------------------------------------------------------------*/

typedef struct s_reading_map_status
{
	t_bool	map_start;
	t_bool	map_is_end;
	t_bool	param_start;
	t_bool	param_is_end;
	t_bool	map_is_valid;
}	t_reading_map_status;

#endif
