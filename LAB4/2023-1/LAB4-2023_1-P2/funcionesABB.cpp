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
		if(elemento.poder > nodo->elemento.poder)
			insertarRecursivo(nodo->derecha, elemento);
		else
			if(elemento.poder < nodo->elemento.poder)
				insertarRecursivo(nodo->izquierda, elemento);
			else
				nodo->elemento.cantidad += elemento.cantidad;
}

void insertar(struct ArbolBinarioBusqueda & arbol, Elemento elemento){
	insertarRecursivo(arbol.arbolBinario.raiz, elemento);
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
	recorrerEnOrden(arbol.arbolBinario);
}

void preOrden(const struct ArbolBinarioBusqueda & arbol){
	recorrerPreOrden(arbol.arbolBinario);
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
    if(comparaABB(nodo->elemento.poder, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento.poder, dato) == 1)
        return buscaArbolRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento.poder, dato) == -1)
            return buscaArbolRecursivo(nodo->derecha, dato);
}

struct NodoArbol * minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}

void eliminarNodo(struct ArbolBinarioBusqueda & arbol, int dato){
    arbol.arbolBinario.raiz = eliminarNodoRecursivo(arbol.arbolBinario.raiz, dato);
}

struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento){
    if(esNodoVacio(nodo))
        return nodo;
    /*Buscamos el nodo a eliminar*/
    if(elemento < nodo->elemento.poder)
        nodo->izquierda = eliminarNodoRecursivo(nodo->izquierda, elemento);
    else if(elemento > nodo->elemento.poder)
        nodo->derecha = eliminarNodoRecursivo(nodo->derecha, elemento);
    else{
        /*encontró el elemento*/
        /*caso de una sola hoja derecha*/
        if(esNodoVacio(nodo->izquierda)){
            struct NodoArbol * hijo = nodo->derecha;
            delete nodo;
            return hijo;
        }
        else if(esNodoVacio(nodo->derecha)){
            struct NodoArbol * hijo = nodo->izquierda;
            delete nodo;
            return hijo;
        }
        else{
            /*el elemento a eliminar tiene dos hijos*/
            struct NodoArbol * minNodo = minimoArbol(nodo->derecha);
            nodo->elemento = minNodo->elemento;
            nodo->derecha = eliminarNodoRecursivo(nodo->derecha, minNodo->elemento.poder);
        }
    }
    return nodo;
}

void destruirArbolBB(struct ArbolBinarioBusqueda & arbol){
    destruirArbolBinario(arbol.arbolBinario);
}
