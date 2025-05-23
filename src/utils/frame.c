/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:57:31 by vgarcia           #+#    #+#             */
/*   Updated: 2025/05/06 13:57:32 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <sys/time.h>

static time_t	get_time_ms(void);

/**
 * @brief Check if the elapsed time is over 20 milliseconds
 */
int	wait_fps(void)
{
	static time_t	last_frame_time;
	time_t			current_time;

	current_time = get_time_ms();
	if (current_time - last_frame_time < 30)
	{
		return (1);
	}
	last_frame_time = current_time;
	return (0);
}

static time_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
