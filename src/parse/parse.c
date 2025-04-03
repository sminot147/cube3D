#include "cube.h"
#include "utils.h"
#include "define.h"

/**
 * @brief Return the boolean that indicates if the line is a line of the map
 *  or a parameter.
 */
static t_bool	is_map_line(char *line)
{
	size_t	i;

	i = -1;
	while (line[++i] == ' ')
		;
	if (line[i] == '\0')
		return (FALSE);
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (FALSE);
	if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (FALSE);
	if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (FALSE);
	if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (FALSE);
	if (ft_strncmp(&line[i], "F", 1) == 0)
		return (FALSE);
	if (ft_strncmp(&line[i], "C", 1) == 0)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief set the reading status to manage if map and param are mixed
 * 
 * @return Return the boolean that indicates if the line is a line of the map
 *  or a parameter.
 */
static t_bool	set_status_and_is_map(char *line, t_reading_map_status *status)
{
	if (is_map_line(line) == TRUE)
	{
		status->map_start = TRUE;
		if (status->map_is_end == TRUE)
		{
			status->map_is_valid = FALSE;
			return (FALSE);
		}
		if (status->param_start == TRUE)
			status->param_is_end = TRUE;
		status->map_start = TRUE;
		return (TRUE);
	}
	else
	{
		status->param_start = TRUE;
		if (status->param_is_end == TRUE)
			status->map_is_valid = FALSE;
		if (status->map_start)
			status->map_is_end = TRUE;
		return (FALSE);
	}
}

/**
 * @brief Read the map, change texture if necesserary, stock all the map in 
 * lst_map, exit if map and param are mixed
 * 
 * @param fd file_descriptor of the map
 * 
 * @param lst_map stock all line of map in the linked list
 * 
 * @param data set in data->map : x_max and y_max
 */
static void	read_map(int fd, t_lststr **lst_map, t_data *data)
{
	char					*line;
	t_reading_map_status	status;

	ft_memset(&status, 0, sizeof(status));
	status.map_is_valid = TRUE;
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
		else
		{
			if (status.map_is_valid == FALSE)
			{
				close(fd);
				safe_exit_parse(data, lst_map, line, "Invalid Map");
			}
			if (!fill_textures(line, data) && !fill_colors(line, data))
			{
				close(fd);
				safe_exit_parse(data, lst_map, line, TEXTURE_ERR);
			}
			free(line);
		}
		line = get_next_line_without_nl(fd);
	}
	--(data->map->y_max);
}

void print_map(t_data *data) {
	t_map *m = data->map;

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

/**
 * @brief Call the different step of map parsing
 * 
 * @note The fonction exit if map is not valid or we have a problem 
 * during the parsind (open, malloc,etc failed) 
 */
void	parse_map(char *map_name, t_data *data)
{
	int			fd;
	t_lststr	*lst_map;

	fd = open(map_name, O_RDONLY);
	lst_map = NULL;
	if (fd == -1)
	{
		putstr_fd("Error\nMap not open\n", 2);
		safe_exit(data);
	}
	read_map(fd, &lst_map, data);
	if (close(fd))
		safe_exit_parse(data, &lst_map, NULL, "Map refuse to close");
	creat_and_fill_map(&lst_map, data);
	clear_lst_str(&lst_map);
	print_map(data);
	check_map_validity(data);
}
