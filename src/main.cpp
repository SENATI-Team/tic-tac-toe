#include <iostream>
#include "db_operations.h"
#include "interface.h"
using namespace std;
using namespace tic_tac_toe;

int main() {
	// SQLite connection
	get_connection();

	Interface interface = Interface();
	interface.showWelcome();

	interface.showWelcomeOptions();

	if(interface.getState().isRunning()){
		interface.startGame();
	}

	while (interface.getState().isRunning()) {
		interface.update();
	}

    return 0;
}
