/*
 * Proyecto : LAB1-2020_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 01:47
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Maquina.h"
#define MIN_MAQ_1 1
#define MIN_MAQ_2 1
#define MIN_MAQ_3 1
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
		cout << "ERROR: No se pudo abrir el archivo.\n";
		exit(1);
	}

	// Leo el total de maquinas y el presupuesto total
	int n, p;
	arch >> n >> p;

	// Leo los datos de cada maquina
	Maquina arrMaquinas[n];
	for(int i = 0; i < n; i++) {
		arch >> arrMaquinas[i].costo >> arrMaquinas[i].ganancia >> arrMaquinas[i].tipo;
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrMaquinas[i].costo << " " << arrMaquinas[i].ganancia << " " << arrMaquinas[i].tipo << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int costoTotal, costoParcial;
	int gananciaMaxima = 0, gananciaParcial;
	int tipo1, tipo2, tipo3;
	int cromo[n];
	int comb = pow(2, n);
	int sol, numSol = 0;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		costoParcial = 0;
		gananciaParcial = 0;
		tipo1 = tipo2 = tipo3 = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				costoParcial += arrMaquinas[j].costo;
				gananciaParcial += arrMaquinas[j].ganancia;
				if(arrMaquinas[j].tipo == 1) tipo1++;
				else if(arrMaquinas[j].tipo == 2) tipo2++;
				else tipo3++;
			}
		}
		if(costoParcial <= p && gananciaParcial > gananciaMaxima && tipo1 >= MIN_MAQ_1 && tipo2 >= MIN_MAQ_2 && tipo3 >= MIN_MAQ_3) {
			sol = i;
			costoTotal = costoParcial;
			gananciaMaxima = gananciaParcial;
		}
	}

	// Imprimo la respuesta hallada
	cargaBin(sol, cromo, n);
	cout << "INCISO A y B:\n";
	cout << "Maquinas: ";
	for(int i = 0; i < n; i++)
		if(cromo[i])
			cout << i + 1 << " ";
	cout << "\nCosto de maquinas: " << costoTotal << "(Millones de $)\n";
	cout << "Ganancia Maxima: " << gananciaMaxima << "(Millones de $)\n";

	// El codigo que viene abajo es del inciso C
	cout << "\nINCISO C:\n";
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		costoParcial = 0;
		gananciaParcial = 0;
		tipo1 = tipo2 = tipo3 = 0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				costoParcial += arrMaquinas[j].costo;
				gananciaParcial += arrMaquinas[j].ganancia;
				if(arrMaquinas[j].tipo == 1) tipo1++;
				else if(arrMaquinas[j].tipo == 2) tipo2++;
				else tipo3++;
			}
		}
		if(costoParcial <= p && gananciaParcial == gananciaMaxima && tipo1 >= MIN_MAQ_1 && tipo2 >= MIN_MAQ_2 && tipo3 >= MIN_MAQ_3) {
			numSol++;
			costoTotal = costoParcial;
			gananciaMaxima = gananciaParcial;
			cout << "Solucion " << numSol;
			cout << "\nMaquinas: ";
			for(int k = 0; k < n; k++)
				if(cromo[k])
					cout << k + 1 << " ";
			cout << "\nCosto de maquinas: " << costoTotal << "(Millones de $)\n";
			cout << "Ganancia Maxima: " << gananciaMaxima << "(Millones de $)\n";
		}
	}

	return 0;
}
