/*
 * Proyecto : LAB5-2024_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de junio de 2024, 09:03
 */

#include <iostream>
#define N 10
using namespace std;

int buscarBadSunny(int conocidos[N][N], int n, int posible, int otro) {
	// Si uno de los dos parametros se pasa o es igual al limite,
	// devuelvo el que haya quedado como posible Bad Sunny
	if(posible >= n || otro >= n)
		return posible;

	// Si la posicion del posible Bad Sunny contra la otra persona es cero,
	// significa que no la conoce, por ende, el posible Bad Sunny sigue siendo
	// el mismo y aumento en uno a la otra persona
	if(conocidos[posible][otro] == 0)
		return buscarBadSunny(conocidos, n, posible, otro + 1);
	// Caso contrario, la otra persona pasa a ser el posible Bad Sunny
	// y el parametro de la otra persona aumenta en uno
	else
		return buscarBadSunny(conocidos, n, otro, otro + 1);
}

bool corroborarBadSunny(int conocidos[N][N], int n, int posBadSunny) {
	int contadorCeros = 0, contadorUnos = 0;

	for(int filas = 0; filas < n; filas++)
		if(conocidos[filas][posBadSunny] == 1)
			contadorUnos++;

	for(int columnas = 0; columnas < n; columnas++)
		if(conocidos[posBadSunny][columnas] == 0)
			contadorCeros++;

	// Si la cantidad de unos en toda la columna del posible Bad Sunny es igual a n
	// y la cantidad de ceros es igual a n - 1 (va haber un solo uno en la posicion
	// conocidos[posBadSunny][posBadSunny] porque se conoce a si mismo). Entonces
	// mi posible Bad Sunny si es el verdadero
	if(contadorCeros == n - 1 && contadorUnos == n)
		return true;
	else  // Si no cumple alguna condicion, ya no es Bad Sunny
		return false;
}

void buscarBadSunny(int conocidos[N][N], int n) {
	int posBadSunny = buscarBadSunny(conocidos, n, 0, 1);

	if(corroborarBadSunny(conocidos, n, posBadSunny))
		cout << "El codigo asignado a Bad Sunny es " << posBadSunny << endl;
    else
        cout << "Bad Sunny no se encuentra en la fiesta\n";
}

int main(int argc, char** argv) {
	int n = 6;
	int conocidos[N][N] = {
		{1, 1, 1, 1, 1, 1},
		{0, 1, 0, 0, 1, 1},
		{0, 0, 1, 0, 1, 1},
		{0, 1, 1, 1, 1, 0},
		{0, 0, 0, 0, 1, 0},
		{1, 0, 0, 0, 1, 1}
	};
	buscarBadSunny(conocidos, n);
	return 0;
}
