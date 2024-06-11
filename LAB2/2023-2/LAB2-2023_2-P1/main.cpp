/*
 * Proyecto : LAB2-2023_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 4 de junio de 2024, 10:58
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#define N 10
using namespace std;

void lecturaDeDatos(int poder[N], int movimiento[N][2], int ciudad[N][N], int n) {
    ifstream arch("data.txt", ios::in);
    if(!arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo de datos.\n";
        exit(1);
    }

	// Leo los poderes de cada torturga
    for(int i = 0; i < n; i++)
        arch >> poder[i];

	// Leo la direccion en la que se mueve cada tortuga
    char c;
    for(int i = 0; i < n; i++) {
        arch >> c;
        // Si es D, asigno 0 1, ya que en X no va a variar y en Y va a variar
        if(c == 'D') {
            movimiento[i][0] = 0;
            movimiento[i][1] = 1;
        } else {  // Caso contrario cuando leo A
            movimiento[i][0] = 1;
            movimiento[i][1] = 0;
        }
    }

	// Leo los valores de cada posicion en la matriz de la ciudad
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            arch >> ciudad[i][j];
        }
    }
}

bool logranVencer(int poder[N], int movimiento[N][2], int ciudad[N][N], int n, int tortuga, int x, int y) {
    // Se logro vencer a SuperFly
	if(ciudad[x][y] == 50 && poder[tortuga] >= ciudad[x][y])
        return true;

	// No quedan mas tortugas que puedan pelear
    if(tortuga == n - 1 && poder[tortuga] < ciudad[x][y])
        return false;

	// Si el valor de la ciudad en la posicion actual es cero, simplemente avanzo a la siguiente posicion
    if(ciudad[x][y] == 0)
        return logranVencer(poder, movimiento, ciudad, n, tortuga, x + movimiento[tortuga][0], y + movimiento[tortuga][1]);
    else {  // El valor en la posicion actual de la ciudad es diferente a cero
        // El poder de la tortuga actual es mayor que el valor en la posicion actual de la ciudad
		if(poder[tortuga] >= ciudad[x][y]) {
            poder[tortuga] -= ciudad[x][y];  // Disminuyo el poder de la tortuga
            ciudad[x][y] = 0;  // Actualizo el valor del mapa con cero en esa posicion
            return logranVencer(poder, movimiento, ciudad, n, tortuga, x + movimiento[tortuga][0], y + movimiento[tortuga][1]);
        } else {  // El poder de la tortuga es menor que el valor en la posicion actual de la ciudad
            x -= movimiento[tortuga][0];
            y -= movimiento[tortuga][1];
            return logranVencer(poder, movimiento, ciudad, n, tortuga + 1, x, y);
        }
    }
}

int main(int argc, char** argv) {
	// INCISO A
    // No leo este dato, ya que siempre van a ser 4 tortugas
    int n = 4;
    int poder[N];
    // Matriz movimiento con dos columnas que representan x e y
    int movimiento[N][2];
    int ciudad[N][N];
    lecturaDeDatos(poder, movimiento, ciudad, n);

//    for(int i = 0; i < n; i++)
//        cout << poder[i] << " ";
//    cout << endl;
//    for(int i = 0; i < n; i++)
//        cout << movimiento[i][0] << " " << movimiento[i][1] << endl;
//    for(int i = 0; i < N; i++) {
//        for(int j = 0; j < N; j++) {
//            cout << setw(2) << ciudad[i][j] << " ";
//        }
//        cout << endl;
//    }

    // INCISO B
    // El primer cero es el indice de la tortuga actual que esta peleando
    // y los dos ceros siguientes son la posicion actual en x e y
    if(logranVencer(poder, movimiento, ciudad, n, 0, 0, 0))
        cout << "Las tortuninjas SI lograron vencer a SuperFly\n";
    else
        cout << "Las tortuninjas NO lograron vencer a SuperFly\n";

	return 0;
}
