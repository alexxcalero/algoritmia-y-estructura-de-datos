/*
 * Proyecto : funciones-con-lista
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 17 de mayo de 2024, 23:46
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;

void invertirLista(Lista &lista) {
	if(esListaVacia(lista) || longitud(lista) == 1)
		return;

	Nodo *anterior = nullptr;
	Nodo *siguiente = nullptr;
	Nodo *actual = lista.cabeza;
	while(actual) {
		siguiente = actual->siguiente;
		actual->siguiente = anterior;
		anterior = actual;
		actual = siguiente;
	}
	lista.cabeza = anterior;
}

void invertirIzquierda(Lista &lista) {
	if(esListaVacia(lista) || longitud(lista) == 1)
		return;

	Nodo *ultimo = obtenerUltimoNodo(lista);
	Nodo *cabeza = lista.cabeza;
	Nodo *nuevaCabeza = lista.cabeza->siguiente;
	cabeza->siguiente = nullptr;
	ultimo->siguiente = cabeza;
	lista.cabeza = nuevaCabeza;
}

void eliminarRepetidos(Lista &lista) {
	if(esListaVacia(lista) || longitud(lista) == 1)
		return;

	Nodo *recorrido = lista.cabeza;
	while(recorrido->siguiente != nullptr) {
		Nodo *aux = recorrido->siguiente;
		Nodo *anterior = recorrido;
		while(aux != nullptr) {
			if(recorrido->elemento == aux->elemento) {
				Nodo *eliminar = aux;
				anterior->siguiente = aux->siguiente;
				aux = aux->siguiente;
				eliminar->siguiente = nullptr;
				delete eliminar;
				lista.longitud--;
			} else {
				anterior = aux;
				aux = aux->siguiente;
			}
		}
		recorrido = recorrido->siguiente;
	}
}

int main(int argc, char** argv) {
	Lista lista;
	construir(lista);

	insertarAlFinal(lista, 3);
	insertarAlFinal(lista, 1);
	insertarAlFinal(lista, 8);
	insertarAlFinal(lista, 5);
	insertarAlFinal(lista, 10);
	insertarAlFinal(lista, 6);
	insertarAlFinal(lista, 5);
	insertarAlFinal(lista, 3);
	insertarAlFinal(lista, 4);
	insertarAlFinal(lista, 2);
	insertarAlFinal(lista, 8);

	cout << "Lista original: ";
	imprime(lista);

	invertirLista(lista);
	cout << "Lista invertida: ";
	imprime(lista);

	invertirIzquierda(lista);
	cout << "Lista invertida a la izquierda: ";
	imprime(lista);

	eliminarRepetidos(lista);
	cout << "Lista sin elementos repetidos: ";
	imprime(lista);

	return 0;
}
