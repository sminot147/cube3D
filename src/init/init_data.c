#include "cube.h"

static void init_ptrs(t_data *data);
static void init_allocs(t_map *map, t_data *data);
static void init_vars(t_data *data);

void	init_data(t_map *map, t_data *data)
{
	init_ptrs(data);
	init_allocs(map, data);
	init_vars(data);
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data
 */
static void init_ptrs(t_data *data)
{	
	(void)data;
	data->inf = NULL;
}

static t_bool	temp_init(t_mlx_inf *inf);

/**
 * @brief Allocate data pointers
 * @param t_map, t_data
 */
static void init_allocs(t_map *map, t_data *data)
{	
	data->map = map;
	data->inf = malloc(sizeof(t_mlx_inf));
	if (!data->inf)
		exit_free_with_msg("Allocation", data, 1);
	//Allocs others;


	/*A changer test */
	if (temp_init(data->inf))
		exit_free_with_msg("Allocation", data, 1);
}

static t_bool	temp_init(t_mlx_inf *inf)
{
	inf->mlx = mlx_init();
	if (inf->mlx == NULL)
		return (-1);
	inf->win = mlx_new_window(inf->mlx, 1920, 1080, "test");
	if (inf->win == NULL)
		return (mlx_destroy_display(inf->mlx), free(inf->mlx), -1);
	inf->img = mlx_new_image(inf->mlx, 1920, 1080);
	if (inf->img == NULL)
		return (mlx_destroy_window(inf->mlx, inf->win),
			mlx_destroy_display(inf->mlx), free(inf->mlx), -1);
	inf->data = mlx_get_data_addr(inf->img, &inf->bpp, &inf->sl, &inf->endian);
	return (0);
}
////////////////////////////////




/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data
 */
static void init_vars(t_data *data)
{	
	(void)data;
}
