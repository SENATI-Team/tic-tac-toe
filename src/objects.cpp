#include "objects.h"
using namespace tic_tac_toe;

Vector::Vector(int _x, int _y){
	x = _x;
	y = _y;
}
int Vector::getX(){
	return x;
}
int Vector::getY(){
	return y;
}
void Vector::setX(int _x){
	x = _x;
}
void Vector::setY(int _y){
	y = _y;
}
//Possibility
Possibility::Possibility(char _player, int _init_size){
	player = _player;
	//Hay que cambiar esto porque gasta memoria
	for(int i = 0; i < _init_size ; i++){
		addEmptyPosition(Vector()); //LLena objetos vacios dependiendo del tamaño de la tabla
	}
}
Possibility::Possibility(char _player){
	player = _player;
}
void Possibility::addEmptyPosition(Vector _empty){
	empty_positions[empty_count++] = _empty;
}
Vector Possibility::getEmtyPosition(int _index){
	Vector tempVector = empty_positions[_index];
	/*for(int i = 0; i < empty_positions.size();i++){
		cout<<"X : "<<empty_positions[i].getX();
		cout<<"Y : "<<empty_positions[i].getY()<<endl;
	}
	char a;
	cin>> a;*/
	return tempVector;
}
int Possibility::getEmptyCount(){
	return empty_count;
}
int Possibility::getEmptySize(){
	return empty_positions.size();
}
bool Possibility::isAvailable(){
	return available;
}
void Possibility::disable(){
	available = false;
}

