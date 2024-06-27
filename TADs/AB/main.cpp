/*
 * Proyecto : AB
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 19:55
 */

#include <iostream>
#include "ArbolBinario.h"
#include "funcionesDeAB.h"
using namespace std;

int main(int argc, char** argv) {
	ArbolBinario arbol;
	construir(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol SI esta vacio\n";
	else cout << "El arbol NO esta vacio\n";

	plantarAB(arbol, nullptr, 100, nullptr);
	cout << "La raiz del arbol es: " << arbol.raiz->dato << endl;

	ArbolBinario arbol1, arbol2, arbol3, arbol4;
	construir(arbol1); construir(arbol2);
	construir(arbol3); construir(arbol4);

	plantarAB(arbol1, nullptr, 25, nullptr);
	plantarAB(arbol2, nullptr, 75, nullptr);
	plantarAB(arbol3, arbol1, 50, arbol2);
	plantarAB(arbol4, nullptr, 150, nullptr);
	plantarAB(arbol, arbol3, 100, arbol4);

	if(esArbolVacio(arbol)) cout << "El arbol SI esta vacio\n";
	else cout << "El arbol NO esta vacio\n";

	cout << "Recorrer en pre orden: ";
	recorrerEnPreorden(arbol);
	cout << "Recorrer en orden: ";
	recorrerEnOrden(arbol);
	cout << "Recorrer en post orden: ";
	recorrerEnPostorden(arbol);

	cout << "Altura del arbol: " << altura(arbol) << endl;
	cout << "Numero de hojas: " << numeroDeHojas(arbol) << endl;
	cout << "Numero de nodos: " << numeroDeNodos(arbol) << endl;
	if(esEquilibrado(arbol)) cout << "El arbol SI es equilibrado\n";
	else cout << "El arbol NO es equilibrado\n";

	destruir(arbol);

	if(esArbolVacio(arbol)) cout << "El arbol SI esta vacio\n";
	else cout << "El arbol NO esta vacio\n";

	return 0;
}
