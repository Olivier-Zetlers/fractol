NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./

SRC = src/arg_validation.c src/fractal_calculations.c src/keyboard_events.c src/mouse_events.c src/str_to_double.c \
      src/color_palette.c src/init_app.c src/main.c src/render_loop.c src/usage_message.c src/app_cleanup.c \
      src/keyboard_events2.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

LIBX_FLAGS = -Lminilibx-linux/ -lmlx -lX11 -lXext -lm -O3

all: $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBX_FLAGS) -o $(NAME)

bonus: $(MLX) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBX_FLAGS) -o $(NAME)

$(MLX):
	make -C $(MLX_PATH)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)
	make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re

