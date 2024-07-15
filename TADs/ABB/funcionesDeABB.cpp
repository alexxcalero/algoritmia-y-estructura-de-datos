/*
 * Proyecto : ABB
 * Archivo  : funcionesDeABB.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 20:17
 */

#include <iostream>
#include "ABB.h"
#include "NodoArbol.h"
#include "funcionesDeAB.h"
#include "funcionesDeABB.h"
using namespace std;

void construir(ABB &arbol) {
	construir(arbol.arbolBinario);
}

bool esArbolVacio(const ABB &arbol) {
	return esArbolVacio(arbol.arbolBinario);
}

void plantarABB(NodoArbol *&nodo, NodoArbol *izq, int dato, NodoArbol *der) {
	NodoArbol *nuevoNodo = new NodoArbol;
	nuevoNodo->izq = izq;
	nuevoNodo->dato = dato;
	nuevoNodo->der = der;
	nodo = nuevoNodo;
}

void insertarRecursivo(NodoArbol *&nodo, int dato) {
	if(esNodoVacio(nodo))
		plantarABB(nodo, nullptr, dato, nullptr);
	else {
		if(dato < nodo->dato)
			insertarRecursivo(nodo->izq, dato);
		else if(dato > nodo->dato)
			insertarRecursivo(nodo->der, dato);
	}
}

void insertar(ABB &arbol, int dato) {
	insertarRecursivo(arbol.arbolBinario.raiz, dato);
}

void recorrerEnOrden(const ABB &arbol) {
	recorrerEnOrden(arbol.arbolBinario);
}

void recorrerEnPreOrden(const ABB &arbol) {
	recorrerEnPreOrden(arbol.arbolBinario);
}

void recorrerEnPostOrden(const ABB &arbol) {
	recorrerEnPostOrden(arbol.arbolBinario);
}

bool buscarDatoRecursivo(NodoArbol *nodo, int dato) {
	if(esNodoVacio(nodo))
		return false;

	if(dato == nodo->dato)
		return true;
	else if(dato < nodo->dato)
		return buscarDatoRecursivo(nodo->izq, dato);
	else
		return buscarDatoRecursivo(nodo->der, dato);
}

bool buscarDato(const ABB &arbol, int dato) {
	return buscarDatoRecursivo(arbol.arbolBinario.raiz, dato);
}

NodoArbol *minimoNodoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return nodo;
	if(esNodoVacio(nodo->izq))
		return nodo;
	return minimoNodoRecursivo(nodo->izq);
}

NodoArbol *minimoNodo(ABB &arbol) {
	return minimoNodoRecursivo(arbol.arbolBinario.raiz);
}

NodoArbol *mayorNodoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return nodo;
	if(esNodoVacio(nodo->der))
		return nodo;
	return mayorNodoRecursivo(nodo->der);
}

NodoArbol *mayorNodo(ABB &arbol) {
	return mayorNodoRecursivo(arbol.arbolBinario.raiz);
}

NodoArbol *eliminarNodoRecursivo(NodoArbol *nodo, int dato) {
	if(esNodoVacio(nodo))
		return nodo;

	if(dato < nodo->dato)
		nodo->izq = eliminarNodoRecursivo(nodo->izq, dato);
	else if(dato > nodo->dato)
		nodo->der = eliminarNodoRecursivo(nodo->der, dato);
	else {
		if(esNodoVacio(nodo->izq) && esNodoVacio(nodo->der)) {  // El nodo a eliminar es una hoja
			delete nodo;
			return nullptr;
		} else if(esNodoVacio(nodo->izq)) {  // El nodo a eliminar solo tiene hijo derecho
			NodoArbol *minDer = minimoNodoRecursivo(nodo->der);
			nodo->dato = minDer->dato;
			nodo->der = eliminarNodoRecursivo(nodo->der, minDer->dato);
		} else if(esNodoVacio(nodo->der)) {  // El nodo a eliminar solo tiene hijo izquierdo
			NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izq);
			nodo->dato = maxIzq->dato;
			nodo->izq = eliminarNodoRecursivo(nodo->izq, maxIzq->dato);
		} else {  // El nodo a eliminar tiene ambos hijos
			NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izq);
			nodo->dato = maxIzq->dato;
			nodo->izq = eliminarNodoRecursivo(nodo->izq, maxIzq->dato);
		}
	}
	return nodo;
}

void eliminarNodo(ABB &arbol, int dato) {
	arbol.arbolBinario.raiz = eliminarNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

void destruir(ABB &arbol) {
	destruir(arbol.arbolBinario);
}
