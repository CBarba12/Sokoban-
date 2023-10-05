#include "Jugador.h"

Jugador::Jugador(char icono, Nodo* posicion, Grid* grid) : icono(icono), posicion(posicion), grid(grid) {}

void Jugador::moverDerecha() {
	Nodo* siguienteNodo = posicion->derecha;

	/*if (siguienteNodo && !siguienteNodo->esObstaculo) {
		if (!siguienteNodo->esCaja) {
			posicion->valor = ' ';
			siguienteNodo->valor = icono;
			posicion = siguienteNodo;
		}

		else {
			Nodo* nodoDetrasCaja = siguienteNodo->derecha;

			if (nodoDetrasCaja && nodoDetrasCaja->valor == ' ' && !nodoDetrasCaja->esObstaculo) {

				posicion->valor = ' ';
				siguienteNodo->valor = icono;
				nodoDetrasCaja->valor = '$';
				siguienteNodo->esCaja = false;
				nodoDetrasCaja->esCaja = true;
				posicion = siguienteNodo;
			}
		}
	}*/

	if (siguienteNodo && siguienteNodo->valor != '#') {


		if (siguienteNodo->valor != '$' && siguienteNodo->valor != '!') {

			if (siguienteNodo->valor == '!') {

				if (siguienteNodo->derecha->pos_ganadora == 'P') {

					siguienteNodo->derecha->valor = '!';

					if (siguienteNodo->pos_ganadora == 'P') {

						siguienteNodo->valor = icono;
						posicion->valor = ' ';
					}
					else
					{
						siguienteNodo->valor = ' ';
					}

					posicion = siguienteNodo;
				}
				else {

					siguienteNodo->derecha->valor = '$';

					if (posicion->pos_ganadora == 'P') {
						posicion->valor = '.';
					}
					else
					{
						posicion->valor = ' ';
					}
					siguienteNodo->valor = icono;
					siguienteNodo->pos_ganadora = 'P';

					posicion = siguienteNodo;
				}

			}
			else if (posicion->pos_ganadora == 'P' && posicion->valor == icono) {

				posicion->valor = '.';
				siguienteNodo->valor = icono;

				posicion = siguienteNodo;

			}

			else
			{
				posicion->valor = ' ';
				siguienteNodo->valor = icono;
				posicion = siguienteNodo;
			}
		}

		else {
			Nodo* nodoDetrasCaja = siguienteNodo->derecha;

			if (nodoDetrasCaja && nodoDetrasCaja->valor == ' ' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P')
						grid->push_pila();

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					siguienteNodo->esCaja = false;
					nodoDetrasCaja->esCaja = true;
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P' && siguienteNodo->valor == '@')
						grid->push_pila();
				}


			}


			if (nodoDetrasCaja && nodoDetrasCaja->valor == '.' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';


					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';



					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}



				siguienteNodo->esCaja = false;
				nodoDetrasCaja->esCaja = true;
				posicion = siguienteNodo;
			}
		}
	}

}

void Jugador::moverIzquierda() {

	Nodo* siguienteNodo = posicion->izquierda;

	if (siguienteNodo && siguienteNodo->valor != '#') {

		if (siguienteNodo->valor != '$' && siguienteNodo->valor != '!') {

			if (siguienteNodo->valor == '!') {

				if (siguienteNodo->izquierda->pos_ganadora == 'P') {

					siguienteNodo->izquierda->valor = '!';

					if (siguienteNodo->pos_ganadora == 'P') {

						siguienteNodo->valor = icono;
						posicion->valor = ' ';
					}
					else
					{
						siguienteNodo->valor = ' ';
					}

					posicion = siguienteNodo;
				}
				else {

					siguienteNodo->izquierda->valor = '$';

					if (posicion->pos_ganadora == 'P') {
						posicion->valor = '.';
					}
					else
					{
						posicion->valor = ' ';
					}
					siguienteNodo->valor = icono;
					siguienteNodo->pos_ganadora = 'P';

					posicion = siguienteNodo;
				}

			}
			else if (posicion->pos_ganadora == 'P' && posicion->valor == icono) {

				posicion->valor = '.';
				siguienteNodo->valor = icono;

				posicion = siguienteNodo;

			}

			else
			{
				posicion->valor = ' ';
				siguienteNodo->valor = icono;
				posicion = siguienteNodo;
			}
		}

		else {
			Nodo* nodoDetrasCaja = siguienteNodo->izquierda;
			if (nodoDetrasCaja && nodoDetrasCaja->valor == ' ' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P')
						grid->push_pila();

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					siguienteNodo->esCaja = false;
					nodoDetrasCaja->esCaja = true;
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P' && siguienteNodo->valor == '@')
						grid->push_pila();
				}


			}


			if (nodoDetrasCaja && nodoDetrasCaja->valor == '.' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';


					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';



					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}



				siguienteNodo->esCaja = false;
				nodoDetrasCaja->esCaja = true;
				posicion = siguienteNodo;
			}
		}
	}

}

