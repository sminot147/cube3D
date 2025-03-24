/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:35:44 by sminot            #+#    #+#             */
/*   Updated: 2025/03/24 18:39:48 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "utils.h"

# include <fcntl.h>

typedef struct s_map
{
	int		x_max;
	int		y_max;
	char	**map;
}	t_map;

typedef struct s_data
{
	t_map	*map;
}	t_data;

void	parse_map(char *map_name, t_map *map);

#endif