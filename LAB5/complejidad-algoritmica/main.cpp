/*
 * Proyecto : complejidad-algoritmica
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de julio de 2024, 20:18
 */

#include <iostream>
#include <iomanip>
using namespace std;

void complejidadN() {
	cout << "Complejidad O(n):\n";
	cout << " - Al recorrer un arreglo: ";
	int n = 5;
	int arr[n];
	for(int i = 0; i < n; i++)
		arr[i] = i + 1;
	// Si se ponen dos for loops por separados,
	// la complejidad sigue siendo O(n)
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}

void complejidadN2() {
	cout << "\n\nComplejidad O(n^2):\n";
	cout << " - Al recorrer una matriz:\n";
	int n = 5;
	int arr[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = (i + 1) * ((j + 1) * 2);
	// Si se ponen dos for loops por separados,
	// la complejidad sigue siendo O(n)
	for(int i = 0; i < n; i++) {
		cout << "    ";
		for(int j = 0; j < n; j++) {
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
}

// En esta funcion, se cuenta la cantidad de ceros en el arreglo, yendonos
// para la izquierda o para la derecha en el arreglo dependiendo de la condicional
int contarCeros(int arr[], int ini, int fin) {
	if(ini > fin)
		return 0;

	int medio = (ini + fin) / 2;
	if(arr[medio] == 0)
		return (fin - medio + 1) + contarCeros(arr, ini, medio - 1);  // Me voy para la izquierda
	else
		return contarCeros(arr, medio + 1, fin);  // O me voy para la derecha
}

void complejidadLogN() {
	cout << "\nComplejidad O(log(n)):\n";
	cout << " - Al aplicar divide y venceras (sabiendo para que mitad irte):\n";
	int n = 7;
	int arr[n] = {1, 1, 1, 0, 0, 0, 0};
	cout << "    - Arreglo: ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	int cantCeros = contarCeros(arr, 0, n - 1);
	cout << "\n    - La cantidad de ceros en el arreglo es " << cantCeros << endl;
}

// En esta funcion, se busca al mayor elemento de manera recursiva, yendonos
// tanto para la izquierda como para la derecha en el arreglo
int buscarMayor(int arr[], int ini, int fin) {
	if(ini == fin)  // Si ini y fin son iguales, solo hay un elemento
		return arr[ini];

	int medio = (ini + fin) / 2;
	int mayorIzq = buscarMayor(arr, ini, medio);      // Me voy para la izquierda
	int mayorDer = buscarMayor(arr, medio + 1, fin);  // Me voy para la derecha

	return max(mayorIzq, mayorDer);
}

void complejidadNLogN() {
	cout << "\nComplejidad O(nlog(n)):\n";
	cout << " - Al aplicar divide y venceras (yendonos para ambos lados):\n";
	int n = 6;
	int arr[n] = {12, 24, 15, 17, 11, 10};
	cout << "    - Arreglo: ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	int mayor = buscarMayor(arr, 0, n - 1);
	cout << "\n    - El mayor elemento del arreglo es " << mayor << endl;
}

int main(int argc, char** argv) {
	complejidadN();
	complejidadN2();
	complejidadLogN();
	complejidadNLogN();
	return 0;
}
