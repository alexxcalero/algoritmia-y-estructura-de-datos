/*
 * Proyecto : EX1-2024_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de mayo de 2024, 10:00
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include "Lista.h"
#include "funciones.h"
#define T 6
using namespace std;

void leerEImprimirDatos(Lista productos[], char tipoProductos[], int &cantProductos,
        char tiposSeleccionados[], int cantProdSeleccioandos[], int totalCalorias[]) {
    ifstream arch("datos.txt", ios::in);
    if(!arch.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo de datos\n";
        exit(1);
    }

    arch >> cantProductos;

    for(int i = 0; i < cantProductos; i++) {
        arch >> tipoProductos[i];
        construir(productos[i]);
        while(1) {
            int prod;
            arch >> prod;
            if(prod == 0) break;
            insertarOrdenado(productos[i], prod);
        }
    }

    for(int i = 0; i < cantProductos; i++) {
        cout << "Tipo de Producto " << tipoProductos[i] << endl;
        cout << "Calorias de los productos " << tipoProductos[i] << ": ";
        imprime(productos[i]);
    }

    // Leo la formula;
    for(int i = 0; i < cantProductos; i++) {
        arch >> tiposSeleccionados[i];
        if(tiposSeleccionados[i] == '-')
            break;
        arch >> cantProdSeleccioandos[i] >> totalCalorias[i];
    }

    for(int i = 0; i < cantProductos; i++) {
        if(tiposSeleccionados[i] == '-')
            break;
        cout << "Tipo de Producto " << tiposSeleccionados[i] << endl;
        cout << "Cantidad de Productos del Tipo " << tiposSeleccionados[i] << ": ";
        cout << cantProdSeleccioandos[i] << endl;
        cout << "Total de calorias maxima de todos los productos " << tiposSeleccionados[i];
        cout << ": " << totalCalorias[i] << endl;
    }
	cout << endl;
}

int buscarProducto(char tipo, char tipos[], int cantProductos) {
    for(int i = 0; i < cantProductos; i++)
        if(tipo == tipos[i])
            return i;
    return -1;
}

void cargaBin(int num, int cromo[], int size) {
    int i;
    for(i = 0; i < size; i++)
        cromo[i] = 0;

    i = 0;
    while(num != 0) {
        cromo[i] = num % 2;
        num /= 2;
        i++;
    }
}

bool verificarCantidad(int cromo[], int n, int cantidadSeleccionada) {
    int sum = 0;
    for(int i = 0; i < n; i++)
        if(cromo[i] == 1)
            sum++;
    return sum == cantidadSeleccionada;
}

int obtenerCaloria(Lista lista, int ind) {
    int calorias = 0;
    int cont = 0;
    Nodo *recorrido = lista.cabeza;
    while(recorrido) {
        if(cont == ind) {
            calorias += recorrido->elemento;
            break;
        }
        recorrido = recorrido->siguiente;
        cont++;
    }
    return calorias;
}

void imprimirElemento(Lista lista, int ind) {
    Nodo *recorrido = lista.cabeza;
    int cont = 0;
    while(recorrido) {
        if(cont == ind)
            cout << recorrido->elemento << " ";
        recorrido = recorrido->siguiente;
        cont++;
    }
}

void imprimirListaEnBaseAlCromo(Lista lista, int cromo[], int lonCromo) {
    for(int i = 0; i < lonCromo; i++) {
        if(cromo[i] == 1)
            imprimirElemento(lista, i);
    }
}

bool verificarProductosEnFormula(Lista productos[], char tipoProductos[], int cantProductos,
            char tiposSeleccionados[], int cantProdSeleccioandos[], int totalCalorias[]) {
    int posProducto;
	bool cumple = false;
    for(int i = 0; i < cantProductos; i++) {
        if(tiposSeleccionados[i] == '-')
            break;
        else {
            posProducto = buscarProducto(tiposSeleccionados[i], tipoProductos, cantProductos);
            int lonCromo = longitud(productos[posProducto]);
            int cromo[lonCromo];
            int comb = pow(2, lonCromo);
            int caloParc;
            for(int j = 0; j < comb; j++) {
                cargaBin(j, cromo, lonCromo);
                if(verificarCantidad(cromo, lonCromo, cantProdSeleccioandos[i])) {
                    caloParc = 0;
                    for(int k = 0; k < lonCromo; k++) {
                        if(cromo[k] == 1) {
                            caloParc += obtenerCaloria(productos[posProducto], k);
                        }
                    }
                    if(caloParc <= totalCalorias[j]) {
                        imprimirListaEnBaseAlCromo(productos[posProducto], cromo, lonCromo);
                        cout << endl;
						cumple = true;
                    }
                }
            }
        }
    }

	return cumple;
}

int main(int argc, char** argv) {
	// Ingreso de datos
    Lista productos[T];
    char tipoProductos[T];
    int cantProductos;

    char tiposSeleccionados[T];
    int cantProdSeleccioandos[T];
    int totalCalorias[T];

	cout << "INCISO A:\n";
    leerEImprimirDatos(productos, tipoProductos, cantProductos,
            tiposSeleccionados, cantProdSeleccioandos, totalCalorias);

    // Verificar los productos que cumplen la formula
	cout << "INCISO B:\n";
    if(verificarProductosEnFormula(productos, tipoProductos, cantProductos,
            tiposSeleccionados, cantProdSeleccioandos, totalCalorias))
		cout << "SI hay una posible combinacion de productos\n";
	else
		cout << "NO hay una posible combinacion de productos\n";

	return 0;
}
