/*
 * File:   FuncionesAuxiliares.cpp
 * Author: ANA RONCAL
 * Created on 21 de agosto de 2023, 12:11 PM
 */

#include <iostream>
#include <iomanip> /*formato de números*/
#include <fstream>
#include "Lista.h"
#include "Elemento.h"
#include "funcionesLista.h"
using namespace std;

/*Valores iniciales de la lista*/
void construir(struct Lista & tad) {
    tad.cabeza = nullptr;
	tad.mayores = nullptr;
	tad.menores = nullptr;
    tad.cola = nullptr;
    tad.longitud = 0;
}

/*devuelve si la lista esta vacia 1, caso contrario 0 */
const bool esListaVacia(const struct Lista & tad) {
    return tad.cabeza == nullptr;
}

/*devuelve la longitud de la lista*/
int longitud(const struct Lista  & tad) {
    return tad.longitud;
}

/*inserta un nodo siempre al final de la cola*/
void insertarencola(struct Lista & tad, Elemento elemento) {

    struct Nodo * ultimoNodo = tad.cola;
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

    if (ultimoNodo == nullptr){/*Si la lista está vacia*/
        tad.cabeza = nuevoNodo; /*se inserta en la cabeza de la lista*/
        tad.cola = nuevoNodo;
    }
    else{ //La lista ya tiene nodos
        ultimoNodo->siguiente = nuevoNodo;
        tad.cola = nuevoNodo;
    }
    tad.longitud++;
}

// Algoritmo para encolar con prioridad
void insertarPrioridad(Lista &tad, Elemento elemento) {
    struct Nodo * nuevoNodo = crearNodo(elemento, nullptr);

	int fecha = elemento.fecha;
	int anho = fecha / 10000;
	int edad = 2024 - anho;

	if(esListaVacia(tad)) {
		tad.cabeza = nuevoNodo;  // Siempre se apunta cabeza
		tad.cola = nuevoNodo;    // Siempre se apunta cola
		if(edad > 80) tad.mayores = nuevoNodo;  // Solo apunto mayores si entra un nodo de su categoria
		if(edad < 10) tad.menores = nuevoNodo;  // Solo apunto menores si entra un nodo de su categoria
	} else {
		if(edad > 80) {  // Si voy a insertar un nodo de categoria mayores
			if(tad.mayores == nullptr) {  // Va a ser el primer nodo mayores a insertar
				tad.mayores = nuevoNodo;  // Apunto mayores al nuevoNodo
				nuevoNodo->siguiente = tad.cabeza;  // El nuevoNodo apunta a la cabeza de la cola
				tad.cabeza = nuevoNodo;  // La cabeza de la lista apunta al nuevoNodo
			} else {  // Ya hay un nodo de categoria mayores en la cola
				if(tad.mayores->siguiente == nullptr)  // Es el ultimo elemento de la cola
					tad.cola = nuevoNodo;  // Hago apuntar la cola al nuevoNodo
				// El siguiente del nuevoNodo va a ser el siguiente del actual ptro mayores
				nuevoNodo->siguiente = tad.mayores->siguiente;
				tad.mayores->siguiente = nuevoNodo;  // El siguiente del ptro mayores apunta al nuevoNodo
				tad.mayores = nuevoNodo;  // El ptro mayores apunta al nuevoNodo insertado
			}
		} else if(edad < 10) {   // Si voy a insertar un nodo de categoria menores
			if(tad.menores == nullptr) {  // Primer nodo de categoria menores que voy a insertar
				tad.menores = nuevoNodo;  // Apunto el puntero menores al nuevoNodo
				if(tad.mayores == nullptr) {  // No hay ningun nodo de categoria mayores en la cola
					nuevoNodo->siguiente = tad.cabeza;
					tad.cabeza = nuevoNodo;
				} else {  // Si hay nodos de categoria mayores en la cola
					if(tad.mayores->siguiente == nullptr)  // Solo hay un nodo
						tad.cola = nuevoNodo;  // Apunto la cola de la la cola al nuevoNodo
					nuevoNodo->siguiente = tad.mayores->siguiente;
					tad.mayores->siguiente = nuevoNodo;
				}
			} else {
				if(tad.menores->siguiente == nullptr)
					tad.cola = nuevoNodo;
				nuevoNodo->siguiente = tad.menores->siguiente;
				tad.menores->siguiente = nuevoNodo;
				tad.menores = nuevoNodo;
			}
		} else {  // Si voy a insertar un nodo de cualquier otra categoria
			tad.cola->siguiente = nuevoNodo;
			tad.cola = nuevoNodo;
		}
	}
	tad.longitud++;
}

/*Crea un nuevo nodo con los datos dados como parámetros*/
struct Nodo * crearNodo(Elemento elemento, struct Nodo * siguiente) {
    struct Nodo * nuevoNodo = new struct Nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

Elemento retornaCabeza(const struct Lista & tad){
    return tad.cabeza->elemento;
}

void eliminaCabeza(struct Lista & tad) {
    struct Nodo * nodoAEliminar = tad.cabeza;
    if (nodoAEliminar != nullptr) {
        tad.cabeza = tad.cabeza->siguiente;
        delete nodoAEliminar;
        tad.longitud--;
    }
}

/*Elimina el último elemento de la lista, es llamado cola*/
void eliminaCola(struct Lista & tad) {
    struct Nodo * ultimo = nullptr;
    struct Nodo * penultimo = nullptr;
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        if (ultimo != nullptr)
            penultimo = ultimo;
        ultimo = recorrido;
        recorrido = recorrido->siguiente;
    }

    if (ultimo != nullptr) {
        //Si no hay penultimo, se está¡ eliminando el Único nodo de la lista
        if (penultimo == nullptr)
            tad.cabeza = nullptr;
        else
            penultimo->siguiente = nullptr;
        delete ultimo;
        tad.longitud--;
    }
}

void destruir(struct Lista & tad) {
    /*recorrido apunta al inicio del tad*/
    struct Nodo * recorrido = tad.cabeza;

    while (recorrido != nullptr) {
        /*Nodo auxiliar que va servir para eliminar los nodos*/
        struct Nodo * nodoAEliminar = recorrido;
        recorrido = recorrido->siguiente;
        delete nodoAEliminar;
    }
    /*la lista queda vacia*/
    tad.cabeza = nullptr;
    tad.longitud = 0;
}

/*Se recorre la lista en forma secuencial*/
/*se utiliza para no modificar la estructura, la prOteje de ti mismo*/
/*Si se quiere acceder a los datos, por ejemplo tad.longitud = 20, no te deja
 dado que la estructura es de lectura solamente*/
/*con const aquello que pasas no va cambiar, el compilador se da cuenta que es constante*/
void imprime(const struct Lista & tad) {
    cout << fixed;
    cout << setprecision(2);
    if (esListaVacia(tad)) {
        cout << "La lista está vacía no se puede mostrar" << endl;
        return;
    } else {
        struct Nodo * recorrido = tad.cabeza;
        int estaImprimiendoLaCabeza = 1;
        cout << "[";

        while (recorrido != nullptr) {
            /*Este artificio coloca la primera coma después de la cabeza*/
            if (!estaImprimiendoLaCabeza)
                cout << ", ";
            estaImprimiendoLaCabeza = 0;
			int fecha = recorrido->elemento.fecha;
			int anho = fecha / 10000; fecha %= 10000;
			int mes = fecha / 100, dia = fecha % 100;
            cout << dia << '/' << mes << '/' << anho << " " << recorrido->elemento.codigo;
            recorrido = recorrido->siguiente;
        }
        cout << "]" << endl;
    }
}