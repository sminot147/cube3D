#include "cube.h"
#include "utils.h"
#include "define.h"

static void 	init_allocs(t_data *data);
static void 	init_vars(t_data *data);
static t_bool	init_mlx(t_mlx_data *mlx_inf);
static void		load_imgs(t_data *data, t_img img[4], char *img_name[4]);

/**
 * @brief Centralize all initialization
 * @param t_data contains every informations of te program
 */
void	init_data(t_data *data)
{
	init_allocs(data);
	init_vars(data);
}

/**
 * @brief Allocate data pointers
 * @param t_data contains every informations of te program
 */
static void init_allocs(t_data *data)
{	
	data->mlx_inf = malloc(sizeof(t_mlx_data));
	if (!data->mlx_inf)
	{
		exit_free_with_msg("Allocation", data, 1);
	}
	if (!init_mlx(data->mlx_inf))
	{
		exit_free_with_msg("Allocation", data, 1);
	}
	load_imgs(data, data->face, data->images_name);	
}


/**
 * @brief Initialize all the mlx informations
 * @param t_mlx_data contains every informations for the mlx library
 */
static t_bool	init_mlx(t_mlx_data *mlx_inf)
{
	mlx_inf->mlx = mlx_init();
	if (mlx_inf->mlx == NULL)
	{
		return (0);
	}
	mlx_inf->win = mlx_new_window(mlx_inf->mlx, WIDTH, HEIGHT, "cub3D");
	if (mlx_inf->win == NULL)
	{
		mlx_destroy_display(mlx_inf->mlx);
		free(mlx_inf->mlx);
		return (0);
	}
	mlx_inf->img = mlx_new_image(mlx_inf->mlx, WIDTH, HEIGHT);
	if (mlx_inf->img == NULL)
	{
		mlx_destroy_window(mlx_inf->mlx, mlx_inf->win);
		mlx_destroy_display(mlx_inf->mlx), free(mlx_inf->mlx);
		return (0);
	}
	mlx_inf->data = mlx_get_data_addr(mlx_inf->img, &mlx_inf->bpp, \
							&mlx_inf->size_line, &mlx_inf->endian);
	mlx_mouse_hide(mlx_inf->mlx, mlx_inf->win);
	return (1);
}

static void	load_imgs(t_data *data, t_img face[4], char *img_name[4])
{
	char		*name;
	int			size;
	int			i;
	t_mlx_data	*info;

	i = -1;
	size = 64;
	info = data->mlx_inf->mlx;
	while (++i < 4)
	{
		name = img_name[i] + 3;
		face[i].img = mlx_xpm_file_to_image(info, name, &size, &size);
		if (!face[i].img)
			exit_free_with_msg("Something went wrong with textures", data, 1);
		face[i].addr = mlx_get_data_addr(face[i].img, &face[i].bpp, \
						&face[i].size_line, &face[i].endian);
	}
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data contains every informations of te program
 */
static void init_vars(t_data *data)
{
	data->tile_size = (WIDTH / 6) / (data->map->x_max + 1);
	data->mouse_pos.x = WIDTH * 0.5;
	data->mouse_pos.y = HEIGHT * 0.5;
	data->key[NORTH] = 0;
	data->key[EAST] = 0;
	data->key[SOUTH] = 0;
	data->key[WEST] = 0;
	data->key[SPACE] = 0;
	data->key[LEFT_ARROW] = 0;
	data->key[RIGHT_ARROW] = 0;
}
