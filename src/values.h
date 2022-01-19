namespace tic_tac_toe {
	class Config {
	private:
		int table_size;
		char player_one;
		char player_two;
	public:
		//Constructor
		Config(int _table_size = 3, char _player_one = 'X', char _player_two = 'O');
		//Getters
		int getTableSize();
		char getPlayerOne();
		char getPlayerTwo();
		//Setters
		void setTableSize(int _table_size = 3);
		void setPlayerOne(char);
		void setPlayerTwo(char);
		void setPlayers();
	};

	class State {
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
