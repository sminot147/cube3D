#include "cube.h"
#include "utils.h"

static void 	init_ptrs(t_data *data);
static void 	init_allocs(t_data *data);
static void 	init_vars(t_data *data);
static t_bool	init_mlx(t_mlx_data *inf);

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
	data->inf = NULL;
}

/**
 * @brief Allocate data pointers
 * @param t_data
 */
static void init_allocs(t_data *data)
{	
	
	data->inf = malloc(sizeof(t_mlx_data));
	if (!data->inf)
		exit_free_with_msg("Allocation", data, 1);
	if (!init_mlx(data->inf))
		exit_free_with_msg("Allocation", data, 1);
	//Allocs others;
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data
 */
static void init_vars(t_data *data)
{	
	data->tile_size = MINI_W / (data->map->x_max + 1);
}

/**
 * @brief Initialize all the mlx informations
 * @param t_mlx_data
 */
static t_bool	init_mlx(t_mlx_data *inf)
{
	inf->mlx = mlx_init();
	if (inf->mlx == NULL)
	{
		return (0);
	}
	inf->win = mlx_new_window(inf->mlx, 1920, 1080, "test");
	if (inf->win == NULL)
	{
		mlx_destroy_display(inf->mlx);
		free(inf->mlx);
		return (0);
	}
	inf->img = mlx_new_image(inf->mlx, 1920, 1080);
	if (inf->img == NULL)
	{
		mlx_destroy_window(inf->mlx, inf->win);
		mlx_destroy_display(inf->mlx), free(inf->mlx);
		return (0);
	}
	inf->data = mlx_get_data_addr \
				(inf->img, &inf->bpp, &inf->size_len, &inf->endian);
	return (1);
}
