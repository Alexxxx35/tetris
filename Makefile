SRC = *.cpp
OBJ = $(SRC)
NAME = exe
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14
LBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f
all:
	$(CXX)	$(OBJ) -o $(NAME) $(CXXFLAGS) $(LBFLAGS)

# erase: 
# 	$(RM) $(OBJ)

fclean: 
	$(RM)	$(NAME)

re: fclean all

# .PHONY: all fclean re