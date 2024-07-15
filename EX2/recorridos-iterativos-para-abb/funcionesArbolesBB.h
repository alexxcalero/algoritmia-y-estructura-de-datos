/*
 * File:   funcionesArbolesBB.h
 * Author: ANA RONCAL
 * Created on 24 de septiembre de 2023, 10:34 PM
 */

#ifndef FUNCIONESARBOLESBB_H
#define FUNCIONESARBOLESBB_H

void construir(struct ArbolBinarioBusqueda & arbol);
bool esArbolVacio(const struct ArbolBinarioBusqueda & arbol);
void plantarArbolBB(struct NodoArbol *& arbol,
                    struct NodoArbol * arbolIzquierdo, int elemento,
                    struct NodoArbol * arbolDerecho);
void insertarRecursivo(struct NodoArbol *& nodo, int elemento);
void insertar(struct ArbolBinarioBusqueda & arbol, int elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void preOrden(const struct ArbolBinarioBusqueda & arbol);
void postOrden(const struct ArbolBinarioBusqueda & arbol);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);
int minimoNodoABB(const struct ArbolBinarioBusqueda &);
int maximoNodoABB(const struct ArbolBinarioBusqueda &);
int minimoNodo(struct NodoArbol * nodo);
int maximoNodo(struct NodoArbol * nodo);
struct NodoArbol *  minimoArbol(struct NodoArbol * nodo);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, int elemento);
void eliminarNodo(struct ArbolBinarioBusqueda & ,int );
int comparaABB(int, int);
bool buscaArbolRecursivo(struct NodoArbol * nodo, int dato);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol ,int dato);
int sumarNodos(const struct ArbolBinarioBusqueda & arbol);

#endif /* FUNCIONESARBOLESBB_H */
