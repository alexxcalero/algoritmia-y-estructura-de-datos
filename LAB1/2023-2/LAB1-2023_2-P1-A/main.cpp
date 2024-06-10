/*
 * Proyecto : LAB1-2023_2-P1-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 21:25
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Producto.h"
#define N 4
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

void imprimirPesos(Producto arrProductos[][N], int index, int *cromo, int size) {
	for(int i = 0; i < size; i++) {
		if(cromo[i])
			cout << setw(2) << arrProductos[index][i].peso;
		else
			cout << setw(2) << "0";
		cout << " ";
	}
	cout << endl;
}

void imprimirValores(Producto arrProductos[][N], int index, int *cromo, int size) {
	for(int i = 0; i < size; i++) {
		if(cromo[i])
			cout << setw(2) << arrProductos[index][i].valor;
		else
			cout << setw(2) << "0";
		cout << " ";
	}
	cout << endl;
}

int main(int argc, char** argv) {
	// Inicializo el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo la disposicion del almacen y el peso total
	int n, p;
	arch >> n >> p;

	// Leo los datos de cada producto
	Producto arrProductos[N][N];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			arch >> arrProductos[i][j].peso;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			arch >> arrProductos[i][j].valor;
		}
	}

//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << arrProductos[i][j].peso << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << arrProductos[i][j].valor << " ";
//		}
//		cout << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int pesoParcial;
	int valorMaximo = 0, valorParcial;
	int cromo1[n], cromo2[n], cromo3[n], cromo4[n];
	int comb = pow(2, n);
	int solCromo1, solCromo2, solCromo3, solCromo4;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo1, n);
		for(int j = 0; j < comb; j++) {
			cargaBin(j, cromo2, n);
			for(int k = 0; k < comb; k++) {
				cargaBin(k, cromo3, n);
				for(int l = 0; l < comb; l++) {
					cargaBin(l, cromo4, n);
					pesoParcial = 0;
					valorParcial = 0;
					for(int m = 0; m < n; m++) {
						if(cromo1[m] == 1) {
							pesoParcial += arrProductos[0][m].peso;
							valorParcial += arrProductos[0][m].valor;
						}
						if(cromo2[m] == 1) {
							pesoParcial += arrProductos[1][m].peso;
							valorParcial += arrProductos[1][m].valor;
						}
						if(cromo3[m] == 1) {
							pesoParcial += arrProductos[2][m].peso;
							valorParcial += arrProductos[2][m].valor;
						}
						if(cromo4[m] == 1) {
							pesoParcial += arrProductos[3][m].peso;
							valorParcial += arrProductos[3][m].valor;
						}
					}
					if(pesoParcial <= p && valorParcial > valorMaximo) {
						solCromo1 = i;
						solCromo2 = j;
						solCromo3 = k;
						solCromo4 = l;
						valorMaximo = valorParcial;
					}
				}
			}
		}
	}

	// Imprimo la mejor solucion hallada
	cout << "Valor maximo: " << valorMaximo << "(en miles de $)\n";
	cargaBin(solCromo1, cromo1, n);
	cargaBin(solCromo2, cromo2, n);
	cargaBin(solCromo3, cromo3, n);
	cargaBin(solCromo4, cromo4, n);

	cout << "\nPESOS (Toneladas)\n";
	imprimirPesos(arrProductos, 0, cromo1, n);
	imprimirPesos(arrProductos, 1, cromo2, n);
	imprimirPesos(arrProductos, 2, cromo3, n);
	imprimirPesos(arrProductos, 3, cromo4, n);

	cout << "\nVALORES (Miles de $)\n";
	imprimirValores(arrProductos, 0, cromo1, n);
	imprimirValores(arrProductos, 1, cromo2, n);
	imprimirValores(arrProductos, 2, cromo3, n);
	imprimirValores(arrProductos, 3, cromo4, n);

	return 0;
}
