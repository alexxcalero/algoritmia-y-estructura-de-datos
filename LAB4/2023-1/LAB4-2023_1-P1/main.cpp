/*
 * Proyecto : LAB4-2023_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 28 de mayo de 2024, 13:08
 */

#include <iostream>
#include "Cola.h"
#include "Elemento.h"
#include "ArbolBinario.h"
#include "funcionesCola.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

bool encontrarSkyNerd(ArbolBinario & arbol, int &nivel) {
	Cola cola;
	construir(cola);
	encolar(cola, arbol.raiz);
	int nivelActual = 1;
	int nodosNivelActual = 1;
	int nodosNivelSiguiente = 0;
	while(!esColaVacia(cola)) {
		NodoArbol *elemento;
		elemento = desencolar(cola);
		nodosNivelActual--;
		if(elemento->elemento.velocidad != 200) {
			if(elemento->derecha != nullptr) {
				encolar(cola, elemento->derecha);
				nodosNivelSiguiente++;
			}
			if(elemento->izquierda != nullptr) {
				encolar(cola, elemento->izquierda);
				nodosNivelSiguiente++;
			}
		} else {
			NodoArbol *hijoIzq;
			NodoArbol *hijoDer;
			if(elemento->izquierda != nullptr) {
				hijoIzq = elemento->izquierda;
				if(hijoIzq->elemento.tipo == 'S' && hijoIzq->elemento.velocidad == 200) {
					nivel = nivelActual + 1;
					return true;
				}
				encolar(cola, elemento->izquierda);
				nodosNivelSiguiente++;
			}
			if(elemento->derecha != nullptr) {
				hijoDer = elemento->derecha;
				if(hijoDer->elemento.tipo == 'S' && hijoDer->elemento.velocidad == 200) {
					nivel = nivelActual + 1;
					return true;
				}
				encolar(cola, elemento->derecha);
				nodosNivelSiguiente++;
			}
		}
		if(nodosNivelActual == 0) {
			nivelActual++;
			nodosNivelActual = nodosNivelSiguiente;
			nodosNivelSiguiente = 0;
		}
	}
	return false;
}

int main(int argc, char** argv) {
	ArbolBinario arbol1,arbol2,arbol3,arbol4,arbol5,arbol6,arbol7;
	ArbolBinario arbol8,arbol9,arbol10,arbol11,arbol12,arbol13;
	construir(arbol1);construir(arbol2);
	construir(arbol3);construir(arbol4);
	construir(arbol5);construir(arbol6);
	construir(arbol7);construir(arbol8);
	construir(arbol9);construir(arbol10);
	construir(arbol11);construir(arbol12);
	construir(arbol13);
	Elemento elementos[13]{{'E',50},{'S',50},{'E',100},{'Z',200},{'E',100},
						   {'S',50},{'Z',50},{'S',100},{'E',200},{'S',200},
						   {'S',150},{'E',200},{'Z',100}};
	plantarArbolBinario(arbol1,nullptr,elementos[0],nullptr);
	plantarArbolBinario(arbol2,arbol1,elementos[1],nullptr);
	plantarArbolBinario(arbol3,nullptr,elementos[2],nullptr);
	plantarArbolBinario(arbol4,arbol3,elementos[3],nullptr);
	plantarArbolBinario(arbol5,arbol2,elementos[4],arbol4);
	plantarArbolBinario(arbol6,nullptr,elementos[5],nullptr);
	plantarArbolBinario(arbol7,arbol5,elementos[6],arbol6);
	plantarArbolBinario(arbol8,nullptr,elementos[7],nullptr);
	plantarArbolBinario(arbol9,nullptr,elementos[8],nullptr);
	plantarArbolBinario(arbol10,arbol8,elementos[9],arbol9);
	plantarArbolBinario(arbol11,nullptr,elementos[10],nullptr);
	plantarArbolBinario(arbol12,arbol10,elementos[11],arbol11);
	plantarArbolBinario(arbol13,arbol7,elementos[12],arbol12);

	//recorrerPreOrden(arbol13); cout << endl;
	int nivel;
	if(encontrarSkyNerd(arbol13, nivel))
		cout << "SkyNerd SI esta en el AB, en el nivel " << nivel << endl;
	else
		cout << "SkyNerd NO esta en el AB.\n";
	
	return 0;
}
