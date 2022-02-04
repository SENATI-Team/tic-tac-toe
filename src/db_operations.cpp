#include <iostream>
#include <sqlite3.h>
#include "db_operations.h"
using namespace std;

sqlite3* db;

void get_connection() {
	int result = sqlite3_open("../db/tic-tac-toe.db", &db);

	if (result) {
		cout << "Error" << sqlite3_errmsg(db) << endl;
	}
}

void close_connection() {
	sqlite3_close(db);
}

void save() {

}
