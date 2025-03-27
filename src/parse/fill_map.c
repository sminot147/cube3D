#include "cube.h"
#include "utils.h"

static void	creat_map(t_lststr **lst_map, t_data *data)
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

static void	error_in_map(t_lststr **lst_map, t_data *data, char *line_error)
{
	putstr_fd("Error\nInvalide line on map file :", 2);
	putstr_fd(line_error, 2);
	clear_lst_str(lst_map);
	safe_exit(data);
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


void	print_lststr(t_lststr *lst)
{
    while (lst) {
        ft_printf("%s\n", lst->content);
        lst = lst->next;	//delete
    }
}

char *direct(t_direction direction)
{
	if (direction == NORTH)
		return ("NORTH");
	if (direction == EAST)
		return ("EAST");
	if (direction == SOUTH)
		return ("SOUTH");
	if (direction == WEST)
		return ("WEST");
	return ("");
}

void print_map(t_data *data) {
	t_map *m = data->map;
	// ft_printf("player pos : x = %i et y = %i direction = %s\n", data->player_pos.x, data->player_pos.y, direct(data->player_dir));
    ft_printf("Map dimensions: %i x %i\n", m->x_max, m->y_max);
    for (size_t i = 0; i <= m->y_max; i++) {
        for (size_t j = 0; j <= m->x_max; j++) {
			if (m->grid[i][j] != -1)
         	   ft_printf("%d ", m->grid[i][j]);
			else
			 	ft_printf(". ");
        }
        ft_printf("\n");
    }
}

void	creat_and_fill_map(t_lststr **lst_map, t_data *data)
{
	//print_lststr(*lst_map);
	creat_map(lst_map, data);
	fill_map(lst_map, data);
	print_map(data);
	
}
