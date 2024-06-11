/*
 * Proyecto : busqueda-binaria-dv
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 16:02
 */

#include <iostream>
using namespace std;

// PRECONDICION: El arreglo debe estar ordenado
int busquedaBinaria(int arr[], int ini, int fin, int buscado) {
	int medio = (ini + fin) / 2;
	if(arr[medio] == buscado)
		return medio;

	if(arr[medio] < buscado)
		busquedaBinaria(arr, medio + 1, fin, buscado);
	else
		busquedaBinaria(arr, ini, medio - 1, buscado);
}

int main(int argc, char** argv) {
	int arreglo[] = {1, 5, 7, 9, 12, 15, 17};
	int n = 7;
	int buscado = 15;
	int pos = busquedaBinaria(arreglo, 0, n - 1, buscado);
	if(pos != -1)
		cout << "El elemento " << buscado << " se encuentra en la posicion " << pos + 1 << endl;
	else
		cout << "No se encuentra en el arreglo el elemento " << buscado << endl;
	return 0;
}
