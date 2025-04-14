/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:38 by sminot            #+#    #+#             */
/*   Updated: 2025/04/14 13:05:20 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <unistd.h>

typedef enum e_bool
{
	FALSE ,
	TRUE
}	t_bool;

typedef enum e_direction
{
	NORTH ,
	SOUTH ,
	WEST ,
	EAST
}	t_direction;

typedef struct s_map
{
	size_t	ceiling_color;
	size_t	floor_color;
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

typedef struct s_vi2d
{
	int	x;
	int	y;
}	t_vi2d;

typedef struct s_vf2d
{
	float	x;
	float	y;
}	t_vf2d;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		endian;
	int		size_line;
}	t_img;

typedef struct s_mlx_inf
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
	char		*images_name[4];
	float		view_angle;
	int			minimap_size;
	t_vi2d		mouse_pos;
	t_vf2d		player_pos;
	t_img		face[4];
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
	t_bool	map_is_valid;
}	t_reading_map_status;

#endif
