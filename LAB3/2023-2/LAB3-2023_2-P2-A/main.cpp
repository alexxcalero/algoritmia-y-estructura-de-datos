/*
 * Proyecto : LAB3-2023_2-P2-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 19:35
 */

#include <iostream>
#define MAXF 15
#define MAXC 15
using namespace std;

void hallarBocaditoExtra(char matriz[MAXF][MAXC], int fila, int ini, int fin) {
	int med = (ini + fin) / 2;
	if(ini + 2 == fin)  // Si solo quedan tres bocaditos
		// Verifico si los tres bocaditos son iguales
		if(matriz[fila][ini] == matriz[fila][med] && matriz[fila][med] == matriz[fila][fin]) {
			cout << "La fila " << fila + 1 << " tiene un " << matriz[fila][med] << " adicional.\n";
			return;
		}
		else
			return;

	// Caso en el que los tres bocaditos esten en el centro de la fila
	if(matriz[fila][med] == matriz[fila][med + 1] && matriz[fila][med] == matriz[fila][med - 1]) {
		cout << "La fila " << fila + 1 << " tiene un " << matriz[fila][med] << " adicional.\n";
		return;
	}

	if(med % 2 == 0) {  // Cuando el indice del medio es par
		if(matriz[fila][med] == matriz[fila][med + 1])
			hallarBocaditoExtra(matriz, fila, med, fin);
		else
			hallarBocaditoExtra(matriz, fila, ini, med);
	} else {  // Cuando el indice del medio es impar
		if(matriz[fila][med] == matriz[fila][med - 1])
			hallarBocaditoExtra(matriz, fila, med + 1, fin);
		else
			hallarBocaditoExtra(matriz, fila, ini, med - 1);
	}

}

int main(int argc, char** argv) {
	char matriz[MAXF][MAXC] = {{'O','O','C','C','A','A','E','E','R','R','R'},
							   {'C','C','A','A','R','R','E','E','B','B'},
							   {'R','R','E','E','C','C','F','F','A','A'},
							   {'E','E','F','F','A','A','A','B','B','R','R'},
							   {'C','C','C','A','A','R','R','O','O','E','E'},
							   {'O','O','C','C','A','A','R','R','E','E'},
							   {'A','A','F','F','R','R','E','E','O','O'},
							   {'E','E','A','A','O','O','B','B','F','F'}};
	int m = 8;
	int n = 11;
	for(int i = 0; i < m; i++) hallarBocaditoExtra(matriz, i, 0, n - 1);
	return 0;
}
