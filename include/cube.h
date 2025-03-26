#ifndef CUBE_H
# define CUBE_H

# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "struct.h"

# include <math.h>
# include <fcntl.h>

# define WIN_X 1920
# define WIN_Y 1080

# define MINI_W 1920
# define MINI_H 1080


void	parse_map(char *map_name, t_data *data);

/*---------------------------------------------------------------------------*/
/*                              fill_map.c                                   */
/*---------------------------------------------------------------------------*/

void	creat_and_fill_map(t_lststr **lst_map, t_data *data);
void	init_data(t_data *data);
void	render_view(t_data *data);


#endif
