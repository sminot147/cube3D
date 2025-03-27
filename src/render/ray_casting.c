/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:31:06 by sminot            #+#    #+#             */
/*   Updated: 2025/03/27 14:05:50 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_end_ray	set_pos_to_end_ray(t_map *map, t_vf2d pos_player, float angle)
{
	t_end_ray	end_ray_h;
	t_end_ray	end_ray_v;

	return (end_ray_h = end_ray_horizontal(map, pos_player, angle));
	//end_ray_v = en_ray_vertical(map, pos_player, angle);
	// if (end_ray_h.dist < end_ray_v.dist)
	// 	return (end_ray_h);
	// return(end_ray_v);
}
