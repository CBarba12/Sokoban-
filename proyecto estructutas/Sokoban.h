#pragma once
#include <iostream>
#include <conio.h> // Para la función _getch() en Windows
#include<fstream>
#include<sstream>
#include<Stack>
#include<vector>
#include<Windows.h>
#include"Nodo.h"
#include"Grid.h"
#include"utiles.h"
#include"Jugador.h"
#include"reproducion.h"

#define delimitacampo '\t'
using namespace std;

class Sokoban
{
public:
    Sokoban() {}
    void guardarPartida(vector<char> m, string nombre_ARCHIVO, int des);

    void nuevoJuego(int nivel);

    void cargarPartidaGuardada();
};

