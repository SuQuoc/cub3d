NAME = tester

DEP = unit_tests.h ../cubed.h

CC = cc
CFLAGS = -Wall

C_SRC =	framework.c \
		test_main.c \
		../2d_array_utils.c \
		../check_extension.c \
		../colors.c \
		../draw_line_utils.c \
		../draw_line.c \
		../error_msg.c \
		../free_utils.c \
		../ft_strcmp.c \
		../identifier_utils.c \
		../init_structs.c \
		../loop_file.c \
		../loop_idf.c \
		../newline_map_check.c \
		../parsing_utils.c \
		../printing_utils.c \
		../textures.c \

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