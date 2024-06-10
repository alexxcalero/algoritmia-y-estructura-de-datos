/*
 * Proyecto : LAB1-2021_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 23:42
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Cliente.h"
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
		cout << "ERROR: No se pudo abrir el archivo.\n";
		exit(1);
	}

	// Leo la cantidad de acciones a comprar, el precio de la accion
	// y la cantidad de clientes
	int t, p, n;
	arch >> t >> p >> n;

	// Leo los datos de cada cliente
	Cliente arrClientes[n];
	for(int i = 0; i < n; i++) {
		arch >> arrClientes[i].acciones >> arrClientes[i].comision;
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrClientes[i].acciones << " " << arrClientes[i].comision << endl;
//	}

	// Algoritmo de Fuerza Bruta
	double gananciaMaxima = 0.0, gananciaParcial;
	int accionesTotales, accionesParciales;
	int cromo[n];
	int comb = pow(2, n);
	int sol, numSol = 0;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		accionesParciales = 0;
		gananciaParcial = 0.0;
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				accionesParciales += arrClientes[j].acciones;
				gananciaParcial += (arrClientes[j].acciones * p * arrClientes[j].comision);
			}
		}
		if(accionesParciales <= t && gananciaParcial > gananciaMaxima) {
			sol = i;
			accionesTotales = accionesParciales;
			gananciaMaxima = gananciaParcial;
		}
	}

	// Imprimo la solucion hallada
	cargaBin(sol, cromo, n);
	cout << "La maxima ganancia es de " << fixed << setprecision(2) << gananciaMaxima;
	cout << " dolares por un total de " << accionesTotales << " acciones.\n";
	cout << "\nLos clientes que se deben elegir para obtener la mayor ganancia son:\n";
	for(int i = 0; i < n; i++) {
		if(cromo[i]) {
			cout << " - El cliente " << i + 1 << " otorga una ganancia de ";
			cout << fixed << setprecision(2) << arrClientes[i].acciones * p * arrClientes[i].comision;
			cout << " dolares por comprar " << arrClientes[i].acciones << " acciones.\n";
		}
	}

	// Descomentar el codigo que viene a continuación para cumplir con el inciso C
//	for(int i = 0; i < comb; i++) {
//		cargaBin(i, cromo, n);
//		accionesParciales = 0;
//		gananciaParcial = 0.0;
//		for(int j = 0; j < n; j++) {
//			if(cromo[j] == 1) {
//				accionesParciales += arrClientes[j].acciones;
//				gananciaParcial += (arrClientes[j].acciones * p * arrClientes[j].comision);
//			}
//		}
//		if(accionesParciales <= t && abs(gananciaParcial - gananciaMaxima) < 1.0) {
//			numSol++;
//			cout << "\nSolucion " << numSol;
//			cout << "\nLa maxima ganancia es de " << fixed << setprecision(2) << gananciaParcial;
//			cout << " dolares por un total de " << accionesParciales << " acciones.\n";
//			cout << "\nLos clientes que se deben elegir para obtener la mayor ganancia son:\n";
//			for(int j = 0; j < n; j++) {
//				if(cromo[j]) {
//					cout << " - El cliente " << j + 1 << " otorga una ganancia de ";
//					cout << fixed << setprecision(2) << arrClientes[j].acciones * p * arrClientes[j].comision;
//					cout << " dolares por comprar " << arrClientes[j].acciones << " acciones.\n";
//				}
//			}
//		}
//	}
	
	return 0;
}
