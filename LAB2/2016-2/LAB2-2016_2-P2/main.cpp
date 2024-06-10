/*
 * Proyecto : LAB2-2016_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 19:57
 */

#include <iostream>
#include <fstream>
#define MAXF 10
#define MAXC 10
using namespace std;

int calcularMaxPuntaje(int tablero[MAXF][MAXC], int maxX, int maxY, int x, int y) {
	if(x == maxX - 1 && y == maxY - 1)
		return tablero[x][y];

	int derecha = -9999, abajo = -9999;
	if(x < maxX - 1)
		abajo = calcularMaxPuntaje(tablero, maxX, maxY, x + 1, y);
	if(y < maxY - 1)
		derecha = calcularMaxPuntaje(tablero, maxX, maxY, x, y + 1);

	if(derecha > abajo)
		return tablero[x][y] + derecha;
	else
		return tablero[x][y] + abajo;
}

int main(int argc, char** argv) {
	ifstream arch("data.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	int n, m;
	arch >> n >> m;
	int tablero[MAXF][MAXC];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			arch >> tablero[i][j];

//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m; j++)
//			cout << tablero[i][j] << " ";
//		cout << endl;
//	}

	int maxPuntaje = calcularMaxPuntaje(tablero, n, m, 0, 0);
	cout << "El maximo puntaje posible es " << maxPuntaje << endl;

	return 0;
}
