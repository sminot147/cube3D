/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:26:29 by vgarcia           #+#    #+#             */
/*   Updated: 2025/04/08 12:26:30 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_bool	isequal_vi2d(t_vi2d point1, t_vi2d point2)
{
	if (point1.x == point2.x && point1.y == point2.y)
		return (TRUE);
	return (FALSE);
}

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
