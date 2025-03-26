#include "cube.h"
#include "utils.h"

void	safe_exit(t_data *data)
{
	if (data->map)
		free_double_array((void **)data->map->map);
	free(data->map);
	exit(EXIT_FAILURE);
}

void	safe_exit_parse(t_data *data, t_lststr **lst_map, char *line, \
						char *error_message)
{
	if (error_message)
	{
		putendl_fd("Error", 2);
		putendl_fd(error_message, 2);
	}
	free(line);
	clear_lst_str(lst_map);
	safe_exit(data);
}
