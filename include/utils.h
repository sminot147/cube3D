/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:26:32 by vgarcia           #+#    #+#             */
/*   Updated: 2025/04/08 12:26:33 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cube.h"

/*---------------------------------------------------------------------------*/
/*                                exit.c                                     */
/*---------------------------------------------------------------------------*/
void		safe_exit(t_data *data);
void		safe_exit_parse(t_data *data, t_lststr **lst_map, \
							char *error_message);

/*---------------------------------------------------------------------------*/
/*                               lst_str.c                                   */
/*---------------------------------------------------------------------------*/

t_bool		add_content_lst(t_lststr **lst_str, char *new_content);
void		clear_lst_str(t_lststr **lst_str);
size_t		len_lst(t_lststr **lst_str);

/*---------------------------------------------------------------------------*/
/*                        free_double_array                                  */
/*---------------------------------------------------------------------------*/

void		free_double_array(void **array);

/* ************************************************************************** */
/*									CLOSE									  */
/* ************************************************************************** */

void		exit_with_msg(char *comment, int code);
void		exit_free_with_msg(char *comment, t_data *data, int code);

/* ************************************************************************** */
/*									CALCUL									  */
/* ************************************************************************** */

t_bool		isequal_vi2d(t_vi2d point1, t_vi2d point2);
size_t		ft_max(size_t a, size_t b);
size_t		ft_min(size_t a, size_t b);

/* ************************************************************************** */
/*									TIME									  */
/* ************************************************************************** */

int			wait_fps(void);

/* ************************************************************************** */
/*									GEOMETRY								  */
/* ************************************************************************** */

void		set_pixel(t_mlx_data *inf, int x, int y, int color);
void		set_pixels(t_mlx_data *inf, int c, size_t n, char *address);
void		draw_square(t_mlx_data *inf, t_vi2d position, \
						int tile_size, int color);
void		draw_circle(t_mlx_data *inf, t_vf2d position, int diam, int color);
void		draw_line(t_mlx_data *inf, t_vf2d point1, t_vf2d point2, int color);

/* ************************************************************************** */
/*									COLOR									  */
/* ************************************************************************** */

size_t		rgba_to_hexa(int r, int g, int b, int a);

#endif
