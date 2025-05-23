/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:09:32 by sminot            #+#    #+#             */
/*   Updated: 2025/04/08 12:18:16 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "struct.h"

# include <math.h>
# include <stdio.h>
# include <fcntl.h>

/*****************************************************************************/
/*                                Parsing                                    */
/*****************************************************************************/
void		parse_map(char *map_name, t_data *data);
void		creat_and_fill_map(t_lststr **lst_map, t_data *data);
void		check_map_validity(t_data *data);

void		init_data(t_data *data);
void		render_view(t_data *data);
t_bool		fill_textures(char *line, t_data *data);
t_bool		fill_colors(char *line, t_data *data);

/* ************************************************************************** */
/*								PROCESS										  */
/* ************************************************************************** */

void		process_input(t_data *data);
t_bool		try_move(t_data *data, float angle);
int			mouse_move(int x, int y, void *param);
void		arrow_angle_update(t_data *data, int left, int right);
int			update_action(void *param);

/* ************************************************************************** */
/*								RENDER	           							  */
/* ************************************************************************** */

void		draw2d_line(t_mlx_data *inf, int ts, t_vf2d point1, t_vf2d point2);
void		draw2d_map(int ts, t_map *map, t_mlx_data *inf);
void		draw2d_camera(t_mlx_data *inf, t_data *data, int ts);

/*****************************************************************************/
/*                            ray_casting.c                                  */
/*****************************************************************************/

float		calc_dist(t_vf2d point1, t_vf2d point2);
t_bool		is_int(float nb);
t_bool		is_wall(t_vf2d *point, t_data *data);
t_end_ray	end_ray_vertical(t_data *data, float angle);
void		trace_ray_casting(t_data *data);

void		render_ray3d(float ray_index, t_end_ray *ray, t_data *data);
void		render_surface(int screen_midpoint_y, t_data *data);
int			get_image_xposition(t_end_ray *ray);
void		draw_texture(t_end_ray *ray, int x_coords[2], \
				int y_edge[2], t_data *data);
#endif
