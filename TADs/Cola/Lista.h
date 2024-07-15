/*
 * Proyecto : Lista
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:00
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

struct Lista {
	Nodo *ini;
	Nodo *fin;
	int len;
};

#endif /* LISTA_H */
