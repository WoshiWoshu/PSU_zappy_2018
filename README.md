# PSU_zappy_2018
Second year C/C++ project in which the goal is to create a local TCP network game to manage a world and it's inhabitants. The server is resposible for the management and process of all datas from/to client. Clients connect to server and only rely on a graphical interface.
Several teams made entirely on AI bots (no player) confront on a tiles map containing resources. The winning team is the one with 6 players who reached maximum elevation. The game board represents the entirety of this world’s surface, like a world map. The environment is rather rich in resources (as many mineral as dietary). Therefore, by walking around this planet, the bots can find succulent food and a variety of natural stones. generated randomly by the server. The bots feeds themselves and collects stones in order to reach maximum elevation. The bots are pacifist and doesn't fight. They can also see as far as his/her visual capacities allow. So it's impossible to distinguish his/her direction when they run into them.
The elevation begins when the bots starts the ritual/incantation with a certain combinations of stones and bots of the same level. With each elevation, the vision for the bot increases by one unit in front, and one on each side of the new line. At the first level, the unit is defined as 1. The Client can recognize his/her teammates by sending a look command to the server.

PREREQUISITE : SFML needs to be installed.

USAGE SERVER :

./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq

port is the port number

width is the width of the world

height is the height of the world

nameX is the name of the team X

clientsNb is the number of authorized clients per team

freq is the reciprocal of time unit for execution of actions



USAGE CLIENT:

./zappy_ai -p port -n name -h machine

port is the port number

name is the name of the team

machine is the name of the machine; localhost by default
