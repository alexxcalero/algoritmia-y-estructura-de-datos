/*
 * Proyecto : sube-baja-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 17:53
 */

#include <iostream>
using namespace std;

// PRECONDICION: El arreglo primero va de forma ascendente y luego de forma descendente
int buscarMaximo(int arr[], int ini, int fin) {
	int medio = (ini + fin) / 2;
	// Si el elemento del medio es mayor a los de sus costados, entonces es el maximo
	if(arr[medio] > arr[medio - 1] && arr[medio] > arr[medio + 1])
		return arr[medio];

	if(arr[medio] < arr[medio + 1])
		return buscarMaximo(arr, medio, fin);
	else
		return buscarMaximo(arr, ini, medio);
}

int main(int argc, char** argv) {
	int arreglo[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
	int n = 11;
	int maximo = buscarMaximo(arreglo, 0, n - 1);
	cout << "El maximo elemento del arreglo es " << maximo << endl;
	return 0;
}
