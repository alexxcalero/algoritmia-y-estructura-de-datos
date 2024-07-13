/*
 * Proyecto : predict-de-mikler
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 5 de julio de 2024, 20:33
 */

#include <iostream>
#include <iomanip>
#define MAX 9999
#define V 9
using namespace std;

int hallarMinimaLatencia(int latencias[], bool visitados[]) {
	int menor, menorLatencia = MAX;
	for(int i = 0; i < V; i++) {
		if(!visitados[i] && latencias[i] <= menorLatencia) {
			menorLatencia = latencias[i];
			menor = i;
		}
	}
	return menor;
}

void hallarMinimasLatencias(int servidores[V][V], int inicio) {
	int latencias[V];
	bool visitados[V];
	for(int i = 0; i < V; i++) {
		latencias[i] = MAX;
		visitados[i] = false;
	}

	latencias[inicio] = 0;

	for(int i = 0; i < V - 1; i++) {
		int actual = hallarMinimaLatencia(latencias, visitados);
		visitados[actual] = true;
		for(int j = 0; j < V; j++) {
			if(!visitados[j] && servidores[actual][j] && latencias[actual] != MAX &&
			   (latencias[actual] + servidores[actual][j]) < latencias[j]) {
				latencias[j] = latencias[actual] + servidores[actual][j];
			}
		}
	}

	char letra = 'A';
	cout << "Servidores: ";
	for(int i = 0; i < V; i++) {
		cout << setw(2) << letra << " ";
		letra++;
	}
	cout << "\nLatencias : ";
	for(int i = 0; i < V; i++)
		cout << setw(2) << latencias[i] << " ";
}

int main(int argc, char** argv) {
	int servidores[V][V] = {
	  // A, B, C, D, E, F, G, H, I
		{0, 5, 0, 0, 0, 0, 4, 0, 6},
		{5, 0, 7, 0, 0, 0, 0, 5, 3},
		{0, 7, 0, 4, 0, 0, 0, 1, 0},
		{0, 0, 4, 0, 3, 0, 0, 6, 0},
		{0, 0, 0, 3, 0, 5, 0, 4, 0},
		{0, 0, 0, 0, 5, 0, 1, 5, 0},
		{4, 0, 0, 0, 0, 1, 0, 3, 5},
		{0, 5, 1, 6, 4, 5, 3, 0, 2},
		{6, 3, 0, 0, 0, 0, 5, 2, 0}
	};

	cout << "MINIMAS LATENCIAS POR SERVIDOR:\n";
	hallarMinimasLatencias(servidores, 0);

	return 0;
}
