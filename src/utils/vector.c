#include "cube.h"

t_vi2d	sub_vec2d(t_vi2d position, t_vi2d to_sub)
{
	t_vi2d	result;

	result.x = position.x - to_sub.x;
	result.y = position.y - to_sub.y;
	return (result);
}

t_vi2d	sum_vec2d(t_vi2d position, t_vi2d to_sum)
{
	t_vi2d	result;

	result.x = position.x + to_sum.x;
	result.y = position.y + to_sum.y;
	return (result);
}

t_vi2d	mul_vec2d(t_vi2d position, t_vi2d to_mul)
{
	t_vi2d	result;

	result.x = position.x * to_mul.x;
	result.y = position.y * to_mul.y;
	return (result);
}