void Jugador::moverArriba() {
	Nodo* siguienteNodo = posicion->arriba;

	if (siguienteNodo && siguienteNodo->valor != '#') {

		if (siguienteNodo->valor != '$' && siguienteNodo->valor != '!') {

			if (siguienteNodo->valor == '!') {

				if (siguienteNodo->arriba->pos_ganadora == 'P') {

					siguienteNodo->arriba->valor = '!';

					if (siguienteNodo->pos_ganadora == 'P') {

						siguienteNodo->valor = icono;
						posicion->valor = ' ';
					}
					else
					{
						siguienteNodo->valor = ' ';
					}

					posicion = siguienteNodo;
				}
				else {

					siguienteNodo->arriba->valor = '$';

					if (posicion->pos_ganadora == 'P') {
						posicion->valor = '.';
					}
					else
					{
						posicion->valor = ' ';
					}
					siguienteNodo->valor = icono;
					siguienteNodo->pos_ganadora = 'P';

					posicion = siguienteNodo;
				}

			}
			else if (posicion->pos_ganadora == 'P' && posicion->valor == icono) {

				posicion->valor = '.';
				siguienteNodo->valor = icono;

				posicion = siguienteNodo;

			}

			else
			{
				posicion->valor = ' ';
				siguienteNodo->valor = icono;
				posicion = siguienteNodo;
			}
		}

		else {
			Nodo* nodoDetrasCaja = siguienteNodo->arriba;
			if (nodoDetrasCaja && nodoDetrasCaja->valor == ' ' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P')
						grid->push_pila();

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					siguienteNodo->esCaja = false;
					nodoDetrasCaja->esCaja = true;
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P' && siguienteNodo->valor == '@')
						grid->push_pila();
				}


			}


			if (nodoDetrasCaja && nodoDetrasCaja->valor == '.' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';


					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';



					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}



				siguienteNodo->esCaja = false;
				nodoDetrasCaja->esCaja = true;
				posicion = siguienteNodo;
			}
		}
	}
}

void Jugador::moverAbajo() {
	Nodo* siguienteNodo = posicion->abajo;

	if (siguienteNodo && siguienteNodo->valor != '#') {

		if (siguienteNodo->valor != '$' && siguienteNodo->valor != '!') {

			if (siguienteNodo->valor == '!') {

				if (siguienteNodo->abajo->pos_ganadora == 'P') {

					siguienteNodo->abajo->valor = '!';

					if (siguienteNodo->pos_ganadora == 'P') {

						siguienteNodo->valor = icono;
						posicion->valor = ' ';
					}
					else
					{
						siguienteNodo->valor = ' ';
					}

					posicion = siguienteNodo;
				}
				else {

					siguienteNodo->abajo->valor = '$';

					if (posicion->pos_ganadora == 'P') {
						posicion->valor = '.';
					}
					else
					{
						posicion->valor = ' ';
					}
					siguienteNodo->valor = icono;
					siguienteNodo->pos_ganadora = 'P';

					posicion = siguienteNodo;
				}

			}
			else if (posicion->pos_ganadora == 'P' && posicion->valor == icono) {

				posicion->valor = '.';
				siguienteNodo->valor = icono;

				posicion = siguienteNodo;

			}

			else
			{
				posicion->valor = ' ';
				siguienteNodo->valor = icono;
				posicion = siguienteNodo;
			}
		}




		else {
			Nodo* nodoDetrasCaja = siguienteNodo->abajo;

			if (nodoDetrasCaja && nodoDetrasCaja->valor == ' ' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P')
						grid->push_pila();

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '$';
					siguienteNodo->esCaja = false;
					nodoDetrasCaja->esCaja = true;
					posicion = siguienteNodo;

					if (siguienteNodo->pos_ganadora == 'P' && siguienteNodo->valor == '@')
						grid->push_pila();
				}


			}


			if (nodoDetrasCaja && nodoDetrasCaja->valor == '.' && nodoDetrasCaja->valor != '#') {

				if (posicion->pos_ganadora == 'P') {
					posicion->valor = '.';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';


					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}
				else
				{
					posicion->valor = ' ';
					siguienteNodo->valor = icono;
					nodoDetrasCaja->valor = '!';



					if (siguienteNodo->valor == icono && siguienteNodo->pos_ganadora == 'P') {
						grid->push_pila();
					}
					if (nodoDetrasCaja->valor == '!' && nodoDetrasCaja->pos_ganadora == 'P') {
						grid->pop_pila();
					}

				}



				siguienteNodo->esCaja = false;
				nodoDetrasCaja->esCaja = true;
				posicion = siguienteNodo;
			}
		}
	}


}

