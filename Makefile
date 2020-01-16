##
## EPITECH PROJECT, 2019
## PSU_zappy_2018
## File description:
## Makefile
##

all: zappy_server zappy_ai

zappy_server:
	make -C server

zappy_ai:
	make -C client

clean:
	make -s -C server clean
	make -s -C client clean

fclean:
	make -s -C server fclean
	make -s -C client fclean

re: fclean all

.PHONY: all zappy_server zappy_ai clean fclean re