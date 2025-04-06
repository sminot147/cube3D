#include "cube.h"
#include "utils.h"

static void	free_data(t_data *data);
static void	close_mlx(t_mlx_data *inf);

void	exit_free_with_msg(char *comment, t_data *data, int code)
{
	free_data(data);
	close_mlx(data->mlx_inf);
	if (data->mlx_inf)
		free(data->mlx_inf);
	exit_with_msg(comment, code);
}

void	exit_with_msg(char *comment, int code)
{
	if (code)
	{
		putstr_fd("Error\n", 2);
		putstr_fd(comment, 2);
		putstr_fd("\n", 2);
	}
	exit(code);
}

static void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		if (data->map->grid)
			free_double_array((void **)data->map->grid);
		free(data->map);
	}
	while (i < 4)
	{
		free(data->images_name[i]);
		if (data->face[i].img)
		{
			mlx_destroy_image(data->mlx_inf->mlx, data->face[i].img);
		}
		++i;
	}
}

static void	close_mlx(t_mlx_data *info)
{
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
}
