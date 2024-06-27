/*
 * Proyecto : AB
 * Archivo  : funcionesDeAB.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 19:58
 */

#ifndef FUNCIONESDEAB_H
#define FUNCIONESDEAB_H

void construir(ArbolBinario &arbol);
bool esNodoVacio(NodoArbol *nodo);
bool esArbolVacio(const ArbolBinario &arbol);

NodoArbol *crearNodoArbol(NodoArbol *izquierda, int dato, NodoArbol *derecha);
void plantarAB(ArbolBinario &arbol, NodoArbol *izquierda, int dato, NodoArbol *derecha);
void plantarAB(ArbolBinario &arbol, ArbolBinario &arbolIzq, int dato, ArbolBinario &arbolDer);
void plantarAB(ArbolBinario &arbol, NodoArbol *izquierda, int dato, ArbolBinario &arbolDer);
void plantarAB(ArbolBinario &arbol, ArbolBinario &arbolIzq, int dato, NodoArbol *derecha);

int raiz(NodoArbol *nodo);
NodoArbol *hijoIzquierdo(const ArbolBinario &arbol);
NodoArbol *hijoDerecho(const ArbolBinario &arbol);

void recorrerEnOrdenRecursivo(NodoArbol *nodo);
void recorrerEnOrden(const ArbolBinario &arbol);
void recorrerEnPreordenRecursivo(NodoArbol *nodo);
void recorrerEnPreorden(const ArbolBinario &arbol);
void recorrerEnPostordenRecursivo(NodoArbol *nodo);
void recorrerEnPostorden(const ArbolBinario &arbol);

int alturaRecursivo(NodoArbol *nodo);
int altura(const ArbolBinario &arbol);

int numeroDeNodosRecursivo(NodoArbol *nodo);
int numeroDeNodos(const ArbolBinario &arbol);

int numeroDeHojasRecursivo(NodoArbol *nodo);
int numeroDeHojas(const ArbolBinario &arbol);

bool esEquilibradoRecursivo(NodoArbol *nodo);
bool esEquilibrado(const ArbolBinario &arbol);

bool esHoja(const ArbolBinario &arbol);

void destruirRecursivo(NodoArbol *nodo);
void destruir(ArbolBinario &arbol);

#endif /* FUNCIONESDEAB_H */
