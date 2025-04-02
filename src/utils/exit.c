#include "cube.h"
#include "utils.h"

void	safe_exit(t_data *data)
{
	if (data->map)
		free_double_array((void **)data->map->grid);
	free(data->map);
	exit(EXIT_FAILURE);
}

void	safe_exit_parse(t_data *data, t_lststr **lst_map, char *line, \
						char *error_message)
{
	int	i;

	i = -1;
	if (error_message)
	{
		putendl_fd("Error", 2);
		putendl_fd(error_message, 2);
	}
	while (++i < 4)
		free(data->images_name[i]);
	free(line);
	clear_lst_str(lst_map);
	safe_exit(data);
}
