/*
 * Proyecto : LAB2-2020_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 21:37
 */

#include <iostream>
#define MAXF 10
#define MAXC 10
using namespace std;

int buscarVertical(int tablero[MAXF][MAXC], int maxX, int x, int y) {
	if(x == maxX - 1)
		return tablero[x][y];
	return tablero[x][y] + buscarVertical(tablero, maxX, x + 1, y);
}

int buscarHorizontal(int tablero[MAXF][MAXC], int maxY, int x, int y) {
	if(y == maxY - 1)
		return tablero[x][y];
	return tablero[x][y] + buscarHorizontal(tablero, maxY, x, y + 1);
}

int calcularUnos(int tablero[MAXF][MAXC], int maxX, int maxY, int movX, int movY, int x, int y) {
	if(x == maxX || y == maxY || x < 0 || y < 0) {
		if(movX == 0) {
			return buscarHorizontal(tablero, maxY, x, 0);
		} else {
			return buscarVertical(tablero, maxX, 0, y);
		}
	} else {
		int minas;
		if(movX == 0) {
			minas = buscarVertical(tablero, maxX, 0, y);
		} else {
			minas = buscarHorizontal(tablero, maxY, x, 0);
		}
		minas = minas - tablero[x][y];
		return minas + calcularUnos(tablero, maxX, maxY, movX, movY, x + movX, y + movY);
	}
}

void verificarMovimiento(char mov, int &movX, int &movY) {
	if(mov == 'D') {         // Derecha
		movX = 0;
		movY = 1;
	} else if(mov == 'I') {  // Izquierda
		movX = 0;
		movY = -1;
	} else if(mov == 'A') {  // Arriba
		movX = -1;
		movY = 0;
	} else if(mov == 'U') {  // Abajo
		movX = 1;
		movY = 0;
	}
}

int main(int argc, char** argv) {
	int n = 6, m = 6;
	int xIni = 3, yIni = 2;
	char mov = 'A';
	int movX, movY;
	verificarMovimiento(mov, movX, movY);
	int tablero[MAXF][MAXC] = {{0,0,0,1,0,1},
							   {0,0,1,0,0,0},
							   {0,1,0,0,0,1},
							   {1,0,0,0,0,0},
							   {0,1,0,0,0,0},
							   {0,0,0,0,1,0}};
	int unos = calcularUnos(tablero, n, m, movX, movY, xIni, yIni);
	cout << "La cantidad de unos encontrados durante la busqueda es " << unos << endl;
	return 0;
}
