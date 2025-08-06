#--------------------------------------------------------------------
#  Final executable
#--------------------------------------------------------------------

# Default goal
NAME		:= libft.a

#--------------------------------------------------------------------
#  Toolchain
#--------------------------------------------------------------------

# Compiler
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror

# Archiver
AR		:= ar
ARFLAGS		:= rcs

#--------------------------------------------------------------------
#  Project layout
#--------------------------------------------------------------------

# Sources & objects
SRC_DIR		:= src
SRC		:= $(strip $(SRC_DIR)/ft_atoi.c $(SRC_DIR)/ft_bzero.c $(SRC_DIR)/ft_calloc.c \
                  $(SRC_DIR)/ft_isalnum.c $(SRC_DIR)/ft_isalpha.c $(SRC_DIR)/ft_isascii.c $(SRC_DIR)/ft_isdigit.c \
                  $(SRC_DIR)/ft_isprint.c $(SRC_DIR)/ft_itoa.c $(SRC_DIR)/ft_memchr.c $(SRC_DIR)/ft_memcmp.c \
                  $(SRC_DIR)/ft_memcpy.c $(SRC_DIR)/ft_memmove.c $(SRC_DIR)/ft_memset.c $(SRC_DIR)/ft_putchar_fd.c \
                  $(SRC_DIR)/ft_putendl_fd.c $(SRC_DIR)/ft_putnbr_fd.c $(SRC_DIR)/ft_putstr_fd.c $(SRC_DIR)/ft_split.c \
                  $(SRC_DIR)/ft_strchr.c $(SRC_DIR)/ft_strdup.c $(SRC_DIR)/ft_striteri.c $(SRC_DIR)/ft_strjoin.c \
                  $(SRC_DIR)/ft_strlcat.c $(SRC_DIR)/ft_strlcpy.c $(SRC_DIR)/ft_strlen.c $(SRC_DIR)/ft_strmapi.c \
                  $(SRC_DIR)/ft_strncmp.c $(SRC_DIR)/ft_strnstr.c $(SRC_DIR)/ft_strrchr.c $(SRC_DIR)/ft_strtrim.c \
                  $(SRC_DIR)/ft_substr.c $(SRC_DIR)/ft_tolower.c $(SRC_DIR)/ft_toupper.c)
OBJ_DIR		:= obj
OBJ		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# Headers
HDR_DIR		:= inc
HDR		:= $(HDR_DIR)/libft.h

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


# Archive creation
$(NAME): $(OBJ) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

# Object compilation
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HDR) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Object file directory creation
$(OBJ_DIR):
	mkdir -p $@

# Clean rule
clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)

# fclean rule
fclean: clean
	$(RM) $(RMFLAGS) $(NAME) 

# re rule
re:
	$(MAKE) fclean
	$(MAKE) all

# Phony target declaration directive
.PHONY: all clean fclean re
