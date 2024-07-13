/*
 * Proyecto : recorrido-dfs-para-grafo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 5 de julio de 2024, 20:12
 */

/*
 * TEORIA SACADA DEL SIGUIENTE LINK:
 * https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define V 5
using namespace std;

void dfs(int grafo[V][V], int inicio) {
	bool visitados[V];
	for(int i = 0; i < V; i++)
		visitados[i] = false;

	Pila porVisitar;
	construir(porVisitar);

	apilar(porVisitar, inicio);
	visitados[inicio] = true;

	while(!esPilaVacia(porVisitar)) {
		int actual = desapilar(porVisitar);
		cout << actual << " ";
		for(int i = V - 1; i >= 0; i--) {
			// Verificamos lo siguiente:
			//   1. El vertice i no ha sido visitado
			//   2. Hay camino desde el vertice actual al vertice i
			if(!visitados[i] && grafo[actual][i]) {
				apilar(porVisitar, i);
				visitados[i] = true;
			}
		}
	}
}

int main(int argc, char** argv) {
	int grafo[V][V] = {
		{0, 1, 1, 1, 0},
		{1, 0, 0, 0, 0},
		{1, 0, 0, 1, 1},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 0}
	};
	dfs(grafo, 0);
	return 0;
}
