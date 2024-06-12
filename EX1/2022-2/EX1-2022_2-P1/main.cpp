/*
 * Proyecto : EX1-2022_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 16 de mayo de 2024, 01:09
 */

#include <iostream>
#include "Lista.h"
#include "funciones.h"
using namespace std;

void fusionarListas(Lista &lista1, Lista &lista2) {
	if(lista1.cola->elemento.hora < lista2.cabeza->elemento.hora) {
		lista1.cola->siguiente = lista2.cabeza;
		lista1.cola = lista2.cola;
	} else if(lista2.cola->elemento.hora < lista1.cabeza->elemento.hora) {
		lista2.cola->siguiente = lista1.cabeza;
		lista1.cabeza = lista2.cabeza;
	} else {
		Nodo * ini = nullptr;
		Nodo * fin = nullptr;
		while(!esListaVacia(lista1) && !esListaVacia(lista2)) {
			if(lista1.cabeza->elemento.hora <= lista2.cabeza->elemento.hora) {
				if(ini == nullptr)
					ini = lista1.cabeza;
				else
					fin->siguiente = lista1.cabeza;
				fin = lista1.cabeza;
				lista1.cabeza = lista1.cabeza->siguiente;
			} else {
				if(ini == nullptr)
					ini = lista2.cabeza;
				else
					fin->siguiente = lista2.cabeza;
				fin = lista2.cabeza;
				lista2.cabeza = lista2.cabeza->siguiente;
			}
		}
		if(!esListaVacia(lista1)) {
			fin->siguiente = lista1.cabeza;
			fin = lista1.cola;
		}
		if(!esListaVacia(lista2)) {
			fin->siguiente = lista2.cabeza;
			fin = lista2.cola;
		}
		lista1.cabeza = ini;
		lista2.cola = fin;
	}
}

int main(int argc, char** argv) {
	Lista lunes, martes, miercoles, jueves, viernes;
	construir(lunes);
	construir(martes);
	construir(miercoles);
	construir(jueves);
	construir(viernes);

	insertarAlInicio(lunes, 12, 1);
	insertarAlInicio(lunes, 10, 14);
	insertarAlInicio(lunes, 8, 6);
//	imprime(lunes);

	insertarAlFinal(martes, 9, 3);
	insertarAlFinal(martes, 11, 8);
//	imprime(martes);

	insertarAlFinal(miercoles, 8, 2);
	insertarAlFinal(miercoles, 9, 5);
	insertarAlFinal(miercoles, 10, 10);
//	imprime(miercoles);

	insertarAlFinal(jueves, 14, 13);
	insertarAlFinal(jueves, 15, 9);
	insertarAlFinal(jueves, 16, 11);
//	imprime(jueves);

	insertarAlFinal(viernes, 17, 4);
	insertarAlFinal(viernes, 18, 12);
	insertarAlFinal(viernes, 19, 7);
//	imprime(viernes);

	fusionarListas(lunes, martes);
	fusionarListas(lunes, miercoles);
	fusionarListas(lunes, jueves);
	fusionarListas(lunes, viernes);
	imprime(lunes);

	return 0;
}
