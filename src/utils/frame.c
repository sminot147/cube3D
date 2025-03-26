#include "cube.h"
#include <sys/time.h>

static time_t	get_time_ms(void);

int	wait_fps(void)
{
	static time_t	last_frame_time;
	time_t			current_time;

	current_time = get_time_ms();
	if (current_time - last_frame_time < 20)
		return (1);
	last_frame_time = current_time;
	return (0);
}

static time_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
