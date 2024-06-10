/*
 * Proyecto : busca-mayor-recursivo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 22:00
 */

#include <iostream>
using namespace std;

int buscarMayor(int *arr, int n, int mayor, int pos) {
	if(pos == n)
		return mayor;

	if(arr[pos] > mayor)
		mayor = arr[pos];

	return buscarMayor(arr, n, mayor, pos + 1);
}

int main(int argc, char** argv) {
	int arr[] = {3, 5, 12, 52, 33, 86, 20};
	int n = 7;
	int mayor = buscarMayor(arr, n, arr[0], 1);
	cout << "El mayor elemento del arreglo es " << mayor << endl;
	return 0;
}
