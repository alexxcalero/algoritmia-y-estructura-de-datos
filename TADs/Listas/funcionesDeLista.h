/*
 * Proyecto : Listas
 * Archivo  : funcionesDeLista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 16:20
 */

#ifndef FUNCIONESDELISTA_H
#define FUNCIONESDELISTA_H

void construir(Lista &lista);
bool esListaVacia(const Lista &lista);
int longitud(const Lista &lista);
void insertarAlInicio(Lista &lista, int dato);
void insertarAlFinal(Lista &lista, int dato);
void insertarOrdenado(Lista &lista, int dato);
int cabeza(const Lista &lista);
int cola(const Lista &lista);
void eliminarCabeza(Lista &lista);
void imprimir(const Lista &lista);
void destruir(Lista &lista);

#endif /* FUNCIONESDELISTA_H */
