#include <iostream>
#include <string>
#include "tablero.h"

using namespace tic_tac_toe;
using namespace std;

void tablero::mostrar_tablero()
{
	// valores de prueba
	string casillas[9] = {"O", "O", "X", "O", "O", "O", "X", "X", "O"};
		
	for (int i = 0; i < 7; i += 3)
	{
		string fila = "|";

		for (int j = 0; j < 3; j++)
		{
			int indice = i + j;

			fila += " " + casillas[indice] + " |";
		}

		cout << fila << endl;
	}
}