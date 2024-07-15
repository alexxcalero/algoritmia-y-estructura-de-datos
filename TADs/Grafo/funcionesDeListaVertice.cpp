/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeListaVertice.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#include <iostream>
#include "ListaVertice.h"
#include "NodoListaVertice.h"
#include "funcionesDeListaArista.h"
#include "funcionesDeListaVertice.h"
using namespace std;

void construirListaVertice(ListaVertice &lista) {
	lista.ini = nullptr;
	lista.len = 0;
}

bool esListaVerticeVacia(const ListaVertice &lista) {
	return lista.ini == nullptr;
}

bool seEncuentraVerticeEnLista(const ListaVertice &lista, char llave) {
	NodoListaVertice *rec = lista.ini;
	while(rec) {
		if(rec->dato == llave)
			break;
		rec = rec->sig;
	}
	return rec != nullptr;
}

NodoListaVertice *crearNodoVertice(char dato, NodoListaVertice *sig) {
	NodoListaVertice *nuevoNodo = new NodoListaVertice;

	nuevoNodo->dato = dato;
	nuevoNodo->sig = sig;
	construirListaArista(nuevoNodo->listaArista);

	return nuevoNodo;
}

NodoListaVertice *obtenerUltimoNodoVertice(const ListaVertice &lista) {
	NodoListaVertice *rec = lista.ini;
	NodoListaVertice *ult = nullptr;

	while(rec) {
		ult = rec;
		rec = rec->sig;
	}

	return ult;  // Retorna nullptr en caso la lista este vacia
}

void insertarVerticeAlFinal(ListaVertice &lista, char dato) {
	NodoListaVertice *ultimoNodo = obtenerUltimoNodoVertice(lista);
	NodoListaVertice *nuevoNodo = crearNodoVertice(dato, nullptr);

	if(ultimoNodo == nullptr)  // Se inserta al inicio de la lista de vertices
		lista.ini = nuevoNodo;
	else
		ultimoNodo->sig = nuevoNodo;

	lista.len++;
}

NodoListaVertice *obtenerNodoVertice(const ListaVertice &lista, char llave) {
	NodoListaVertice *rec = lista.ini;
	while(rec) {
		if(rec->dato == llave)
			return rec;
		rec = rec->sig;
	}
	return nullptr;  // En caso no se encuentre
}

bool seEncuentraAristaEnLista(const ListaVertice &lista, char origen, char destino) {
	NodoListaVertice *nodoVerticeOrigen = obtenerNodoVertice(lista, origen);
	if(nodoVerticeOrigen == nullptr)
		return false;
	else
		return seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, destino);
}

void insertarListaAristas(ListaVertice &lista, char origen, char destino) {
	NodoListaVertice *nodoVerticeOrigen = obtenerNodoVertice(lista, origen);
	if(nodoVerticeOrigen == nullptr) {
		cout << "ERROR: No se puede insertar la lista arista, ya que no se ha encontrado el vertice " << origen << endl;
		return;
	}

	if(!seEncuentraAristaEnListaArista(nodoVerticeOrigen->listaArista, destino))
		insertarAristaAlFinal(nodoVerticeOrigen->listaArista, destino);
}

void eliminarDeListaDeAristas(ListaVertice &lista, char origen, char destino) {
	NodoListaVertice *nodoVerticeOrigen = obtenerNodoVertice(lista, origen);
	if(nodoVerticeOrigen != nullptr)
		eliminarAristaEnLista(nodoVerticeOrigen->listaArista, destino);
}

void eliminarVerticeEnLista(ListaVertice &lista, char vertice) {
	NodoListaVertice *ult = nullptr;
	NodoListaVertice *rec = lista.ini;

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

		destruirListaArista(rec->listaArista);
		delete rec;
		lista.len--;
	}
}

void destruirListaVertice(ListaVertice &lista) {
	NodoListaVertice *rec = lista.ini;
	while(rec) {
		destruirListaArista(rec->listaArista);
		NodoListaVertice *eliminar = rec;
		rec = rec->sig;
		delete eliminar;
	}
	lista.ini = nullptr;
	lista.len = 0;
}
