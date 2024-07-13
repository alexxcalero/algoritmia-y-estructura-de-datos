/*
 * Proyecto : LAB5-2024_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de junio de 2024, 08:07
 */

#include <iostream>
#define N 5
#define M 7
using namespace std;

// Simula a la funcion merge()
void ordenar(char fila[], int ini, int med, int fin) {
	int p, q, m;
	char aux[M]{};  // Creo el arreglo auxiliar donde guardare las letras en orden
	for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
		// La letra de la parte izquierda es menor que la de la parte derecha
		if(fila[p] < fila[q]) {
			aux[m] = fila[p];
			p++;
		} else {  // Caso contrario
			aux[m] = fila[q];
			q++;
		}
	}

	// Sigue habiendo elementos en la parte izquierda sin pasar
	while(p <= med) {
		aux[m] = fila[p];
		p++;
		m++;
	}

	// Sigue habiendo elementos en la parte derecha sin pasar
	while(q <= fin) {
		aux[m] = fila[q];
		q++;
		m++;
	}

	// Copio los elementos en orden del arreglo auxiliar al arreglo original
	for(int i = ini; i <= fin; i++) {
		fila[i] = aux[i];
	}
}

// Simula a la funcion mergeSort()
void ordenarUnaFila(char fila[], int ini, int fin) {
	if(ini == fin)
		return;

	int med = (ini + fin) / 2;
	ordenarUnaFila(fila, ini, med);
	ordenarUnaFila(fila, med + 1, fin);
	ordenar(fila, ini, med, fin);
}

void ordenarFilas(char matriz[N][M], int n, int m) {
	for(int i = 0; i < n; i++)
		ordenarUnaFila(matriz[i], 0, m - 1);  // INCISO A

	cout << "Matriz ordenada:\n";
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

char buscarPlatoDiferente(char fila[], int ini, int fin) {
	// Si ini y fin son iguales, he hallado la letra diferente
	if(ini == fin) {
		cout << fila[ini];
		return fila[ini];
	}

	int med = (ini + fin) / 2;
	if(med % 2 == 0) {  // El indice medio es par
		if(fila[med] == fila[med + 1])
			buscarPlatoDiferente(fila, med, fin);
		else
			buscarPlatoDiferente(fila, ini, med);
	} else {  // El indice medio es impar
		if(fila[med] == fila[med + 1])
			buscarPlatoDiferente(fila, ini, med - 1);
		else
			buscarPlatoDiferente(fila, med + 1, fin);
	}
}

void buscarLasagna(char matriz[N][M], int n, int m) {
	int fila;
	cout << "Plato diferente por fila:\n";
	for(int i = 0; i < n; i++) {
		cout << " - El plato diferente de la fila " << i + 1 << " es: ";
		char plato = buscarPlatoDiferente(matriz[i], 0, m - 1);  // INCISO C
		cout << endl;
		if(plato == 'L')
			fila = i;
	}
	cout << "\nLa lasagna esta ubicada en la fila " << fila + 1 << endl;
}

int main(int argc, char** argv) {
	int n = 5, m = 7;
	char matriz[N][M] = {
		{'C', 'O', 'C', 'V', 'O', 'V', 'J'},
		{'F', 'J', 'A', 'F', 'A', 'J', 'Y'},
		{'W', 'G', 'L', 'W', 'G', 'S', 'S'},
		{'S', 'I', 'S', 'M', 'M', 'I', 'Q'},
		{'O', 'B', 'B', 'O', 'F', 'X', 'F'}
	};
	ordenarFilas(matriz, n, m);   // INCISO B
	buscarLasagna(matriz, n, m);  // INCISO D
	return 0;
}
