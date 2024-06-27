/*
 * Proyecto : ABB
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 20:36
 */

#include <iostream>
#include "funcionesDeABB.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;

int main(int argc, char** argv) {
	ArbolBinarioBusqueda arbol;
	construir(arbol);

	insertar(arbol, 100);
	insertar(arbol, 50);
	insertar(arbol, 200);
	insertar(arbol, 30);
	insertar(arbol, 75);
	insertar(arbol, 201);
	insertar(arbol, 1500);
	insertar(arbol, 150);

	cout << "Recorrer en pre orden: ";
	recorrerEnPreorden(arbol);
	cout << "Recorrer en orden: ";
	recorrerEnOrden(arbol);
	cout << "Recorrer en post orden: ";
	recorrerEnPostorden(arbol);

	if(buscarDato(arbol, 100)) cout << "El elemento 100 SI se encuentra en el arbol\n";
	else cout << "El elemento 100 NO se encuentra en el arbol\n";

	eliminarNodo(arbol, 100);

	if(buscarDato(arbol, 100)) cout << "El elemento 100 SI se encuentra en el arbol\n";
	else cout << "El elemento 100 NO se encuentra en el arbol\n";

	cout << "Recorrer en orden: ";
	recorrerEnOrden(arbol);

	destruir(arbol);

	return 0;
}
