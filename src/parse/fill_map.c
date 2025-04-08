/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 12:10:28 by sminot            #+#    #+#             */
/*   Updated: 2025/04/08 12:10:36 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "utils.h"

/**
 * @brief Allocate the necessary memory
 * 
 * @note exit if allocation failed
 */
static void	creat_map(t_lststr **lst_map, t_data *data)
{
	size_t	i;

	data->map->grid = ft_calloc(data->map->y_max + 2, sizeof(int *));
	if (data->map->grid == NULL)
		safe_exit_parse(data, lst_map, "Malloc Failed");
	i = -1;
	while (++i <= data->map->y_max)
	{
		data->map->grid[i] = ft_calloc(data->map->x_max + 1, sizeof(int));
		if (data->map->grid[i] == NULL)
			safe_exit_parse(data, lst_map, "Malloc Failed");
	}
}

/**
 * @brief place the player in the middle of the case
 * 
 * @note exit if the player is already place somewhere
 */
static t_bool	place_player(t_data *data, size_t x_pos, size_t y_pos, char c)
{
	if (data->player_pos.x != 0)
	{
		putstr_fd("Error\nInvalid map: two or more starting positions", 2);
		putstr_fd(" for the player\n", 2);
		return (TRUE);
	}
	data->player_pos.x = x_pos + 0.5;
	data->player_pos.y = y_pos + 0.5;
	if (c == 'N')
		data->view_angle = M_PI / 2;
	else if (c == 'E')
		data->view_angle = 0;
	else if (c == 'S')
		data->view_angle = -M_PI / 2;
	else if (c == 'W')
		data->view_angle = M_PI;
	return (FALSE);
}

/**
 * @brief fill one line of the map and test each charactere
 * 
 * @note exit if one charactere is not valide
 */
static void	treat_one_line(t_lststr *line, t_data *data, size_t i, \
							t_lststr **lst_map)
{
	size_t		j;

	j = -1;
	while (line->content[++j])
	{
		if (line->content[j] == ' ')
			data->map->grid[i][j] = -1;
		else if (ft_strchr("NESW", line->content[j]) != 0)
		{
			if (place_player(data, j, i, line->content[j]))
				safe_exit_parse(data, lst_map, NULL);
			data->map->grid[i][j] = 0;
		}
		else if (ft_strchr("01", line->content[j]) != 0)
			data->map->grid[i][j] = line->content[j] - '0';
		else
		{
			putstr_fd("Error\nInvalide line on map file : ", 2);
			putendl_fd(line->content, 2);
			safe_exit_parse(data, lst_map, NULL);
		}
	}
	if (j <= data->map->x_max && --j)
		while (++j <= data->map->x_max)
			data->map->grid[i][j] = -1;
}

/**
 * @brief creat and fill map
 * 
 * @note this fonction can exit
 */
void	creat_and_fill_map(t_lststr **lst_map, t_data *data)
{
	size_t		i;
	t_lststr	*current;

	creat_map(lst_map, data);
	current = *lst_map;
	i = -1;
	while (++i <= data->map->y_max)
	{
		treat_one_line(current, data, i, lst_map);
		current = current->next;
	}
}
