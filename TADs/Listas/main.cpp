/*
 * Proyecto : Listas
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 16:18
 */

#include <iostream>
#include "Lista.h"
#include "funcionesDeLista.h"
using namespace std;

int main(int argc, char** argv) {
	Lista lista;
	construir(lista);

	if(esListaVacia(lista)) cout << "La lista SI esta vacia\n";
	else cout << "La lista NO esta vacia\n";

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

	if(esListaVacia(lista)) cout << "La lista SI esta vacia\n";
	else cout << "La lista NO esta vacia\n";

	cout << "La lista tiene " << longitud(lista) << " elementos\n";

	cout << "Elementos de la lista: ";
	imprimir(lista);

	cout << "El primer elemento de la lista es: " << cabeza(lista) << endl;
	cout << "El ultimo elemento de la lista es: " << cola(lista) << endl;

	eliminarCabeza(lista);
	int primerElemento = cabeza(lista);
	cout << "El nuevo primer elemento de la lista es: " << primerElemento << endl;

	destruir(lista);

	if(esListaVacia(lista)) cout << "La lista SI esta vacia\n";
	else cout << "La lista NO esta vacia\n";

	cout << "La lista tiene " << longitud(lista) << " elementos\n";

	return 0;
}
