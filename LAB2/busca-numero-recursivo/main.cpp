/*
 * Proyecto : busca-numero-recursivo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 22:23
 */

#include <iostream>
using namespace std;

int buscarNumero(int *arr, int n, int buscado, int pos) {
	if(pos == n)
		return -1;

	if(arr[pos] == buscado)
		return pos;

	return buscarNumero(arr, n, buscado, pos + 1);
}

int main(int argc, char** argv) {
	int arr[] = {3, 5, 12, 52, 33, 86, 20};
	int n = 7, buscado = 86;
	int pos = buscarNumero(arr, n, buscado, 0);

	if(pos != -1)
		cout << "SI se encontro el elemento " << buscado << " en la posicion " << pos + 1 << endl;
	else
		cout << "NO se pudo encontrar el elemento " << buscado << " en el arreglo.\n";

	return 0;
}
