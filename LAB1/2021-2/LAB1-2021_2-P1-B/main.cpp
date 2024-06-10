/*
 * Proyecto : LAB1-2021_2-P1-B
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 1 de abril de 2024, 00:43
 */

#include <iostream>
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

int main(int argc, char** argv) {
	// Inicializo el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo la cantidad de secciones y el peso solicitado
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
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < n; j++) {
//			cout << arrProductos[i][j].valor << " ";
//		}
//		cout << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int pesoParcial;
	int gananciaMaxima = 0, gananciaParcial;
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
					gananciaParcial = 0;
					for(int m = 0; m < n; m++) {
						if(cromo1[m] == 1) {
							pesoParcial += arrProductos[0][m].peso;
							gananciaParcial += arrProductos[0][m].valor;
						}
						if(cromo2[m] == 1) {
							pesoParcial += arrProductos[1][m].peso;
							gananciaParcial += arrProductos[1][m].valor;
						}
						if(cromo3[m] == 1) {
							pesoParcial += arrProductos[2][m].peso;
							gananciaParcial += arrProductos[2][m].valor;
						}
						if(cromo4[m] == 1) {
							pesoParcial += arrProductos[3][m].peso;
							gananciaParcial += arrProductos[3][m].valor;
						}
					}
					if(pesoParcial <= p && gananciaParcial >= gananciaMaxima) {
						solCromo1 = i;
						solCromo2 = j;
						solCromo3 = k;
						solCromo4 = l;
						gananciaMaxima = gananciaParcial;
					}
				}
			}
		}
	}

	// Imprimo la respuesta hallada
	cout << "Ganancia: " << gananciaMaxima;
	cout << "\nResultado: ";
	cargaBin(solCromo1, cromo1, n);
	cargaBin(solCromo2, cromo2, n);
	cargaBin(solCromo3, cromo3, n);
	cargaBin(solCromo4, cromo4, n);
	for(int m = 0; m < n; m++) {
		if(cromo1[m] == 1) cout << arrProductos[0][m].peso << "k ";
		if(cromo2[m] == 1) cout << arrProductos[1][m].peso << "k ";
		if(cromo3[m] == 1) cout << arrProductos[2][m].peso << "k ";
		if(cromo4[m] == 1) cout << arrProductos[3][m].peso << "k ";
	}
	cout << "\nUbicaciones: ";
	for(int m = 0; m < n; m++) {
		if(cromo1[m] == 1) cout << "IA" << m + 1 << " ";
		if(cromo2[m] == 1) cout << "IB" << m + 1 << " ";
		if(cromo3[m] == 1) cout << "DA" << m + 1 << " ";
		if(cromo4[m] == 1) cout << "DB" << m + 1 << " ";
	}
	cout << endl;

	return 0;
}
