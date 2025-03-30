#include "cube.h"
#include "define.h"

t_bool	parse_textures(int fd, t_data *data)
{
	t_bool	flag;
	char	*line;
	char	tab[6][3];
	int		i;

	ft_memcpy(tab[0], "NO", 3);
	ft_memcpy(tab[1], "SO", 3);
	ft_memcpy(tab[2], "WE", 3);
	ft_memcpy(tab[3], "EA", 3);
	ft_memcpy(tab[4], "F", 2);
	ft_memcpy(tab[5], "C", 2);
	i = 0;
	flag = TRUE;
	line = get_next_line(fd);
	if (!line)
		return (FALSE);
	while (flag && line && !ft_strncmp(tab[i], line, 2))
		flag = parse_line(line, data, tab[i++]);
	if (!flag || !line || line[0] != '\n')
		return (FALSE);
}

static t_bool	parse_line(char *line, t_data *data, char *symbol)
{
	if (ft_strncmp(line, symbol, 2))
		return (FALSE);
	
}
