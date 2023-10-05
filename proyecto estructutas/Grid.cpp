#include "Grid.h"

Grid::Grid(int filas, int columnas, string archivo) : filas(filas), columnas(columnas), primerNodo(nullptr) {

	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {

			char valor = ' ';


			Nodo* nuevoNodo = new Nodo(valor);


			if (j > 0) {
				Nodo* nodoIzquierda = obtenerNodo(i, j - 1);
				nodoIzquierda->derecha = nuevoNodo;
				nuevoNodo->izquierda = nodoIzquierda;
			}

			if (i > 0) {
				Nodo* nodoArriba = obtenerNodo(i - 1, j);
				nodoArriba->abajo = nuevoNodo;
				nuevoNodo->arriba = nodoArriba;
			}


			if (i == 0 && j == 0) {
				primerNodo = nuevoNodo;
			}

		}
	}




	nombre_Archivo = archivo;
	inicializar(nombre_Archivo);
}

Nodo* Grid::obtenerNodo(int fila, int columna) {
	if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
		Nodo* nodoActual = primerNodo;

		for (int i = 0; i < fila; i++) {
			nodoActual = nodoActual->abajo;
		}

		for (int j = 0; j < columna; j++) {
			nodoActual = nodoActual->derecha;
		}
		return nodoActual;
	}
	return nullptr;
}

bool Grid::tieneCaja(int fila, int columna) {
	Nodo* nodo = obtenerNodo(fila, columna);
	if (nodo) {
		return nodo->esCaja;
	}
	return false;
}

void Grid::imprimirGrid() {
	Nodo* nodoActual = primerNodo;
	for (int i = 0; i < filas; i++) {
		Nodo* filaActual = nodoActual;
		for (int j = 0; j < columnas; j++) {
			if (filaActual->esObstaculo) {
				cout << "X ";
			}
			else {
				cout << filaActual->valor << " ";
			}
			filaActual = filaActual->derecha;
		}
		cout << endl;
		nodoActual = nodoActual->abajo;
	}
}

Grid::~Grid()
{
}

void Grid::inicializar(string archivo) {

	string nombre;
	int fila = 0;
	int columna = 0;
	int contador_pila = 0;

	ifstream lectura2(archivo);

	while (lectura2.good())
	{
		getline(lectura2, nombre, '\n');
		for (int i = 0; i < nombre.length(); i++) {
			obtenerNodo(columna, i)->valor = nombre[i];
		}

		columna++;
	}

	Nodo* nodoActual = primerNodo;

	for (int i = 0; i < filas; i++) {
		Nodo* filaActual = nodoActual;
		for (int j = 0; j < columnas; j++) {
			if (obtenerNodo(i, j)->valor == '.' || obtenerNodo(i, j)->valor == '!') {
				obtenerNodo(i, j)->pos_ganadora = 'P';

				pila.push(contador_pila++);//veremos
			}

		}
	}




}

pair<int, int> Grid::pos_jugador()
{
	Nodo* nodoActual = primerNodo;
	for (int i = 0; i < filas; i++) {

		Nodo* filaActual = nodoActual;
		for (int j = 0; j < columnas; j++) {

			if (filaActual->valor == '@') {

				return make_pair(i, j);
			}


			filaActual = filaActual->derecha;
		}

		nodoActual = nodoActual->abajo;
	}
}

stack<int> Grid::getStack()
{
	return pila;
}

int Grid::top()
{
	return pila.top();
}

void Grid::pop_pila()
{
	pila.pop();
}

void Grid::push_pila()
{

	pila.push(pila.top() + 1);
}

int Grid::contador_posicion_total()
{

	Nodo* nodoActual = primerNodo;
	int contador_pila = 0;

	for (int i = 0; i < filas; i++) {
		Nodo* filaActual = nodoActual;
		for (int j = 0; j < columnas; j++) {
			if (obtenerNodo(i, j)->valor == '.' || obtenerNodo(i, j)->valor == '!') {
				contador_pila++;
			}

		}
	}

	return contador_pila;
}

void Grid::guardar_juego()
{

	ofstream archivo("Partida_guardar.txt");

	Nodo* nodoActual = primerNodo;

	stringstream s;



	for (int i = 0; i < filas; i++) {
		Nodo* filaActual = nodoActual;
		for (int j = 0; j < columnas; j++) {

			;
			if (j == columnas - 1) {
				s << obtenerNodo(i, j)->valor << '\n';
			}
			else
			{
				s << obtenerNodo(i, j)->valor;
			}
		}
	}


	archivo << s.str();
	archivo.close();

}
