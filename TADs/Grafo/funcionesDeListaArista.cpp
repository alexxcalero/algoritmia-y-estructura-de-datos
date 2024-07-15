/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeListaArista.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#include <iostream>
#include "ListaArista.h"
#include "NodoListaArista.h"
#include "funcionesDeListaArista.h"
using namespace std;

void construirListaArista(ListaArista &lista) {
	lista.ini = nullptr;
	lista.len = 0;
}

bool seEncuentraAristaEnListaArista(ListaArista &lista, char llave) {
	NodoListaArista *rec = lista.ini;
	while(rec) {
		if(rec->dato == llave)
			return true;
		rec = rec->sig;
	}
	return false;  // En caso no lo encuentre
}

NodoListaArista *crearNodoArista(char dato, NodoListaArista *sig) {
	NodoListaArista *nuevoNodo = new NodoListaArista;

	nuevoNodo->dato = dato;
	nuevoNodo->sig = sig;

	return nuevoNodo;
}

NodoListaArista *obtenerUltimoNodoArista(const ListaArista &lista) {
	NodoListaArista *rec = lista.ini;
	NodoListaArista *ult = nullptr;

	while(rec) {
		ult = rec;
		rec = rec->sig;
	}

	return ult;  // Retorna nullptr en caso la lista este vacia
}

void insertarAristaAlFinal(ListaArista &lista, char vertice) {
	NodoListaArista *ultimo = obtenerUltimoNodoArista(lista);
	NodoListaArista *nuevoNodo = crearNodoArista(vertice, nullptr);

	if(ultimo == nullptr)  // Se inserta al inicio de la lista
		lista.ini = nuevoNodo;
	else  // La lista ya tiene elementos
		ultimo->sig = nuevoNodo;

	lista.len++;
}

void eliminarAristaEnLista(ListaArista &lista, char vertice) {
	NodoListaArista *ult = nullptr;
	NodoListaArista *rec = lista.ini;
	while(rec) {
		if(rec->dato == vertice)
			break;
		ult = rec;
		rec = rec->sig;
	}

	if(rec != nullptr) {
		if(ult == nullptr)
			lista.ini = rec->sig;
		else
			ult->sig = rec->sig;

		delete rec;
		lista.len--;
	}
}

void destruirListaArista(ListaArista &lista) {
	NodoListaArista *rec = lista.ini;
	while(rec) {
		NodoListaArista *eliminar = rec;
		rec = rec->sig;
		delete eliminar;
	}
	lista.ini = nullptr;
	lista.len = 0;
}
