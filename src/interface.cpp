#include <iostream>
#include "interface.h"
#include "utility.h"
using namespace tic_tac_toe;
using namespace std;

Interface::Interface() {}

//Esto se muestra en al iniciar
void Interface::showWelcome() {
	showText("//////////////////////");
	showText("***** BIENVENIDO *****");
	showText("**** TIC-TAC-TOE #****");
	showText("//////////////////////");
}

void Interface::showStateGame() {
	system("clear");

	cout<<"TABLA: " << tablero.getTableSize() << " X " << tablero.getTableSize()<<endl;
	cout<<"Jugadores: P1: " << config.getPlayerOne() << " /VS/ P2: " << config.getPlayerTwo()<<endl;
	showText("---------");
	cout<<"X: " <<winsX<<endl;
	cout<<"O: " <<winsO<<endl;
	showText("---------");
	cout<<"Turno de: " << getTurn(0)<<endl<<endl;
}

//Formularios
Config Interface::showCustomConfig() { //Personalizar juego
	int tmp_new_size;
	char tmp_player_one;

	showText("TIC-TAC-TOE");
	showText("Configuracion alternativa");
	cout<<"Inserte tamaño de tabla: ";
	cin>>tmp_new_size;
	Config tmpConfig = Config(tmp_new_size, 'X','O');

	return tmpConfig;
}

Machine Interface::showMachineConfig(){
	showText("Modo COM\nElija Nivel:");
	showText("[0] Facil (NO)");
	showText("[1] Normal (NO)");
	showText("[2] Dificil (NO)");
	int difficulty;
	cout<<"Elija el Nivel: ";
	cin>> difficulty;
	Machine tmp_machine;
	if(difficulty >= 0 && difficulty <= 2){
		tmp_machine = Machine(difficulty);
	}
	return tmp_machine;
}
void Interface::showWelcomeOptions() {
	bool unconfigured = true; //No configurado

	while (unconfigured) {
		int option;
		showText("[1] Iniciar Juego");
		showText("[2] Personalizado (NO PROBAR)");
		showText("[3] vs COM");
		cin >> option;

		if (option == 1) {
			config = Config(); // Retorna valores por defecto
			unconfigured = false;
		} else if (option == 2) {
			config = showCustomConfig(); // Muestra un formulario para personlizar valores
			unconfigured = false;
		} else if(option == 3){
			config = Config();
			machine = showMachineConfig();
			unconfigured = false;

		}else {
			showText("Ingrese una opcion Correcta");
		}
	}
}

void Interface::showTableVector() { //Se ingresan valores para la jugada en cordenadas x,y por eso es Vector
	if(error != ""){
		cout<<"ERROR: "<<error<<endl;
	}
	showText("INGRESAR JUGADA (X, Y)");
	int x,y;
	cout<<"X: ";
	cin>>x;
	cout<<"Y: ";
	cin>>y;
	int flag = config.getTableSize();

	if ((x>=0 && x<flag) && (y>=0 && y<flag)) {
		if (tablero.getTable()[x][y] == '-') {
			Vector position;
			position = Vector(x, y);
			insertInTable(position);
			error = "";
		} else {
			error = "Jugada no realizada";
		}
	} else {
		error = "No seencuentra en los rangos";
	}
}

//Control del estado del juego
void Interface::startGame() {
	tablero = Tablero(config.getTableSize());
	tablero.resetTable();
	state.start();
}

void Interface::stopGame() {
	state.stop();
}

void Interface::finishGame(char whoIsWin) {
	if (whoIsWin == 'X') {
		winsX++;
	} else if (whoIsWin == 'O') {
		winsO++;
	}
	gamesCount++;
}
void Interface::insertInTable(Vector _position){
	char player = getTurn(1);
	tablero.newMovement(_position.getX(),_position.getY(), player);
	if (tablero.checkIsWinning(player)) {
			finishGame(player);
			tablero.resetTable();
		}
}
//Actualizacion
void Interface::update() {
	//Mostrar Tabla
	showStateGame();
	tablero.showTable();
	//Modificar tabla
	showTableVector();
	if(machine.isActive() && getTurn(0) == machine.getPlayer()){
		Vector generated = machine.generateMove(tablero);
		insertInTable(generated);
	}
}

char Interface::getTurn(int _turn)
{
	div_t target = div(count, 2);
	count += _turn;

	if (target.rem == 0) {
		return config.getPlayerOne();
	} else {
		return config.getPlayerTwo();
	}
}

//Retornar valores para poder ser configurados o ver el estado
State Interface::getState() {
	return state;
}

Config Interface::getConfig() {
	return config;
}

Tablero Interface::getTablero() {
	return tablero;
}
