/*
 * Proyecto : Colas
 * Archivo  : funcionesDeCola.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 18:39
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

// No retorna ningun valor. Se tiene que usar primero la funcion primero()
void desencolar(Cola &cola) {
	eliminarCabeza(cola.lista);
}

int primero(const Cola &cola) {
	return cabeza(cola.lista);
}

int ultimo(const Cola &c) {
	return cola(c.lista);
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
