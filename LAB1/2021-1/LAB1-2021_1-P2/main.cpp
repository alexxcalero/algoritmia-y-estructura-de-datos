/*
 * Proyecto : LAB1-2021_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 02:42
 */

#include <iostream>
#include <fstream>
#include <cmath>
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

	// Leo la cantidad de productos, la cantidad de divisiones y el peso maximo
	int n, m, c;
	arch >> n >> m >> c;

	// Leo los productos de cada bahia
	int arrBahias[3][n];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < n; j++)
			arch >> arrBahias[i][j];

//	for(int i = 0; i < 3; i++) {
//		for(int j = 0; j < n; j++)
//			cout << arrBahias[i][j] << " ";
//		cout << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int pesoParcial;
	int cantProductos;
	int cromo1[n], cromo2[n], cromo3[n];
	int comb = pow(2, n);
	int numSol = 0;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo1, n);
		for(int j = 0; j < comb; j++) {
			cargaBin(j, cromo2, n);
			for(int k = 0; k < comb; k++) {
				cargaBin(k, cromo3, n);
				pesoParcial = 0;
				cantProductos = 0;
				for(int l = 0; l < n; l++) {
					if(cromo1[l] == 1) {
						pesoParcial += arrBahias[0][l];
						cantProductos++;
					}
					if(cromo2[l] == 1) {
						pesoParcial += arrBahias[1][l];
						cantProductos++;
					}
					if(cromo3[l] == 1) {
						pesoParcial += arrBahias[2][l];
						cantProductos++;
					}
				}
				if(cantProductos == m && pesoParcial == c) {
					numSol++;
					cout << "Solucion " << numSol;
					cout << "\nBahia 1: ";
					for(int l = 0; l < n; l++)
						if(cromo1[l])
							cout << arrBahias[0][l] << " ";
					cout << "\nBahia 2: ";
					for(int l = 0; l < n; l++)
						if(cromo2[l])
							cout << arrBahias[1][l] << " ";
					cout << "\nBahia 3: ";
					for(int l = 0; l < n; l++)
						if(cromo3[l])
							cout << arrBahias[2][l] << " ";
					cout << endl << endl;
					//return EXIT_SUCCESS;  // Comentar esta linea para el inciso C
				}
			}
		}
	}

	return 0;
}
