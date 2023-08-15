NAME = cub3D

C = cc
CFLAGS = -g -Wall -Werror -Wextra

SRC =	check_extension.c \
		draw_line_utils.c \
		draw_line.c \
		error_msg.c \
		ft_strcmp.c \
		free_utils.c \
		init_structs.c \
		loop_file.c \
		loop_idf.c \
		textures.c \
		colors.c \
		main.c \
		parsing_utils.c \
		printing_utils.c \
		2d_array_utils.c

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
	./$(NAME) maps/testmap.cub