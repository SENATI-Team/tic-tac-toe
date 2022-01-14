namespace tic_tac_toe{
	class Config{
	private:
		int table_size;
		char player_one;
		char player_two;
	public:
		//Constructores
		Config();
		Config(int, char, char);
		//Gets
		int getTableSize();
		char getPlayerOne();
		char getPlayerTwo();
		//Sets
		void setTableSize(int);
		void setTableSize();
		void setPlayerOne(char);
		void setPlayerTwo(char);
		void setPlayers();
	};
	class State{
	private:
		bool is_running;
		bool is_winning;
	public:
		State();
		bool isRunning();
		void start();
		void stop();
	};
}
