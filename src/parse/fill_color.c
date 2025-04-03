#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	parse_color(t_data *data, char *color_line);
static t_bool	set_color(char *line, size_t *color);
static int		count_char(char *str, char c);
static int		color_atoi(char *str);

t_bool	fill_colors(char *line, t_data *data)
{
	char	tab[2][3];
	int		i;

	i = 0;
	ft_memcpy(tab[0], "F ", 3);
	ft_memcpy(tab[1], "C ", 3);
	while (i < 2)
	{
		if (!ft_strncmp(tab[i], line, 2))
		{
			return (parse_color(data, line));
		}
		++i;
	}
	return (FALSE);
}

static t_bool	parse_color(t_data *data, char *color_line)
{
	t_map	*map;
	size_t	i;

	i = 0;
	map = data->map;
	while (color_line[i] && !ft_isdigit(color_line[i]))
		++i;
	if (count_char(color_line, ',') != 2)
		return (FALSE);
	else if (*color_line == 'F' && !map->floor_color)
	{
		return (set_color(&color_line[i], &map->floor_color));
	}
	else if (*color_line == 'C' && !map->ceiling_color)
	{
		return (set_color(&color_line[i], &map->ceiling_color));
	}
	return (FALSE);
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
