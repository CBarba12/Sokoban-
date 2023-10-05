#include <iostream>
#include <conio.h> // Para la funci�n _getch() en Windows
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
#include"Sokoban.h"

#define delimitacampo '\t'
using namespace std;



//----------------------------------------------------------------------



int main() {


    int opcion;
    Sokoban sok;
    do {
        system("cls");
        cout << "-------------------------------BIENVENIDO AL JUEGO SOKOBAN ------------------------------------------------------" << endl;
        cout << endl << endl;
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Nuevo Juego" << endl;
        cout << "2. Cargar Partida Guardada" << endl;
        cout << "3. Salir del Juego" << endl;
        cout << "Ingrese su opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:

            sok.nuevoJuego(1);  
            break;
        case 2:
            sok.cargarPartidaGuardada();
            break;
        case 3:
            cout << "�Gracias por jugar! Hasta luego." << endl;
            break;
        default:
            cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
            break;
        }
    } while (opcion != 3);

    return 0;


}
