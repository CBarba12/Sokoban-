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

#define delimitacampo '\t'
using namespace std;

class utiles {
	private:
	    int colum;
	    int fila;
	    string archivo;
	public:
		utiles(string arch);
	   

		int getfila();
		
		int getcolum();
		void setfila(int p);
		void setcolum(int p);
	
	
		int obtener_fila();
		int obtener_Columna();
	
	};
