# Zgodnie z PDF, nazwa musi być cub3D
NAME = cub3D

# 42 preferuje użycie cc
CC = cc

# OBOWIĄZKOWE flagi 42 dodane na początek
CFLAGS = -Wall -Wextra -Werror -g -I includes -I includes/libft -fPIE -O3

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -lXext -lX11 -lm -lz -lbsd

OBJ_DIR = obj

SRCS = main.c \
src/map_checker.c \
src/utils.c \
src/data_init.c \
src/data_init_utils.c \
src/extract_colors_textures.c \
src/clean.c \
src/control.c \
src/map_convert.c \
src/error.c \
src/moves_and_rotations.c \
src/moves_utils.c \
src/render.c \
src/load_textures.c \
src/map_parsing.c \
src/textures_colors_utils.c \
src/dda.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# $(NAME) teraz jawnie zależy od bibliotek, co naprawia ewentualne problemy z linkowaniem
$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Reguły do budowy bibliotek
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then $(MAKE) -C $(MLX_DIR) clean; fi
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re