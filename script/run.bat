rem Script para realizar la compilacion y ejecucion en Windows

@echo off
cd ..

IF NOT EXIST bin (
mkdir bin
)

rem g++ -Wall -Isrc -Isrc\database -Isrc\sqlite-amalgamation-3370200 -Isrc\user_interface src\*.cpp src\database\*.cpp src\sqlite-amalgamation-3370200\*.c src\user_interface\*.cpp -o bin\tic_tac_toe && bin\tic_tac_toe
g++ -Wall -Isrc -Isrc\user_interface src\*.cpp src\user_interface\*.cpp -o bin\tic_tac_toe && bin\tic_tac_toe
cd script
