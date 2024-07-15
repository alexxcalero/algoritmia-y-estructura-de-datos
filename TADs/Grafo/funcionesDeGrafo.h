/*
 * Proyecto : Grafo
 * Archivo  : funcionesDeGrafo.h
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de julio de 2024, 00:01
 */

#ifndef FUNCIONESDEGRAFO_H
#define FUNCIONESDEGRAFO_H

void construirGrafo(Grafo &grafo);
bool esGrafoVacio(const Grafo &grafo);
bool seEncuentraVertice(const Grafo &grafo, char vertice);
void agregarVertice(Grafo &grafo, char vertice);
bool seEncuentraArista(const Grafo &grafo, char origen, char destino);
void agregarArista(Grafo &grafo, char origen, char destino);
int longitudGrafo(const Grafo &grafo);
void eliminarVertice(Grafo &grafo, char vertice);
void eliminarArista(Grafo &grafo, char origen, char destino);
void imprimirGrafo(const Grafo &grafo);
void destruirGrafo(Grafo &grafo);

#endif /* FUNCIONESDEGRAFO_H */
