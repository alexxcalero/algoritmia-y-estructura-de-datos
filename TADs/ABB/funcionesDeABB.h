/*
 * Proyecto : ABB
 * Archivo  : funcionesDeABB.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 20:16
 */

#ifndef FUNCIONESDEABB_H
#define FUNCIONESDEABB_H

void construir(ABB &arbol);
bool esArbolVacio(const ABB &arbol);

void plantarABB(NodoArbol *&nodo, NodoArbol *izq, int dato, NodoArbol *der);
void insertarRecursivo(NodoArbol *&nodo, int dato);
void insertar(ABB &arbol, int dato);

void recorrerEnOrden(const ABB &arbol);
void recorrerEnPreOrden(const ABB &arbol);
void recorrerEnPostOrden(const ABB &arbol);

bool buscarDatoRecursivo(NodoArbol *nodo, int dato);
bool buscarDato(const ABB &arbol, int dato);

NodoArbol *minimoNodoRecursivo(NodoArbol *nodo);
NodoArbol *minimoNodo(ABB &arbol);

NodoArbol *mayorNodoRecursivo(NodoArbol *nodo);
NodoArbol *mayorNodo(ABB &arbol);

NodoArbol *eliminarNodoRecursivo(NodoArbol *nodo, int dato);
void eliminarNodo(ABB &arbol, int dato);

void destruir(ABB &arbol);

#endif /* FUNCIONESDEABB_H */
