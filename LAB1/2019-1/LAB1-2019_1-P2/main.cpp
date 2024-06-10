/*
 * Proyecto : LAB1-2019_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 3 de abril de 2024, 23:05
 */

#include <iostream>
#define MAX_FIL 5
#define MAX_COL 5
using namespace std;

int mov[4][2];
int solMov[1][2];

void movimientos() {
	mov[0][0] = 0; mov[0][1] = -1;
	mov[1][0] = -1; mov[1][1] = 0;
	mov[2][0] = 0; mov[2][1] = 1;
	mov[3][0] = 1; mov[3][1] = 0;
}

void imprimirDireccion() {
	if(solMov[0][1] == 0 && solMov[0][2] == -1)
		cout << "izquierda\n";

	if(solMov[0][1] == -1 && solMov[0][2] == 0)
		cout << "arriba\n";

	if(solMov[0][1] == 0 && solMov[0][2] == 1)
		cout << "derecha\n";

	if(solMov[0][1] == 1 && solMov[0][2] == 0)
		cout << "abajo\n";
}

bool buscarPalabra(char tablero[MAX_FIL][MAX_COL], char palabra[], int n, int i, int j) {
	// Si la letra en la posicion del tablero en la que estoy no es igual a la primera
	// letra de la palabra buscada, ya no es necesario seguir buscando.
	// Simplemente, retorno falso
	if(tablero[i][j] != palabra[0])
		return false;

	int nuevoI, nuevoJ;
	for(int k = 0; k < 4; k++) {  // For para iterar en todo el arreglo de movimientos
		nuevoI = i + mov[k][0];  // Me muevo a la siguiente posicion en X
		nuevoJ = j + mov[k][1];  // Me muevo a la siguiente posicion en Y
		int p;
		for(p = 1; p < n; p++) {
			// Si me salgo de los rangos del tablero, dejo de evaluar
			if(nuevoI < 0 || nuevoI >= MAX_FIL || nuevoJ < 0 || nuevoJ >= MAX_COL)
				break;
			// Si la letra en la posicion actual del tablero es diferente a la letra
			// de la palabra evaluada, dejo de evaluar
			if(tablero[nuevoI][nuevoJ] != palabra[p])
				break;
			// Si no entre a ninguno de los ifs anteriores,
			// significa que he encontrado una letra de la palabra.
			// Por lo tanto, me vuelvo a mover en la misma direccion.
			nuevoI += mov[k][0];  // Me muevo a la siguiente posicion en X
			nuevoJ += mov[k][1];  // Me muevo a la siguiente posicion en Y
		}
		// Si al momento de salir del for, el valor de p es igual a n
		// significa que he encontrado la palabra buscado en el pupiletras.
		// Por lo tanto, retorno verdadero
		if(p == n) {
			solMov[0][1] = mov[k][0];
			solMov[0][2] = mov[k][1];
			return true;
		}
	}
	// Si llego a este punto del algoritmo, significa que no encontre
	// la palabra buscada y retorno falso
	return false;
}

void pupiletras(char tablero[MAX_FIL][MAX_COL], char palabra[], int n) {
	for(int i = 0; i < MAX_FIL; i++) {  // Itero en todas las filas
		for(int j = 0; j < MAX_COL; j++) {  // Itero en todas las columnas
			if(buscarPalabra(tablero, palabra, n, i, j)) {
				cout << "Se encontro la palabra en (" << i + 1 << "," << j + 1 << ") - ";
				imprimirDireccion();
			}
		}
	}
}

int main(int argc, char** argv) {
	char tablero[MAX_FIL][MAX_COL] = {{'H','G','A','F','Y'},
									  {'D','Q','G','Z','R'},
									  {'A','M','E','N','H'},
									  {'O','G','O','R','F'},
									  {'T','R','W','I','P'}};
	char palabra[] = {'F','R','O','G'};
	int n = 4;
	movimientos();  // Cargo con valores el arreglo global de movimientos
	pupiletras(tablero, palabra, n);  // Empieza el algoritmo de fuerza bruta
	return 0;
}
