/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminot <simeon.minot@outlook.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:32:30 by sminot            #+#    #+#             */
/*   Updated: 2025/03/25 19:00:29 by sminot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "utils.h"

void	safe_exit(t_data *data)
{
	free(data->map);
	exit(EXIT_FAILURE);
}

void	safe_exit_parse(t_data *data, t_lststr **lst_map, char *line)
{
	free(line);
	clear_lst_str(lst_map);
	safe_exit(data);
}
