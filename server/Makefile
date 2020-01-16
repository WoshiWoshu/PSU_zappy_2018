##
## EPITECH PROJECT, 2019
## PSU_zappy_2018
## File description:
## Makefile
##

SRC = src/main.c \
	  src/help.c \
	  src/options.c \
	  src/options1.c \
	  src/options2.c \
	  src/player.c \
	  src/player_lst.c \
	  src/map.c \
	  src/server.c \
	  src/server_util.c \
	  src/server_cmds.c \
	  src/server_cmds1.c \
	  src/server_cmds2.c \
	  src/util.c \
	  src/look.c \
	  src/look2.c \
	  src/movement.c \
	  src/interaction.c \
	  src/command_lst.c \
	  src/elevation.c \
	  src/elevation2.c \
	  src/broadcast.c \

OBJ = $(SRC:.c=.o)

NAME = zappy_server

CFLAGS = -Wall -Wextra -I./include

CC = gcc

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)
	@echo -e '\e[36m> $(NAME) compiled successfully.\e[0m'
	cp $(NAME) ../

clean:
	@echo -e '\e[36m> Removing $(NAME) object files.\e[0m'
	rm -f $(OBJ)

fclean: clean
	@echo -e '\e[36m> Removing $(NAME) binary.\e[0m'
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re