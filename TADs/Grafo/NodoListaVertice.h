/*
 * Proyecto : Grafo
 * Archivo  : NodoListaVertice.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 23:55
 */

#ifndef NODOLISTAVERTICE_H
#define NODOLISTAVERTICE_H

#include "ListaArista.h"

struct NodoListaVertice {
	char dato;
	NodoListaVertice *sig;
	ListaArista listaArista;
};

#endif /* NODOLISTAVERTICE_H */
