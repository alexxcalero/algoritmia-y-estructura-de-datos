/*
 * Proyecto : AB
 * Archivo  : funcionesDeAB.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 19:50
 */

#ifndef FUNCIONESDEAB_H
#define FUNCIONESDEAB_H

void construir(AB &arbol);
bool esNodoVacio(NodoArbol *nodo);
bool esArbolVacio(const AB &arbol);

NodoArbol *crearNodoArbol(NodoArbol *izq, int dato, NodoArbol *der);
void plantarAB(AB &arbol, NodoArbol *izq, int dato, NodoArbol *der);
void plantarAB(AB &arbol, AB &arbolIzq, int dato, AB &arbolDer);
void plantarAB(AB &arbol, NodoArbol *izq, int dato, AB &arbolDer);
void plantarAB(AB &arbol, AB &arbolIzq, int dato, NodoArbol *der);

int raiz(AB &arbol);
NodoArbol *hijoIzquierdo(const AB &arbol);
NodoArbol *hijoDerecho(const AB &arbol);

void recorrerEnOrdenRecursivo(NodoArbol *nodo);
void recorrerEnOrden(const AB &arbol);

void recorrerEnPreOrdenRecursivo(NodoArbol *nodo);
void recorrerEnPreOrden(const AB &arbol);

void recorrerEnPostOrdenRecursivo(NodoArbol *nodo);
void recorrerEnPostOrden(const AB &arbol);

int alturaRecursivo(NodoArbol *nodo);
int altura(const AB &arbol);

int numeroDeNodosRecursivo(NodoArbol *nodo);
int numeroDeNodos(const AB &arbol);

int numeroDeHojasRecursivo(NodoArbol *nodo);
int numeroDeHojas(const AB &arbol);

bool esEquilibradoRecursivo(NodoArbol *nodo);
bool esEquilibrado(const AB &arbol);

bool esHoja(const AB &arbol);

void destruirRecursivo(NodoArbol *nodo);
void destruir(AB &arbol);

#endif /* FUNCIONESDEAB_H */
