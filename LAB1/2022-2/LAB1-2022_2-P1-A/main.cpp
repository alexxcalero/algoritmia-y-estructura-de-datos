/*
 * Proyecto : LAB1-2022_2-P1-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 03:32
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Herramienta.h"
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

	// Leo la cantidad de herramientas, la cantidad maxima de tipos de herramientas
	// a renovar y el presupuesto total
	int n, m, p;
	arch >> n >> m >> p;

	// Leo los datos de cada herramienta;
	Herramienta arrHerramientas[n];
	for(int i = 0; i < n; i++)
		arch >> arrHerramientas[i].precio >> arrHerramientas[i].cantidad;

//	for(int i = 0; i < n; i++)
//		cout << arrHerramientas[i].precio << " " << arrHerramientas[i].cantidad << endl;

	// Algoritmo de Fuerza Bruta
	int presupuestoTotal, presupuestoParcial;
	int cantHerraMaxima = 0, cantHerraParcial;
	int cromo[n];
	int comb = pow(2, n);
	int sol;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		presupuestoParcial = 0;
		cantHerraParcial = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				presupuestoParcial += (arrHerramientas[j].cantidad * arrHerramientas[j].precio);
				cantHerraParcial += arrHerramientas[j].cantidad;
			}
		}
		if(presupuestoParcial <= p && cantHerraParcial > cantHerraMaxima) {
			sol = i;
			presupuestoTotal = presupuestoParcial;
			cantHerraMaxima = cantHerraParcial;
		}
	}

	// Imprimo el resultado hallado
	cargaBin(sol, cromo, n);
	cout << "Mejor solucion: ";
	for(int i = 0; i < n; i++)
		if(cromo[i])
			cout << i + 1 << " ";
	cout << "\nMonto total: " << presupuestoTotal;
	cout << "\nCantidad de herramientas: " << cantHerraMaxima << endl;

	return 0;
}
