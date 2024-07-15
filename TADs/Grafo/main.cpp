/*
 * Proyecto : Grafo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 14 de julio de 2024, 23:55
 */

#include <iostream>
#include "Grafo.h"
#include "funcionesDeGrafo.h"
using namespace std;

int main(int argc, char** argv) {
	Grafo grafo;
	construirGrafo(grafo);

	agregarVertice(grafo, 'A');
	agregarVertice(grafo, 'B');
	agregarVertice(grafo, 'C');
	agregarVertice(grafo, 'D');
	agregarVertice(grafo, 'E');
	agregarVertice(grafo, 'F');

	agregarArista(grafo, 'A', 'C');
	agregarArista(grafo, 'B', 'C');
	agregarArista(grafo, 'B', 'F');
	agregarArista(grafo, 'C', 'E');
	agregarArista(grafo, 'D', 'A');
	agregarArista(grafo, 'D', 'E');
	agregarArista(grafo, 'E', 'C');
	agregarArista(grafo, 'E', 'F');

	cout << "Grafo inicial:\n";
	imprimirGrafo(grafo);

	eliminarVertice(grafo, 'E');
	eliminarArista(grafo, 'C', 'E');
	eliminarArista(grafo, 'D', 'E');
	cout << "\nGrafo luego de eliminar el vertice E:\n";
	imprimirGrafo(grafo);

	destruirGrafo(grafo);

	return 0;
}
