#include <iostream>
#include <map>
using namespace std;

namespace tic_tac_toe {
	class Tablero {
	private:
		int table_size;
		map<int, map<int, char>> table;
	public:
		Tablero(int);
		void resetTable();
		void showTable();
		bool checkIsWinning(char);
		void newMovement(int, int, char); // Recibira "X" e "Y"
		map<int, map<int, char>> getTable();
		//GETS
		int getTableSize();
		bool isFulled();
	};
}
