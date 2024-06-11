/*
 * Proyecto : LAB3-2022_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de mayo de 2024, 15:50
 */

#include <iostream>
#include <fstream>
using namespace std;

int hallarMenorPeso(int arr[], int ini, int fin) {
	if(ini == fin)
		return arr[ini];

	int medio = (ini + fin) / 2;
	int minIzq = hallarMenorPeso(arr, ini, medio);
	int minDer = hallarMenorPeso(arr, medio + 1, fin);

	return min(minIzq, minDer);
}

int hallarRangoMedio(int arr[], int menorPeso, int ini, int med, int fin) {
	// Si el medio es diferente del menor peso, ya no hace falta corroborar
	// si hay un intervalo igual del menor peso que justo pase por el medio
	if(arr[med] != menorPeso)
		return 0;

	int cuentaIzq, cuentaDer;
	cuentaIzq = cuentaDer = 0;

	// Para no perder el valor de medio, creo una variable auxiliar
	int auxMed = med;
	// Recorro para la izquierda hasta que el indice sea mayor o igual al inicio
	// o hasta que encuentre un valor diferente al menor peso
	while(auxMed >= ini) {
		if(arr[auxMed] != menorPeso)
			break;
		cuentaIzq++;
		auxMed--;
	}

	// Ahora seteo la posicion de la variable auxiliar en una posicion a la derecha
	// del indice del medio, ya que el medio ya fue evaluado en la parte de la izquierda
	auxMed = med + 1;
	while(auxMed <= fin) {
		if(arr[auxMed] != menorPeso)
			break;
		cuentaDer++;
		auxMed++;
	}

	// Finalmente retorno la cuenta obtenida tanto para la izquierda como para la derecha
	return cuentaIzq + cuentaDer;
}

int hallarRangoDias(int arr[], int menorPeso, int ini, int fin) {
	if(ini == fin)
		if(arr[ini] == menorPeso)
			return 1;
		else
			return 0;

	int medio = (ini + fin) / 2;

	int rangoIzq = hallarRangoDias(arr, menorPeso, ini, medio);
	int rangoDer = hallarRangoDias(arr, menorPeso, medio + 1, fin);
	int rangoMed = hallarRangoMedio(arr, menorPeso, ini, medio, fin);

	return max(rangoIzq, max(rangoDer, rangoMed));
}

int main(int argc, char** argv) {
	// PARTE A
	ifstream arch("datos.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}
	int n;
	arch >> n;
	int arr[n]{};
	for(int i = 0; i < n; i++)
		arch >> arr[i];

//	for(int i = 0; i < n; i++)
//		cout << arr[i] << " ";

	// PARTE B
	int menorPeso = hallarMenorPeso(arr, 0, n - 1);
	int cantDias = hallarRangoDias(arr, menorPeso, 0, n - 1);
	cout << "El menor peso fue de " << menorPeso;
	cout << ".\nEn un periodo de " << cantDias << " dias.\n";
	
	return 0;
}
