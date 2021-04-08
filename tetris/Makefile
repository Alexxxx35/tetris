CC      = g++
CFLAGS  = -Wall -g -Wextra -Wpedantic -Werror -std=c++14
LFLAGS	= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

NAME    = Tetris	
RM      = rm -f
SRC	= \
	Piece.cpp \
	Case.cpp \
	GameCore.cpp \
	Scene.cpp \
	main.cpp \

OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LFLAGS)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
