SRC = main.cpp
OBJ = $(SRC)
NAME = exe
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14
LBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f
all:	$(NAME)
$(NAME):	
			$(CXX)	$(OBJ) -o $(NAME) $(CXXFLAGS) $(LBFLAGS)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: all clean flean re