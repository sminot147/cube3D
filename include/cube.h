#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

# include <math.h>
# include <fcntl.h>

# define WIN_X 1920
# define WIN_Y 1080

# define MINI_W 1920
# define MINI_H 1080

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
	size_t	x_max;
	size_t	y_max;
	int		**map;
}	t_map;

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
	int		size_len;
}	t_mlx_data;

typedef struct s_data
{
	t_map		*map;
	t_vf2d		player_pos;
	t_direction	player_dir;
	t_mlx_data	*inf;
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

void	parse_map(char *map_name, t_data *data);

/*---------------------------------------------------------------------------*/
/*                              fill_map.c                                   */
/*---------------------------------------------------------------------------*/

void	creat_and_fill_map(t_lststr **lst_map, t_data *data);
void	init_data(t_data *data);
void	render_view(t_data *data);


#endif
