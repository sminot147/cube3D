/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:35:44 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 15:04:28by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "utils.h"

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

typedef enum e_cardinal
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_cardinal;

typedef struct s_map
{
	unsigned long	x_max;
	unsigned long	y_max;
	char			**map;
}	t_map;

typedef	struct s_vec2d
{
	int x;
	int y;
}	t_vec2d;

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
	t_cardinal	orientation;
	t_vec2d		player_pos;
	t_mlx_data	*inf;
}	t_data;

/*---------------------------------------------------------------------------*/
/*                            parse.c                                        */
/*---------------------------------------------------------------------------*/
typedef struct s_reading_map_status
{
	t_bool	map_start;
	t_bool	map_is_end;
	t_bool	param_start;
	t_bool	param_is_end;
}	t_reading_map_status;

void	parse_map(char *map_name, t_map *map);

void	init_data(t_map *map, t_data *data);

void	render_view(t_data *data);

#endif
