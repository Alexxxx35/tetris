SRC = *.cpp
OBJ = $(SRC)
NAME = test/exe.out
CXX = g++
CXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14
DEBUGCXXFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++14 -g
LBFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
RM = rm -f
all:	$(NAME)

$(NAME):	
			$(CXX)	$(OBJ) -o $(NAME) $(CXXFLAGS) $(LBFLAGS) -g

clean: 
	$(RM) $(OBJ)

fclean: 
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean flean re