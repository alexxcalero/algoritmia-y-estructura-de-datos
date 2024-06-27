/*
 * Proyecto : Colas
 * Archivo  : funcionesDeCola.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 18:39
 */

#ifndef FUNCIONESDECOLA_H
#define FUNCIONESDECOLA_H

void construir(Cola &cola);
bool esColaVacia(const Cola &cola);
int longitud(const Cola &cola);
void encolar(Cola &cola, int dato);
void desencolar(Cola &cola);
int primero(const Cola &cola);
int ultimo(const Cola &cola);
void imprimir(const Cola &cola);
void destruir(Cola &cola);

#endif /* FUNCIONESDECOLA_H */
