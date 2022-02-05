#include "interface.h"
#include <iostream>
using namespace tic_tac_toe;
using namespace std;

int main() {
	Interface interface;
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
