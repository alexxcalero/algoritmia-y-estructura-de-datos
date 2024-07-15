/*
 * Proyecto : recorridos-iterativos-para-abb
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 23:23
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#include "funcionesArbolesBB.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

void preOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pila;
	construir(pila);
	apilar(pila, arbol.arbolBinario.raiz);
	while(!esPilaVacia(pila)) {
		NodoArbol *rec = desapilar(pila);
		imprimeNodo(rec);
		if(rec->derecha != nullptr)
			apilar(pila, rec->derecha);
		if(rec->izquierda != nullptr)
			apilar(pila, rec->izquierda);
	}
	destruirPila(pila);
}

void postOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pilaAux, pilaFinal;
	construir(pilaAux);
	construir(pilaFinal);
	apilar(pilaAux, arbol.arbolBinario.raiz);
	while(!esPilaVacia(pilaAux)) {
		NodoArbol *aux = desapilar(pilaAux);
		apilar(pilaFinal, aux);
		if(aux->izquierda != nullptr)
			apilar(pilaAux, aux->izquierda);
		if(aux->derecha != nullptr)
			apilar(pilaAux, aux->derecha);
	}
	while(!esPilaVacia(pilaFinal)) {
		NodoArbol *nodo = desapilar(pilaFinal);
		imprimeNodo(nodo);
	}
	destruirPila(pilaAux);
	destruirPila(pilaFinal);
}

void enOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pila;
    construir(pila);
    NodoArbol *rec = arbol.arbolBinario.raiz;
    while(rec || !esPilaVacia(pila)) {
        while(rec != nullptr) {
            apilar(pila, rec);
            rec = rec->izquierda;
        }

        rec = desapilar(pila);
        imprimeNodo(rec);

        rec = rec->derecha;
    }
    destruirPila(pila);
}

int main(int argc, char** argv) {
	ArbolBinarioBusqueda arbol;
	construir(arbol);

	insertar(arbol, 8);
	insertar(arbol, 6);
	insertar(arbol, 15);
	insertar(arbol, 13);
	insertar(arbol, 10);
	insertar(arbol, 14);
	insertar(arbol, 9);
	insertar(arbol, 7);
	insertar(arbol, 5);
	insertar(arbol, 4);

	cout << "Recorrido en orden recursivo: ";
	enOrden(arbol);
	cout << "\nRecorrido en orden iterativo: ";
	enOrdenIterativo(arbol);

	cout << "\n\nRecorrido en pre orden recursivo: ";
	preOrden(arbol);
	cout << "\nRecorrido en pre orden iterativo: ";
	preOrdenIterativo(arbol);

	cout << "\n\nRecorrido en post orden recursivo: ";
	postOrden(arbol);
	cout << "\nRecorrido en post orden iterativo: ";
	postOrdenIterativo(arbol);

	return 0;
}
