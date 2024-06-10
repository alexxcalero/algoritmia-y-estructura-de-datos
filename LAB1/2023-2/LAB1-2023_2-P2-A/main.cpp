/*
 * Proyecto : LAB1-2023_2-P2-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 21:02
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Antivirus.h"
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

bool cumplePredecesores(Antivirus *arrAntivirus, int *cromo, int size) {
	for(int i = 0; i < size; i++) {
		if(cromo[i] == 1) {
			for(int j = 0; j < 3; j++) {
				if(arrAntivirus[i].requisitos[j] == 0)
					break;
				if(cromo[arrAntivirus[i].requisitos[j] - 1] == 0)
					return false;
			}
		}
	}
	return true;
}

int main(int argc, char** argv) {
	// Inicializo el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo la cantidad de antivirus y el presupuesto
	int n, p;
	arch >> n >> p;

	// Leo los datos de cada antivirus
	Antivirus arrAntivirus[n];
	for(int i = 0; i < n; i++) {
		arch >> arrAntivirus[i].inversion >> arrAntivirus[i].beneficio;
		for(int j = 0; j < 3; j++) {
			arch >> arrAntivirus[i].requisitos[j];
			if(arrAntivirus[i].requisitos[j] == 0)
				break;
		}
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrAntivirus[i].inversion << " " << arrAntivirus[i].beneficio << " ";
//		for(int j = 0; j < 3; j++) {
//			cout << arrAntivirus[i].requisitos[j] << " ";
//			if(arrAntivirus[i].requisitos[j] == 0)
//				break;
//		}
//		cout << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int inversionParcial;
	int cromo[n];
	int comb = pow(2, n);
	int numSol = 0;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		inversionParcial = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				inversionParcial += arrAntivirus[j].inversion;
			}
		}
		if(inversionParcial == p && cumplePredecesores(arrAntivirus, cromo, n)) {
			numSol++;
			cout << "Solucion " << numSol;
			cout << "\nAntivirus seleccionados: ";
			for(int j = 0; j < n; j++)
				if(cromo[j])
					cout << j + 1 << " ";
			cout << endl << endl;
		}
	}

	return 0;
}
