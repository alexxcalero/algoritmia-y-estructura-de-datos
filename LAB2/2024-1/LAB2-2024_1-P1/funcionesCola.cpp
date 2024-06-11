/*
 * File:   funcionesCola.cpp
 * Author: ANA RONCAL
 * Created on 7 de abril de 2024, 06:07 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cola.h"
#include "Elemento.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

/*Construye la Cola*/
void construir(struct Cola & cola){
    construir(cola.lista);
}

/*Verifica si la cola está vacía*/
bool esColaVacia(const struct Cola & cola){
    return esListaVacia(cola.lista);
}

/*Devuelve la longitud de la cola*/
int longitud(const struct Cola & cola){
    return longitud(cola.lista);
}

/*Añade un elemento a la cola*/
void encolar(struct Cola & cola, Elemento elemento){
    //insertarencola(cola.lista, elemento);
	insertarPrioridad(cola.lista, elemento);
}

/*Elimina un elemento de la cola*/
Elemento desencolar(struct Cola & cola){
	Elemento e;
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede desencolar"<<endl;
		e.fecha = -1;
		strcpy(e.codigo, "\0");
		return e; //Cero o algún elemento que no esté en la cola
    }
    else{
        e = retornaCabeza(cola.lista);
        eliminaCabeza(cola.lista);
        if(esColaVacia(cola))
            cola.lista.cola = nullptr;
        return e;
    }
}

/*Muestra los elementos de la cola*/
void imprime(const struct Cola & cola){
    if(esColaVacia(cola)){
        cout<<"La cola está vacía no se puede mostrar"<<endl;
    }
    else
        imprime(cola.lista);
}

void destruirCola(struct Cola & cola){
    destruir(cola.lista);
}
