/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeListaArista.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#ifndef FUNCIONESDELISTAARISTA_H
#define FUNCIONESDELISTAARISTA_H

void construirListaArista(ListaArista &lista);
bool seEncuentraAristaEnListaArista(ListaArista &lista, char llave);
NodoListaArista *crearNodoArista(char dato, NodoListaArista *sig);
NodoListaArista *obtenerUltimoNodoArista(const ListaArista &lista);
void insertarAristaAlFinal(ListaArista &lista, char vertice);
void eliminarAristaEnLista(ListaArista &lista, char vertice);
void destruirListaArista(ListaArista &lista);

#endif /* FUNCIONESDELISTAARISTA_H */
