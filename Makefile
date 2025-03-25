# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/24 18:12:50 by sminot            #+#    #+#              #
#    Updated: 2025/03/25 15:29:14 by vgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC_FILE = main.c\

SRC_DIR = src/
PARSE_DIR = $(SRC_DIR)parse/
INIT_DIR = $(SRC_DIR)init/
RENDER_DIR = $(SRC_DIR)render/
UTILS_DIR = $(SRC_DIR)utils/
PROCESS_DIR = $(SRC_DIR)process/

PARSE = parse.c
INIT = init_data.c
RENDER = render_view.c
UTILS = free_double_array.c error.c
PROCESS = #init_data.c


FILE = $(addprefix $(SRC_DIR), $(SRC_FILE))\
	$(addprefix $(INIT_DIR), $(INIT))\
	$(addprefix $(PARSE_DIR), $(PARSE))\
	$(addprefix $(RENDER_DIR), $(RENDER))\
	$(addprefix $(PROCESS_DIR), $(PROCESS))\
	$(addprefix $(UTILS_DIR), $(UTILS))

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE) -MMD -g3
MLX_FLAGS = -L$(MLX_DIR) -lXext -lX11 -lm
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
