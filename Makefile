NAME = cub_3d

CC = gcc
CFLAGS = -g -I includes -I includes/libft -fPIE

LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11

OBJ_DIR = obj

SRCS = main.c \
src/map_checker.c \
src/utils.c \
src/data_init.c \
src/data_init_utils.c \
src/extract_colors_textures.c \
src/clean.c \
src/control.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
