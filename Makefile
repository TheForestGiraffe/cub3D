# **************************************************************************** #
#                                    CONFIG                                    #
# **************************************************************************** #

NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g

# **************************************************************************** #
#                                 DIRECTORIES                                  #
# **************************************************************************** #

SRC_DIR			:= src
OBJ_DIR			:= obj
INC_DIR			:= include
LIBFT_DIR		:= libs/libft
MLX_DIR			:= libs/mlx
MLX_WRAPPER_DIR := src/mlx_wrapper

# **************************************************************************** #
#                                   SOURCES                                    #
# **************************************************************************** #

SRCS		:= \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/game/game_destroy.c \
			$(SRC_DIR)/game/game_loop.c \
			$(SRC_DIR)/game/game_setup.c \
			$(SRC_DIR)/game/game_setup_load_model.c \
			$(SRC_DIR)/game/game_setup_load_player.c \
			$(SRC_DIR)/mlx_wrapper/mlx_destroy.c \
			$(SRC_DIR)/mlx_wrapper/mlx_events.c \
			$(SRC_DIR)/mlx_wrapper/mlx_register_hooks.c \
			$(SRC_DIR)/mlx_wrapper/mlx_setup.c \
			$(SRC_DIR)/parser/parser.c \
			$(SRC_DIR)/parser/parser_map.c \
			$(SRC_DIR)/parser/parser_retrieve_grid.c \
			$(SRC_DIR)/parser/parser_validate_grid.c \
			$(SRC_DIR)/parser/parser_textures.c \
			$(SRC_DIR)/parser/parser_utils.c \
			$(SRC_DIR)/parser/parser_destroy.c \
			$(SRC_DIR)/raycaster/cast_rays.c \
			$(SRC_DIR)/raycaster/calc_hit_point.c \
			$(SRC_DIR)/raycaster/calc_perp_wall_dist.c \
			$(SRC_DIR)/raycaster/calc_wall_height.c \
			$(SRC_DIR)/raycaster/calc_wall_x.c \
			$(SRC_DIR)/raycaster/perform_dda.c \
			$(SRC_DIR)/raycaster/ray_init.c \
			$(SRC_DIR)/raycaster/set_wall_dir.c \
			$(SRC_DIR)/renderer/draw_minimap.c \
			$(SRC_DIR)/renderer/draw_square.c \
			$(SRC_DIR)/renderer/put_pixel.c \
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
	@rm -f $(NAME) $(TEST_PARSER_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "$(NAME) removed."

re: fclean all

# **************************************************************************** #
#                                    TEST NORM                                 #
# **************************************************************************** #

test_norm:
	norminette -R CheckForbiddenHeaderSource \
	$(SRC_DIR) $(INC_DIR) $(LIBFT_DIR)

# **************************************************************************** #
#                                    TEST PARSER                               #
# **************************************************************************** #

TEST_PARSER_NAME	:= test_parser
TEST_PARSER_DIR	:= test
TEST_PARSER_SRCS	:= \
			$(SRC_DIR)/parser/parser.c \
			$(SRC_DIR)/parser/parser_map.c \
			$(SRC_DIR)/parser/parser_retrieve_grid.c \
			$(SRC_DIR)/parser/parser_validate_grid.c \
			$(SRC_DIR)/parser/parser_textures.c \
			$(SRC_DIR)/parser/parser_utils.c \
			$(SRC_DIR)/parser/parser_destroy.c \
			$(SRC_DIR)/utils/error.c \
			$(SRC_DIR)/test/test_init.c \
			$(SRC_DIR)/test/test_printer.c \
			$(SRC_DIR)/test/test.c
TEST_OBJS	:= $(TEST_PARSER_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/$(TEST_PARSER_DIR)/%.o: $(TEST_PARSER_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -I$(TEST_PARSER_DIR) -c $< -o $@

$(TEST_PARSER_NAME): $(LIBFT) $(TEST_OBJS)
	@$(CC) $(CFLAGS) $(TEST_OBJS) -L$(LIBFT_DIR) -lft -o $(TEST_PARSER_NAME)
	@echo "$(TEST_PARSER_NAME) built successfully!"
	@./$(TEST_PARSER_NAME)	

.PHONY: all clean fclean re test
