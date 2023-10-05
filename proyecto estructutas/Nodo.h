#pragma once

class Nodo {
public:
    char valor;
    int cuenta;
    char pos_ganadora;
    Nodo* arriba;
    Nodo* abajo;
    Nodo* izquierda;
    Nodo* derecha;

    bool esCaja;
    bool esObstaculo;


    Nodo(char val);
};

