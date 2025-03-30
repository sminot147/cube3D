#include "cube.h"
#include "utils.h"

void	creat_map(t_lststr **lst_map, t_data *data)
{
	size_t	i;

	data->map->grid = ft_calloc(data->map->y_max + 2, sizeof(int *));
	if (data->map->grid == NULL)
		safe_exit_parse(data, lst_map, NULL, "Malloc Failed");
	i = -1;
	while (++i <= data->map->y_max)
	{
		data->map->grid[i] = ft_calloc(data->map->x_max + 1, sizeof(int));
		if (data->map->grid[i] == NULL)
			safe_exit_parse(data, lst_map, NULL, "Malloc Failed");
	}
}

static void	place_player(t_data *data, size_t x_pos, size_t y_pos, char c)
{
	data->player_pos.x = x_pos + 0.5;
	data->player_pos.y = y_pos + 0.5;
	if (c == 'N')
		data->view_angle = M_PI / 2;
	else if (c == 'E')
		data->view_angle = 0;
	else if (c == 'S')
		data->view_angle = - M_PI / 2;
	else if (c == 'W')
		data->view_angle = M_PI;
}

void	fill_map(t_lststr **lst_map, t_data *data)
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
				data->map->grid[i][j] = -1;
			else if (ft_strchr("NESW", current->content[j]) != 0)
			{
				place_player(data, j, i, current->content[j]);
				data->map->grid[i][j] = 0;
			}
			else if(ft_strchr("01", current->content[j]) != 0)
				data->map->grid[i][j] = current->content[j] - '0';
			else
				error_in_map(lst_map, data, current->content);
		}
		if (j <= data->map->x_max && --j)
			while (++j <= data->map->x_max)
				data->map->grid[i][j] = -1;
		current = current->next;
	}
}

void	parse_map(int fd, t_reading_map_status status, \
				t_lststr **lst_map, t_data *data)
{
	char	*line;

	line = get_next_line_without_nl(fd);
	while (line)
	{
		if (set_status_and_is_map(line, &status))
		{
			++(data->map->y_max);
			if (add_content_lst(lst_map, line) == FALSE)
			{
				close(fd);
				safe_exit_parse(data, lst_map, line, "Malloc failed");
			}
			if (data->map->x_max < ft_strlen(line) - 1)
				data->map->x_max = ft_strlen(line) - 1;
		}
		else if (status.map_is_valid == FALSE)
		{
			close(fd);
			safe_exit_parse(data, lst_map, line, "Map invalid");
		}
		line = get_next_line_without_nl(fd);
	}
	--(data->map->y_max);
}
