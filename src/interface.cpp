#include "interface.h"
#include <iostream>
using namespace tic_tac_toe;
using namespace std;

Interface::Interface() {}

//Esto se muestra en al iniciar
void Interface::showWelcome() {
	cout<<"//////////////////////"<<endl;
	cout<<"***** BIENVENIDO *****"<<endl;
	cout<<"**** TIC-TAC-TOE #****"<<endl;
	cout<<"//////////////////////"<<endl;
}

void Interface::showStateGame() {
	system("clear");
	cout<<"TABLA: " << tablero.getTableSize() << " X " << tablero.getTableSize()<<endl;
	cout<<"Jugadores: P1: " << config.getPlayerOne() << " /VS/ P2: " << config.getPlayerTwo()<<endl;
	cout<<"---------"<<endl;
	cout<<"X: " <<winsX<<endl;
	cout<<"O: " <<winsO<<endl;
	cout<<"---------"<<endl;
	cout<<"Turno de: " << getTurn(count)<<endl<<endl;
}

//Formularios
Config Interface::showCustomConfig() { //Personalizar juego
	cout<<"TIC-TAC-TOE";
	cout<<"Configuracion alternativa";
	cout<<"Inserte tamaño de tabla";
	return Config();
}

void Interface::showWelcomeOptions() {
	bool unconfigured = true; //No configurado

	while (unconfigured) {
		int option;
		cout<<"[1] Iniciar Juego"<<endl;
		cout<<"[2] Personalizado (NO PROBAR)"<<endl;
		cin >> option;

		if (option == 1) {
			config = Config(); // Retorna valores por defecto
			unconfigured = false;
		} else if (option == 2) {
			config = showCustomConfig(); // Muestra un formulario para personlizar valores
			unconfigured = false;
		} else {
			cout<<"Ingrese una opcion Correcta"<<endl;
		}
	}
}

void Interface::showTableVector() { //Se ingresan valores para la jugada en cordenadas x,y por eso es Vector
	cout<<"INGRESAR JUGADA (X, Y)"<<endl;
	int x,y;
	cout<<"X: ";
	cin>>x;
	cout<<"Y: ";
	cin>>y;
	bool flag = config.getTableSize();

	if ((x>=0 && x<flag) && (y>=0 && y<flag)) {
		if (tablero.getTable()[x][y] == '-') {
			tablero.newMovement(x,y, getTurn(count));
		} else {
			cout<<"Jugada no realizada"<<endl;
			count--;
		}
	} else {
		cout<<"Rangos no validos!!"<<endl;
		count--;
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

//Actualizacion
void Interface::update() {
	count++;
	//Mostrar Tabla
	showStateGame();
	tablero.showTable();
	//Modificar tabla
	showTableVector();

	if (tablero.checkIsWinning(getTurn(count))) {
		finishGame(getTurn(count));
		tablero.resetTable();
	}
}

char Interface::getTurn(int count_p) {
	div_t target = div(count_p, 2);
	
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
