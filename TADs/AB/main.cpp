/*
 * Proyecto : AB
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 19:48
 */

#include <iostream>
#include "AB.h"
#include "funcionesDeAB.h"
using namespace std;

int main(int argc, char** argv) {
	AB arbol;
	construir(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol esta vacio\n";
	else cout << "El arbol no esta vacio\n";

	plantarAB(arbol, nullptr, 120, nullptr);
	cout << "La raiz del arbol es: " << raiz(arbol) << endl;

	AB arbol1, arbol2, arbol3, arbol4;
	construir(arbol1); construir(arbol2);
	construir(arbol3); construir(arbol4);

	plantarAB(arbol1, nullptr, 25, nullptr);
	plantarAB(arbol2, nullptr, 75, nullptr);
	plantarAB(arbol3, arbol1, 50, arbol2);
	plantarAB(arbol4, nullptr, 150, nullptr);
	plantarAB(arbol, arbol3, 100, arbol4);

	cout << "Se insertaron elementos en el arbol:\n";
	cout << " - Recorrido en pre orden: ";
	recorrerEnPreOrden(arbol);
	cout << " - Recorrido en orden: ";
	recorrerEnOrden(arbol);
	cout << " - Recorrido en post orden: ";
	recorrerEnPostOrden(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol esta vacio\n";
	else cout << "El arbol no esta vacio\n";

	cout << "Altura del arbol: " << altura(arbol) << endl;
	cout << "Numero de hojas: " << numeroDeHojas(arbol) << endl;
	cout << "Numero de nodos: " << numeroDeNodos(arbol) << endl;
	if(esEquilibrado(arbol)) cout << "El arbol esta equilibrado\n";
	else cout << "El arbol no esta equilibrado\n";

	destruir(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol esta vacio\n";
	else cout << "El arbol no esta vacio\n";

	return 0;
}
