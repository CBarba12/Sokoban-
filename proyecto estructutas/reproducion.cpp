#include "reproducion.h"

reproducion::reproducion(vector<char> m, Jugador* j, Grid* g)
{
    lista = m;
    jugador = j;
    grid = g;
}

reproducion::reproducion(vector<char> m, Jugador* j, Grid* g, string arch)
{
    lista = m;
    jugador = j;
    grid = g;
    archivo = arch;
}

void reproducion::menu()
{

    char tecla;

    for (int i = 0; i < lista.size(); i++) {

        tecla = lista[i];

        system("cls");

        switch (tecla) {
        case 'd':
            jugador->moverDerecha();

            break;
        case 'a':
            jugador->moverIzquierda();

            break;
        case 'w':
            jugador->moverArriba();

            break;
        case 's':
            jugador->moverAbajo();

            break;
        default:
            break;
        }


        grid->imprimirGrid();
        Sleep(400);
    }


}