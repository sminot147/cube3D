/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:35:44 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 22:25:54 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"


# include <fcntl.h>

typedef enum e_bool
{
	FALSE ,
	TRUE
}	t_bool;

typedef struct s_map
{
	size_t	x_max;
	size_t	y_max;
	int		**map;
}	t_map;

typedef struct s_data
{
	t_map	*map;
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
	t_bool	param_start;
	t_bool	param_is_end;
	t_bool	map_is_valid;
}	t_reading_map_status;

void	parse_map(char *map_name, t_data *data);

/*---------------------------------------------------------------------------*/
/*                              fill_map.c                                   */
/*---------------------------------------------------------------------------*/

void	creat_and_fill_map(t_lststr **lst_map, t_data *data);


#endif