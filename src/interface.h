#include "values.h"
#include "tablero.h"
#include <string>
namespace tic_tac_toe {
	class Interface {
	private:
		Config config = Config();
		State state = State();
		Tablero tablero = Tablero(config.getTableSize());
		int count = 0; //atraves de esto definimos los turnos en caso sea par o impar
		int winsX = 0;
		int winsO = 0;
		int gamesCount = 0;
		string error = "";
	public:
		Interface();
		Config showCustomConfig();
		void showWelcomeOptions();
		void showTableVector();
		void showWelcome();
		void showStateGame();
		void startGame();
		void stopGame();
		char getTurn(int);
		void finishGame(char); //¿Quien gano?, y tambien sumara las partidas
		//Mostrar el estado del tablero
		void update();
		State getState();
		Config getConfig();
		Tablero getTablero();
	};
}
