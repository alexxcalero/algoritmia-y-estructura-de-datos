/*
 * Proyecto : LAB1-2019_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de marzo de 2024, 23:27
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Articulo.h"
using namespace std;

void cargaBin(int num, int *cromo, int size) {
	int i;
	for(i = 0; i < size; i++)
		cromo[i] = 0;

	i = 0;
	while(num != 0) {
		cromo[i] = num % 2;
		num /= 2;
		i++;
	}
}

int main(int argc, char** argv) {
	// Abro el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo el total de articulos y el peso maximo
	int m, w;
	arch >> m >> w;

	// Leo los pesos y ganancias de los articulos
	Articulo arrArticulos[m];
	for(int i = 0; i < m; i++)
		arch >> arrArticulos[i].peso >> arrArticulos[i].ganancia;

//	for(int i = 0; i < m; i++)
//		cout << arrArticulos[i].peso << " " << arrArticulos[i].ganancia << endl;

	// Algoritmo de Fuerza Bruta
	int gananciaMaxima = 0, gananciaParcial;
	int pesoParcial;
	int cromo[m];
	int comb = pow(2, m);
	int sol;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, m);
		pesoParcial = 0;
		gananciaParcial = 0;
		for(int j = 0; j < m; j++) {
			if(cromo[j] == 1) {
				pesoParcial += arrArticulos[j].peso;
				gananciaParcial += arrArticulos[j].ganancia;
			}
		}
		if(gananciaParcial > gananciaMaxima && pesoParcial <= w) {
			gananciaMaxima = gananciaParcial;
			sol = i;
		}
	}

	// Imprimo la solucion hallada
	cargaBin(sol, cromo, m);
	cout << "Articulos: ";
	for(int i = 0; i < m; i++) {
		if(cromo[i] == 1) {
			cout << i + 1 << " ";
		}
	}
	cout << "\nGanancia Total: " << gananciaMaxima << endl;

	return 0;
}
