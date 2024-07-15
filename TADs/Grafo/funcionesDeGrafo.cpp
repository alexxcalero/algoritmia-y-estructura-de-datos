/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeGrafo.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#include <iostream>
#include "Grafo.h"
#include "ListaArista.h"
#include "ListaVertice.h"
#include "funcionesDeGrafo.h"
#include "funcionesDeListaArista.h"
#include "funcionesDeListaVertice.h"
using namespace std;

void construirGrafo(Grafo &grafo) {
	construirListaVertice(grafo.listaVertice);
	grafo.len = 0;
}

bool esGrafoVacio(const Grafo &grafo) {
	return esListaVerticeVacia(grafo.listaVertice);
}

bool seEncuentraVertice(const Grafo &grafo, char vertice) {
	return seEncuentraVerticeEnLista(grafo.listaVertice, vertice);
}

void agregarVertice(Grafo &grafo, char vertice) {
	if(!seEncuentraVertice(grafo, vertice)) {
		insertarVerticeAlFinal(grafo.listaVertice, vertice);
		grafo.len++;
	}
}

bool seEncuentraArista(const Grafo &grafo, char origen, char destino) {
	return seEncuentraAristaEnLista(grafo.listaVertice, origen, destino);
}

void agregarArista(Grafo &grafo, char origen, char destino) {
	bool seEncuentraVerticeOrigen = seEncuentraVertice(grafo, origen);
	bool seEncuentraVerticeDestino = seEncuentraVertice(grafo, destino);

	if(!seEncuentraVerticeOrigen or !seEncuentraVerticeDestino) {
		cout << "No se ha encontrado alguno de los dos vertices\n";
		return;
	}

	if(!seEncuentraArista(grafo, origen, destino))
		insertarListaAristas(grafo.listaVertice, origen, destino);
}

int longitudGrafo(const Grafo &grafo) {
	return grafo.len;
}

void eliminarVertice(Grafo &grafo, char vertice) {
	if(seEncuentraVertice(grafo, vertice)) {
		eliminarVerticeEnLista(grafo.listaVertice, vertice);
		grafo.len--;
	}
}

void eliminarArista(Grafo &grafo, char origen, char destino) {
	int seEncuentraVerticeOrigen = seEncuentraVertice(grafo, origen);
	if(seEncuentraVerticeOrigen)
		eliminarDeListaDeAristas(grafo.listaVertice, origen, destino);
}

void imprimirGrafo(const Grafo &grafo) {
	NodoListaVertice *recG = new NodoListaVertice;
	NodoListaArista *recA = new NodoListaArista;
	recG = grafo.listaVertice.ini;

	if(recG == nullptr) {
		cout << "El grafo esta vacio\n";
		return;
	} else {
		while(recG) {
			cout << "Vertice " << recG->dato << ": ";
			recA = recG->listaArista.ini;
			while(recA) {
				cout << recA->dato << " ";
				recA = recA->sig;
			}
			recG = recG->sig;
			cout << endl;
		}
		delete recG;
	}
}

void destruirGrafo(Grafo &grafo) {
	destruirListaVertice(grafo.listaVertice);
    grafo.len = 0;
}
