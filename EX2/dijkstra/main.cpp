/*
 * Proyecto : dijkstra
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 5 de julio de 2024, 20:17
 */

#include <iostream>
#define MAX 9999
#define V 5
using namespace std;

int hallarMenorDistancia(int distancias[], bool visitados[]) {
	int menor, menorDistancia = MAX;
	for(int i = 0; i < V; i++) {
		if(!visitados[i] && distancias[i] <= menorDistancia) {
			menorDistancia = distancias[i];
			menor = i;
		}
	}
	return menor;
}

void dijkstra(int grafo[V][V], int inicio) {
	int distancias[V];
	bool visitados[V];
	for(int i = 0; i < V; i++) {
		distancias[i] = MAX;
		visitados[i] = false;
	}

	distancias[inicio] = 0;

	for(int i = 0; i < V - 1; i++) {
		int actual = hallarMenorDistancia(distancias, visitados);
		visitados[actual] = true;
		for(int j = 0; j < V; j++) {
			// Verificamos lo siguiente:
			//   1. El vertice j no ha sido visitado
			//   2. Hay camino desde el vertice actual al vertice j
			//   3. La distancia del vertice actual es valida
			//   4. Si la distancia del vertice actual mas la
			//      distancia del vertice actual al vertice j
			//      es menor que la distancia actual al vertice j
			if(!visitados[j] && grafo[actual][j] && distancias[actual] != MAX &&
			   (distancias[actual] + grafo[actual][j]) < distancias[j]) {
				distancias[j] = distancias[actual] + grafo[actual][j];
			}
		}
	}

	cout << "Vertices  : ";
	for(int i = 0; i < V; i++)
		cout << i << " ";
	cout << "\nDistancias: ";
	for(int i = 0; i < V; i++)
		cout << distancias[i] << " ";
}

int main(int argc, char** argv) {
	int grafo[V][V] = {
		{0, 3, 0, 7, 0},
		{3, 0, 4, 2, 0},
		{0, 4, 0, 5, 6},
		{7, 2, 5, 0, 4},
		{0, 0, 6, 4, 0}
	};
	dijkstra(grafo, 0);
	return 0;
}
