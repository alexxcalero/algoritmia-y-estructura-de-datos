/*
 * Proyecto : recorrido-bfs-para-grafo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 5 de julio de 2024, 20:07
 */

/*
 * TEORIA SACADA DEL SIGUIENTE LINK:
 * https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
 */

#include <iostream>
#include "Cola.h"
#include "funcionesCola.h"
#define V 5
using namespace std;

void bfs(int grafo[V][V], int inicio) {
	bool visitados[V];
	for(int i = 0; i < V; i++)
		visitados[i] = false;

	Cola porVisitar;
	construir(porVisitar);

	encolar(porVisitar, inicio);
	visitados[inicio] = true;

	while(!esColaVacia(porVisitar)) {
		int actual = desencolar(porVisitar);
		cout << actual << " ";
		for(int i = 0; i < V; i++) {
			// Verificamos lo siguiente:
			//   1. El vertice i no ha sido visitado
			//   2. Hay camino desde el vertice actual al vertice i
			if(!visitados[i] && grafo[actual][i]) {
				encolar(porVisitar, i);
				visitados[i] = true;
			}
		}
	}
}

int main(int argc, char** argv) {
	int grafo[V][V] = {
		{0, 1, 1, 0, 0},
		{1, 0, 1, 1, 0},
		{1, 1, 0, 0, 1},
		{0, 1, 0, 0, 1},
		{0, 0, 1, 1, 0}
	};
	bfs(grafo, 0);
	return 0;
}
