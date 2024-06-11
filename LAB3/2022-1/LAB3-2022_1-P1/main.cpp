/*
 * Proyecto : LAB3-2022_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 10 de mayo de 2024, 23:50
 */

#include <iostream>
#include <fstream>
#define N 10
using namespace std;

void cargarArreglo(ifstream &arch, int arr[], int n) {
	for(int i = 0; i < n; i++)
		arch >> arr[i];
}

void mostrarArreglo(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int hallarIntervaloCentro(int arr[], int ini, int med, int fin) {
	int cuenta = 1;

	for(int i = med; i > ini; i--) {
		if(arr[i] <= arr[i - 1])
			break;
		cuenta++;
	}

	for(int i = med; i < fin; i++) {
		if(arr[i] >= arr[i + 1])
			break;
		cuenta++;
	}

	return cuenta;
}

int hallarIntervaloMaximo(int arr[], int ini, int fin) {
	if(ini == fin)
		return 1;

	int med = (ini + fin) / 2;
	int IntervIzq = hallarIntervaloMaximo(arr, ini, med);
	int IntervDer = hallarIntervaloMaximo(arr, med + 1, fin);
	int IntervMed = hallarIntervaloCentro(arr, ini, med, fin);

	return max(IntervIzq, max(IntervMed, IntervDer));
}

int main(int argc, char** argv) {
	ifstream arch("datos.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	int n1, n2;
	arch >> n1 >> n2;

	int arr1[n1], arr2[n2];
	cargarArreglo(arch, arr1, n1);
	cargarArreglo(arch, arr2, n2);

//	mostrarArreglo(arr1, n1);
//	mostrarArreglo(arr2, n2);

	int maxIntervalo1 = hallarIntervaloMaximo(arr1, 0, n1 - 1);
	int maxIntervalo2 = hallarIntervaloMaximo(arr2, 0, n2 - 1);

	double porc1 = (double)maxIntervalo1 / n1;
	double porc2 = (double)maxIntervalo2 / n2;

	cout << "El intervalo maximo de incrementos de contagios es de " << maxIntervalo1;
	cout << " dias.\nLo que genera un indice de incrementos de " << porc1 << endl;

	cout << "\nEl intervalo maximo de incrementos de contagios es de " << maxIntervalo2;
	cout << " dias.\nLo que genera un indice de incrementos de " << porc2 << endl;
	
	return 0;
}
