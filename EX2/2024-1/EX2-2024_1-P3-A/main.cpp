/*
 * Proyecto : EX2-2024_1-P3-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 6 de julio de 2024, 08:07
 */

#include <iostream>
#define MAX 9999
#define V 6
using namespace std;

int hallarMenorLatencia(int latencias[], bool visitados[]) {
	int menor, menorLatencia = MAX;
	for(int i = 0; i < V; i++) {
		if(!visitados[i] && latencias[i] <= menorLatencia) {
			menorLatencia = latencias[i];
			menor = i;
		}
	}
	return menor;
}

void dikjstra(int matrizServidores[V][V], int matrizSeguridad[V][V], int inicio) {
	int latencias[V];  // Arreglo donde ire guardando las menores latencias
	int seguridades[V];  // Arreglo donde ire sumando las seguridades
	int cantVertices[V];  // Arreglo para llevar la cuenta de los vertices por los que he pasado
	double promedios[V];  // Arreglo donde tengo el nivel de seguridad promedio
	bool visitados[V];  // Arreglo para marcar los servidores visitados

	// Inicializo los arreglos necesarios con sus valores por defecto
	for(int i = 0; i < V; i++) {
		latencias[i] = MAX;
		seguridades[i] = 0;
		cantVertices[i] = 0;
		visitados[i] = false;
	}

	// Seteo los valores para el servidor inicial
	latencias[inicio] = 0;
	promedios[inicio] = 0;

	for(int i = 0; i < V; i++) {
		// Vertice no visitado con la menor distancia calculada hasta el momento
		int actual = hallarMenorLatencia(latencias, visitados);
		visitados[actual] = true;

		// Para evitar dividir entre cero (esto sucederia en la primera iteracion)
		if(cantVertices[actual] > 0)
			promedios[actual] = (double)seguridades[actual] / cantVertices[actual];

		for(int j = 0; j < V; j++) {
			if(!visitados[j] && matrizServidores[actual][j] && latencias[actual] != MAX
			   && (latencias[actual] + matrizServidores[actual][j] < latencias[j])) {
				// Actualizo la latencia
				latencias[j] = latencias[actual] + matrizServidores[actual][j];
				// Voy aumentando la suma del valor de seguridad
				seguridades[j] = seguridades[actual] + matrizSeguridad[actual][j];
				// Aumento la cantidad de vertices en uno
				cantVertices[j] = cantVertices[actual] + 1;
			}
		}
	}

	for(int i = 0; i < V; i++) {
		cout << "Servidor: " << i + 1 << " Latencia: " << latencias[i];
		cout << " Seguridad Promedio: " << promedios[i] << endl;
	}
}

int main(int argc, char** argv) {
	int matrizServidores[V][V] = {
		{0, 0, 0, 3, 0, 0},
		{0, 0, 1, 0, 3, 0},
		{0, 1, 0, 2, 5, 7},
		{3, 0, 2, 0, 7, 0},
		{0, 3, 5, 7, 0, 2},
		{0, 0, 7, 0, 2, 0},
	};
	int matrizSeguridad[V][V] = {
		{0, 0, 0, 9, 0, 0},
		{0, 0, 7, 0, 8, 0},
		{0, 7, 0, 7, 5, 7},
		{9, 0, 7, 0, 7, 0},
		{0, 8, 5, 7, 0, 9},
		{0, 0, 7, 0, 9, 0},
	};

//	int matrizServidores[V][V] = {
//		{0, 0, 0, 3, 0, 0},
//		{0, 0, 3, 0, 3, 0},
//		{0, 3, 0, 2, 5, 7},
//		{3, 0, 2, 0, 7, 0},
//		{0, 3, 5, 7, 0, 2},
//		{0, 0, 7, 0, 2, 0},
//	};
//	int matrizSeguridad[V][V] = {
//		{0, 0, 0, 9, 0, 0},
//		{0, 0, 7, 0, 8, 0},
//		{0, 7, 0, 7, 5, 7},
//		{9, 0, 7, 0, 7, 0},
//		{0, 8, 5, 7, 0, 9},
//		{0, 0, 7, 0, 9, 0},
//	};

	dikjstra(matrizServidores, matrizSeguridad, 0);

	return 0;
}
