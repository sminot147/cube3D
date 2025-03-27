#include "cube.h"
#include "utils.h"
#include "define.h"

static void 	init_ptrs(t_data *data);
static void 	init_allocs(t_data *data);
static void 	init_vars(t_data *data);
static t_bool	init_mlx(t_mlx_data *mlx_inf);

/**
 * @brief Centralize all initialization
 * @param t_data
 */
void	init_data(t_data *data)
{
	init_ptrs(data);
	init_allocs(data);
	init_vars(data);
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data
 */
static void init_ptrs(t_data *data)
{	
	data->mlx_inf = NULL;
}

/**
 * @brief Allocate data pointers
 * @param t_data
 */
static void init_allocs(t_data *data)
{	
	data->mlx_inf = malloc(sizeof(t_mlx_data));
	if (!data->mlx_inf)
		exit_free_with_msg("Allocation", data, 1);
	if (!init_mlx(data->mlx_inf))
		exit_free_with_msg("Allocation", data, 1);
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data
 */
static void init_vars(t_data *data)
{	
	data->tile_size = MINI_W / (data->map->x_max + 1);
	data->mouse_pos.x = WIDTH * 0.5;
	data->mouse_pos.y = HEIGHT * 0.5;
	data->key[NORTH] = 0;
	data->key[EAST] = 0;
	data->key[SOUTH] = 0;
	data->key[WEST] = 0;
}

/**
 * @brief Initialize all the mlx informations
 * @param t_mlx_data
 */
static t_bool	init_mlx(t_mlx_data *mlx_inf)
{
	mlx_inf->mlx = mlx_init();
	if (mlx_inf->mlx == NULL)
	{
		return (0);
	}
	mlx_inf->win = mlx_new_window(mlx_inf->mlx, 1920, 1080, "test");
	if (mlx_inf->win == NULL)
	{
		mlx_destroy_display(mlx_inf->mlx);
		free(mlx_inf->mlx);
		return (0);
	}
	mlx_inf->img = mlx_new_image(mlx_inf->mlx, 1920, 1080);
	if (mlx_inf->img == NULL)
	{
		mlx_destroy_window(mlx_inf->mlx, mlx_inf->win);
		mlx_destroy_display(mlx_inf->mlx), free(mlx_inf->mlx);
		return (0);
	}
	mlx_inf->data = mlx_get_data_addr(mlx_inf->img, &mlx_inf->bpp, \
							&mlx_inf->size_len, &mlx_inf->endian);
	mlx_mouse_hide(mlx_inf->mlx, mlx_inf->win);
	return (1);
}
