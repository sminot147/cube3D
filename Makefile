NAME = cub3D

SRC_DIR = src/
SRC_FILE = main.c\

PARSE_DIR = $(SRC_DIR)parse/
PARSE = parse.c\
		fill_map.c

INIT_DIR = $(SRC_DIR)init/
INIT = init.c


RENDER_DIR = $(SRC_DIR)render/
RENDER = render_view.c\
		draw2d.c\
		geometry.c\
		ray_casting.c\
		ray_casting_vertical.c\

PSEUDO_DIR = $(RENDER_DIR)pseudo3d/
PSEUDO = render3d.c

UTILS_DIR = $(SRC_DIR)utils/
UTILS = free_double_array.c\
		error.c\
		exit.c\
		liste_str.c\
		vector.c\
		frame.c

PROCESS_DIR = $(SRC_DIR)process/
PROCESS = input.c\
		move.c\
		mouse.c

FILE = $(addprefix $(SRC_DIR), $(SRC_FILE))\
	$(addprefix $(INIT_DIR), $(INIT))\
	$(addprefix $(PARSE_DIR), $(PARSE))\
	$(addprefix $(RENDER_DIR), $(RENDER))\
	$(addprefix $(PSEUDO_DIR), $(PSEUDO))\
	$(addprefix $(PROCESS_DIR), $(PROCESS))\
	$(addprefix $(UTILS_DIR), $(UTILS))

CC = cc
CFLAGS = -Wall -Wextra  -I$(INCLUDE) -MMD -g3
MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_DIR) -lXext -lX11 -lm
INCLUDE = include

OBJ_DIR = .obj/

OBJ = $(addprefix $(OBJ_DIR), $(FILE:.c=.o))

DEPS =  $(addprefix $(OBJ_DIR), $(FILE:.c=.d))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

$(OBJ_DIR)%.o : %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(LIBFT) : force
	$(MAKE) -C $(LIBFT_DIR)

$(MLX) : force
	$(MAKE) -C $(MLX_DIR)

$(NAME) : $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME) $(LIBFT) $(MLX)

clean :
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean 
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

force :

re : fclean all

-include $(DEPS)

.PHONY: all clean fclean re force
