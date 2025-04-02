#include "cube.h"
#include "define.h"
#include "utils.h"

static void	parse_texture(char **texture, t_data *data, int fd, int i);

void	parse_textures(int fd, t_data *data)
{
	char	*line;
	char	tab[4][3];
	int		i;

	ft_memcpy(tab[0], "NO ", 4);
	ft_memcpy(tab[1], "SO ", 4);
	ft_memcpy(tab[2], "WE ", 4);
	ft_memcpy(tab[3], "EA ", 4);
	i = 0;
	line = get_next_line_without_nl(fd);
	if (!line)
	{
		close(fd);
		safe_exit_parse(data, NULL, NULL, "Allocation");
	}
	while (i <= 3 && !ft_strncmp(tab[i], line, 3))
		parse_texture(&line, data, fd, i++);
	free(line);
	if (i < 4)
	{
		close(fd);
		safe_exit_parse(data, NULL, NULL, "Wrong texture format");
	}
	parse_color(fd, data);
}

static void	parse_texture(char **texture, t_data *data, int fd, int i)
{
	data->images_name[i] = *texture;
	*texture = get_next_line_without_nl(fd);
	if (!*texture)
	{
		close(fd);
		safe_exit_parse(data, NULL, NULL, "Allocation");
	}
}
