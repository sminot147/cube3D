#include "cube.h"

t_bool	isequal_vi2d(t_vi2d point1, t_vi2d point2)
{
	if (point1.x == point2.x && point1.y == point2.y)
		return (TRUE);
	return (FALSE);
}

size_t	ft_max(size_t a, size_t b)
{
	if (a > b)
		return (a);
	return (b);
}

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}
