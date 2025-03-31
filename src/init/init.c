#include "cube.h"
#include "utils.h"
#include "define.h"

static void 	init_ptrs(t_data *data);
static void 	init_allocs(t_data *data);
static void 	init_vars(t_data *data);
static t_bool	init_mlx(t_mlx_data *mlx_inf);

/**
 * @brief Centralize all initialization
 * @param t_data contains every informations of te program
 */
void	init_data(t_data *data)
{
	init_ptrs(data);
	init_allocs(data);
	init_vars(data);
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data contains every informations of te program
 */
static void init_ptrs(t_data *data)
{	
	data->mlx_inf = NULL;
	data->map = NULL;
	data->wall_textures[0] = NULL;
	data->wall_textures[1] = NULL;
	data->wall_textures[2] = NULL;
	data->wall_textures[3] = NULL;
}

/**
 * @brief Allocate data pointers
 * @param t_data contains every informations of te program
 */
static void init_allocs(t_data *data)
{
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
	{
		exit_with_msg("Allocation", 1);
	}
	data->mlx_inf = malloc(sizeof(t_mlx_data));
	if (!data->mlx_inf)
	{
		exit_free_with_msg("Allocation", data, 1);
	}
	if (!init_mlx(data->mlx_inf))
	{
		exit_free_with_msg("Allocation", data, 1);
	}
}

/**
 * @brief Set all the pointers to NULL, to set up the free function
 * @param t_data contains every informations of te program
 */
static void init_vars(t_data *data)
{
	data->tile_size = 0;
	data->mouse_pos.x = WIDTH * 0.5;
	data->mouse_pos.y = HEIGHT * 0.5;
	data->key[NORTH] = 0;
	data->key[EAST] = 0;
	data->key[SOUTH] = 0;
	data->key[WEST] = 0;
	data->key[SPACE] = 0;
	data->key[LEFT_ARROW] = 0;
	data->key[RIGHT_ARROW] = 0;
	data->map->ceiling_color = SKY_BLUE;
	data->map->floor_color = GRASS_GREEN;
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
		return (FALSE);
	}
	mlx_inf->win = mlx_new_window(mlx_inf->mlx, WIDTH, HEIGHT, "cub3D");
	if (mlx_inf->win == NULL)
	{
		mlx_destroy_display(mlx_inf->mlx);
		free(mlx_inf->mlx);
		return (FALSE);
	}
	mlx_inf->img = mlx_new_image(mlx_inf->mlx, WIDTH, HEIGHT);
	if (mlx_inf->img == NULL)
	{
		mlx_destroy_window(mlx_inf->mlx, mlx_inf->win);
		mlx_destroy_display(mlx_inf->mlx), free(mlx_inf->mlx);
		return (FALSE);
	}
	mlx_inf->data = mlx_get_data_addr(mlx_inf->img, &mlx_inf->bpp, \
							&mlx_inf->size_line, &mlx_inf->endian);
	mlx_mouse_hide(mlx_inf->mlx, mlx_inf->win);
	return (TRUE);
}
