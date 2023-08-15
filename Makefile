NAME = cub3D

C = cc
CFLAGS = -g -Wall -Werror -Wextra

SRC =	_player.c \
		check_extension.c \
		draw_line_utils.c \
		draw_line.c \
		error_msg.c \
		free_utils.c \
		init_structs.c \
		loop_file.c \
		main.c \
		printing_utils.c

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
	valgrind ./$(NAME) maps/subject_map.cub