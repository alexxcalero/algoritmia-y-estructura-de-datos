/*
 * Proyecto : cuenta-ceros-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 16:40
 */

#include <iostream>
using namespace std;

int contarCeros(int arr[], int ini, int fin) {
	if(ini > fin)
		return 0;

	int medio = (ini + fin) / 2;
	if(arr[medio] == 0)
		return (fin - medio + 1) + contarCeros(arr, ini, medio - 1);
	else
		return contarCeros(arr, medio + 1, fin);
}

int main(int argc, char** argv) {
	int arreglo[] = {1, 1, 1, 0, 0, 0, 0};
	int n = 7;
	int cantCeros = contarCeros(arreglo, 0, n - 1);
	cout << "La cantidad de ceros en el arreglo es " << cantCeros << endl;
	return 0;
}
