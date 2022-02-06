//Chequearemos del sistema operativo
#ifdef __linux__
#define SO 'L' // Linux 
#elif _WIN32
#define SO 'W' // Windows
#endif

#include <iostream>
#include "interface.h"
#include "utility.h"
using namespace tic_tac_toe;
using namespace std;



//Constructor Prueba
Interface::Interface(){
	score["X"] = 0;
	score["O"] = 0;
	score["T"] = 0; // EMPATE 'TIE'
	score["gamesCount"] = 0;
}
//Esto se muestra en al iniciar
void Interface::showWelcome() {
	showText("//////////////////////");
	showText("***** BIENVENIDO *****");
	showText("**** TIC-TAC-TOE #****");
	showText("//////////////////////");
}
void Interface::showStateGame() {
	if(SO == 'L'){
		system("clear");
	}else if(SO == 'W'){
		system("cls");
	}
	
	cout<<"TABLA: " << tablero.getTableSize() << " X " << tablero.getTableSize()<<endl;
	if(machine.isActive()){
		cout<<"Jugadores: P1: " << config.getPlayerOne() << " /VS/ [COM]: " << machine.getIdentifier()<<endl;
		cout<<"[COM] Dificultad: "<< machine.getDifficultyES()<<endl;
	}else{
		cout<<"Jugadores: P1: " << config.getPlayerOne() << " /VS/ P2: " << config.getPlayerTwo()<<endl;
	}
	showText("---------");
	cout<<"X: " <<score["X"]<<endl;
	cout<<"O: " <<score["O"]<<endl;
	cout<<"Empates: "<<score["T"]<<endl;
	cout<<"Partidas Total: " << score["gamesCount"]<<endl;
	showText("---------");
	cout<<"Turno de: " << getTurn(0)<<endl<<endl;
}
//Formularios
Config Interface::showCustomConfig() { //Personalizar juego
	int tmp_new_size;
	char tmp_player_one;

	showText("TIC-TAC-TOE");
	showText("Configuracion alternativa");
	cout<<"Inserte tamaño de tabla: ";
	cin>>tmp_new_size;
	Config tmpConfig = Config(tmp_new_size);

	return tmpConfig;
}
Machine Interface::showMachineConfig() {
	showText("Modo COM\nElija Nivel:");
	showText("[0] Facil");
	showText("[1] Normal");
	showText("[2] Dificil (NO)");
	int difficulty;
	cout<<"Elija el Nivel: ";
	cin>>difficulty;
	Machine tmp_machine = Machine();
	if (difficulty >= 0 && difficulty <= 2) {
		tmp_machine.setDifficulty(difficulty);
		tmp_machine.setActive(true);
	}
	return tmp_machine;
}
void Interface::showWelcomeOptions() {
	while (!state.isConfigured()) {
		state.enableConfigured();
		int option;
		showText("[1] Iniciar Juego");
		showText("[2] Personalizado");
		showText("[3] vs COM");
		showText("[4] vs COM - Personalizado");
		showText("[0] Salir");
		cout	<<":> ";
		cin >> option;

		if(option == 0){
			stopGame();
		}else if (option == 1) {
			// Retorna valores por defecto
		} else if (option == 2) {
			config = showCustomConfig(); // Muestra un formulario para personlizar valores
		} else if(option == 3) {
			machine = showMachineConfig();
		} else if(option == 4) {
			//Pa Probar
			config = showCustomConfig();
			machine = showMachineConfig();
		} else {
			showText("Ingrese una opcion Correcta");
			state.enableConfigured();
		}
	}
}

void Interface::showTableVector() { //Se ingresan valores para la jugada en cordenadas x,y por eso es Vector
	if (message != "") {
		cout<<"MENSAJE: "<<message<<endl;
	}
	showText("INGRESAR JUGADA (X, Y)");
	int x, y;
	cout<<"X: ";
	cin>>x;
	cout<<"Y: ";
	cin>>y;
	int flag = config.getTableSize();

	if ((x>=0 && x<flag) && (y>=0 && y<flag)) {
		if (tablero.getTable()[x][y] == '-') {
			Vector position;
			position = Vector(x, y);
			insertInTable(position);
			message = "";
		} else {
			message = "Jugada no realizada";
		}
	} else {
		message = "No seencuentra en los rangos";
	}
}

//Control del estado del juego
void Interface::startGame() {
	tablero = Tablero(config.getTableSize());
	tablero.resetTable();
	state.start();
}

void Interface::stopGame() {
	state.stop();
}

void Interface::finishGame(char whoIsWin) {
	string temp_string;
	temp_string.push_back(whoIsWin);
	score[temp_string]++;
	score["gamesCount"]++;
}

void Interface::insertInTable(Vector _position) {
	char player = getTurn(1);
	tablero.newMovement(_position.getX(), _position.getY(), player);
	if (tablero.checkIsWinning(player)) {
		finishGame(player);
		tablero.resetTable();
	}else 	if(tablero.isFulled()){
		finishGame('T');
		tablero.resetTable();
	}
}
//Actualizacion
void Interface::update() {
	//Mostrar Tabla
	showStateGame();
	tablero.showTable();
	//Modificar tabla
	showTableVector();
	if(machine.isActive() && getTurn(0) == machine.getIdentifier()) {
		Vector generated = machine.generateMove(tablero);
		insertInTable(generated);
	}
}

char Interface::getTurn(int _turn) {
	div_t target = div(count, 2);
	count += _turn;

	return (target.rem == 0) ? config.getPlayerOne() : config.getPlayerTwo();
}

//Retornar valores para poder ser configurados o ver el estado
State Interface::getState() {
	return state;
}

Config Interface::getConfig() {
	return config;
}

Tablero Interface::getTablero() {
	return tablero;
}
