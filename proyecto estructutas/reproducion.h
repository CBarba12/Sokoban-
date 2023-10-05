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

#define delimitacampo '\t'
using namespace std;

class reproducion {

private:
    vector<char> lista;
    Jugador* jugador;
    Grid* grid;
    string archivo;

public:

    reproducion(vector<char> m, Jugador* j, Grid* g);
    reproducion(vector<char> m, Jugador* j, Grid* g, string arch);
    void menu();

};
