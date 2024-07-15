/*
 * Proyecto : EX2-2023_2-P3
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 4 de julio de 2024, 13:53
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define V 9
#define DEFAULT 1
#define MAX_ETI 4
using namespace std;

void asignarEtiquetas(int servidores[V][V], int inicio) {
	int etiquetas[V];
	bool visitados[V];
	bool etiquetados[V];

	for(int i = 0; i < V; i++) {
		etiquetas[i] = DEFAULT;
		visitados[i] = false;
		etiquetados[i] = false;
	}

	Pila vecinos;
	construir(vecinos);

	apilar(vecinos, inicio);
	etiquetas[inicio] = 1;
	visitados[inicio] = true;
	etiquetados[inicio] = true;

	while(!esPilaVacia(vecinos)) {
		int actual = desapilar(vecinos);
		for(int i = V - 1; i >= 0; i--) {
			if(actual == i) continue;  // No evaluamos el cruce del mismo servidor
			if(servidores[actual][i] && !visitados[i]) {
				apilar(vecinos, i);
				visitados[i] = true;
			}
			for(int j = 0; j < V; j++) {
				if(actual == j) continue;  // No evaluamos el cruce del mismo servidor
				if(servidores[actual][j] && etiquetados[j]) {
					if(etiquetas[actual] == etiquetas[j]) {
						etiquetas[actual]++;
						if(etiquetas[actual] > MAX_ETI) {  // Por si la etiqueta se pasa del maximo
							cout << "No hay solucion\n";
							return;
						}
					}
				}
			}
		}
		etiquetados[actual] = true;
	}

	cout << "Servidores: ";
	for(int i = 0; i < V; i++)
		cout << i + 1 << " ";
	cout << "\nEtiquetas : ";
	for(int i = 0; i < V; i++)
		cout << etiquetas[i] << " ";
}

int main(int argc, char** argv) {
	int servidores[V][V] = {
		{1, 2, 0, 6, 0, 0, 0, 0, 2},
		{7, 1, 5, 2, 0, 0, 0, 0, 7},
		{0, 3, 1, 2, 3, 8, 9, 7, 5},
		{2, 7, 5, 1, 2, 0, 0, 0, 0},
		{0, 0, 5, 3, 1, 4, 0, 0, 0},
		{0, 0, 9, 0, 6, 1, 2, 0, 0},
		{0, 0, 3, 0, 0, 7, 1, 4, 0},
		{0, 0, 4, 0, 0, 0, 9, 1, 9},
		{5, 3, 6, 0, 0, 0, 0, 4, 1}
	};
	asignarEtiquetas(servidores, 0);
	return 0;
}
