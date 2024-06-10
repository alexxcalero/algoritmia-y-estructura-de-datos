/*
 * Proyecto : LAB1-2019_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 00:22
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Producto.h"
#define MIN_PROD_1 2
#define MIN_PROD_2 2
#define MIN_PROD_3 1
#define MIN_PROD_4 1
using namespace std;

void cargaBin(int num, int *cromo, int size) {
	int i;
	for(i = 0; i < size; i++) {
		cromo[i] = 0;
	}

	i = 0;
	while(num != 0) {
		cromo[i] = num % 2;
		num /= 2;
		i++;
	}
}

void llenarHorasConCero(int *horas, int size) {
	for(int i = 0; i < size; i++)
		horas[i] = 0;
}

int main(int argc, char** argv) {
	// Inicializo el archivo de datos
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	// Leo los datos de cada producto
	Producto arrProductos[12];
	int n = 12;
	for(int i = 0; i < n; i++) {
		arch >> arrProductos[i].codigo >> arrProductos[i].tipo >> arrProductos[i].horaInicio >> arrProductos[i].tiempoEstimado;
	}

//	for(int i = 0; i < n; i++) {
//		cout << arrProductos[i].codigo << " " << arrProductos[i].tipo << " ";
//		cout << arrProductos[i].horaInicio << " " << arrProductos[i].tiempoEstimado << endl;
//	}

	// Algoritmo de Fuerza Bruta
	int cromo[n];
	int comb = pow(2, n);
	int horas[24]{};
	int cantProd1, cantProd2, cantProd3, cantProd4;
	int sol, numSol = 0;
	bool hayCruce;
	for(int i = 0; i < comb; i++) {
		cargaBin(i, cromo, n);
		hayCruce = false;
		cantProd1 = cantProd2 = cantProd3 = cantProd4 = 0;
		llenarHorasConCero(horas, 24);
		for(int j = 0; j < n; j++) {
			if(cromo[j] == 1) {
				for(int k = arrProductos[j].horaInicio; k < arrProductos[j].horaInicio + arrProductos[j].tiempoEstimado; k++) {
					if(horas[k] == 1) {
						hayCruce = true;
						break;
					}
					horas[k] = 1;
				}
				if(!hayCruce) {
					if(arrProductos[j].tipo == 1) cantProd1++;
					else if(arrProductos[j].tipo == 2) cantProd2++;
					else if(arrProductos[j].tipo == 3) cantProd3++;
					else cantProd4++;
				}
			}
		}
		if(!hayCruce) {
			if(cantProd1 >= MIN_PROD_1 && cantProd2 >= MIN_PROD_2 && cantProd3 >= MIN_PROD_3 && cantProd4 >= MIN_PROD_4) {
//				sol = i;
				numSol++;
				cout << "Solucion " << numSol << endl;
				cout << "Productos a repartir:\n";
				for(int k = 0; k < n; k++)
					if(cromo[k])
						cout << arrProductos[k].codigo << " " << arrProductos[k].tipo << endl;
				cout << endl;
			}
		}
	}

	// Si solo quiero imprimir un resultado descomentamos la linea 90 y desde la 104 a la 108.
	// Y a su vez comentamos las lineas desde la 91 a la 97.
//	cargaBin(sol, cromo, n);
//	cout << "Productos a repartir:\n";
//	for(int i = 0; i < n; i++)
//		if(cromo[i])
//			cout << arrProductos[i].codigo << " " << arrProductos[i].tipo << endl;
	
	return 0;
}
