#include <iostream>
#include "tablero.h"
#include <stdlib.h>
using namespace tic_tac_toe;
using namespace std;

Tablero::Tablero(int tableSize) {
	table_size = tableSize;
}

void Tablero::showTable() {
	for (int x = 0; x < table_size; x++) {
		string fila = "| ";

		for (int y = 0; y < table_size; y++) {
			fila = fila + table[x][y] + " | ";
		}

		cout << fila << endl;
	}
}

void Tablero::newMovement(int x, int y, char player) {
	table[x][y] = player;
}

void Tablero::resetTable() {
	for (int x = 0; x < table_size; x++) {
		for (int y = 0; y < table_size; y++) {
			table[x][y] = '-';
		}
	}
}

bool Tablero::checkIsWinning(char player) {
	//estas variables son para almacenar si es igual a el tamaño de la tabla
	// temporal por ahora almacenare un numero entero
	// pero se planea poner una lista con las coordenadas

	//Diagonales
	int diagonalOne = 0; //  '/'
	int diagonalTwo = 0; //  '\'

	for (int x = 0; x < table_size; x++) {
		//Verticales
		int vertical = 0;
		int horizontal = 0;

		//chequear si hay en diagonal
		if (table[x][x] == player) {
			diagonalOne++;
		}

		if (table[x][table_size-1-x] == player) {
			diagonalTwo++;
		}

		for (int y = 0; y < table_size; y++) {

			if (table[x][y] == player) {
				horizontal++;
			}

			if (table[y][x] == player) {
				vertical++;
			}
		}

		return horizontal == table_size || vertical == table_size || diagonalOne == table_size || diagonalTwo == table_size;
	}

	return false;
}

int Tablero::getTableSize() {
	return table_size;
}

map<int, map<int, char>> Tablero::getTable() {
	return table;
}
