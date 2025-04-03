#include "cube.h"
#include "define.h"
#include "utils.h"

static t_bool	parse_texture(t_data *data, int i, char *texture);

void	filling_textures(char *line, t_data *data)
{
	char	tab[4][3];
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
			return (parse_texture(data, i, line));
		}
		++i;
	}
	return (FALSE);
}

static t_bool	parse_texture(t_data *data, int i, char *texture)
{
	data->images_name[i] = ft_strdup(texture);
	if (!data->images_name[i])
	{
		return (FALSE);
	}
	return (TRUE);
}

/*
fill_texture :
strncmp 3 chars, si dans tab && image_name == NULL

fill_color
*/
