#include "cube.h"

t_vi2d	sub_vi2d(t_vi2d position, t_vi2d to_sub)
{
	t_vi2d	result;

	result.x = position.x - to_sub.x;
	result.y = position.y - to_sub.y;
	return (result);
}

t_vi2d	sum_vi2d(t_vi2d position, t_vi2d to_sum)
{
	t_vi2d	result;

	result.x = position.x + to_sum.x;
	result.y = position.y + to_sum.y;
	return (result);
}

t_vi2d	mul_vi2d(t_vi2d position, t_vi2d to_mul)
{
	t_vi2d	result;

	result.x = position.x * to_mul.x;
	result.y = position.y * to_mul.y;
	return (result);
}

t_bool	isequal_vi2d(t_vi2d point1, t_vi2d point2)
{
	if (point1.x == point2.x && point1.y == point2.y)
		return (TRUE);
	return (FALSE);
}
