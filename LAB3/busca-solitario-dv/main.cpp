/*
 * Proyecto : busca-solitario-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 16:21
 */

#include <iostream>
using namespace std;

int buscarSolitario(int arr[], int ini, int fin) {
	if(ini == fin)  // Cuando solo hay un elemento en el arreglo
		return arr[ini];

	int medio = (ini + fin) / 2;
	// Si justo el solitario esta en el medio del arreglo
	if(arr[medio] != arr[medio - 1] && arr[medio] != arr[medio + 1])
		return arr[medio];

	if(medio % 2 == 0) {  // Cuando el indice del medio es par
		if(arr[medio] == arr[medio + 1])
			buscarSolitario(arr, medio + 2, fin);
		else
			buscarSolitario(arr, ini, medio - 1);
	} else {  // Cuando el indice del medio es impar
		if(arr[medio] == arr[medio - 1])
			buscarSolitario(arr, medio + 1, fin);
		else
			buscarSolitario(arr, ini, medio - 1);
	}
}

int main(int argc, char** argv) {
	int arreglo[] = {1, 1, 2, 2, 3, 3, 4, 8, 8};
	int n = 9;
	int solitario = buscarSolitario(arreglo, 0, n - 1);
	cout << "El elemento solitario del arreglo es " << solitario << endl;
	return 0;
}
