/*
 * File:   funcionesABB.h
 * Author: ANA RONCAL
 *
 * Created on 30 de mayo de 2024, 15:54
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H

void construir(struct ArbolBinarioBusqueda & arbol);
void insertar(struct ArbolBinarioBusqueda & arbol, Elemento elemento);
void insertarRecursivo(struct NodoArbol *& nodo, Elemento elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void plantarArbolBB(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
         Elemento elemento, struct NodoArbol * arbolDerecha);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol, int dato);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
int comparaABB(int elementoA, int elementoB);
struct NodoArbol * minimoNodo(struct ArbolBinarioBusqueda & arbol);
struct NodoArbol * minimoNodoRecursivo(struct NodoArbol * nodo);
struct NodoArbol * mayorNodo(struct ArbolBinarioBusqueda & arbol);
struct NodoArbol * mayorNodoRecursivo(struct NodoArbol * nodo);
void eliminarNodo(struct ArbolBinarioBusqueda & arbol, int dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);

#endif /* FUNCIONESABB_H */
