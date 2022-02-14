#!/bin/bash

# Script para realizar la compilación y ejecución en Linux

cd ..
FILE=bin/tic_tac_toe

if [ ! -d bin ]; then
	mkdir bin
fi


g++ src/*.cpp -l sqlite3 -I src/sqlite-amalgamation-3370200 -o $FILE -Wall && $FILE
cd script
