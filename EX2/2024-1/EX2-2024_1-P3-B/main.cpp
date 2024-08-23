/*
 * Proyecto : EX2-2024_1-P3-B
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 6 de julio de 2024, 09:15
 */

#include <iostream>
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;

// Paso como parametros la lista y cada cuanto voy a eliminar un empleado de la lista
void procesarDespidos(Lista &planilla, int k) {
	int contador = 1;
	Nodo *rec = planilla.cabeza;
	// Como es una lista circular, mi recorrido siempre va a estar
	// dando vueltas a lo largo de toda la lista. Por tal motivo, mi
	// condicion de parada es cuando solo haya un elemento en la lista
	while(longitud(planilla) != 1) {
		if(contador == k) {  // Elimino el k-esimo empleado
			int datoEliminar = rec->elemento;  // Guardo el empleado a eliminar
			rec = rec->siguiente;  // Recorrido avanza en uno para no perder la secuencia
			eliminaNodo(planilla, datoEliminar);  // Elimo el empleado con la funcion brindada
			contador = 1;  // Reseteo el contador a 1
		} else {  // El contador todavia no es igual a k
			rec = rec->siguiente;  // Recorrido avanza a la siguiente posicion
			contador++;  // Contador aumenta en uno
		}
	}
}

int main(int argc, char** argv) {
	Lista planilla;
	construir(planilla);

	insertarAlFinal(planilla, 1);
	insertarAlFinal(planilla, 2);
	insertarAlFinal(planilla, 3);
	insertarAlFinal(planilla, 4);
	insertarAlFinal(planilla, 5);
	insertarAlFinal(planilla, 6);
	insertarAlFinal(planilla, 7);
//	insertarAlFinal(planilla, 8);
//	insertarAlFinal(planilla, 9);
//	insertarAlFinal(planilla, 10);

	int k = 3;  // Cambiar manualmente el k para probar los otros casos :D
	cout << "En una lista de " << longitud(planilla) << " empleados";
	cout << ", para k = " << k << ". El empleado elegido es: ";
	procesarDespidos(planilla, k);
	imprime(planilla);

	return 0;
}
