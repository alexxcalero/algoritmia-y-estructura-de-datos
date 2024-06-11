/*
 * Proyecto : LAB3-2022_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 8 de mayo de 2024, 22:27
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 15
#define M 15
using namespace std;

void cargarMatrices(int matriz[N][M], int &n, int &m) {
	ifstream arch("datos.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	arch >> n >> m;

	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			arch >> matriz[i][j];
}

void mostrarMatrices(int matriz[N][M], int n, int m) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cout << setw(2) << matriz[i][j] << " ";
		}
		cout << endl;
	}
}

int obtenerFilaConPotenciaMaxima(int matriz[N][M], int col, int ini, int fin) {
	int medio = (ini + fin) / 2;
	if(matriz[medio][col] > matriz[medio - 1][col] && matriz[medio][col] > matriz[medio + 1][col])
		return medio;

	if(matriz[medio][col] >= matriz[medio - 1][col])
		obtenerFilaConPotenciaMaxima(matriz, col, medio, fin);
	else
		obtenerFilaConPotenciaMaxima(matriz, col, ini, medio);
}

// Se hace un DV a toda la matriz sin necesidad de ordenarla
// Esta funcion va dividiendo la matriz en cuadrantes
// Solo faltaria poder obtener la columna donde se ubica la potencia maxima
int hallarPotenciaMaxima(int matriz[N][M], int &col, int filIni, int filFin, int colIni, int colFin) {
	if(filIni > filFin || colIni > colFin)
		return 0;

	if(filIni == filFin && colIni == colFin)
		return matriz[filIni][colIni];

	int filMed = (filIni + filFin) / 2;
	int colMed = (colIni + colFin) / 2;

	int submatriz1 = hallarPotenciaMaxima(matriz, col, filIni, filMed, colIni, colMed);
	int submatriz2 = hallarPotenciaMaxima(matriz, col, filIni, filMed, colMed + 1, colFin);
	int submatriz3 = hallarPotenciaMaxima(matriz, col, filMed + 1, filFin, colIni, colMed);
	int submatriz4 = hallarPotenciaMaxima(matriz, col, filMed + 1, filFin, colMed + 1, colFin);

	return max(submatriz1, max(submatriz2, max(submatriz3, submatriz4)));
}

int main(int argc, char** argv) {
	int n, m;
	int matriz[N][M]{};

	cargarMatrices(matriz, n, m);
//	mostrarMatrices(matriz, n, m);

	// PARTE A
	// Faltaria hallar la columna donde se ubica la potencia maxima
	int potenciaMax, columna = 2;
	potenciaMax = hallarPotenciaMaxima(matriz, columna, 0, m - 1, 0, n - 1);

	// PARTE B
	int fila = obtenerFilaConPotenciaMaxima(matriz, columna, 0, m - 1);

	cout << "Para este juego de datos la potencia mas alta de bomba es " << potenciaMax;
	cout << ", y la columna donde se ubica es " << columna << ".\nLa fila con mayor ";
	cout << "impacto es la " << fila << endl;

	return 0;
}
