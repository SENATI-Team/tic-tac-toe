#include <ctime>
#include <iostream>
#include <string>
#include "utility.h"
using namespace std;

void showText(string text)
{
	cout << text << endl;
}

string getCurrentTime()
{
	time_t current_time;
	time(&current_time);
	return asctime(localtime(&current_time));
}
