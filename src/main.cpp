#include <iostream>
#include "console_interface.h"
// #include "db_operations.h"

using namespace std;
using namespace tic_tac_toe;

int main()
{
	// SQLite connection
	// tic_tac_toe::openConnection();

	ConsoleInterface consoleInterface = ConsoleInterface();
	consoleInterface.showWelcome();
	consoleInterface.showWelcomeOptions();
	if (consoleInterface.getState().isRunning())
	{
		consoleInterface.startGame();
	}
	while (consoleInterface.getState().isRunning())
	{
		consoleInterface.update();
	}
    return 0;
}
