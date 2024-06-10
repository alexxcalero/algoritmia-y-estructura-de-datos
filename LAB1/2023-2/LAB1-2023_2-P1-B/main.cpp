/*
 * Proyecto : LAB1-2023_2-P1-B
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de marzo de 2024, 21:53
 */

#include <iostream>
#define MAX_FIL 4
#define MAX_COL 10
using namespace std;

int mov[4][2];

void movimientos() {
	mov[0][0] = 0;  mov[0][1] = -1;
	mov[1][0] = 0;  mov[1][1] = 1;
	mov[2][0] = -1; mov[2][1] = 0;
	mov[3][0] = 1;  mov[3][1] = 0;
}

bool buscarPalabra(char tablero[MAX_FIL][MAX_COL], int sol[], char palabra[], int n, int i, int j) {
	bool encontroLetra = false;
	int indicePrimeraLetra;
	for(int l = 0; l < n; l++) sol[l] = 0;
	for(int l = 0; l < n; l++) {
		if(tablero[i][j] == palabra[l] && sol[l] == 0) {
			sol[l] = 1;
			indicePrimeraLetra = l;  // Guardo el indice de la primera letra donde empiezo a probar caminos
			encontroLetra = true;
			break;
		}
	}

	if(!encontroLetra)
		return false;

	int nuevoI, nuevoJ, p;
	int sum;
	for(int k = 0; k < 4; k++) {
		sum = 0;
		// Inicializo en cero todo el arreglo de solucion, excepto en el indice de la primera letra
		// verificada lineas mas arriba, ya que aqui empezamos con un nuevo camino
		for(int l = 0; l < n; l++) {
			if(l == indicePrimeraLetra)
				continue;
			sol[l] = 0;
		}
		nuevoI = i + mov[k][0];
		nuevoJ = j + mov[k][1];
		while(1) {
			encontroLetra = false;
			if(nuevoI < 0 || nuevoJ < 0 || nuevoI >= MAX_FIL || nuevoJ >= MAX_COL)
				break;
			for(int l = 0; l < n; l++) {
				if(tablero[nuevoI][nuevoJ] == palabra[l] && sol[l] == 0) {
					sol[l] = 1;
					encontroLetra = true;
					break;
				}
			}
			if(!encontroLetra)
				break;
			nuevoI += mov[k][0];
			nuevoJ += mov[k][1];
		}
		for(int l = 0; l < n; l++)
			if(sol[l] == 1)
				sum++;
		if(sum == n)
			return true;
	}
	return false;
}

void pupiletras(char tablero[MAX_FIL][MAX_COL], int sol[], char palabra[], int n) {
	cout << "Se encontro el Acido Sulfurico en las siguientes posiciones:\n";
	for(int i = 0; i < MAX_FIL; i++)
		for(int j = 0; j < MAX_COL; j++)
			if(buscarPalabra(tablero, sol, palabra, n, i, j))
				cout << "(" << i << "," << j << ") ";
}

int main(int argc, char** argv) {
	char tablero[MAX_FIL][MAX_COL] = {{'H','C','H','B','Y','S','O','S','O','H'},
									  {'S','C','S','S','Y','Q','O','S','Z','K'},
									  {'O','P','N','Y','O','K','F','H','C','K'},
									  {'O','B','N','I','Y','S','P','O','O','K'}};
	char palabra[] = {'H','S','O'};
	int n = 3;
	int sol[n];
	movimientos();
	pupiletras(tablero, sol, palabra, n);
	return 0;
}
