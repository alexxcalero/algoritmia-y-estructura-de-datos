/*
 * Proyecto : ABB
 * Archivo  : funcionesDeABB.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 20:37
 */

#include <iostream>
#include "funcionesDeAB.h"
#include "funcionesDeABB.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;

void construir(ArbolBinarioBusqueda &arbol) {
	construir(arbol.arbolBinario);
}

void plantarABB(NodoArbol *&nodo, NodoArbol *arbolIzq, int dato, NodoArbol *arbolDer) {
	NodoArbol *nuevoNodo = new NodoArbol;
	nuevoNodo->izquierda = arbolIzq;
	nuevoNodo->dato = dato;
	nuevoNodo->derecha = arbolDer;
	nodo = nuevoNodo;
}

void insertarRecursivo(NodoArbol *&nodo, int dato) {
	if(esNodoVacio(nodo))
		plantarABB(nodo, nullptr, dato, nullptr);
	else {
		if(dato < nodo->dato)
			insertarRecursivo(nodo->izquierda, dato);
		else if(dato > nodo->dato)
			insertarRecursivo(nodo->derecha, dato);
	}
}

void insertar(ArbolBinarioBusqueda &arbol, int dato) {
	insertarRecursivo(arbol.arbolBinario.raiz, dato);
}

void recorrerEnOrden(const ArbolBinarioBusqueda &arbol) {
	recorrerEnOrden(arbol.arbolBinario);
}

void recorrerEnPreorden(const ArbolBinarioBusqueda &arbol) {
	recorrerEnPreorden(arbol.arbolBinario);
}

void recorrerEnPostorden(const ArbolBinarioBusqueda &arbol) {
	recorrerEnPostorden(arbol.arbolBinario);
}

bool buscarDatoRecursivo(NodoArbol *nodo, int dato) {
	if(esNodoVacio(nodo))
		return false;

	if(dato == nodo->dato)
		return true;
	else if(dato < nodo->dato)
		return buscarDatoRecursivo(nodo->izquierda, dato);
	else
		return buscarDatoRecursivo(nodo->derecha, dato);
}

bool buscarDato(const ArbolBinarioBusqueda &arbol, int dato) {
	return buscarDatoRecursivo(arbol.arbolBinario.raiz, dato);
}

NodoArbol *minimoNodoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return nodo;
	if(esNodoVacio(nodo->izquierda))
		return nodo;
	return minimoNodoRecursivo(nodo->izquierda);
}

NodoArbol *minimoNodo(ArbolBinarioBusqueda &arbol) {
	return minimoNodoRecursivo(arbol.arbolBinario.raiz);
}

NodoArbol *mayorNodoRecursivo(NodoArbol *nodo) {
	if(esNodoVacio(nodo))
		return nodo;
	if(esNodoVacio(nodo->derecha))
		return nodo;
	return mayorNodoRecursivo(nodo->derecha);
}

NodoArbol *mayorNodo(ArbolBinarioBusqueda &arbol) {
	return mayorNodoRecursivo(arbol.arbolBinario.raiz);
}

NodoArbol *eliminarNodoRecursivo(NodoArbol *nodo, int dato) {
	if(esNodoVacio(nodo))
		return nodo;

	if(dato < nodo->dato)
		nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, dato);
	else if(dato > nodo->dato)
		nodo->derecha = eliminarNodoRecursivo(nodo->derecha, dato);
	else {
		if(esNodoVacio(nodo->izquierda) && esNodoVacio(nodo->derecha)) {  // El nodo a eliminar es una hoja
			delete nodo;
			return nullptr;
		} else if(esNodoVacio(nodo->izquierda)) {  // El nodo a eliminar solo tiene hijo derecho
			NodoArbol *minDer = minimoNodoRecursivo(nodo->derecha);
			nodo->dato = minDer->dato;
			nodo->derecha = eliminarNodoRecursivo(nodo->derecha, minDer->dato);
		} else if(esNodoVacio(nodo->derecha)) {  // El nodo a eliminar solo tiene hijo izquierdo
			NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izquierda);
			nodo->dato = maxIzq->dato;
			nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, maxIzq->dato);
		} else {  // El nodo a eliminar tiene ambos hijos
			NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izquierda);
			nodo->dato = maxIzq->dato;
			nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, maxIzq->dato);
		}
	}
	return nodo;
}

void eliminarNodo(ArbolBinarioBusqueda &arbol, int dato) {
	arbol.arbolBinario.raiz = eliminarNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

void destruir(ArbolBinarioBusqueda &arbol) {
	destruir(arbol.arbolBinario);
}
