/*
 * Proyecto : funciones-con-pila
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 17 de mayo de 2024, 23:06
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void pasaPilaIterativo(Pila &pila, Pila &pila2) {
	int valor, aux, n;
	while(!esPilaVacia(pila)) {
		valor = desapilar(pila);
		n = 0;
		while(!esPilaVacia(pila)) {
			apilar(pila2, valor);
			n++;
			valor = desapilar(pila);
		}
		while(n != 0) {
			aux = desapilar(pila2);
			apilar(pila, aux);
			n--;
		}
		apilar(pila2, valor);
	}
}

void pasaPilaRecursivo(Pila &pila, Pila &pila2) {
	if(esPilaVacia(pila))
		return;

	int valor = desapilar(pila);
	pasaPilaRecursivo(pila, pila2);
	apilar(pila2, valor);
}

int main(int argc, char** argv) {
	Pila pila, pila2;
	construir(pila);
	construir(pila2);

	apilar(pila, 1);
	apilar(pila, 2);
	apilar(pila, 3);
	apilar(pila, 4);
	apilar(pila, 5);
	apilar(pila, 6);
	apilar(pila, 7);
	apilar(pila, 8);

	cout << "Pila 1: ";
	imprimir(pila);

//	pasaPilaRecursivo(pila, pila2);
	pasaPilaIterativo(pila, pila2);

	cout << "Pila 2: ";
	imprimir(pila2);

	return 0;
}
