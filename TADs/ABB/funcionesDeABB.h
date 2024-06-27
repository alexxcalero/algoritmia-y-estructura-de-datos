/*
 * Proyecto : ABB
 * Archivo  : funcionesDeABB.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 20:37
 */

#ifndef FUNCIONESDEABB_H
#define FUNCIONESDEABB_H

#include "ArbolBinarioBusqueda.h"

void construir(ArbolBinarioBusqueda &arbol);

void plantarABB(NodoArbol *&nodo, NodoArbol *arbolIzq, int dato, NodoArbol *arbolDer);
void insertarRecursivo(NodoArbol *&nodo, int dato);
void insertar(ArbolBinarioBusqueda &arbol, int dato);

void recorrerEnOrden(const ArbolBinarioBusqueda &arbol);
void recorrerEnPreorden(const ArbolBinarioBusqueda &arbol);
void recorrerEnPostorden(const ArbolBinarioBusqueda &arbol);

bool buscarDatoRecursivo(NodoArbol *nodo, int dato);
bool buscarDato(const ArbolBinarioBusqueda &arbol, int dato);

NodoArbol *minimoNodoRecursivo(NodoArbol *nodo);
NodoArbol *minimoNodo(ArbolBinarioBusqueda &arbol);

NodoArbol *mayorNodoRecursivo(NodoArbol *nodo);
NodoArbol *mayorNodo(ArbolBinarioBusqueda &arbol);

NodoArbol *eliminarNodoRecursivo(NodoArbol *nodo, int dato);
void eliminarNodo(ArbolBinarioBusqueda &arbol, int dato);

void destruir(ArbolBinarioBusqueda &arbol);

#endif /* FUNCIONESDEABB_H */
