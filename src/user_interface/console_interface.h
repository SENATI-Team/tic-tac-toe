#include <map>
#include <string>
#include "objects.h"
#include "values.h"

namespace tic_tac_toe {
	class ConsoleInterface {
	private:
		Config config = Config();
		State state = State();
		Tablero tablero = Tablero(config.getTableSize());
		Machine machine;
		int count = 0; //atraves de esto definimos los turnos en caso sea par o impar
		map<string, int> score;
		string message = "";
	public:
		ConsoleInterface();
		Config showCustomConfig();
		void showWelcomeOptions();
		void showTableVector();
		void showWelcome();
		void showStateGame();
		Machine showMachineConfig();

		void startGame();
		void stopGame();
		char getTurn(int);
		void insertInTable(Vector);
		void finishGame(char); //¿Quien gano?, y tambien sumara las partidas
		//Mostrar el estado del tablero
		void update();
		State getState();
		Config getConfig();
		Tablero getTablero();
		Machine getMachine();
	};
}