//MACHINE
Machine::Machine(int _difficulty){
	difficulty= _difficulty;
	active = true;
}
Machine::Machine(){
	difficulty = 0;
	active = false;
}
char Machine::getPlayer(){

	return player;
}
bool Machine::isActive(){
	return active;
}
Vector Machine::generateMove(Tablero _tablero){
	if(difficulty == 0){
		return getEasyMove(_tablero);
	}else if(difficulty == 1){
		return getNormalMove(_tablero);
	}
	return Vector();
}
Vector Machine::getEasyMove(Tablero _tablero){
	Tablero tablero = _tablero;
	bool findingPosition = true;
	while(findingPosition){
		int x, y;
			x = rand() % tablero.getTableSize();
			y = rand() % tablero.getTableSize();
		if(tablero.getTable()[x][y] == '-'){
			findingPosition = false;
			return Vector(x, y);
		}
	}
	return Vector();
}
Vector Machine::getNormalMove(Tablero _tablero){
	Tablero tablero = _tablero;

	// Posibilidad Seleccionada
	Possibility forPlayerX = Possibility('X',tablero.getTableSize());
	Possibility forPlayerO = Possibility('O',tablero.getTableSize());

	// Para X
	Possibility diagonalOneX = Possibility('X');//  '/'
	Possibility diagonalTwoX = Possibility('X'); //  '\'
	// Para O
	Possibility diagonalOneO = Possibility('O');//  '/'
	Possibility diagonalTwoO = Possibility('O'); //  '\'

	for (int x = 0; x < tablero.getTableSize(); x++) {
		//Para X
		Possibility verticalX = Possibility('X');
		Possibility horizontalX = Possibility('X');
		// Para O
		Possibility verticalO = Possibility('O');
		Possibility horizontalO = Possibility('O');
		//chequear si hay en diagonal
		//Para X
		if (tablero.getTable()[x][x] == '-') {
			diagonalOneX.addEmptyPosition(Vector(x,x));
		}else if(tablero.getTable()[x][x] != 'X'){
			diagonalOneX.disable();
		}
		if (tablero.getTable()[x][tablero.getTableSize()-1-x] == '-') {
			diagonalTwoX.addEmptyPosition(Vector(x, tablero.getTableSize()-1-x ));
		}else if(tablero.getTable()[x][tablero.getTableSize()-1-x] != 'X'){
				diagonalTwoX.disable();
		}
		//Para O
		if (tablero.getTable()[x][x] == '-') {
			diagonalOneO.addEmptyPosition(Vector(x,x));
		}else if(tablero.getTable()[x][x] != 'O'){
			diagonalOneO.disable();
		}
		if (tablero.getTable()[x][tablero.getTableSize()-1-x] == '-') {
			diagonalTwoO.addEmptyPosition(Vector(x, tablero.getTableSize()-1-x ));
		}else	if(tablero.getTable()[x][tablero.getTableSize()-1-x] != 'O'){
			diagonalTwoO.disable();
		}

		for (int y = 0; y < tablero.getTableSize(); y++) {
			// Para X
			if (tablero.getTable()[x][y] == '-') {
				horizontalX.addEmptyPosition(Vector(x,y));
			}else if(tablero.getTable()[x][y] != 'X'){
				horizontalX.disable();
			}

			if (tablero.getTable()[y][x] == '-') {
				verticalX.addEmptyPosition(Vector(y, x));
			}else if (tablero.getTable()[y][x] != 'X') {
				verticalX.disable();
			}
			// Para O
			if (tablero.getTable()[x][y] == '-') {
				horizontalO.addEmptyPosition(Vector(x,y));
			}else if(tablero.getTable()[x][y] != 'O'){
				horizontalO.disable();
			}

			if (tablero.getTable()[y][x] == '-') {
				verticalO.addEmptyPosition(Vector(y, x));
			}else if (tablero.getTable()[y][x] != 'O') {
				verticalO.disable();
			}
		}
		// Para O
		if(forPlayerO.getEmptySize() > verticalO.getEmptySize() &&
				verticalO.isAvailable()){
			forPlayerO = verticalO;
		}
		if(forPlayerO.getEmptySize() > horizontalO.getEmptySize() &&
				horizontalO.isAvailable()){
			forPlayerO = horizontalO;
		}
		// Para X
		if(forPlayerX.getEmptySize() > verticalX.getEmptySize() &&
				verticalX.isAvailable()){
			forPlayerX = verticalX;
		}
		if(forPlayerX.getEmptySize() > horizontalX.getEmptySize() &&
				horizontalX.isAvailable()){
			forPlayerX = horizontalX;
		}
	}
	// Para X
	if(forPlayerX.getEmptySize() > diagonalOneX.getEmptySize() &&
			diagonalOneX.isAvailable()){
		forPlayerX = diagonalOneX;
	}
	if(forPlayerX.getEmptySize() > diagonalTwoX.getEmptySize() &&
			diagonalTwoX.isAvailable()){
		forPlayerX = diagonalTwoX;
	}
	// Para O
	if(forPlayerO.getEmptySize() > diagonalOneO.getEmptySize() &&
			diagonalOneO.isAvailable()){
		forPlayerO = diagonalOneO;
	}
	if(forPlayerO.getEmptySize() > diagonalTwoO.getEmptySize() &&
			diagonalTwoO.isAvailable()){
		forPlayerO = diagonalTwoO;
	}

	// Trabajar con el resultado
	// forPlayerO - el mejor resultado obtenidp de O
	// forPlayerX - el mejor resultado obtenidp de X

	int a; // PRueba
	if(forPlayerX.getEmptySize() == tablero.getTableSize()){
		return getEasyMove(tablero);
	}
	else if(forPlayerX.getEmptySize() <= forPlayerO.getEmptySize()){
		a = rand() % forPlayerX.getEmptySize();
		Vector b =forPlayerX.getEmtyPosition(a);
		return b;
	}else {
		a = rand() % forPlayerO.getEmptySize();
		Vector b =forPlayerO.getEmtyPosition(a);
		return b;
	}
}
void Machine::setDifficulty(int _difficulty){
	difficulty = _difficulty;
}
/*
bool Tablero::checkIsWinning(char player) {
	//estas variables son para almacenar si es igual a el tamaño de la tabla
	// temporal por ahora almacenare un numero entero
	// pero se planea poner una lista con las coordenadas

	//Diagonales
	int diagonalOne = 0; //  '/'
	int diagonalTwo = 0; //  '\'

	for (int x = 0; x < table_size; x++) {

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
		//Por ahora mantendremos eso asi, por que no sirve  en diagonales
		if(horizontal == table_size || vertical == table_size || diagonalOne == table_size || diagonalTwo == table_size){
			return true;
		}
	}




	return false;
}
*/
