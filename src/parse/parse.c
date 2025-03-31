#include "cube.h"
#include "utils.h"

/**
 * @brief Return the boolean that indicates if the line is a line of the map
 *  or a parameter.
 */
static t_bool	is_map_line(char *line)
{
	size_t i;

	i = -1;
	while (line[++i] == ' ')
		;
	if (line[i] == '\0')		//si on n'accepte pas les ligne avec que des espace
		return (FALSE);			//mettre cette condition avant de passer les espaces
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
t_bool	set_status_and_is_map(char *line, t_parsing_status *status)
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

void print_structure(const t_parsing_status *s) {
    ft_printf("\tmap_start: %s\n", s->map_start ? "TRUE" : "FALSE");
    ft_printf("\tmap_is_end: %s\n", s->map_is_end ? "TRUE" : "FALSE");
    ft_printf("\tparam_start: %s\n", s->param_start ? "TRUE" : "FALSE");
    ft_printf("\tparam_is_end: %s\n", s->param_is_end ? "TRUE" : "FALSE");//enlever tout la fonction
    ft_printf("\tmap_is_valid: %s\n", s->map_is_valid ? "TRUE" : "FALSE");
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
static void	read_file(int fd, t_lststr **lst_map, t_data *data)
{
	t_parsing_status	status;

	ft_memset(&status, 0, sizeof(status));
	status.map_is_valid = TRUE;
	if (!parse_textures(fd, data))
		exit_free_with_msg("File is not conform to the .cub norm", data, 1);
	parse_map(fd, status, lst_map, data);
}

/*
parse_map check gnl = NULL a faire
*/
void	parse_file(char *map_name, t_data *data)
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
	read_file(fd, &lst_map, data);
	if (close(fd))
		safe_exit_parse(data, &lst_map, NULL, "Map refuse to close");
	creat_map(&lst_map, data);
	fill_map(&lst_map, data);
	clear_lst_str(&lst_map);
	//check map
	// safe_exit(data);
	//dup chaque element de lise pour avoir une map rectangle 
	//					-> completer par des espaces ' ' les lignes plus courtes;
}

/*
Changer toute les exit avec free_data fonction
*/
