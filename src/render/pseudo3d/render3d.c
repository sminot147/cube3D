/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:12:03 by sminot            #+#    #+#             */
/*   Updated: 2025/04/08 12:12:05 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "cube.h"
#include "utils.h"

void	render_ray3d(float ray_index, t_end_ray *ray, t_data *data)
{
	int	x_coords[2];
	int	wall_edge[2];
	int	half_wall_height;

	ray_index = FIELD_OF_VIEW - (ray_index + FIELD_OF_VIEW * 0.5);
	half_wall_height = HEIGHT / ray->dist;
	wall_edge[0] = HEIGHT * 0.5 + half_wall_height;
	wall_edge[1] = HEIGHT * 0.5 - half_wall_height;
	x_coords[0] = (ray_index * (WIDTH / FIELD_OF_VIEW + 1));
	x_coords[1] = get_image_xposition(ray);
	draw_texture(ray, x_coords, wall_edge, data);
}

void	render_surface(int screen_midpoint_y, t_data *data)
{
	int		color;
	int		size_line;
	char	*addr;

	addr = data->mlx_inf->data;
	size_line = data->mlx_inf->size_line;
	color = data->map->ceiling_color;
	set_pixels(data->mlx_inf, color, \
		size_line * screen_midpoint_y, addr);
	color = data->map->floor_color;
	set_pixels(data->mlx_inf, color, \
		size_line * screen_midpoint_y, addr + size_line * screen_midpoint_y);
}
