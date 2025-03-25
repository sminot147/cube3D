/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 20:54:04 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 22:43:58 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "utils.h"

static void	creat_map(t_lststr **lst_map, t_data *data)
{
	size_t	i;

	data->map->map = ft_calloc(data->map->y_max + 2, sizeof(int *));
	if (data->map->map == NULL)
		safe_exit_parse(data, lst_map, NULL, "Malloc Failed");
	i = -1;
	while (++i <= data->map->y_max)
	{
		data->map->map[i] = ft_calloc(data->map->x_max + 1, sizeof(int));
		if (data->map->map[i] == NULL)
			safe_exit_parse(data, lst_map, NULL, "Malloc Failed");
	}
}

static void	error_in_map(t_lststr **lst_map, t_data *data, char *line_error)
{
	putstr_fd("Error\nInvalide line on map file :", 2);
	putstr_fd(line_error, 2);
	clear_lst_str(lst_map);
	safe_exit(data);
}

static void	fill_map(t_lststr **lst_map, t_data *data)
{
	size_t		i;
	size_t		j;
	t_lststr	*current;

	current = *lst_map;
	i = -1;
	while (++i <= data->map->y_max)
	{
		j = -1;
		while (current->content[++j])
		{
		
			if (current->content[j] == ' ')
				data->map->map[i][j] = -1;
			else if (ft_strchr("NESW", current->content[j]) != 0)
			{
				//place_the_player;
				data->map->map[i][j] = 0;
			}
			else if(ft_strchr("01", current->content[j]) != 0)
				data->map->map[i][j] = current->content[j] - '0';
			else
				error_in_map(lst_map, data, current->content);
		}
		if (j <= data->map->x_max && --j)
			while (++j <= data->map->x_max)
				data->map->map[i][j] = -1;
		current = current->next;
	}
}


void	print_lststr(t_lststr *lst)
{
    while (lst) {
        ft_printf("%s\n", lst->content);
        lst = lst->next;	//delete
    }
}

void print_map(const t_map *m) {
    ft_printf("Map dimensions: %i x %i\n", m->x_max, m->y_max);
    for (size_t i = 0; i <= m->y_max; i++) {
        for (size_t j = 0; j <= m->x_max; j++) {
			if (m->map[i][j] != -1)
         	   ft_printf("%d ", m->map[i][j]);
			else
			 	ft_printf("  ", m->map[i][j]);
        }
        ft_printf("\n");
    }
}

void	creat_and_fill_map(t_lststr **lst_map, t_data *data)
{
	//print_lststr(*lst_map);
	creat_map(lst_map, data);
	fill_map(lst_map, data);
	print_map(data->map);
}
