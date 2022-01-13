rem Script para realizar la compilación y ejecución en Windows

@echo off
cd ..

IF NOT EXIST bin (
mkdir bin
)

g++ src\*.cpp -o bin\tic_tac_toe && bin\tic_tac_toe
cd script
