/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:03:58 by vgarcia           #+#    #+#             */
/*   Updated: 2025/03/25 15:29:35 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

static void	free_data(t_data *data);

void	exit_free_with_msg(char *comment, t_data *data, int code)
{
	if (data)
	{
		free_data(data);
	}
	exit_with_msg(comment, code);
}

void	exit_with_msg(char *comment, int code)
{
	putstr_fd("Error\n", 2);
	putstr_fd(comment, 2);
	putstr_fd("\n", 2);
	exit(code);
}

static void	free_data(t_data *data)
{
	if (data->map)
	{
		if (data->map->map)
		{
			free_double_array((void **)data->map->map);
		}
		free(data->map);
	}
}
