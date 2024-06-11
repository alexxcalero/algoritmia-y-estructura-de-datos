/*
 * Proyecto : merge-sort-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 17:20
 */

#include <iostream>
#define N 15
using namespace std;

void merge(int arr[], int ini, int med, int fin) {
	int aux[N]{};
	int p, q, m;

	for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
		if(arr[p] < arr[q]) {
			aux[m] = arr[p];
			p++;
		} else {
			aux[m] = arr[q];
			q++;
		}
	}

	// Por si quedan pasar datos antes de la mitad
	while(p <= med) {
		aux[m] = arr[p];
		p++;
		m++;
	}

	// Por si quedan pasar datos despues de la mitad
	while(q <= fin) {
		aux[m] = arr[q];
		q++;
		m++;
	}

	// Copio el arreglo auxiliar ordenado al original
	for(int i = ini; i <= fin; i++)
		arr[i] = aux[i];
}

void mergeSort(int arr[], int ini, int fin) {
	if(ini == fin)
		return;

	int medio = (ini + fin) / 2;
	mergeSort(arr, ini, medio);
	mergeSort(arr, medio + 1, fin);
	merge(arr, ini, medio, fin);
}

int main(int argc, char** argv) {
	int arreglo[] = {11, 2, 7, 1, 2, 3, 5};
	int n = 7;
	int i;

	cout << "Arreglo original:\n";
	for(i = 0; i < n; i++)
		cout << arreglo[i] << " ";
	cout << endl;

	// Ordeno el arreglo mediante Merge Sort
	mergeSort(arreglo, 0, n - 1);

	cout << "Arreglo ordenado a traves de Merge Sort:\n";
	for(i = 0; i < n; i++)
		cout << arreglo[i] << " ";
	cout << endl;
	
	return 0;
}
