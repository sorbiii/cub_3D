NAME        = cub_3d

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -g -I includes -I includes/libft -g

LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a

MLX_DIR     = minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a
MLX_FLAGS   = -lXext -lX11

SRC_DIR     = src
SRC_FILES   = main.c src/map_checker.c src/utils.c
OBJ_FILES   = $(SRC_FILES:.c=.o)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(MLX_LIB) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJ_FILES)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
