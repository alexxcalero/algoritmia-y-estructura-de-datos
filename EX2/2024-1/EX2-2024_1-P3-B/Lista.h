/*
 * File:   Lista.h
 * Author: ANA RONCAL
 *
 * Created on 4 de julio de 2024, 10:58
 */

#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

struct Lista {
	struct Nodo * cabeza; /*apunta al inicio de la lista*/
	int longitud; /*guarda la longitud de la lista*/
};

#endif /* LISTA_H */
