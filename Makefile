# **************************************************************************** #
#                                    CONFIG                                    #
# **************************************************************************** #

NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= include
LIBFT_DIR	:= libs/libft
MLX_DIR		:= libs/mlx

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS		:= \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/parser/parser.c \
			$(SRC_DIR)/parser/parser_map.c \
			$(SRC_DIR)/parser/parser_retrieve_map.c \
			$(SRC_DIR)/parser/parser_validate_map.c \
			$(SRC_DIR)/parser/parser_textures.c \
			$(SRC_DIR)/parser/parser_utils.c \
			$(SRC_DIR)/parser/parser_destroy.c \
			$(SRC_DIR)/utils/error.c

OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                  LIBRARIES                                   #
# **************************************************************************** #

LIBFT		:= $(LIBFT_DIR)/libft.a
MLX_LIB		:= $(MLX_DIR)/libmlx_Linux.a

INCLUDES	:= -I$(INC_DIR) -I$(LIBFT_DIR)/includes -I$(MLX_DIR)
LDFLAGS		:= -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS		:= -lft -lmlx -lXext -lX11 -lm

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(NAME)
	@echo "$(NAME) built successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null 2>&1
	@echo "Object files cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
