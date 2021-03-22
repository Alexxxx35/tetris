SRC = *.cpp
OBJ = $(SRC)
NAME = exe
DEBUGNAME = exefake
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14
DEBUGCXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14
LBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f
all:
	$(CXX)	$(OBJ) -o $(NAME) $(CXXFLAGS) $(LBFLAGS)

# erase: 
# 	$(RM) $(OBJ)
debug:
	$(CXX)	$(OBJ) -o $(DEBUGNAME) -g $(DEBUGCXXFLAGS) $(LBFLAGS)


fclean: 
	$(RM)	$(NAME)

re: fclean all

# .PHONY: all fclean re