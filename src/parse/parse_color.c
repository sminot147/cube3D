#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	set_color(char *line, size_t *color);
static int		count_char(char *str, char c);
static int		color_atoi(char *str);

void	parse_color(int fd, t_data *data)
{
	char	*line;

	line = get_next_line_without_nl(fd);
	if (!line || ft_strncmp(line, "F ", 2) || count_char(line, ',') != 2 \
		|| !set_color(line + 2, &data->map->floor_color))
	{
		close(fd);
		safe_exit_parse(data, NULL, line, "Something wrong in color parsing");
	}
	free(line);
	line = get_next_line_without_nl(fd);
	if (!line || ft_strncmp(line, "C ", 2) || count_char(line, ',') != 2 \
		|| !set_color(line + 2, &data->map->ceiling_color))
	{
		close(fd);
		safe_exit_parse(data, NULL, line, "Something wrong in color parsing");
	}
	free(line);
}

static t_bool	set_color(char *line, size_t *color)
{
	char	**char_colors;
	int		rgb[3];
	int		i;

	char_colors = ft_split(line, ',');
	if (!char_colors)
		return (FALSE);
	i = -1;
	while (++i < 3 && char_colors[i])
	{
		rgb[i] = color_atoi(char_colors[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			free_double_array((void **)char_colors);
			return (FALSE);
		}
	}
	if (i != 3 || char_colors[i])
	{
		free_double_array((void **)char_colors);
		return (FALSE);
	}
	*color = rgba_to_hexa(rgb[0], rgb[1], rgb[2], 0);
	free_double_array((void **)char_colors);
	return (TRUE);
}

static int	count_char(char *str, char c)
{
	int	i;
	int	nb_char;

	i = 0;
	nb_char = 0;
	while (str[i])
	{
		if (str[i] == c)
			++nb_char;
		++i;
	}
	return (nb_char);
}

static int	color_atoi(char *str)
{
	int	i;
	int	sgn;
	int	nb;

	i = 0;
	sgn = 1;
	nb = 0;
	if (str[i] == '-')
	{
		sgn *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ('0' <= str[i] && str[i] <= '9' && nb < 100)
	{
		nb = 10 * nb + str[i] - '0';
		i++;
	}
	if (str[i])
		return (-1);
	return ((int)(sgn * nb));
}
