/*
 * Proyecto : EX1-2023_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de mayo de 2024, 01:31
 */

#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define N 10
using namespace std;

int main(int argc, char** argv) {
	int n = 7;
	int paquetes[N][N] = {{0  , 0 , 0 , 0 , 0, 0  , 0 },
						  {10 , 0 , 20, 30, 0, 20 , 40},
						  {0  , 0 , 0 , 0 , 0, 100, 0 },
						  {0  , 0 , 0 , 0 , 0, 80 , 0 },
						  {50 , 10, 5 , 10, 0, 100, 4 },
						  {100, 0 , 0 , 0 , 0, 0  , 0 },
						  {0  , 0 , 0 , 0 , 0, 0  , 0 }};

//	int paquetes[N][N] = {{0  , 10, 10, 10, 20, 10 , 10},
//						  {10 , 0 , 20, 30, 0 , 20 , 40},
//						  {0  , 0 , 0 , 0 , 0 , 100, 0 },
//						  {0  , 0 , 0 , 0 , 0 , 80 , 0 },
//						  {50 , 10, 5 , 10, 0 , 100, 4 },
//						  {100, 0 , 0 , 0 , 0 , 0  , 0 },
//						  {0  , 0 , 0 , 0 , 0 , 0  , 0 }};

	Pila servidores;
	construir(servidores);
	for(int i = 0; i < n; i++)
		apilar(servidores, i);

	int emisor, receptor;
	while(!esPilaVacia(servidores)) {
		emisor = desapilar(servidores);
		if(longitud(servidores) >= 1) {
			receptor = desapilar(servidores);
			if(paquetes[emisor][receptor] == 0)
				apilar(servidores, receptor);
			else
				apilar(servidores, emisor);
		}
	}

	// Una vez que tengo el posible emisor, reviso la fila y la columna
	// verificando la correcta cantidad de ceros y asegurarnos que sea SkyNerd
	int sumFil = 0, sumCol = 0, maxPaquete = -9999;
	for(int col = 0; col < n; col++) {
		if(paquetes[emisor][col] > maxPaquete)
			maxPaquete = paquetes[emisor][col];
		if(paquetes[emisor][col] == 0)
			sumCol++;
	}

	for(int fil = 0; fil < n; fil++)
		if(paquetes[fil][emisor] == 0)
			sumFil++;

	if(sumFil == n && sumCol == 1) {
		cout << "SkyNerd ha sido detectado en el servidor: " << emisor + 1 << endl;
		cout << "Maximo de paquetes enviados por SkyNerd: " << maxPaquete << endl;
	} else {
		cout << "SkyNerd no esta en la red\n";
	}

	return 0;
}
