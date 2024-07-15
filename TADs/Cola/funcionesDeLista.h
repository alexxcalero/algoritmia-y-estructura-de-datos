/*
 * Proyecto : Lista
 * Archivo  : funcionesDeLista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:01
 */

#ifndef FUNCIONESDELISTA_H
#define FUNCIONESDELISTA_H

void construir(Lista &lista);
bool esListaVacia(const Lista &lista);
int longitud(const Lista &lista);
void insertarAlInicio(Lista &lista, int dato);
void insertarAlFinal(Lista &lista, int dato);
void insertarOrdenado(Lista &lista, int dato);
int primero(const Lista &lista);
int ultimo(const Lista &lista);
void eliminarCabeza(Lista &lista);
void imprimir(const Lista &lista);
void destruir(Lista &lista);

#endif /* FUNCIONESDELISTA_H */
