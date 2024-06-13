/*
 * Proyecto : LAB4-2019_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 31 de mayo de 2024, 21:20
 */

#include <iostream>
#include "Elemento.h"
#include "funcionesABB.h"
#include "ArbolBinarioBusqueda.h"
using namespace std;

int main(int argc, char** argv) {
	ArbolBinarioBusqueda abb;
	construir(abb);

	Elemento elementos[10] {{20170620, 20},{20170810, 20},
							{20180211, 20},{20180409, 20}};
	int cantElementos = 4;

	insertar(abb, elementos[0]);
	insertar(abb, elementos[1]);
	insertar(abb, elementos[2]);
	insertar(abb, elementos[3]);

	cout << "Productos disponibles en el almacen antes del despacho:\n";
	enOrden(abb); cout << endl;

	NodoArbol *masAntiguo = minimoNodo(abb);

	int cantDespachar = 35;

	while(cantDespachar != 0) {
		if(cantDespachar >= masAntiguo->elemento.cantidad) {
			cantDespachar -= masAntiguo->elemento.cantidad;
			eliminarNodo(abb, masAntiguo->elemento.fecha);
			masAntiguo = minimoNodo(abb);
		} else {
			masAntiguo->elemento.cantidad -= cantDespachar;
			cantDespachar = 0;
		}
	}
	
	cout << "\nProductos restantes en el almacen despues del despacho:\n";
	enOrden(abb); cout << endl;

	return 0;
}
