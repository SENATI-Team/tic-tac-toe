#include "objects.h"

using namespace std;
using namespace tic_tac_toe;

Vector::Vector(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Vector::getX()
{
	return x;
}

int Vector::getY()
{
	return y;
}

void Vector::setX(int _x)
{
	x = _x;
}

void Vector::setY(int _y)
{
	y = _y;
}

//Possibility
Possibility::Possibility(bool _available, int  _height)
{
	available = _available;
	for (int i = 0; i <  _height; i++) {
		addEmptyPosition(Vector()); //LLena objetos vacios dependiendo del tamaño de la tabla
	}
}

void Possibility::addEmptyPosition(Vector _empty)
{
	empty_positions[getEmptySize()] = _empty;
}

Vector Possibility::getEmtyPosition()
{
	int i = rand() % getEmptySize();
	Vector tempVector = empty_positions[i];
	return tempVector;
}

int Possibility::getEmptySize()
{
	return empty_positions.size();
}

bool Possibility::isAvailable()
{
	return available;
}

void Possibility::disable()
{
	available = false;
}

void Possibility::enable()
{
	available = true;
}

bool Possibility::checkPossibility()
{
	int count_nothing = 0;

	for(int i = 0; i < getEmptySize(); i++) {
		if(empty_positions[i].getX() == 0 && empty_positions[i].getY() == 0) {
			count_nothing++;
		}
	}

	if(count_nothing > 1) {
		return false;
	}else {
		return true;
	}
}

// MACHINE
Machine::Machine(int _difficulty, char _identifier, bool _active)
{
	difficulty = _difficulty;
	identifier = _identifier;
	active = _active;
}

char Machine::getIdentifier()
{
	return identifier;
}

bool Machine::isActive()
{
	return active;
}

Vector Machine::generateMove(Tablero _tablero)
{
	if(difficulty == 0) {
		return getEasyMove(_tablero);
	}else if(difficulty == 1) {
		return getNormalMove(_tablero);
	}
	return Vector();
}

Possibility Machine::generatePossibility(Tablero _tablero, char _player)
{
	// solo esta de relleno
	Tablero tablero = _tablero;
	char player = _player;

	// Posibilidad Seleccionada
	Possibility moveSelected = Possibility( false, tablero.getTableSize() );

	// Diagonales
	Possibility diagonalOne;
	Possibility diagonalTwo;

	for (int x = 0; x < tablero.getTableSize(); x++) {
		// Lineas Rectas
		Possibility vertical;
		Possibility horizontal;

		//Chequeo de Diagonales
		if (tablero.getTable()[x][x] == '-') {
			diagonalOne.addEmptyPosition(Vector(x,x));
		}else if(tablero.getTable()[x][x] != player) {
			diagonalOne.disable();
		}

		if (tablero.getTable()[x][tablero.getTableSize()-1-x] == '-') {
			diagonalTwo.addEmptyPosition(Vector(x, tablero.getTableSize()-1-x ));
		}else if(tablero.getTable()[x][tablero.getTableSize()-1-x] != player) {
			diagonalTwo.disable();
		}

		for (int y = 0; y < tablero.getTableSize(); y++) {
			// Chequeo de lineas rectas
			if (tablero.getTable()[x][y] == '-') {
				horizontal.addEmptyPosition(Vector(x,y));
			}else if(tablero.getTable()[x][y] != player) {
				horizontal.disable();
			}
			if (tablero.getTable()[y][x] == '-') {
				vertical.addEmptyPosition(Vector(y, x));
			}else if (tablero.getTable()[y][x] != player) {
				vertical.disable();
			}
		}

		// Chequeo de posibilidades en lineas rectas
		if(moveSelected.getEmptySize() > vertical.getEmptySize() &&
				vertical.isAvailable()) {
			moveSelected = vertical;
		}

		if(moveSelected.getEmptySize() > horizontal.getEmptySize() &&
				horizontal.isAvailable()) {
			moveSelected = horizontal;
		}
	}

	// Chequeo de diagonales
	if(moveSelected.getEmptySize() > diagonalOne.getEmptySize() &&
			diagonalOne.isAvailable()) {
		moveSelected = diagonalOne;
	}
	else if(moveSelected.getEmptySize() > diagonalTwo.getEmptySize() &&
			diagonalTwo.isAvailable()) {
		moveSelected = diagonalTwo;
	}
	return moveSelected;
}

Vector Machine::getEasyMove(Tablero _tablero)
{
	Tablero tablero = _tablero;
	bool findingPosition = true;
	while(findingPosition) {
		int x, y;
			x = rand() % tablero.getTableSize();
			y = rand() % tablero.getTableSize();
		if(tablero.getTable()[x][y] == '-') {
			findingPosition = false;
			return Vector(x, y);
		}
	}
	return Vector();
}

Vector Machine::getNormalMove(Tablero _tablero)
{
	Possibility forX = generatePossibility(_tablero, 'X');
	Possibility forO = generatePossibility(_tablero, 'O');

	if(forX.getEmptySize() > forO.getEmptySize()) {

		return forO.getEmtyPosition();

	}else if(forX.getEmptySize() < forO.getEmptySize()) {

		return forX.getEmtyPosition();

	}else if(forX.getEmptySize() == forO.getEmptySize()) {
		if(identifier == 'O') {
			return forO.getEmtyPosition();
		}else {
			return forX.getEmtyPosition();
		}
	}else {
		return getEasyMove(_tablero);
	}
}

// Vector Machine::getHardMove(Tablero _tablero)
// {

// }

void Machine::setDifficulty(int _difficulty)
{
	difficulty = _difficulty;
}

void Machine::setActive(bool _active)
{
	active = _active;
}

void Machine::setIdentifier(char _identifier)
{
	identifier = _identifier;
}

string Machine::getDifficultyES()
{
	if(difficulty == 0) return "Facil";
	else if(difficulty == 1) return "Normal";
	else if(difficulty == 2) return "Dificil";
	else return "NO SELECCIONADO";
}
