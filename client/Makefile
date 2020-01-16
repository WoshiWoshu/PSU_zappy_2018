##
## EPITECH PROJECT, 2019
## PSU_zappy_2018
## File description:
## Makefile
##

SRC =  	src/main.cpp \
	src/Help.cpp \
	src/Client.cpp \
	src/Player.cpp \
	src/Character.cpp \
	src/Graph/Graphics.cpp \
	src/Graph/Map.cpp \
	src/Graph/Inventory.cpp \
	src/Graph/Resources.cpp \

OBJ = $(SRC:.cpp=.o)

NAME = zappy_ai

CPPFLAGS = -Wall -Wextra -Weffc++ -lsfml-audio -lsfml-system -lsfml-graphics -lsfml-window -I./include/ -I./include/Graph -pthread

CC = g++

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)
	@echo -e '\e[32m> $(NAME) compiled successfully.\e[0m'
	cp $(NAME) ../

clean:
	@echo -e '\e[32m> Removing $(NAME) object files.\e[0m'
	rm -f $(OBJ)

fclean: clean
	@echo -e '\e[32m> Removing $(NAME) binary.\e[0m'
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
