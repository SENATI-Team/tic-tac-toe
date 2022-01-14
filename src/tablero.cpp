#include <iostream>
#include "tablero.h"
#include <stdlib.h>

using namespace tic_tac_toe;
using namespace std;

Tablero::Tablero(int tableSize){
	table_size = tableSize;
}

void Tablero::showTable()
{
	system("clear");

	for (int x = 0; x < table_size; x++)
	{
		string fila = "| ";

		for (int y = 0; y < table_size; y++)
		{
			fila = fila + table[x][y] + " | ";
		}

		cout << fila << endl;
	}
}

void Tablero::newMovement(int x, int y, char player){

	table[x][y]=player;

}

void Tablero::resetTable()
{

	for (int x = 0; x < table_size; x++)
	{
		for (int y = 0; y < table_size; y++)
		{
			table[x][y] = '-';
		}
	}
}


