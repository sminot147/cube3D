#include "define.h"

unsigned int rgba_to_hexa(int r, int g, int b, int a)
{
	return ((r << 24) + (g << 16) + (b << 8) + a);
}
