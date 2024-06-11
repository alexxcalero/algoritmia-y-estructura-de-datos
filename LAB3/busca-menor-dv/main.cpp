/*
 * Proyecto : busca-menor-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 16:01
 */

#include <iostream>
using namespace std;

int buscarMenor(int arr[], int ini, int fin) {
	if(ini == fin)  // Si ini y fin son iguales, solo hay un elemento
		return arr[ini];

	int medio = (ini + fin) / 2;
	int menorIzq = buscarMenor(arr, ini, medio);
	int menorDer = buscarMenor(arr, medio + 1, fin);

	return min(menorIzq, menorDer);
}

int main(int argc, char** argv) {
	int arreglo[] = {12, 24, 15, 17, 11, 10};
	int n = 6;
	int menor = buscarMenor(arreglo, 0, n - 1);
	cout << "El menor elemento del arreglo es " << menor << endl;
	return 0;
}
