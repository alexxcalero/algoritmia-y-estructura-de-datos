/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeListaVertice.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#ifndef FUNCIONESDELISTAVERTICE_H
#define FUNCIONESDELISTAVERTICE_H

void construirListaVertice(ListaVertice &lista);
bool esListaVerticeVacia(const ListaVertice &lista);
bool seEncuentraVerticeEnLista(const ListaVertice &lista, char llave);
NodoListaVertice *crearNodoVertice(char dato, NodoListaVertice *sig);
NodoListaVertice *obtenerUltimoNodoVertice(const ListaVertice &lista);
void insertarVerticeAlFinal(ListaVertice &lista, char dato);
NodoListaVertice *obtenerNodoVertice(const ListaVertice &lista, char llave);
bool seEncuentraAristaEnLista(const ListaVertice &lista, char origen, char destino);
void insertarListaAristas(ListaVertice &lista, char origen, char destino);
void eliminarDeListaDeAristas(ListaVertice &lista, char origen, char destino);
void eliminarVerticeEnLista(ListaVertice &lista, char vertice);
void destruirListaVertice(ListaVertice &lista);

#endif /* FUNCIONESDELISTAVERTICE_H */
