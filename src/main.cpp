#include "interface.h"
#include <iostream>
using namespace tic_tac_toe;
using namespace std;

int main() {
	Interface interface = Interface();
	interface.showWelcome();
	interface.showWelcomeOptions();
	interface.startGame();

	while (interface.getState().isRunning()) {
		interface.update();
	}

	/*
	State state = State();
	Config config;

	Interface interface = Interface();

	interface.showWelcome();

	config = interface.showWelcomeOptions();
	state.setConfig(config);

	Tablero tablero = Tablero(config.getTableSize());

	tablero.resetTable();

	state.start();

	while(state.isRunning()){

		tablero.showTable();

		cout<<"INGRESE COORDENADAS (X, Y)";
		int x, y;
		cout<<"X: ";
		cin>>x;
		cout<<"Y: ";
		cin>>y;

		tablero.newMovement(x, y, );
	}
	 */

    return 0;
}
