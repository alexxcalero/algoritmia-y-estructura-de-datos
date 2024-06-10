/*
 * Proyecto : LAB1-2020_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 01:18
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Obrero.h"
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
	// Inicializo el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo la cantidad maxima y minima de obreros y el presupuesto total
	int n, m, p;
	arch >> n >> m >> p;

	// Leo los datos de los obreros
	Obrero arrObreros[n];
	for(int i = 0; i < n; i++) {
		arch >> arrObreros[i].piezasRotas >> arrObreros[i].salario;
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrObreros[i].piezasRotas << " " << arrObreros[i].salario << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int sumPiezasRotas;
	int salarioTotal, salarioParcial;
	int cantObreros;
	int cromo[n];
	int comb = pow(2, n);
	int sol, numSol = 0;
	double promMenor = 9999.9999, promParcial;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		sumPiezasRotas = 0;
		salarioParcial = 0;
		cantObreros = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				salarioParcial += arrObreros[j].salario;
				sumPiezasRotas += arrObreros[j].piezasRotas;
				cantObreros++;
			}
		}
		promParcial = (double)sumPiezasRotas / cantObreros;
		if(salarioParcial <= p && cantObreros >= m && promParcial < promMenor) {
			promMenor = promParcial;
			salarioTotal = salarioParcial;
			sol = i;
		}
	}

	// Imprimo la solucion hallada
	cargaBin(sol, cromo, n);
	cout << "INCISO A y B:\n";
	cout << "Obreros: ";
	for(int i = 0; i < n; i++)
		if(cromo[i])
			cout << i + 1 << " ";
	cout << "\nCosto de salarios: " << salarioTotal << " (Miles de $)";
	cout << "\nRotura promedio: " << promMenor << endl;

	// El codigo que viene a continuacion es para el inciso C
	cout << "\nINCISO C:\n";
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		sumPiezasRotas = 0;
		salarioParcial = 0;
		cantObreros = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				salarioParcial += arrObreros[j].salario;
				sumPiezasRotas += arrObreros[j].piezasRotas;
				cantObreros++;
			}
		}
		promParcial = (double)sumPiezasRotas / cantObreros;
		if(salarioParcial <= p && cantObreros >= m && promParcial == promMenor) {
			promMenor = promParcial;
			salarioTotal = salarioParcial;
			numSol++;
			cout << "Solucion " << numSol;
			cout << "\nObreros: ";
			for(int k = 0; k < n; k++)
				if(cromo[k])
					cout << k + 1 << " ";
			cout << "\nCosto de salarios: " << salarioTotal << " (Miles de $)";
			cout << "\nRotura promedio: " << promMenor << endl << endl;
		}
	}

	return 0;
}
