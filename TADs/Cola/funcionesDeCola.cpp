/*
 * Proyecto : Cola
 * Archivo  : funcionesDeCola.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:19
 */

#include <iostream>
#include "Cola.h"
#include "funcionesDeCola.h"
#include "funcionesDeLista.h"
using namespace std;

void construir(Cola &cola) {
	construir(cola.lista);
}

bool esColaVacia(const Cola &cola) {
	return esListaVacia(cola.lista);
}

int longitud(const Cola &cola) {
	return longitud(cola.lista);
}

void encolar(Cola &cola, int dato) {
	insertarAlFinal(cola.lista, dato);
}

// No retorna ningun valor. Se tiene que usar antes la funcion primero()
void desencolar(Cola &cola) {
	if(esColaVacia(cola)) {
		cout << "La cola esta vacia\n";
		return;
	}
	eliminarCabeza(cola.lista);
}

int primero(const Cola &cola) {
	if(esColaVacia(cola)) {
		cout << "La cola esta vacia, se retorna -1\n";
		return -1;
	}
	return primero(cola.lista);
}

int ultimo(const Cola &cola) {
	if(esColaVacia(cola)) {
		cout << "La cola esta vacia, se retorna -1\n";
		return -1;
	}
	return ultimo(cola.lista);
}

void imprimir(const Cola &cola) {
	if(esColaVacia(cola)) {
		cout << "La cola esta vacia\n";
		return;
	}
	imprimir(cola.lista);
}

void destruir(Cola &cola) {
	destruir(cola.lista);
}
