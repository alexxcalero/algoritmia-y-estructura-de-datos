/*
 * Proyecto : LAB1-2019_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 30 de marzo de 2024, 23:46
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Proyecto.h"
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

bool cumplePredecesores(int *cromo, int size, Proyecto *arrProyectos) {
	for(int i = 0; i < size; i++) {
		if(cromo[i] == 1) {
			for(int j = 0; j < 3; j++) {
				if(arrProyectos[i].predecesores[j] == 0)
					break;
				if(cromo[arrProyectos[i].predecesores[j]-1] == 0)
					return false;
			}
		}
	}
	return true;
}

int main(int argc, char** argv) {
	// Abro el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo el total de proyectos y el presupuesto maximo
	int n, p;
	arch >> n >> p;

	// Leo los costos, ganancias y predecesores de los proyectos
	Proyecto arrProyectos[n];
	for(int i = 0; i < n; i++) {
		arch >> arrProyectos[i].costo >> arrProyectos[i].ganancia;
		for(int j = 0; j < 3; j++) {
			arch >> arrProyectos[i].predecesores[j];
			if(arrProyectos[i].predecesores[j] == 0)
				break;
		}
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrProyectos[i].costo << " " << arrProyectos[i].ganancia << " ";
//		for(int j = 0; j < 3; j++) {
//			cout << arrProyectos[i].predecesores[j] << " ";
//			if(arrProyectos[i].predecesores[j] == 0)
//				break;
//		}
//		cout << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int gananciaMaxima = 0, gananciaParcial;
	int costoParcial;
	int cromo[n];
	int comb = pow(2, n);
	int sol;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		costoParcial = 0;
		gananciaParcial = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j]) {
				costoParcial += arrProyectos[j].costo;
				gananciaParcial += arrProyectos[j].ganancia;
			}
		}
		if(gananciaParcial > gananciaMaxima && costoParcial <= p && cumplePredecesores(cromo, n, arrProyectos)) {
			gananciaMaxima = gananciaParcial;
			sol = i;
		}
	}

	// Imprimo la solucion hallada
	cargaBin(sol, cromo, n);
	cout << "Proyectos: ";
	for(int i = 0; i < n; i++) {
		if(cromo[i] == 1) {
			cout << i + 1 << " ";
		}
	}
	cout << "\nGanancia Maxima: " << gananciaMaxima << endl;

	return 0;
}
