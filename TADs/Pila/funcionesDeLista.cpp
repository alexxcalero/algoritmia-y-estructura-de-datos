/*
 * Proyecto : Lista
 * Archivo  : funcionesDeLista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:01
 */

#include <iostream>
#include "Lista.h"
#include "funcionesDeLista.h"
using namespace std;

void construir(Lista &lista) {
	lista.ini = nullptr;
	lista.fin = nullptr;
	lista.len = 0;
}

bool esListaVacia(const Lista &lista) {
	return lista.ini == nullptr && lista.fin == nullptr;
}

int longitud(const Lista &lista) {
	return lista.len;
}

void insertarAlInicio(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->sig = lista.ini;

	lista.ini = nuevoNodo;
	if(lista.fin == nullptr)  // Para el primer elemento que inserto en la lista
		lista.fin = nuevoNodo;
	lista.len++;
}

void insertarAlFinal(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;
	nuevoNodo->sig = nullptr;

	if(esListaVacia(lista))  // Para el primer elemento que inserto en la lista
		lista.ini = nuevoNodo;
	else
		lista.fin->sig = nuevoNodo;

	lista.fin = nuevoNodo;
	lista.len++;
}

void insertarOrdenado(Lista &lista, int dato) {
	Nodo *nuevoNodo = new Nodo;
	nuevoNodo->dato = dato;

	if(esListaVacia(lista)) {
		nuevoNodo->sig = nullptr;
		lista.ini = nuevoNodo;
		lista.fin = nuevoNodo;
	} else {
		Nodo *rec = lista.ini;
		Nodo *ant = nullptr;
		while(rec) {
			if(rec->dato > dato) break;
			ant = rec;
			rec = rec->sig;
		}

		nuevoNodo->sig = rec;

		if(rec == nullptr)  // Se inserta el elemento en la ultima posicion de la lista
			lista.fin = nuevoNodo;

		if(ant != nullptr)  // Se inserta el elemento en el medio de la lista
			ant->sig = nuevoNodo;
		else  // Se inserta el elemento en la primera posicion de la lista
			lista.ini = nuevoNodo;
	}

	lista.len++;
}

int primero(const Lista &lista) {
	if(esListaVacia(lista)) {
		cout << "La lista esta vacia, se retorna -1\n";
		return -1;
	}
	return lista.ini->dato;
}

int ultimo(const Lista &lista) {
	if(esListaVacia(lista)) {
		cout << "La lista esta vacia, se retorna -1\n";
		return -1;
	}
	return lista.fin->dato;
}

void eliminarCabeza(Lista &lista) {
	if(esListaVacia(lista)) {
		cout << "La lista esta vacia\n";
		return;
	}

	Nodo *eliminar = lista.ini;
	if(eliminar != nullptr) {
		lista.ini = lista.ini->sig;
		if(lista.ini == nullptr)
			lista.fin = nullptr;
		delete eliminar;
		lista.len--;
	}
}

void imprimir(const Lista &lista) {
	if(esListaVacia(lista)) {
		cout << "La lista esta vacia\n";
		return;
	}

	Nodo *rec = lista.ini;
	while(rec) {
		cout << rec->dato << " ";
		rec = rec->sig;
	}
	cout << endl;
}

void destruir(Lista &lista) {
	Nodo *rec = lista.ini;
	while(rec) {
		Nodo *eliminar = rec;
		rec = rec->sig;
		delete eliminar;
	}
	lista.ini = nullptr;
	lista.fin = nullptr;
	lista.len = 0;
}
