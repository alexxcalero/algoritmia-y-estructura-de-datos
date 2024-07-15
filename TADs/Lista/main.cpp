/*
 * Proyecto : Lista
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 18:59
 */

#include <iostream>
#include "Lista.h"
#include "funcionesDeLista.h"
using namespace std;

int main(int argc, char** argv) {
	Lista lista;
	construir(lista);

	if(esListaVacia(lista)) cout << "La lista esta vacia\n";
	else cout << "La lista no esta vacia\n";

	cout << "La lista tiene " << longitud(lista) << " elementos\n";

	insertarOrdenado(lista, 2);
	insertarOrdenado(lista, 5);
	insertarOrdenado(lista, 4);
	insertarOrdenado(lista, 3);
	insertarOrdenado(lista, 6);
	insertarAlFinal(lista, 7);
	insertarAlFinal(lista, 8);
	insertarAlInicio(lista, 1);
	insertarAlInicio(lista, 0);

	cout << "Se insertaron los siguientes elementos a la lista: ";
	imprimir(lista);

	if(esListaVacia(lista)) cout << "La lista esta vacia\n";
	else cout << "La lista no esta vacia\n";

	cout << "La lista tiene " << longitud(lista) << " elementos\n";

	cout << "El primer elemento de la lista es: " << primero(lista) << endl;
	cout << "El ultimo elemento de la lista es: " << ultimo(lista) << endl;

	eliminarCabeza(lista);
	int primerElemento = primero(lista);
	cout << "Ahora, el nuevo primer elemento de la lista es: " << primerElemento << endl;

	destruir(lista);

	if(esListaVacia(lista)) cout << "La lista esta vacia\n";
	else cout << "La lista no esta vacia\n";

	cout << "La lista tiene " << longitud(lista) << " elementos\n";

	return 0;
}
