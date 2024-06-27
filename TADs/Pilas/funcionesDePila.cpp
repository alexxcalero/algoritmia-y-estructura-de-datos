/*
 * Proyecto : Pilas
 * Archivo  : funcionesDePila.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 19:04
 */

#include <iostream>
#include "Pila.h"
#include "funcionesDePila.h"
#include "funcionesDeLista.h"
using namespace std;

void construir(Pila &pila) {
	construir(pila.lista);
}

bool esPilaVacia(const Pila &pila) {
	return esListaVacia(pila.lista);
}

int longitud(const Pila &pila) {
	return longitud(pila.lista);
}

void apilar(Pila &pila, int dato) {
	insertarAlInicio(pila.lista, dato);
}

// No retorna ningun valor. Se tiene que usar primero la funcion cima()
void desapilar(Pila &pila) {
	eliminarCabeza(pila.lista);
}

int cima(const Pila &pila) {
	if(esPilaVacia(pila)) {
		cout << "La pila esta vacia, se retorna -1\n";
		return -1;
	}

	return cabeza(pila.lista);
}

void imprimir(const Pila &pila) {
	if(esPilaVacia(pila)) {
		cout << "La pila esta vacia\n";
		return;
	}
	imprimir(pila.lista);
}

void destruir(Pila &pila) {
	destruir(pila.lista);
}
