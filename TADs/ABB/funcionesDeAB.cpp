/*
 * Proyecto : AB
 * Archivo  : funcionesDeAB.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 19:58
 */

#include <iostream>
#include "ArbolBinario.h"
#include "funcionesDeAB.h"
using namespace std;

void construir(ArbolBinario &arbol) {
	arbol.raiz = nullptr;
}

bool esNodoVacio(NodoArbol *nodo) {
	return nodo == nullptr;
}

bool esArbolVacio(const ArbolBinario &arbol) {
	return esNodoVacio(arbol.raiz);
}

NodoArbol *crearNodoArbol(NodoArbol *izquierda, int dato, NodoArbol *derecha) {
	NodoArbol *nuevoNodo = new NodoArbol;
	nuevoNodo->izquierda = izquierda;
	nuevoNodo->dato = dato;
	nuevoNodo->derecha = derecha;
	return nuevoNodo;
}

void plantarArbolBinario(ArbolBinario &arbol, NodoArbol *izquierda, int dato, NodoArbol *derecha) {
	NodoArbol *nuevoNodo = crearNodoArbol(izquierda, dato, derecha);
	arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(ArbolBinario &arbol, ArbolBinario &arbolIzq, int dato, ArbolBinario &arbolDer) {
	NodoArbol *nuevoNodo = crearNodoArbol(arbolIzq.raiz, dato, arbolDer.raiz);
	arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(ArbolBinario &arbol, NodoArbol *izquierda, int dato, ArbolBinario &arbolDer) {
	NodoArbol *nuevoNodo = crearNodoArbol(izquierda, dato, arbolDer.raiz);
	arbol.raiz = nuevoNodo;
}

void plantarArbolBinario(ArbolBinario &arbol, ArbolBinario &arbolIzq, int dato, NodoArbol *derecha) {
	NodoArbol *nuevoNodo = crearNodoArbol(arbolIzq.raiz, dato, derecha);
	arbol.raiz = nuevoNodo;
}

int raiz(NodoArbol *nodo) {
	if(esNodoVacio(nodo)) {
		cout << "El nodo esta vacio, se retorna -1\n";
		return -1;
	}
	return nodo->dato;
}

NodoArbol *hijoIzquierdo(const ArbolBinario &arbol) {
	if(esArbolVacio(arbol)) {
		cout << "El arbol esta vacio, se retorna nullptr\n";
		return nullptr;
	}
	return arbol.raiz->izquierda;
}

NodoArbol *hijoDerecho(const ArbolBinario &arbol) {
	if(esArbolVacio(arbol)) {
		cout << "El arbol esta vacio, se retorna nullptr\n";
		return nullptr;
	}
	return arbol.raiz->derecha;
}

void recorrerEnOrdenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		recorrerEnOrdenRecursivo(nodo->izquierda);
		cout << nodo->dato << " ";
		recorrerEnOrdenRecursivo(nodo->derecha);
	}
}

void recorrerEnOrden(const ArbolBinario &arbol) {
	recorrerEnOrdenRecursivo(arbol.raiz);
	cout << endl;
}

void recorrerEnPreordenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		cout << nodo->dato << " ";
		recorrerEnPreordenRecursivo(nodo->izquierda);
		recorrerEnPreordenRecursivo(nodo->derecha);
	}
}

void recorrerEnPreorden(const ArbolBinario &arbol) {
	recorrerEnPreordenRecursivo(arbol.raiz);
	cout << endl;
}

void recorrerEnPostordenRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		recorrerEnPostordenRecursivo(nodo->izquierda);
		recorrerEnPostordenRecursivo(nodo->derecha);
		cout << nodo->dato << " ";
	}
}

void recorrerEnPostorden(const ArbolBinario &arbol) {
	recorrerEnPostordenRecursivo(arbol.raiz);
	cout << endl;
}

int alturaRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))  // Vacio
		return 0;
	else if(esNodoVacio(nodo->izquierda) && esNodoVacio(nodo->derecha))  // No tiene hijos
		return 0;
	else
		return 1 + max(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

int altura(const ArbolBinario &arbol) {
	return alturaRecursivo(arbol.raiz);
}

int numeroDeNodosRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return 0;
	else
		return 1 + numeroDeNodosRecursivo(nodo->izquierda) + numeroDeNodosRecursivo(nodo->derecha);
}

int numeroDeNodos(const ArbolBinario &arbol) {
	return numeroDeNodosRecursivo(arbol.raiz);
}

int numeroDeHojasRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return 0;
	else if(esNodoVacio(nodo->izquierda) && esNodoVacio(nodo->derecha))
		return 1;
	else
		return numeroDeHojasRecursivo(nodo->izquierda) + numeroDeHojasRecursivo(nodo->derecha);
}

int numeroDeHojas(const ArbolBinario &arbol) {
	return numeroDeHojasRecursivo(arbol.raiz);
}

bool esEquilibradoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return true;

	int alturaHijoIzq = alturaRecursivo(nodo->izquierda);
	int alturaHijoDer = alturaRecursivo(nodo->derecha);
	int diferencia = abs(alturaHijoIzq - alturaHijoDer);
	return diferencia <= 1 && esEquilibradoRecursivo(nodo->izquierda) && esEquilibradoRecursivo(nodo->derecha);
}

bool esEquilibrado(const ArbolBinario &arbol) {
	return esEquilibradoRecursivo(arbol.raiz);
}

bool esHoja(const ArbolBinario &arbol) {
	if(esArbolVacio(arbol))
		return false;

	return esNodoVacio(arbol.raiz->izquierda) && esNodoVacio(arbol.raiz->derecha);
}

void destruirRecursivo(NodoArbol *nodo) {
	if(!esNodoVacio(nodo)) {
		destruirRecursivo(nodo->izquierda);
		destruirRecursivo(nodo->derecha);
		delete nodo;
	}
}

void destruir(ArbolBinario &arbol) {
	destruirRecursivo(arbol.raiz);
	arbol.raiz = nullptr;
}
