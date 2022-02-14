#include <cstdlib>
#include "values.h"
using namespace tic_tac_toe;

//CONFIGURACIÓN
Config::Config(int _table_size, char _player_one, char _player_two) {
	table_size = _table_size;
	player_one = _player_one;
	player_two = _player_two;
}

int Config::getTableSize() {
	return table_size;
}

char Config::getPlayerOne() {
	return player_one;
}

char Config::getPlayerTwo() {
	return player_two;
}

void Config::setTableSize(int _table_size) {
	table_size = _table_size;
}

void Config::setPlayerOne(char playerOne) {
	player_one = playerOne;
}

void Config::setPlayerTwo(char playerTwo) {
	player_two = playerTwo;
}

void Config::setPlayers() {
	player_one = 'X';
	player_two = 'O';
}

//ESTADO DEL JUEGO
State::State() {
	running = true;
	winning = false;
	configured = false;
}

bool State::isRunning() {
	return running;
}

bool State::isConfigured() {
	return configured;
}

void State::enableConfigured() {
	configured = true;
}

void State::disableConfigured() {
	configured = false;
}

void State::start() {
	running = true;
}

void State::stop() {
	running = false;
}
