/*
 * Proyecto : Pilas
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 19:04
 */

#include <iostream>
#include "Pila.h"
#include "funcionesDePila.h"
using namespace std;

int main(int argc, char** argv) {
	Pila pila;
	construir(pila);

	if(esPilaVacia(pila)) cout << "La pila SI esta vacia\n";
	else cout << "La pila NO esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	for(int i = 0; i < 9; i++) apilar(pila, i);

	if(esPilaVacia(pila)) cout << "La pila SI esta vacia\n";
	else cout << "La pila NO esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	cout << "Elementos de la pila: ";
	imprimir(pila);
	cout << "La cima de la pila es: " << cima(pila) << endl;

	desapilar(pila);
	int primerElemento = cima(pila);
	cout << "La nueva cima de la pila es: " << primerElemento << endl;

	destruir(pila);

	if(esPilaVacia(pila)) cout << "La pila SI esta vacia\n";
	else cout << "La pila NO esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	return 0;
}
