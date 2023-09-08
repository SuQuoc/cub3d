NAME = tester

DEP = unit_tests.h ../cubed.h

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

C_SRC =	framework.c \
		test_main.c \
		../2d_array_utils.c \
		../2d_array_utils2.c \
		../array_utils.c \
		../check_extension.c \
		../colors.c \
		../dda_algorithm_utils.c \
		../dda_algorithm.c \
		../dfs.c \
		../draw_line_utils.c \
		../draw_line.c \
		../draw_map.c \
		../draw_map_scaled.c \
		../error_msg.c \
		../free_utils.c \
		../ft_strcmp.c \
		../hooks.c \
		../identifier_utils.c \
		../pxl_to_image.c \
		../init_structs.c \
		../key_input.c \
		../loop_file.c \
		../loop_idf.c \
		../loop_map.c \
		../map_check_utils.c \
		../parsing_utils.c \
		../player_movement.c \
		../player_rotation.c \
		../player.c \
		../prelim_checks.c \
		../printing_utils.c \
		../textures.c \
		../vector_operations.c \

C_OBJFILES = $(C_SRC:.c=.o)
C_OBJ = $(addprefix $(OBJDIR), $(C_OBJFILES))

OBJDIR = ./obj_and_dep/

.PHONY: clean fclean all tests

all: $(NAME)

$(OBJDIR)%.o: ./%.c $(DEP)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(C_OBJ)
	@$(MAKE) -C ../libft
	$(CC) $(CFLAGS) $(C_OBJ) ../libft/libft.a -o $(NAME) -lmlx -lXext -lX11 -lm
	./$(NAME)

clean:
	@$(MAKE) -C ../libft fclean
	@rm -rf $(OBJDIR) *.o *.d
	@echo all .o and .d files deleted

fclean: clean
	@rm -f $(NAME) my_output/*.txt
	@echo
	@echo ...and the $(NAME) and the my_output-files too

re: fclean all

run: $(NAME)
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	./$(NAME)