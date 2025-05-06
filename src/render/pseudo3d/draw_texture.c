/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:57:10 by vgarcia           #+#    #+#             */
/*   Updated: 2025/05/06 13:57:48 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "define.h"
#include "cube.h"
#include "utils.h"

/**
 * @brief Calculates the x-coordinate position on the texture image
 * 
 * @param ray Pointer to the t_end_ray structure containing ray information.
 * @return int The x-coordinate position on the texture image.
 */
int	get_image_xposition(t_end_ray *ray)
{
	float	pose_in_axe;

	pose_in_axe = 0;
	if (ray->wall == EAST || ray->wall == WEST)
		pose_in_axe = ray->y;
	else if (ray->wall == NORTH || ray->wall == SOUTH)
		pose_in_axe = ray->x;
	pose_in_axe = (pose_in_axe - (int)pose_in_axe) * IMAGE_SIZE;
	return (pose_in_axe);
}

/**
 * @brief Draws a textured wall slice on the screen based on raycasting results.
 * 
 * @param ray Pointer to the t_end_ray structure containing ray information.
 * @param x_coords Array containing the screen's x and the texture's x-coords.
 * @param y_edge Array containing the top and bottom y-coords of the wall slice.
 * @param data Pointer to the t_data structure containing render informations.
 */
void	draw_texture(t_end_ray *ray, int x_coords[2], \
				int y_edge[2], t_data *data)
{
	int			y;
	int			color;
	int			pixel_addr;
	int			limiter;
	t_img		img;

	y = 0;
	limiter = y_edge[0] - y_edge[1];
	img = data->face[ray->wall];
	if (y_edge[1] < 0)
	{
		y = y_edge[1] * (-1);
		limiter -= y;
	}
	while (y < limiter)
	{
		pixel_addr = y * IMAGE_SIZE / (y_edge[0] - y_edge[1]);
		color = *(int *)(img.addr + \
				(pixel_addr * img.size_line + x_coords[1] * (img.bpp / 8)));
		set_pixel(data->mlx_inf, x_coords[0], y + y_edge[1], color);
		++y;
	}
}
