#include <iostream>
#include <sqlite3.h>
#include <string>
#include <cstring>
#include "db_operations.h"
#include "utility.h"
using namespace std;

sqlite3* db;

void get_connection() {
	// int result = sqlite3_open("../db/tic-tac-toe.db", &db);
	int result = sqlite3_open("db/tic-tac-toe.db", &db);

	if (result) {
		cout << "Error" << sqlite3_errmsg(db) << endl;
	}
}

void close_connection() {
	sqlite3_close(db);
}

void save_game()
{
	string stmt_str = "INSERT INTO game (date, winner) VALUES ('" + get_current_time() + "', 'O')";
	int n = stmt_str.length();
	char stmt_chr[n + 1];

	strcpy(stmt_chr, stmt_str.c_str());

	int rc = sqlite3_exec(db, stmt_chr, NULL, 0, NULL);
}
