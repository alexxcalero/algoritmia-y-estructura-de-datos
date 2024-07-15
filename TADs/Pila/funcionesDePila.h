/*
 * Proyecto : Pila
 * Archivo  : funcionesDePila.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 19:34
 */

#ifndef FUNCIONESDEPILA_H
#define FUNCIONESDEPILA_H

void construir(Pila &pila);
bool esPilaVacia(const Pila &pila);
int longitud(const Pila &pila);
void apilar(Pila &pila, int dato);
void desapilar(Pila &pila);
int cima(const Pila &pila);
void imprimir(const Pila &pila);
void destruir(Pila &pila);

#endif /* FUNCIONESDEPILA_H */
