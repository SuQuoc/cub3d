NAME = cub3D

C = cc
CFLAGS = -g -Wall -Werror -Wextra

INCLUDES = ./includes

SRCS =	2d_array_utils.c \
		2d_array_utils2.c \
		array_utils.c \
		check_extension.c \
		colors.c \
		dda_algorithm_functions.c \
		dda_algorithm_utils.c \
		dda_algorithm.c \
		dfs.c \
		draw_map_scaled_utils.c \
		draw_map_scaled.c \
		error_msg.c \
		free_utils.c \
		get_ray_angles.c \
		hooks.c \
		identifier_utils.c \
		pxl_to_image.c \
		init_structs.c \
		init_structs2.c \
		key_input.c \
		lazy_wall_collision.c \
		loop_file.c \
		loop_idf.c \
		loop_map.c \
		main.c \
		map_check_utils.c \
		parsing_utils.c \
		player_movement.c \
		player_rays.c \
		player_rotation.c \
		prelim_checks.c \
		printing_utils.c \
		textures.c \
		vector_operations.c \
# NEEDS A FIX ONLY CHECKS IF objects_and_dependencies/2d_array_utils.o is up to date
SRC_DIR = ./srcs/
SRCS := $(addprefix $(SRC_DIR), $(SRCS))

OBJ_DIR = ./objects_and_dependencies/
OBJFILES = $(notdir $(SRCS:.c=.o))
OBJS = $(addprefix $(OBJ_DIR), $(OBJFILES))

DEPS := $(OBJS:.o=.d)


.PHONY: clean fclean all

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(C) $(CFLAGS) -MMD -MP -I$(INCLUDES) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	$(C) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME) -lmlx -lXext -lX11 -lm $(LDFLAGS)

#malloc_test: $(OBJ_PATH) $(NAME)
#	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJ} -L./libft/ -l:libft.a -L. -lmallocator -lmlx -lXext -lX11 -lm

clean:
	@$(MAKE) -C libft fclean
	@rm -rf $(OBJ_DIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all

run: $(NAME)
	./$(NAME) maps/fiona_raycasting_test_map4.cub

val: $(NAME)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	./$(NAME) maps/fiona_raycasting_test_map4.cub

-include $(DEPS)