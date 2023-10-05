#pragma once
#include <iostream>
#include <conio.h> // Para la función _getch() en Windows
#include<fstream>
#include<sstream>
#include<Stack>
#include<vector>
#include<Windows.h>
#include"Nodo.h"

#define delimitacampo '\t'
using namespace std;


class Grid {
	private:
	    Nodo* primerNodo;
	    int filas;
	    int columnas;
	    stack<int>pila;
	    string nombre_Archivo;
	
	
	public:
	
		Grid(int filas, int columnas, string archivo);
		Nodo* obtenerNodo(int fila, int columna);
		bool tieneCaja(int fila, int columna);
		void imprimirGrid();
		~Grid();
		void inicializar(string archivo);
		pair<int, int> pos_jugador();
		stack<int> getStack();
		int top();
		void pop_pila();
		void push_pila();
		int contador_posicion_total();
		void guardar_juego();

	};

