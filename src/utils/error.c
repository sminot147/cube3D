#include "cube.h"
#include "utils.h"

static void	free_data(t_data *data);
static void close_mlx(t_mlx_data *inf);

void	exit_free_with_msg(char *comment, t_data *data, int code)
{
	close_mlx(data->mlx_inf);
	free_data(data);
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
	if (data->map)
	{
		if (data->map->grid)
			free_double_array((void **)data->map->grid);
	}
	free(data->map);
	free(data->mlx_inf);
	free(data->wall_textures[0]);
	free(data->wall_textures[1]);
	free(data->wall_textures[2]);
	free(data->wall_textures[3]);
}

static void close_mlx(t_mlx_data *info)
{
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->win);
	mlx_destroy_display(info->mlx);
	free(info->mlx);
}

void	error_in_map(t_lststr **lst_map, t_data *data, char *line_error)
{
	putstr_fd("Error\nInvalide line on map file :", 2);
	putstr_fd(line_error, 2);
	clear_lst_str(lst_map);
	safe_exit(data);
}
