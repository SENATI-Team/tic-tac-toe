#include "values.h"
#include <cstdlib>
using namespace tic_tac_toe;

//CONFIGURACIÓN
Config::Config(int tableSize, char playerOne, char playerTwo){
	table_size = tableSize;
	player_one = playerOne;
	player_two = playerTwo;
}

Config::Config(){
	table_size = 3;
	player_one = 'X';
	player_two = 'O';
}

int Config::getTableSize(){
	return table_size;
}
char Config::getPlayerOne(){
	return player_one;
}
char Config::getPlayerTwo(){
	return player_two;
}

void Config::setTableSize(int tableSize){
	table_size = tableSize;
}
void Config::setTableSize(){
	table_size = 3;
}
void Config::setPlayerOne(char playerOne){
	player_one = playerOne;
}
void Config::setPlayerTwo(char playerTwo){
	player_two = playerTwo;
}
void Config::setPlayers(){
	player_one = 'X';
	player_two = 'O';
}

//ESTADO DEL JUEGO
State::State(){
	is_running = false;
	is_winning = false;
}
bool State::isRunning(){
	return is_running;
}
void State::start(){
	is_running = true;
}
void State::stop(){
	is_running = false;
}



