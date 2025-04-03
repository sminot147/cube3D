#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	parse_texture(t_data *data, int i, char *texture);

t_bool	fill_textures(char *line, t_data *data)
{
	char	tab[4][4];
	int		i;

	ft_memcpy(tab[0], "NO ", 4);
	ft_memcpy(tab[1], "SO ", 4);
	ft_memcpy(tab[2], "WE ", 4);
	ft_memcpy(tab[3], "EA ", 4);
	i = 0;
	while (i <= 3)
	{
		if (!ft_strncmp(tab[i], line, 3) && !data->images_name[i])
		{
			return (parse_texture(data, i, line + 3));
		}
		++i;
	}
	return (FALSE);
}

static t_bool	parse_texture(t_data *data, int index, char *texture)
{
	size_t	i;

	i = 0;
	while (texture[i] == ' ')
		++i;
	data->images_name[index] = ft_strdup(&texture[i]);
	if (!data->images_name[i])
	{
		return (FALSE);
	}
	return (TRUE);
}
