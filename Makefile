#--------------------------------------------------------------------
#  Final executable
#--------------------------------------------------------------------

# Default goal
NAME		:= fractol

#--------------------------------------------------------------------
#  Toolchain
#--------------------------------------------------------------------

# Preprocessor
CPPFLAGS	= -I$(HDR_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)/$(LIBFT_HDR_DIR)

# Compiler
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror					# -fsanitize=address,undefined

#--------------------------------------------------------------------
#  Linking
#--------------------------------------------------------------------

# Linker
LDFLAGS		:= -Lminilibx-linux -Llibft 
LDLIBS		:= -lft -lmlx -lX11 -lXext -lm

#--------------------------------------------------------------------
#  Project layout
#--------------------------------------------------------------------

# Sources & objects
SRC_DIR		:= src
SRC		:= $(strip $(SRC_DIR)/app_cleanup.c $(SRC_DIR)/arg_validation.c $(SRC_DIR)/color_palette.c \
                  $(SRC_DIR)/fractal_calculations.c $(SRC_DIR)/init_app.c $(SRC_DIR)/keyboard_events.c $(SRC_DIR)/keyboard_events2.c \
                  $(SRC_DIR)/main.c $(SRC_DIR)/mouse_events.c $(SRC_DIR)/render_loop.c $(SRC_DIR)/str_to_double.c \
                  $(SRC_DIR)/usage_message.c)
OBJ_DIR		:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Headers
HDR_DIR		:= inc
HDR		:= $(HDR_DIR)/fractol.h

# External library 1 (minilibx)
MLX_DIR		:= minilibx-linux
MLX		:= $(MLX_DIR)/libmlx.a

# External library 2 (libft)
LIBFT_DIR	:= libft
LIBFT_HDR_DIR	:= inc
LIBFT		:= $(LIBFT_DIR)/libft.a
LIBFT_HDR	:= $(LIBFT_DIR)/$(LIBFT_HDR_DIR)/libft.h

#--------------------------------------------------------------------
#  File remover
#--------------------------------------------------------------------

# Removal command
RM		:= rm
RMFLAGS		:= -fr

#--------------------------------------------------------------------
#  Rules
#--------------------------------------------------------------------

# Default goal set as phony target "all"
all: $(NAME)

# Program linking
$(NAME): $(OBJ) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@

# External libraries building
$(MLX): 
	-@chmod +x $(MLX_DIR)/configure
	$(MAKE) -C $(MLX_DIR) 

$(LIBFT): $(LIBFT_HDR)
	$(MAKE) -C $(LIBFT_DIR) 

# Object compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# Object file directory creation
$(OBJ_DIR):
	mkdir -p $@

# Clean rule
clean:
	$(MAKE) -C $(LIBFT_DIR) clean 
	$(MAKE) -C $(MLX_DIR)  clean 
	$(RM) $(RMFLAGS) $(OBJ_DIR)

# fclean rule
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean                # fclean inexistent in MLX makefile
	$(RM) $(RMFLAGS) $(NAME) 

# re rule
re:
	$(MAKE) fclean
	$(MAKE) all

# Phony target declaration directive
.PHONY: all clean fclean re
