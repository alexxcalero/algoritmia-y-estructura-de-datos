/*
 * Proyecto : Listas
 * Archivo  : Lista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 16:19
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

struct Lista {
	Nodo *cabeza;
	Nodo *cola;
	int longitud;
};

#endif /* LISTA_H */
