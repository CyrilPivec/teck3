##
## Makefile for bomberman in /home/nawin/rendu/cpp_bomberman
## 
## Made by Nawin Kim
## Login: kim_n <kim_n@epitech.net>
## 
## Started on  Mon Apr 27 13:18:03 2015 Nawin Kim
## Last update Sat May  2 14:39:09 2015 Nawin Kim
##

SRC		= main.cpp \
		  GameEngine.cpp

NAME		= bomberman

OBJ		= $(SRC:.cpp=.o)

DIR_INC		= includes

INC		= -I$(DIR_INC)

DIR_LIB		= -L./libs ./libs/libgdl_gl.a

INC_SDL		= -Iincludes/SDL

LIBS		= $(DIR_LIB) -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread


CXX		= g++
CXXFLAGS	+= $(INC) $(INC_SDL)
#CXXFLAGS	+= -Wall -Werror -Wextra

RM		= rm -rf

all		: $(NAME)

$(NAME)		: $(OBJ)
		  $(CXX) -o $(NAME) $(OBJ) $(LIBS)

clean		:
		  $(RM) $(OBJ)
		  $(RM) *~

fclean		: clean
		  $(RM) $(NAME)


re		: fclean all
