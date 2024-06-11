/*
 * Proyecto : LAB3-2023_2-P2-B
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 7 de mayo de 2024, 20:34
 */

#include <iostream>
#define MAXF 15
#define MAXC 15
using namespace std;

int hallarPrecioMaximo(int matriz[MAXF][MAXC], int fila, int ini, int fin) {
	int med = (ini + fin) / 2;
	if(matriz[fila][med] > matriz[fila][med + 1] && matriz[fila][med] > matriz[fila][med - 1])
		return med + 1;

	if(matriz[fila][med] < matriz[fila][med + 1])
		return hallarPrecioMaximo(matriz, fila, med, fin);
	else
		return hallarPrecioMaximo(matriz, fila, ini, med);
}

int main(int argc, char** argv) {
	int matriz[MAXF][MAXC] = {{1,2,3,2,1},
							  {2,3,2,2,1},
							  {1,2,2,5,3},
							  {2,5,3,3,1},
							  {2,2,3,2,1},
							  {1,2,3,2,1},
							  {3,5,2,1,1},
							  {2,3,2,1,1}};
	int m = 8;
	int n = 5;
	for(int i = 0; i < m; i++) {
		cout << "En la fila " << i + 1 << ", el pasajero del asiento ";
		cout << hallarPrecioMaximo(matriz, i, 0, n - 1);
		cout << " tiene el bocadito mas caro que sus 2 vecinos\n";
	}
	return 0;
}
