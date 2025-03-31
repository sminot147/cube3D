#include "cube.h"
#include "utils.h"

static void	check_arg(int ac, char **av);

int	main(int ac, char **av)
{
	t_data	data;

	check_arg(ac, av);
	init_data(&data);
	parse_file(av[1], &data);
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
