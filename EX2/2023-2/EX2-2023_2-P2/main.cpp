/*
 * Proyecto : EX2-2023_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 6 de julio de 2024, 00:23
 */

#include <iostream>
#include "Nodo.h"
#include "Lista.h"
#include "funciones.h"
#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#define M 6
#define N 10
using namespace std;

// Busco la letra en la palabra
bool procesarLetra(char letra, char palabra[]) {
	for(int i = 0; palabra[i] != '\0'; i++)
		if(letra == palabra[i])
			return true;
	return false;
}

// Verifico que se haya formado correctamente la palabra
bool verificarPalabra(char palabra[], Lista &lista) {
	// Creo una lista auxiliar para no chancar la lista original
	Lista aux;
	construir(aux);

	Nodo *rec = lista.cabeza;
	while(rec) {  // Copio lo de la lista original a la lista auxiliar
		insertarAlFinal(aux, rec->elemento);
		rec = rec->siguiente;
	}

	int size = 0;
	bool encontrado;
	for(int i = 0; palabra[i] != '\0'; i++) {
		encontrado = false;
		size++;
		rec = aux.cabeza;
		// Recorro la lista, para verificar si la letra esta en la palabra
		while(rec) {
			// Encontre la letra en la palabra
			if(rec->elemento == palabra[i]) {
				encontrado = true;  // Marco encontrado = true
				rec->elemento = '-';  // Borro la letra de la lista para evitar repetidos
				break;  // Dejo de buscar para pasar a la siguiente letra
			}
			rec = rec->siguiente;
		}
		// Si no encontre la letra, retorno falso
		if(!encontrado)
			return false;
	}

	// Verifico que se hayan encontrado todas las letras
	// y que el tamanho de la palabra sea igual al de la lista
	return encontrado && (size == longitud(aux));
}

bool procesarPalabra(NodoArbol *raiz, char palabra[], Lista &lista) {
	if(raiz == nullptr)
		return false;

	// Verifico si la letra del nodo del arbol se encuentra en la palabra
	if(procesarLetra(raiz->elemento, palabra))
		insertarAlFinal(lista, raiz->elemento);
	else
		return false;

	// Cuando estoy en una hoja, verifico si he formado la palabra
	if(raiz->derecha == nullptr && raiz->izquierda == nullptr)
		if(verificarPalabra(palabra, lista))
			return true;
		else
			return false;

	return procesarPalabra(raiz->izquierda, palabra, lista) || procesarPalabra(raiz->derecha, palabra, lista);
}

int main(int argc, char** argv) {
	ArbolBinario arbol, arbol1, arbol2, arbol3, arbol4, arbol5, arbol6, arbol7;
	ArbolBinario arbol8, arbol9, arbol10, arbol11, arbol12, arbol13, arbol14;
	construir(arbol); construir(arbol1); construir(arbol2); construir(arbol3);
	construir(arbol4); construir(arbol5); construir(arbol6); construir(arbol7);
	construir(arbol8); construir(arbol9); construir(arbol10); construir(arbol11);
	construir(arbol12); construir(arbol13); construir(arbol14);

	plantarArbolBinario(arbol14, nullptr, 'T', nullptr);
	plantarArbolBinario(arbol13, arbol14, 'G', nullptr);
	plantarArbolBinario(arbol12, nullptr, 'R', nullptr);
	plantarArbolBinario(arbol11, arbol12, 'E', arbol13);
	plantarArbolBinario(arbol10, nullptr, 'E', nullptr);
	plantarArbolBinario(arbol9, arbol10, 'D', arbol11);
	plantarArbolBinario(arbol8, nullptr, 'O', nullptr);
	plantarArbolBinario(arbol7, arbol8, 'C', nullptr);
	plantarArbolBinario(arbol6, arbol7, 'C', nullptr);
	plantarArbolBinario(arbol5, nullptr, 'T', nullptr);
	plantarArbolBinario(arbol4, nullptr, 'F', nullptr);
	plantarArbolBinario(arbol3, arbol4, 'A', arbol5);
	plantarArbolBinario(arbol2, arbol3, 'N', nullptr);
	plantarArbolBinario(arbol1, arbol6, 'I', arbol2);
	plantarArbolBinario(arbol, arbol9, 'L', arbol1);

	//recorrerEnOrden(arbol);

	char palabras[M][N] = {
		{'H', 'I', 'J', 'O', '\0'},
		{'F', 'I', 'N', 'A', 'L', '\0'},
		{'M', 'U', 'N', 'D', 'O', '\0'},
		{'D', 'E', 'L', '\0'},
		{'D', 'I', 'A', '\0'},
		{'C', 'I', 'C', 'L', 'O', '\0'},
	};

	Lista lista;
	for(int i = 0; i < N; i++) {
		construir(lista);
		if(procesarPalabra(arbol.raiz, palabras[i], lista))
			cout << palabras[i] << " ";
		destruir(lista);
	}

	return 0;
}
