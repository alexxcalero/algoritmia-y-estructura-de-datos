/*
 * Proyecto : EX1-2023_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de mayo de 2024, 22:54
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
using namespace std;

int main(int argc, char** argv) {
	// INCISO A
	Cola eventos1;
	construir(eventos1);

	ifstream archA("datosA.txt", ios::in);
	if(!archA.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datosA\n";
		exit(1);
	}

	int prioridad;
	char codigo[10];
	while(1) {
		archA >> codigo;
		if(archA.eof()) break;
		archA >> prioridad;
		archA.get();
		encolarPrioridad(eventos1, prioridad, codigo);
	}
	cout << "INCISO A:\n";
	imprime(eventos1);


	// INCISO B
	Cola eventos2, eventosFinal;
	construir(eventos2);
	construir(eventosFinal);

	Pila pila;
	construir(pila);

	ifstream archB("datosB.txt", ios::in);
	if(!archB.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datosB\n";
		exit(1);
	}

	while(1) {
		archB >> codigo;
		if(archB.eof()) break;
		archB >> prioridad;
		archB.get();
		encolarPrioridad(eventos2, prioridad, codigo);
	}
	cout << "\nINCISO B:\n";
	cout << left << setw(18) << "Cola original:" << right;
	imprime(eventos2);

	// Paso los elementos de la cola a la pila de manera alternada
	while(!esColaVacia(eventos2)) {
		if(esPilaVacia(pila))
			apilar(pila, desencolar(eventos2));
		else {
			Elemento exCola = desencolar(eventos2);
			Elemento cimaPila = cima(pila);
			if(exCola.prioridad == cimaPila.prioridad)
				encolar(eventos2, exCola.prioridad, exCola.codigo);
			else
				apilar(pila, exCola);
		}
	}

	// Devuelvo los elementos de la pila a la cola.
	// Pero me van a quedar en el orden inverso al que los quiero.
	while(!esPilaVacia(pila)) {
		Elemento elem = desapilar(pila);
		encolar(eventos2, elem.prioridad, elem.codigo);
	}
	// Por lo tanto, apilo nuevamente todos los elemento de la cola para luevo
	// volver a encolarlos y tenerlos en el orden que se pide en el problema
	while(!esColaVacia(eventos2)) apilar(pila, desencolar(eventos2));
	while(!esPilaVacia(pila)) {
		Elemento elem = desapilar(pila);
		encolar(eventos2, elem.prioridad, elem.codigo);
	}

	cout << left << setw(18) << "Cola intercalada:" << right;
	imprime(eventos2);

	return 0;
}
