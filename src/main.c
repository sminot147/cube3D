#include "cube.h"
#include "utils.h"

static void	check_arg(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	data;

	check_arg(ac, av);
	ft_memset((void *)&data, 0, sizeof(data));
	data.map = ft_calloc(1, sizeof(t_map));
	if (!data.map)
	{
		exit_with_msg("Allocation", 1);
	}
	parse_map(av[1], &data);
	init_data(&data);
	render_view(&data);
	process_input(&data);
	return (1);
}

static void	check_arg(int ac, char **av)
{
	int	i;

	if (ac != 2)
	{
		exit_with_msg("Wrong number of argument", EXIT_FAILURE);
	}
	i = ft_strlen(av[1]) - 4;
	if (i < 0 || ft_memcmp(av[1] + i, ".cub", 4))
	{
		exit_with_msg("Map is not a .cub", EXIT_FAILURE);
	}
}
