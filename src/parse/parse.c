/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:31 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 15:30:06 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_bool	map_invalid(t_map *map, char *line)
{
	//free (status) + liste chainer aussi
(void)map;
(void)line;
exit(EXIT_FAILURE);
}

static t_bool	is_color_texture_or_empty(char *line)
{
	size_t i;

	i = -1;
	while (line[++i] == ' ')
		;
	if (line[i] == '\0')		//si on n'accepte pas les ligne avec que des espace
		return (TRUE);			//mettre cette condition avant de passer les espaces
	if (ft_strncmp(&line[i], "NO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "SO", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "WE", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "EA", 2) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "F", 1) == 0)
		return (TRUE);
	if (ft_strncmp(&line[i], "C", 1) == 0)
		return (TRUE);
	return (FALSE);
}

/**
 * @note set the reading status to manage if map and other information is mixed
 * and exit if necessery
 */
static t_bool	is_a_map_line(char *line, t_reading_map_status *status, \
							t_map *map)
{
	if (is_color_texture_or_empty(line) == TRUE)
	{
		status->param_start = TRUE;
		if (status->param_is_end == TRUE)
			return (map_invalid(map, line));
		if (status->map_start)
			status->map_is_end = TRUE;
		return (FALSE);
	}
	else
	{
		status->map_start = TRUE;
		if (status->map_is_end == TRUE)
			return (map_invalid(map, line));
		if (status->param_start)
			status->param_is_end = TRUE;
		status->map_start = TRUE;
		return (TRUE);
	}
}

static void	set_x_and_y_max(int fd, t_map *map)
{
	char					*line;
	t_reading_map_status	*status;

	status = ft_calloc(1, sizeof(status));
	line = get_next_line(fd);
	map->x_max = ft_strlen(line) - 2;
	while (line)
	{
		if (is_a_map_line(line, status, map))
			;
			//creer une liste chainer avec les lignes
		if (map->x_max < ft_strlen(line) - 2)
			map->x_max = ft_strlen(line) - 2;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	--(map->y_max);
	free(status);
}

static void	creat_and_fill_map(char *map_name, t_map *map)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		free(map);
		exit_with_msg("Map not open", EXIT_FAILURE);
	}
	set_x_and_y_max(fd, map);			//recupere la liste chainer + changer le nom de la fonciton
	if (close(fd))
	{
		free(map);
		exit_with_msg("Map refuses to close", EXIT_FAILURE);
	}
	//dup chaque element de lise pour avoir une map rectangle 
	//					-> completer par des espaces ' ' les lignes plus courtes;
}

void	parse_map(char *map_name, t_map *map)
{

	creat_and_fill_map(map_name, map);
	//check_map(map)
}
