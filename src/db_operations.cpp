#include <cstring>
#include <iostream>
#include <sqlite3.h>
#include <string>
#include "db_operations.h"
#include "utility.h"
using namespace std;

sqlite3* db;

void close_connection() {
	sqlite3_close(db);
}

void get_connection() {
	int result = sqlite3_open("db/tic-tac-toe.db", &db);

	if (result) {
		cout << "Error" << sqlite3_errmsg(db) << endl;
	}
}

void save_game(char player) {
	string stmt_str = "INSERT INTO game (date, winner) VALUES ('" + get_current_time() + "', '" + player + "')";
	int n = stmt_str.length();
	char stmt_chr[n + 1];

	strcpy(stmt_chr, stmt_str.c_str());

	sqlite3_exec(db, stmt_chr, NULL, 0, NULL);
	// int rc = sqlite3_exec(db, stmt_chr, NULL, 0, NULL);
}
