/*
 * Proyecto : cuenta-inversiones-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 18:03
 */

#include <iostream>
#define N 10
using namespace std;

int contarInversionesCentro(int arr[], int ini, int med, int fin) {
	int cont = 0;
	int izq, der = med + 1;

	while(der <= fin) {
		izq = ini;
		while(izq <= med) {
			if(arr[izq] > arr[der])
				cont++;
			izq++;
		}
		der++;
	}

	return cont;
}

int contarInversiones(int arr[], int ini, int fin){
    if(ini == fin)
		return 0;

	int med = (ini + fin) / 2;

	int izq = contarInversiones(arr, ini, med);
    int der = contarInversiones(arr, med + 1, fin);
    int medio = contarInversionesCentro(arr, ini, med, fin);

	return izq + der + medio;
}

int main(int argc, char** argv) {
	int arr[N] = {7, 5, 8, 2, 3, 4};
    int n = 6;
	int cantInversiones = contarInversiones(arr, 0, n - 1);
    cout << "La cantidad de inversiones fueron " << cantInversiones << endl;
	return 0;
}
