#include "utils.h"
#include "struct.h"
#include "cube.h"

static t_bool	line_above_is_valide(t_data *data, size_t i, size_t j)
{
	if (i == 0)
		return (TRUE);
	if (j != 0 && data->map->grid[i - 1][j - 1] == 0)
		return (FALSE);
	if (data->map->grid[i - 1][j] == 0)
		return (FALSE);
	if (j != data->map->x_max && data->map->grid[i - 1][j + 1] == 0)
		return (FALSE);
	return (TRUE);
}

static t_bool	line_below_is_valide(t_data *data, size_t i, size_t j)
{
	if (i == data->map->y_max)
		return (TRUE);
	if (j != 0 && data->map->grid[i + 1][j - 1] == 0)
		return (FALSE);
	if (data->map->grid[i + 1][j] == 0)
		return (FALSE);
	if (j != data->map->x_max && data->map->grid[i + 1][j + 1] == 0)
		return (FALSE);
	return (TRUE);
}

static t_bool	this_line_is_valide(t_data *data, size_t i, size_t j)
{
	if (j != 0 && data->map->grid[i][j - 1] == 0)
		return (FALSE);
	if (j != data->map->x_max && data->map->grid[i][j + 1] == 0)
		return (FALSE);
	return (TRUE);
}

static void	look_first_char(t_data *data)
{
	size_t	i;
	size_t	max;

	max = data->map->x_max;
	i = -1;

	while (++i <= data->map->y_max)
	{
		if (data->map->grid[i][0] != 1 && data->map->grid[i][0] != -1)
			safe_exit_parse(data, NULL, NULL, "Map not close");
		if (data->map->grid[i][max] != 1 && data->map->grid[i][max] != -1)
			safe_exit_parse(data, NULL, NULL, "Map not close");
	}
	max = data->map->y_max;
	i = -1;
	while (++i <= data->map->x_max)
	{
		if (data->map->grid[0][i] != 1 && data->map->grid[0][i] != -1)
			safe_exit_parse(data, NULL, NULL, "Map not close");
		if (data->map->grid[max][i] != 1 && data->map->grid[max][i] != -1)
			safe_exit_parse(data, NULL, NULL, "Map not close");
	}
}

void	check_map_validity(t_data *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	look_first_char(data);
	while (++i <= data->map->y_max)
	{
		j = -1;
		while (++j <= data->map->x_max)
		{
			if (data->map->grid[i][j] == -1)
			{
				if (line_above_is_valide(data, i, j) == FALSE)
					safe_exit_parse(data, NULL, NULL, "Map not close");
				if (this_line_is_valide(data, i, j) == FALSE)
					safe_exit_parse(data, NULL, NULL, "Map not close");
				if (line_below_is_valide(data, i, j) == FALSE)
					safe_exit_parse(data, NULL, NULL, "Map not close");
			}
		}
	}
}
