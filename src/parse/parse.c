/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:00:31 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 19:02:40 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "utils.h"

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
static t_bool	is_a_map_line(char *line, t_reading_map_status *status)
{
	if (is_color_texture_or_empty(line) == TRUE)
	{
		status->param_start = TRUE;
		if (status->param_is_end == TRUE)
			status->map_is_valid = FALSE;
		if (status->map_start)
			status->map_is_end = TRUE;
		return (FALSE);
	}
	else
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
}

static void	set_x_and_y_max(int fd, t_lststr **lst_map, t_map *map, t_data *data)
{
	char					*line;
	t_reading_map_status	status;

	ft_memset(&status, 0, sizeof(status));
	status.map_is_valid = TRUE;
	line = get_next_line(fd);
	//map->x_max = ft_strlen(line) - 2;
	while (line)
	{
		if (is_a_map_line(line, &status))
		{
			if (add_content_lst(lst_map, line) == FALSE)
				safe_exit_parse(data, lst_map, line);
			if (map->x_max < ft_strlen(line) - 2)
				map->x_max = ft_strlen(line) - 2;
		}
		else
		{
			
			if (status.map_is_valid == FALSE)
				safe_exit_parse(data, lst_map, line);
			free(line);//faire la fonction qui change les textures + free la line
		}
		line = get_next_line(fd);
		static int i;
		ft_printf("i = %i\n", ++i);
	}
	--(map->y_max);
}

static void	creat_and_fill_map(char *map_name, t_map *map, t_data *data)
{
	int			fd;
	t_lststr	*lst_map;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		putstr_fd("Error\nMap not open\n", 2);
		free(map);
		exit(EXIT_FAILURE);
	}
	lst_map = NULL;
	set_x_and_y_max(fd, &lst_map, map, data);			//recupere la liste chainer + changer le nom de la fonciton
	if (close(fd))
	{
		putstr_fd("Error\nMap refuse to close\n", 2);
		free(map);
		exit(EXIT_FAILURE);
	}
	safe_exit_parse(data, &lst_map, NULL);
	//dup chaque element de lise pour avoir une map rectangle 
	//					-> completer par des espaces ' ' les lignes plus courtes;
}

void	parse_map(char *map_name, t_map *map, t_data *data)
{

	creat_and_fill_map(map_name, map, data);
	//check_map(map)
}
