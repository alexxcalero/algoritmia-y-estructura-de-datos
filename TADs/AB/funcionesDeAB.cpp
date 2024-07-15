/*
 * Proyecto : AB
 * Archivo  : funcionesDeAB.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 19:50
 */

#include <iostream>
#include "AB.h"
#include "NodoArbol.h"
#include "funcionesDeAB.h"
using namespace std;

void construir(AB &arbol) {
	arbol.raiz = nullptr;
}

bool esNodoVacio(NodoArbol *nodo) {
	return nodo == nullptr;
}

bool esArbolVacio(const AB &arbol) {
	return esNodoVacio(arbol.raiz);
}

NodoArbol *crearNodoArbol(NodoArbol *izq, int dato, NodoArbol *der) {
	NodoArbol *nuevoNodo = new NodoArbol;

	nuevoNodo->izq = izq;
	nuevoNodo->dato = dato;
	nuevoNodo->der = der;

	return nuevoNodo;
}

void plantarAB(AB &arbol, NodoArbol *izq, int dato, NodoArbol *der) {
	NodoArbol *nuevoNodo = crearNodoArbol(izq, dato, der);
	arbol.raiz = nuevoNodo;
}

void plantarAB(AB &arbol, AB &arbolIzq, int dato, AB &arbolDer) {
	NodoArbol *nuevoNodo = crearNodoArbol(arbolIzq.raiz, dato, arbolDer.raiz);
	arbol.raiz = nuevoNodo;
}

void plantarAB(AB &arbol, NodoArbol *izq, int dato, AB &arbolDer) {
	NodoArbol *nuevoNodo = crearNodoArbol(izq, dato, arbolDer.raiz);
	arbol.raiz = nuevoNodo;
}

void plantarAB(AB &arbol, AB &arbolIzq, int dato, NodoArbol *der) {
	NodoArbol *nuevoNodo = crearNodoArbol(arbolIzq.raiz, dato, der);
	arbol.raiz = nuevoNodo;
}

int raiz(AB &arbol) {
	if(esArbolVacio(arbol)) {
		cout << "El arbol esta vacio, se retorna -1\n";
		return -1;
	}
	return arbol.raiz->dato;
}

NodoArbol *hijoIzquierdo(const AB &arbol) {
	if(esArbolVacio(arbol)) {
		cout << "El arbol esta vacio, se retorna nullptr\n";
		return nullptr;
	}
	return arbol.raiz->izq;
}

NodoArbol *hijoDerecho(const AB &arbol) {
	if(esArbolVacio(arbol)) {
		cout << "El arbol esta vacio, se retorna nullptr\n";
		return nullptr;
	}
	return arbol.raiz->der;
}

void recorrerEnOrdenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		recorrerEnOrdenRecursivo(nodo->izq);
		cout << nodo->dato << " ";
		recorrerEnOrdenRecursivo(nodo->der);
	}
}

void recorrerEnOrden(const AB &arbol) {
	recorrerEnOrdenRecursivo(arbol.raiz);
	cout << endl;
}

void recorrerEnPreOrdenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		cout << nodo->dato << " ";
		recorrerEnPreOrdenRecursivo(nodo->izq);
		recorrerEnPreOrdenRecursivo(nodo->der);
	}
}

void recorrerEnPreOrden(const AB &arbol) {
	recorrerEnPreOrdenRecursivo(arbol.raiz);
	cout << endl;
}

void recorrerEnPostOrdenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		recorrerEnPostOrdenRecursivo(nodo->izq);
		recorrerEnPostOrdenRecursivo(nodo->der);
		cout << nodo->dato << " ";
	}
}

void recorrerEnPostOrden(const AB &arbol) {
	recorrerEnPostOrdenRecursivo(arbol.raiz);
	cout << endl;
}

int alturaRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))  // Vacio
		return 0;
	else if(esNodoVacio(nodo->izq) && esNodoVacio(nodo->der))  // No tiene hijos
		return 0;
	else
		return 1 + max(alturaRecursivo(nodo->izq), alturaRecursivo(nodo->der));
}

int altura(const AB &arbol) {
	return alturaRecursivo(arbol.raiz);
}

int numeroDeNodosRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return 0;
	else
		return 1 + numeroDeNodosRecursivo(nodo->izq) + numeroDeNodosRecursivo(nodo->der);
}

int numeroDeNodos(const AB &arbol) {
	return numeroDeNodosRecursivo(arbol.raiz);
}

int numeroDeHojasRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return 0;
	else if(esNodoVacio(nodo->izq) && esNodoVacio(nodo->der))
		return 1;
	else
		return numeroDeHojasRecursivo(nodo->izq) + numeroDeHojasRecursivo(nodo->der);
}

int numeroDeHojas(const AB &arbol) {
	return numeroDeHojasRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return true;

	int alturaHijoIzq = alturaRecursivo(nodo->izq);
	int alturaHijoDer = alturaRecursivo(nodo->der);
	int diferencia = abs(alturaHijoIzq - alturaHijoDer);
	return diferencia <= 1 && esEquilibradoRecursivo(nodo->izq) && esEquilibradoRecursivo(nodo->der);
}

bool esEquilibrado(const AB &arbol) {
	return esEquilibradoRecursivo(arbol.raiz);
}

bool esHoja(const AB &arbol) {
	if(esArbolVacio(arbol))
		return false;

	return esNodoVacio(arbol.raiz->izq) && esNodoVacio(arbol.raiz->der);
}

void destruirRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		destruirRecursivo(nodo->izq);
		destruirRecursivo(nodo->der);
		delete nodo;
	}
}

void destruir(AB &arbol) {
	destruirRecursivo(arbol.raiz);
	arbol.raiz = nullptr;
}
