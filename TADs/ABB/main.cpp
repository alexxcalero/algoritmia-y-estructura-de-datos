/*
 * Proyecto : ABB
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 20:11
 */

#include <iostream>
#include "ABB.h"
#include "funcionesDeABB.h"
using namespace std;

int main(int argc, char** argv) {
	ABB arbol;
	construir(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol esta vacio\n";
	else cout << "El arbol no esta vacio\n";

	insertar(arbol, 100);
	insertar(arbol, 50);
	insertar(arbol, 200);
	insertar(arbol, 30);
	insertar(arbol, 75);
	insertar(arbol, 210);
	insertar(arbol, 1500);
	insertar(arbol, 150);

	cout << "Se insertaron elementos en el arbol:\n";
	cout << " - Recorrido en pre orden: ";
	recorrerEnPreOrden(arbol);
	cout << " - Recorrido en orden: ";
	recorrerEnOrden(arbol);
	cout << " - Recorrido en post orden: ";
	recorrerEnPostOrden(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol esta vacio\n";
	else cout << "El arbol no esta vacio\n";

	int dato = 100;
	if(buscarDato(arbol, dato)) cout << "Se encontro el elemento " << dato << " en el arbol\n";
	else cout << "No se encontro el elemento " << dato << " en el arbol\n";

	eliminarNodo(arbol, dato);

	if(buscarDato(arbol, dato)) cout << "Se encontro el elemento " << dato << " en el arbol\n";
	else cout << "No se encontro el elemento " << dato << " en el arbol\n";

	cout << "Recorrido en orden: ";
	recorrerEnOrden(arbol);

	destruir(arbol);

	return 0;
}
