#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	parse_texture(char **texture, t_data *data, int fd, int i);
static t_bool	parse_color(int fd, t_data *data);
static void		set_texture(char *line, t_data *data, unsigned int *color);

t_bool	parse_textures(int fd, t_data *data)
{
	t_bool	flag;
	char	*line;
	char	tab[4][3];
	int		i;

	ft_memcpy(tab[0], "NO ", 4);
	ft_memcpy(tab[1], "SO ", 4);
	ft_memcpy(tab[2], "WE ", 4);
	ft_memcpy(tab[3], "EA ", 4);
	i = 0;
	flag = TRUE;
	line = get_next_line_without_nl(fd);
	if (!line)
		return (FALSE);
	while (i <= 3 && flag && !ft_strncmp(tab[i], line, 3))
	{
		flag = parse_texture(&line, data, fd, i);
		++i;
	}
	if (i < 4 || !flag || !line)
		return (FALSE);
	free(line);
	flag = parse_color(fd, data);
	return (flag);
}

static t_bool	parse_texture(char **texture, t_data *data, int fd, int i)
{
	data->wall_textures[i] = *texture;
	*texture = get_next_line_without_nl(fd);
	if (!*texture)
	{
		return (FALSE);
	}
	return (TRUE);
}

static t_bool	parse_color(int fd, t_data *data)
{
	char	*line;

	line = get_next_line_without_nl(fd);
	if (!line)
		exit_free_with_msg("Allocation", data , 1);
	if (ft_strncmp(line, "F ", 2))
	{
		free(line);
		return (FALSE);	
	}
	set_texture(line + 2, data, &data->map->floor_color);
	free(line);
	line = get_next_line_without_nl(fd);
	if (!line)
		exit_free_with_msg("Allocation", data , 1);
	if (ft_strncmp(line, "C ", 2))
	{
		free(line);
		return (FALSE);	
	}
	set_texture(line + 2, data, &data->map->ceiling_color);
	free(line);
	return (TRUE);
}

static void	set_texture(char *line, t_data *data, unsigned int *color)
{
	char	**char_colors;
	int		rgb[3];
	int		i;

	char_colors = ft_split(line, ',');
	if (!char_colors)
		exit_free_with_msg("Alloc", data , 1);
	i = 0;
	while (i < 3 && char_colors[i])
	{
		rgb[i] = ft_atoi(char_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
			exit_free_with_msg("Something wrong in colors", data , 1);
		++i;
	}
	if (i != 3 || char_colors[i])
		exit_free_with_msg("Something wrong in colors", data , 1);
	*color = rgba_to_hexa(rgb[0], rgb[1], rgb[2], 0);
	free_double_array((void **)char_colors);
}
//parsecolor leak
