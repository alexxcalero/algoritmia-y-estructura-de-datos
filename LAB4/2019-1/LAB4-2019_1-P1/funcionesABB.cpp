/*
 * File:   ArbolBinarioBusqueda.cpp
 * Author: Ana Roncal
 *
 * Created on 30 de mayo de 2024, 15:53
 */

#include <iostream>
#include "Elemento.h"
#include "funcionesABB.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

void construir(struct ArbolBinarioBusqueda & arbol){
	construir(arbol.arbolBinario);
}

void plantarArbolBB(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
		Elemento elemento, struct NodoArbol * arbolDerecha){
	struct NodoArbol * nuevoNodo = new struct NodoArbol;
	nuevoNodo->derecha = arbolDerecha;
	nuevoNodo->elemento = elemento;
	nuevoNodo->izquierda = arbolIzquierdo;
	nodo = nuevoNodo;
}

void insertarRecursivo(struct NodoArbol *& nodo, Elemento elemento){
	if(esNodoVacio(nodo))
		plantarArbolBB(nodo, nullptr, elemento, nullptr);
	else
		if(elemento.fecha > nodo->elemento.fecha)
			insertarRecursivo(nodo->derecha, elemento);
		else
			if(elemento.fecha < nodo->elemento.fecha)
				insertarRecursivo(nodo->izquierda, elemento);
}

void insertar(struct ArbolBinarioBusqueda & arbol, Elemento elemento){
	insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
	recorrerEnOrden(arbol.arbolBinario);
}

int comparaABB(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA > elementoB) return 1;
    else if(elementoA < elementoB) return -1;
}

bool buscaArbol(const struct ArbolBinarioBusqueda & arbol, int dato){
    return buscaArbolRecursivo(arbol.arbolBinario.raiz, dato);
}

bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo)){
        return false;
    }
    if(comparaABB(nodo->elemento.fecha, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento.fecha, dato) == 1)
        return buscaArbolRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento.fecha, dato) == -1)
            return buscaArbolRecursivo(nodo->derecha, dato);
}

struct NodoArbol * minimoNodo(struct ArbolBinarioBusqueda & arbol){
    return minimoNodoRecursivo(arbol.arbolBinario.raiz);
}

struct NodoArbol * minimoNodoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoNodoRecursivo(nodo->izquierda);
}

struct NodoArbol * mayorNodo(struct ArbolBinarioBusqueda & arbol){
    return mayorNodoRecursivo(arbol.arbolBinario.raiz);
}

struct NodoArbol * mayorNodoRecursivo(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->derecha))
        return nodo;
    return mayorNodoRecursivo(nodo->derecha);
}

void eliminarNodo(struct ArbolBinarioBusqueda & arbol, int dato){
    arbol.arbolBinario.raiz = eliminarNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento){
    if(esNodoVacio(nodo))
        return nodo;
    /*Buscamos el nodo a eliminar*/
    if(elemento < nodo->elemento.fecha)
        nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, elemento);
    else if(elemento > nodo->elemento.fecha)
        nodo->derecha = eliminarNodoRecursivo(nodo->derecha, elemento);
    else{
        /*encontró el elemento*/
        /*caso de una sola hoja derecha*/
		if(esNodoVacio(nodo->izquierda) && esNodoVacio(nodo->derecha)) {
			delete nodo;
			return nullptr;
		} else if(esNodoVacio(nodo->izquierda)){
			NodoArbol *minDer = minimoNodoRecursivo(nodo->derecha);
			nodo->elemento = minDer->elemento;
			nodo->derecha = eliminarNodoRecursivo(nodo->derecha, minDer->elemento.fecha);
        }
        else if(esNodoVacio(nodo->derecha)){
            NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izquierda);
			nodo->elemento = maxIzq->elemento;
			nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, maxIzq->elemento.fecha);
        }
        else{
            /*el elemento a eliminar tiene dos hijos*/
            NodoArbol *maxIzq = mayorNodoRecursivo(nodo->izquierda);
			nodo->elemento = maxIzq->elemento;
			nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, maxIzq->elemento.fecha);
        }
    }
    return nodo;
}

void destruirArbolBB(struct ArbolBinarioBusqueda & arbol){
    destruirArbolBinario(arbol.arbolBinario);
}
