#include "utiles.h"

utiles::utiles(string arch)
{
	colum = 0;
	fila = 0;
	archivo = arch;
}

int utiles::getfila()
{
	return fila;
}

int utiles::getcolum()
{
	return colum;
}

void utiles::setfila(int p)
{
	fila = p;
}

void utiles::setcolum(int p)
{
	colum = p;
}

int utiles::obtener_fila()
{

	ifstream lectura(archivo);
	string nombre;

	int maximo_de_fila = 0;
	int maximo_de_columna = 0;

	while (lectura.good())
	{
		getline(lectura, nombre, '\n');
		maximo_de_columna++;
		if (nombre.length() > maximo_de_fila)

			maximo_de_fila = (int)nombre.length();


	}
	lectura.close();

	return maximo_de_fila;
}

int utiles::obtener_Columna()
{
	ifstream lectura(archivo);
	string nombre;

	int maximo_de_fila = 0;
	int maximo_de_columna = 0;

	while (lectura.good())
	{
		getline(lectura, nombre, '\n');
		maximo_de_columna++;
		if (nombre.length() > maximo_de_fila)
			maximo_de_fila = (int)nombre.length();


	}
	lectura.close();

	return maximo_de_columna;
}