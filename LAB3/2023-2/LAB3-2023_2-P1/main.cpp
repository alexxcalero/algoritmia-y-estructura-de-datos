/*
 * Proyecto : LAB3-2023_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 9 de mayo de 2024, 16:58
 */

#include <iostream>
#include <fstream>
#define N 10
#define M 10
using namespace std;

void leerDatos(int empresas[N][M], int &n) {
	ifstream arch("datos.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de datos.\n";
		exit(1);
	}

	arch >> n;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < M; j++)
			arch >> empresas[i][j];
}

void mostrarMatriz(int empresas[N][M], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < M; j++)
			cout << empresas[i][j] << " ";
		cout << endl;
	}
}

int hallarPico(int empresas[N][M], int fila, int ini, int fin) {
	if(ini == fin)
		return empresas[fila][ini];

	int med = (ini + fin) / 2;
	int picoIzq = hallarPico(empresas, fila, ini, med);
	int picoDer = hallarPico(empresas, fila, med + 1, fin);

	return max(picoIzq, picoDer);
}

int hallarCantPicosMedio(int empresas[N][M], int fila, int maximo, int ini, int med, int fin) {
	if(empresas[fila][med] != maximo)
		return 0;

	int cuentaIzq, cuentaDer;
	cuentaIzq = cuentaDer = 0;

	for(int i = med; i >= ini; i--) {
		if(empresas[fila][i] != maximo)
			break;
		cuentaIzq++;
	}

//	int auxMed = med;
//	while(auxMed >= ini) {
//		if(empresas[fila][auxMed] != maximo)
//			break;
//		cuentaIzq++;
//		auxMed--;
//	}

	for(int i = med + 1; i <= fin; i++) {
		if(empresas[fila][i] != maximo)
			break;
		cuentaDer++;
	}

//	auxMed = med + 1;
//	while(auxMed <= fin) {
//		if(empresas[fila][auxMed] != maximo)
//			break;
//		cuentaDer++;
//		auxMed++;
//	}

	return cuentaIzq + cuentaDer;

}

int hallarCantPicos(int empresas[N][M], int fila, int maximo, int ini, int fin) {
	if(ini == fin)
		if(empresas[fila][ini] == maximo)
			return 1;
		else
			return 0;

	int med = (ini + fin) / 2;
	int picosIzq = hallarCantPicos(empresas, fila, maximo, ini, med);
	int picosDer = hallarCantPicos(empresas, fila, maximo, med + 1, fin);
	int picosMed = hallarCantPicosMedio(empresas, fila, maximo, ini, med, fin);

	return max(picosIzq, max(picosDer, picosMed));
}

int main(int argc, char** argv) {
	// PARTE A
	int empresas[N][M]{};
	int n;
	leerDatos(empresas, n);
//	mostrarMatriz(empresas, n);

	// PARTE B
	int picos[n];
	for(int i = 0; i < n; i++)
		picos[i] = hallarPico(empresas, i, 0, M - 1);

//	for(int i = 0; i < n; i++)
//		cout << picos[i] << " ";

	// PARTE C
	int minCantPicos = 99999;
	int empresaElegida;
	for(int i = 0; i < n; i++) {
		int cantPicos = hallarCantPicos(empresas, i, picos[i], 0, M - 1);
		if(cantPicos < minCantPicos) {
			minCantPicos = cantPicos;
			empresaElegida = i + 1;
		}
	}

	cout << "El maestro Splinter debe comprar en la Empresa " << empresaElegida;
	cout << " que tiene la menor cantidad de picos de produccion con " << minCantPicos << " horas\n";
	
	return 0;
}
