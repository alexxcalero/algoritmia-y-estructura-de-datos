/*
 * Proyecto : busca-mayor-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 15:56
 */

#include <iostream>
using namespace std;

int buscarMayor(int arr[], int ini, int fin) {
	if(ini == fin)  // Si ini y fin son iguales, solo hay un elemento
		return arr[ini];

	int medio = (ini + fin) / 2;
	int mayorIzq = buscarMayor(arr, ini, medio);
	int mayorDer = buscarMayor(arr, medio + 1, fin);

	return max(mayorIzq, mayorDer);
}

int main(int argc, char** argv) {
	int arreglo[] = {12, 24, 15, 17, 11, 10};
	int n = 6;
	int mayor = buscarMayor(arreglo, 0, n - 1);
	cout << "El mayor elemento del arreglo es " << mayor << endl;
	return 0;
}
