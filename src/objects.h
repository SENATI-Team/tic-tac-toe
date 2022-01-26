#include "tablero.h"
#include <map>
namespace tic_tac_toe{
	class Vector{
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
	class Possibility{
	private:
		char player;
		int empty_count = 0;
		bool available = true;
		map<int, Vector> empty_positions;
	public:
		Possibility(char, int);
		Possibility(char);
		void addEmptyPosition(Vector);
		Vector getEmtyPosition(int);
		int getEmptyCount();
		int getEmptySize();
		bool isAvailable();
		void disable();
	};
	class Machine{
	private:
		/*
		 0: Facil
		 1: Normal
		 2: Dificil
		 */
		int difficulty;
		bool active;
		char player = 'O'; // SU identificador
		Vector getEasyMove(Tablero);
		Vector getNormalMove(Tablero);
		Vector gethardMove(Tablero);
	public:
		Machine();
		Machine(int);
		Vector generateMove(Tablero);
		bool isActive();
		char getPlayer();
		void setDifficulty(int);
	};
}
