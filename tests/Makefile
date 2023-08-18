NAME = tests

DEP = tests.hpp ../cubed.h

CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CC = g++
CFLAGS = -Wall -Werror -Wextra

C_SRC =		../check_extension.c
C_OBJFILES = $(C_SRC:.c=.o)
C_OBJ = $(addprefix $(OBJDIR), $(C_OBJFILES))

CPP_SRC =	compare_functions.cpp \
			test_utils.cpp \
			tests.cpp \
			check_extension_tests.cpp

CPP_OBJFILES = $(CPP_SRC:.cpp=.o)
CPP_OBJ = $(addprefix $(OBJDIR), $(CPP_OBJFILES))

OBJDIR = ./objects_and_dependencies/

.PHONY: clean fclean all tests

all: $(NAME)

$(OBJDIR)%.o: ./%.c $(DEP)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR)%.o: ./%.cpp $(DEP)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(C_OBJ) $(CPP_OBJ)
	@$(MAKE) -C ../libft
	$(CXX) $(CXXFLAGS) $(C_OBJ) $(CPP_OBJ) ../libft/libft.a -o $(NAME)
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