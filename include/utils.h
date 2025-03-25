/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:34:07 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 22:00:32 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_data		t_data;
typedef struct s_mlx_inf	t_mlx_data;
typedef	struct s_vec2d		t_vec2d;

/*---------------------------------------------------------------------------*/
/*                        free_double_array                                  */
/*---------------------------------------------------------------------------*/

void	free_double_array(void **array);


/* ************************************************************************** */
/*									ERROR									  */
/* ************************************************************************** */

void	exit_free_with_msg(char *comment, t_data *data, int code);
void	exit_with_msg(char *comment, int code);

/* ************************************************************************** */
/*								RENDER_TOOLS								  */
/* ************************************************************************** */

void	set_pixel(t_mlx_data *inf, int x, int y, int color);
void	draw_cube(t_mlx_data *inf, t_vec2d position, int tile_size, int color);


void	load_map(t_data *data);
#endif
