#ifndef DEFINE_H
# define DEFINE_H

#include <X11/keysym.h>
#include <X11/X.h>
#include <math.h>

# define RED 0xFF0000
# define WHITE 0xFFFFFF
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define SKY_BLUE 0x77B5FE
# define GRASS_GREEN 0x207125

# define SPACE 4
# define LEFT_ARROW 5
# define RIGHT_ARROW 6

# define WIDTH 1280
# define HEIGHT 960

# define HALF_WIDTH WIDTH * 0.5
# define HALF_HEIGHT HEIGHT * 0.5

# define FIELD_OF_VIEW 90
# define NB_RAY 180

# define RADIANT_MAX M_PI * 2

#endif
