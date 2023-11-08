#include <cstring>
#include <iostream>
//#include <sqlite3.h>
#include <string>
#include "db_operations.h"
#include "utility.h"

using namespace std;
using namespace tic_tac_toe;

//sqlite3* db;

void tic_tac_toe::closeConnection()
{
	// sqlite3_close(db);
}

void tic_tac_toe::openConnection()
{
	// int result = sqlite3_open("db/tic-tac-toe.db", &db);
	// if (result)
	// {
	// 	cout << "Error" << sqlite3_errmsg(db) << endl;
	// }
}

void tic_tac_toe::saveGame(char player)
{
	// string stmt_str = "INSERT INTO game (date, winner) VALUES ('" + getCurrentTime() + "', '" + player + "')";
	// int n = stmt_str.length();
	// char stmt_chr[n + 1];

	// strcpy(stmt_chr, stmt_str.c_str());

	// sqlite3_exec(db, stmt_chr, NULL, 0, NULL);
}
