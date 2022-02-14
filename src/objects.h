#include <map>
#include "tablero.h"
namespace tic_tac_toe {
	class Vector {
	private:
		int x;
		int y;
	public:
		Vector(int _x = 0, int _y = 0);
		//Getters
		int getX();
		int getY();
		//Setters
		void setX(int);
		void setY(int);
	};
	class Possibility {
	private:
		bool available;
		map<int, Vector> empty_positions;
	public:
		Possibility(bool _available = true, int _height= 0);
		void addEmptyPosition(Vector);
		Vector getEmtyPosition();

		bool checkPossibility(); // Esto es una solucion temporal, quisiera agregar null en ves de vectores pero bueno...
		int getEmptySize();
		bool isAvailable();
		void disable();
		void enable();
	};
	class Machine {
	private:
		/*
		 0: Facil
		 1: Normal
		 2: Dificil
		 */
		int difficulty;
		bool active;
		char identifier; // SU identificador
		Vector getEasyMove(Tablero);
		Vector getNormalMove(Tablero);
		Vector gethardMove(Tablero);

		// Generar posibilidad
		Possibility generatePossibility(Tablero, char);

	public:
		Machine(int _difficulty = 0, char _identifier = 'O', bool _active = false); // Dificultad (int), Identificdor(char)
		Vector generateMove(Tablero);
		bool isActive();
		char getIdentifier();
		string getDifficultyES(); // Obtener la difucultad en Español[ES]

		void setIdentifier(char _identifier = 'O');
		void setActive(bool _active = true);
		void setDifficulty(int _difficulty = 0);
	};
}
