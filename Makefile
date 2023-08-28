NAME = cub3D

C = cc
CFLAGS = -g -Wall -Werror -Wextra

SRC =	2d_array_utils.c \
		2d_array_utils2.c \
		array_utils.c \
		check_extension.c \
		colors.c \
		dda_algorithm_utils.c \
		dda_algorithm.c \
		dfs.c \
		draw_line_utils.c \
		draw_line.c \
		draw_map.c \
		error_msg.c \
		free_utils.c \
		ft_strcmp.c \
		hooks.c \
		identifier_utils.c \
		init_structs.c \
		key_input.c \
		loop_file.c \
		loop_idf.c \
		loop_map.c \
		main.c \
		map_check_utils.c \
		parsing_utils.c \
		player_movement.c \
		player_rotation.c \
		player.c \
		prelim_checks.c \
		printing_utils.c \
		textures.c \
		vector_operations.c \

OBJDIR = ./objects_and_dependencies/
OBJFILES = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJDIR), $(OBJFILES))

DEP = cubed.h

.PHONY: clean fclean all

all: $(NAME)

$(OBJDIR)%.o: ./%.c $(DEP)
	$(C) $(CFLAGS) -MMD -MP $< -o $@ -c

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@$(MAKE) -C libft
	$(C) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME) -lmlx -lXext -lX11 -lm

clean:
	@$(MAKE) -C libft fclean
	@rm -rf $(OBJDIR)
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME)
	@echo
	@echo ...and the $(NAME) too

re: fclean all

run: $(NAME)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	./$(NAME) maps/fiona_raycasting_test_map.cub