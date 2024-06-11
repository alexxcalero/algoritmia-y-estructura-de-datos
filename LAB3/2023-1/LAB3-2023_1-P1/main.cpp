/*
 * Proyecto : LAB3-2023_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 22 de mayo de 2024, 12:23
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 5
#define M 6
using namespace std;

void cargarMatrices(int registros[N][M], int instrucciones[N][M], int &n, int &m) {
	ifstream arch("datos.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	arch >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			arch >> registros[i][j];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			arch >> instrucciones[i][j];
}

void mostrarMatriz(int matriz[N][M], int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << setw(4) << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void mostrarArreglo(int arr[], int n) {
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void pasarMatrizToArreglo(int arr[], int matriz[N][M], int n, int m) {
	int ind = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			arr[ind] = matriz[i][j];
			ind++;
		}
	}
}

void pasarArregloToMatriz( int matriz[N][M], int arr[], int n, int m) {
	int ind = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			matriz[i][j] = arr[ind];
			ind++;
		}
	}
}

void merge(int arrReg[], int arrInst[], int ini, int medio, int fin) {
	int auxReg[N*M]{};
	int auxInst[N*M]{};
	int p, q, m;
	for(p = ini, q = medio + 1, m = ini; p <= medio && q <= fin; m++) {
		if(arrReg[p] < arrReg[q]) {
			auxReg[m] = arrReg[p];
			auxInst[m] = arrInst[p];
			p++;
		} else {
			auxReg[m] = arrReg[q];
			auxInst[m] = arrInst[q];
			q++;
		}
	}

	while(p <= medio) {
		auxReg[m] = arrReg[p];
		auxInst[m] = arrInst[p];
		p++;
		m++;
	}

	while(q <= fin) {
		auxReg[m] = arrReg[q];
		auxInst[m] = arrInst[q];
		q++;
		m++;
	}

	for(int i = ini; i <= fin; i++) {
		arrReg[i] = auxReg[i];
		arrInst[i] = auxInst[i];
	}
}

void mergeSort(int arrReg[], int arrInst[], int ini, int fin) {
	if(ini == fin)
		return;

	int medio = (ini + fin) / 2;
	mergeSort(arrReg, arrInst, ini, medio);
	mergeSort(arrReg, arrInst, medio + 1, fin);
	merge(arrReg, arrInst, ini, medio, fin);
}

// No es necesario haber ordenado la matriz previamente
int calcularInstrucciones(int registros[N][M], int instrucciones[N][M], int reg, int filaIni, int filaFin, int colIni, int colFin) {
	if(filaIni > filaFin || colIni > colFin)
		return 0;

	if(filaIni == filaFin && colIni == colFin)
		if(registros[filaIni][colIni] == reg)
			return instrucciones[filaIni][colIni];
		else
			return 0;

	int filMed = (filaIni + filaFin) / 2;
	int colMed = (colIni + colFin) / 2;

	int matriz1, matriz2, matriz3, matriz4;
	matriz1 = matriz2 = matriz3 = matriz4 = 0;

	matriz1 = calcularInstrucciones(registros, instrucciones, reg, filaIni, filMed, colIni, colMed);

	matriz2 = calcularInstrucciones(registros, instrucciones, reg, filaIni, filMed, colMed + 1, colFin);

	matriz3 = calcularInstrucciones(registros, instrucciones, reg, filMed + 1, filaFin, colIni, colMed);

	matriz4 = calcularInstrucciones(registros, instrucciones, reg, filMed + 1, filaFin, colMed + 1, colFin);

	return matriz1 + matriz2 + matriz3 + matriz4;
}

// Metodo para cuando la matriz haya sido ordenada previamente
//int calcularInstrucciones(int registros[N][M], int instrucciones[N][M], int reg, int filaIni, int filaFin, int colIni, int colFin) {
//	if(filaIni > filaFin || colIni > colFin)
//		return 0;
//
//	if(filaIni == filaFin && colIni == colFin)
//		if(registros[filaIni][colIni] == reg)
//			return instrucciones[filaIni][colIni];
//		else
//			return 0;
//
//	int filMed = (filaIni + filaFin) / 2;
//	int colMed = (colIni + colFin) / 2;
//
//	int matriz1, matriz2, matriz3, matriz4;
//	matriz1 = matriz2 = matriz3 = matriz4 = 0;
//
//	if(reg >= registros[filaIni][colIni] && reg <= registros[filMed][colMed])
//		matriz1 = calcularInstrucciones(registros, instrucciones, reg, filaIni, filMed, colIni, colMed);
//
//	if(reg >= registros[filaIni][colMed + 1] && reg <= registros[filMed][colFin])
//		matriz2 = calcularInstrucciones(registros, instrucciones, reg, filaIni, filMed, colMed + 1, colFin);
//
//	if(reg >= registros[filMed + 1][colIni] && reg <= registros[filaFin][colMed])
//		matriz3 = calcularInstrucciones(registros, instrucciones, reg, filMed + 1, filaFin, colIni, colMed);
//
//	if(reg >= registros[filMed + 1][colMed + 1] && reg <= registros[filaFin][colFin])
//		matriz4 = calcularInstrucciones(registros, instrucciones, reg, filMed + 1, filaFin, colMed + 1, colFin);
//
//	return matriz1 + matriz2 + matriz3 + matriz4;
//}

int main(int argc, char** argv) {
	int registros[N][M], instrucciones[N][M];
	int n, m;

	cargarMatrices(registros, instrucciones, n, m);
//	mostrarMatriz(registros, n, m);
//	mostrarMatriz(instrucciones, n, m);

	// Descomentar esto para poder ordenar la matriz
//	int arrReg[n * m], arrInst[n * m];
//	pasarMatrizToArreglo(arrReg, registros, n, m);
//	pasarMatrizToArreglo(arrInst, instrucciones, n, m);

//	mostrarArreglo(arrReg, n * m);
//	mostrarArreglo(arrInst, n * m);
//	cout << endl;

	// Descomentar esto para poder ordenar la matriz
//	mergeSort(arrReg, arrInst, 0, n * m - 1);
//
//	mostrarArreglo(arrReg, n * m);
//	mostrarArreglo(arrInst, n * m);
//	cout << endl;

	// Descomentar esto para poder ordenar la matriz
//	pasarArregloToMatriz(registros, arrReg, n, m);
//	pasarArregloToMatriz(instrucciones, arrInst, n, m);
//
//	mostrarMatriz(registros, n, m);
//	mostrarMatriz(instrucciones, n, m);

	int reg = 1;
	int cantInstrucciones = calcularInstrucciones(registros, instrucciones, reg, 0, n - 1, 0, m - 1);

	cout << "Para el registro " << reg << ", se obtienen " << cantInstrucciones;
	cout << " coincidencias en total.\n";
	if(cantInstrucciones >= 10)
		cout << "Por lo que se considera que el archivo cuenta con codigo malicioso.\n";
	
	return 0;
}
