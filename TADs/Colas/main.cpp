/*
 * Proyecto : Colas
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 26 de junio de 2024, 18:39
 */

#include <iostream>
#include "Cola.h"
#include "funcionesDeCola.h"
using namespace std;

int main(int argc, char** argv) {
	Cola cola;
	construir(cola);

	if(esColaVacia(cola)) cout << "La cola SI esta vacia\n";
	else cout << "La cola NO esta vacia\n";

	cout << "La cola tiene " << longitud(cola) << " elementos\n";

	for(int i = 0; i < 9; i++) encolar(cola, i);

	if(esColaVacia(cola)) cout << "La cola SI esta vacia\n";
	else cout << "La cola NO esta vacia\n";

	cout << "La cola tiene " << longitud(cola) << " elementos\n";

	cout << "Elementos de la cola: ";
	imprimir(cola);

	cout << "El primer elemento de la cola es: " << primero(cola) << endl;
	cout << "El ultimo elemento de la cola es: " << ultimo(cola) << endl;

	desencolar(cola);
	int primerElemento = primero(cola);
	cout << "El nuevo primer elemento de la cola es: " << primerElemento << endl;

	destruir(cola);

	if(esColaVacia(cola)) cout << "La cola SI esta vacia\n";
	else cout << "La cola NO esta vacia\n";

	cout << "La cola tiene " << longitud(cola) << " elementos\n";

	return 0;
}
