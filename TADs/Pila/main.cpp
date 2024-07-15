/*
 * Proyecto : Pila
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:31
 */

#include <iostream>
#include "Pila.h"
#include "funcionesDePila.h"
using namespace std;

int main(int argc, char** argv) {
	Pila pila;
	construir(pila);

	if(esPilaVacia(pila)) cout << "La pila esta vacia\n";
	else cout << "La pila no esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	for(int i = 0; i < 9; i++) apilar(pila, i);

	cout << "Se apilaron los siguientes elementos a la pila: ";
	imprimir(pila);

	if(esPilaVacia(pila)) cout << "La pila esta vacia\n";
	else cout << "La pila no esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	cout << "La cima de la pila es: " << cima(pila) << endl;
	
	desapilar(pila);
	int primerElemento = cima(pila);
	cout << "Ahora, la nueva cima de la pila es: " << primerElemento << endl;

	destruir(pila);

	if(esPilaVacia(pila)) cout << "La pila esta vacia\n";
	else cout << "La pila no esta vacia\n";

	cout << "La pila tiene " << longitud(pila) << " elementos\n";

	return 0;
}
