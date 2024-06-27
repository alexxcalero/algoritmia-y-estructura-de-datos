/*
 * Proyecto : Listas
 * Archivo  : funcionesDeLista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 16:20
 */

#include <iostream>
#include "Lista.h"
#include "funcionesDeLista.h"
using namespace std;

void construir(Lista &lista) {
	lista.cabeza = nullptr;
	lista.cola = nullptr;
	lista.longitud = 0;
}

bool esListaVacia(const Lista &lista) {
	return lista.cabeza == nullptr && lista.cola == nullptr;
}

int longitud(const Lista &lista) {
	return lista.longitud;
}

void insertarAlInicio(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = lista.cabeza;

	lista.cabeza = nuevoNodo;
	if(lista.cola == nullptr)  // Para el primer elemento que inserto en la lista
		lista.cola = nuevoNodo;
	lista.longitud++;
}

void insertarAlFinal(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = nullptr;

	if(esListaVacia(lista))  // Para el primer elemento que inserto en la lista
		lista.cabeza = nuevoNodo;
	else
		lista.cola->siguiente = nuevoNodo;

	lista.cola = nuevoNodo;
	lista.longitud++;
}

void insertarOrdenado(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;

	if(esListaVacia(lista)) {
		nuevoNodo->siguiente = nullptr;
		lista.cabeza = nuevoNodo;
		lista.cola = nuevoNodo;
	} else {
		Nodo *rec = lista.cabeza;
		Nodo *ant = nullptr;
		while(rec) {
			if(rec->dato > dato) break;
			ant = rec;
			rec = rec->siguiente;
		}

		nuevoNodo->siguiente = rec;

		if(rec == nullptr)  // Se inserta el elemento en la ultima posicion de la lista
			lista.cola = nuevoNodo;

		if(ant != nullptr)
			ant->siguiente = nuevoNodo;
		else  // Se inserta el elemento en la primera posicion de la lista
			lista.cabeza = nuevoNodo;
	}

	lista.longitud++;
}

int cabeza(const Lista &lista) {
	return lista.cabeza->dato;
}

int cola(const Lista &lista) {
	return lista.cola->dato;
}

void eliminarCabeza(Lista &lista) {
	Nodo *eliminar = lista.cabeza;
	if(eliminar != nullptr) {
		lista.cabeza = lista.cabeza->siguiente;
		if(lista.cabeza == nullptr)
			lista.cola = nullptr;
		delete eliminar;
		lista.longitud--;
	}
}

void imprimir(const Lista &lista) {
	if(esListaVacia(lista)) {
		cout << "La lista esta vacia\n";
		return;
	}

	Nodo *rec = lista.cabeza;
	while(rec) {
		cout << rec->dato << " ";
		rec = rec->siguiente;
	}
	cout << endl;
}

void destruir(Lista &lista) {
	Nodo *rec = lista.cabeza;
	while(rec) {
		Nodo *eliminar = rec;
		rec = rec->siguiente;
		delete eliminar;
	}
	lista.cabeza = nullptr;
	lista.cola = nullptr;
	lista.longitud = 0;
}
