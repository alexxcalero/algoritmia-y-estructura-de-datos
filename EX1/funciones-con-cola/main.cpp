/*
 * Proyecto : funciones-con-cola
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 17 de mayo de 2024, 21:22
 */

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;

void ordenarCola(Cola &cola) {
	if(esColaVacia(cola))
		return;

	int mayor = desencolar(cola);
	for(int i = 0; i < longitud(cola); i++) {
		int aux = desencolar(cola);
		if(aux > mayor) {
			encolar(cola, mayor);
			mayor = aux;
		} else {
			encolar(cola, aux);
		}
	}
	ordenarCola(cola);
	encolar(cola, mayor);
}

void invertirCola(Cola &cola) {
	if(esColaVacia(cola))
		return;

	int dato = desencolar(cola);
	invertirCola(cola);
	encolar(cola, dato);
}

int main(int argc, char** argv) {
	Cola cola;
	construir(cola);

	encolar(cola, 3);
	encolar(cola, 2);
	encolar(cola, 10);
	encolar(cola, 5);
	encolar(cola, 8);
	encolar(cola, 7);
	encolar(cola, 4);

	cout << "Cola original: ";
	imprime(cola);

	ordenarCola(cola);
	cout << "Cola ordenada: ";
	imprime(cola);

	invertirCola(cola);
	cout << "Cola invertida: ";
	imprime(cola);

	return 0;
}
