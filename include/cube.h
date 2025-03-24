/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:35:44 by sminot            #+#    #+#             */
/*   Updated: 2025/03/24 20:01:11 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "utils.h"

# include <fcntl.h>

typedef enum e_bool
{
	FALSE ,
	TRUE
}	t_bool;

typedef struct s_map
{
	unsigned long	x_max;
	unsigned long	y_max;
	char			**map;
}	t_map;

typedef struct s_data
{
	t_map	*map;
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

#endif