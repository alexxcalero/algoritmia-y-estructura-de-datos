/*
 * Proyecto : LAB4-2023_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 28 de mayo de 2024, 18:59
 */

#include <iostream>
#include "Pila.h"
#include "funcionesABB.h"
#include "funcionesPila.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

void insertarConRepetido(struct NodoArbol *& nodo, Elemento elemento){
	if(esNodoVacio(nodo))
		plantarArbolBB(nodo, nullptr, elemento, nullptr);
	else
		if(elemento.poder > nodo->elemento.poder)
			insertarConRepetido(nodo->derecha, elemento);
		else
			if(elemento.poder < nodo->elemento.poder)
				insertarConRepetido(nodo->izquierda, elemento);
			else  // Si encuentra el nodo ya existente en el arbol
				nodo->elemento.cantidad += elemento.cantidad;  // Solo sumo cantidades

}

void fusionarRecursivo(NodoArbol *destino, NodoArbol *raizOrigen) {

	if(raizOrigen == nullptr) return;

	insertarConRepetido(destino, raizOrigen->elemento);
	fusionarRecursivo(destino, raizOrigen->izquierda);
	fusionarRecursivo(destino, raizOrigen->derecha);
}

void fusionDeEjercitos(ArbolBinarioBusqueda &destino, ArbolBinarioBusqueda &origen) {
	fusionarRecursivo(destino.arbolBinario.raiz, origen.arbolBinario.raiz);
}

void preOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pila;
	construir(pila);
	apilar(pila, arbol.arbolBinario.raiz);
	while(!esPilaVacia(pila)) {
		NodoArbol *rec = desapilar(pila);
		imprimeNodo(rec);
		if(rec->derecha != nullptr)
			apilar(pila, rec->derecha);
		if(rec->izquierda != nullptr)
			apilar(pila, rec->izquierda);
	}
	desapilar(pila);
}

void postOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pilaAux, pilaFinal;
	construir(pilaAux);
	construir(pilaFinal);
	apilar(pilaAux, arbol.arbolBinario.raiz);
	while(!esPilaVacia(pilaAux)) {
		NodoArbol *aux = desapilar(pilaAux);
		apilar(pilaFinal, aux);
		if(aux->izquierda != nullptr)
			apilar(pilaAux, aux->izquierda);
		if(aux->derecha != nullptr)
			apilar(pilaAux, aux->derecha);
	}
	while(!esPilaVacia(pilaFinal)) {
		NodoArbol *nodo = desapilar(pilaFinal);
		imprimeNodo(nodo);
	}
	desapilar(pilaAux);
	desapilar(pilaFinal);
}

void enOrdenIterativo(ArbolBinarioBusqueda &arbol) {
	Pila pila;
	construir(pila);
	NodoArbol *rec = arbol.arbolBinario.raiz;
	//apilar(pila, arbol.arbolBinario.raiz);
	while(!esPilaVacia(pila)) {
		//NodoArbol *top = cima(pila);
		while(rec != nullptr) {
			apilar(pila, rec);
			rec = rec->izquierda;
		}

		rec = desapilar(pila);
		imprimeNodo(rec);
//		if(rec->derecha != nullptr)
//			apilar(pila, rec->derecha);
//		if(rec->izquierda != nullptr)
//			apilar(pila, rec->izquierda);
		rec = rec->derecha;
	}
	desapilar(pila);
}

int main(int argc, char** argv) {
	ArbolBinarioBusqueda peach, donkey;
	Elemento elemento;
	construir(peach);
	construir(donkey);

	// Inserto en el ejercito de Peach
	elemento.cantidad = 2; elemento.poder = 52;
	insertar(peach,elemento);
	elemento.cantidad = 1; elemento.poder = 40;
	insertar(peach, elemento);
	elemento.cantidad = 3; elemento.poder = 25;
	insertar(peach, elemento);
	elemento.cantidad = 2; elemento.poder = 42;
	insertar(peach, elemento);
	elemento.cantidad = 1; elemento.poder = 60;
	insertar(peach, elemento);

	// Inserto en el ejercito de Donkey
	elemento.cantidad = 1; elemento.poder = 65;
	insertar(donkey,elemento);
	elemento.cantidad = 1; elemento.poder = 25;
	insertar(donkey,elemento);
	elemento.cantidad = 2; elemento.poder = 12;
	insertar(donkey,elemento);
	elemento.cantidad = 1; elemento.poder = 34;
	insertar(donkey,elemento);
	elemento.cantidad = 2; elemento.poder = 75;
	insertar(donkey,elemento);
	elemento.cantidad = 1; elemento.poder = 70;
	insertar(donkey,elemento);

	preOrden(peach);
	cout << endl;
	preOrden(donkey);

	fusionDeEjercitos(peach, donkey);

	cout << endl;
	preOrdenIterativo(peach);
	cout << endl;
//	postOrdenIterativo(peach);
//	cout << endl;
	enOrdenIterativo(peach);

	return 0;
}
