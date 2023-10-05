#pragma once
#include <conio.h> // Para la función _getch() en Windows
#include<fstream>
#include<sstream>
#include<Stack>
#include<vector>
#include<Windows.h>
#include"Nodo.h"
#include"Grid.h"
#include"utiles.h"

#define delimitacampo '\t'
using namespace std;

class Jugador {
	public:
	    char icono;
	    Nodo* posicion;
	    Grid* grid;
	
	
		Jugador(char icono, Nodo* posicion, Grid* grid);
	
	
	
		void moverDerecha();
	
		void moverIzquierda();
	
		void moverArriba();
	
		void moverAbajo();
	
	
	
	};
