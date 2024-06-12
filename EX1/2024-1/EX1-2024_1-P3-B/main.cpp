/*
 * Proyecto : EX1-2024_1-P3-B
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de mayo de 2024, 09:00
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "Elemento.h"
#include "funcionesCola.h"
using namespace std;

void ordenarColaPorHoraDeLlegadaInicial(Cola &cola) {
    if(esColaVacia(cola)) return;
    Elemento mayor, aux;
    mayor = desencolar(cola);
    for(int i = 0; i < longitud(cola); i++) {
        aux = desencolar(cola);
        if(mayor.horaIni > aux.horaIni) {  // Primero verifico la hora inicial
            encolar(cola, aux);
        } else if(mayor.horaIni < aux.horaIni) {
            encolar(cola, mayor);
            mayor = aux;
        } else {  // En caso sean iguales las horas, verifico los minutos
            if(mayor.minuIni > aux.minuIni) {
                encolar(cola, aux);
            } else {
                encolar(cola, mayor);
                mayor = aux;
            }
        }
    }
    ordenarColaPorHoraDeLlegadaInicial(cola);
    encolar(cola, mayor);
}

void ordenarColaPorHoraDeLlegadaFinal(Cola &cola) {
    if(esColaVacia(cola)) return;
    Elemento mayor, aux;
    mayor = desencolar(cola);
    for(int i = 0; i < longitud(cola); i++) {
        aux = desencolar(cola);
        if(mayor.horaFin > aux.horaFin) {  // Primero verifico la hora inicial
            encolar(cola, aux);
        } else if(mayor.horaFin < aux.horaFin) {
            encolar(cola, mayor);
            mayor = aux;
        } else {  // En caso sean iguales las horas, verifico los minutos
            if(mayor.minuFin > aux.minuFin) {
                encolar(cola, aux);
            } else {
                encolar(cola, mayor);
                mayor = aux;
            }
        }
    }
    ordenarColaPorHoraDeLlegadaFinal(cola);
    encolar(cola, mayor);
}

void actualizarVuelo(Cola &cola, Elemento vueloActualizado) {
    Elemento valor;
    for(int i = 0; i < longitud(cola); i++) {
        valor = desencolar(cola);
        if(vueloActualizado.idVuelo != valor.idVuelo)
            encolar(cola, valor);
        else
            encolar(cola, vueloActualizado);
    }
}

int main(int argc, char** argv) {
	// Primer paso: Guardar la informacion
    Elemento vuelos[5] = {
        {2101, 0, 55, 0, 55},
        {1102, 1, 45, 1, 45},
        {4111, 0, 30, 0, 30},
        {2105, 1, 22, 1, 22},
        {3108, 5, 25, 5, 25},
    };

    Cola cola;
    construir(cola);

    encolar(cola, vuelos[0]);
    encolar(cola, vuelos[1]);
    encolar(cola, vuelos[2]);
    encolar(cola, vuelos[3]);
    encolar(cola, vuelos[4]);

    // Segundo paso: Ordenar la cola por hora de llegada inicial
    ordenarColaPorHoraDeLlegadaInicial(cola);

    cout << setw(30) << "AEROPUERTO AURORA\n";
    cout << "HORA DE LLEGADA:\n";
    cout << left << setw(8) << "Avion" << setw(20) << "Hora de llegada";
    cout << setw(25) << "Nueva hora de llegada" << endl;
    imprime(cola);

    // Tercer paso: Actualizar la nueva hora de llegada
    // Supongo que puede ser variable, por eso creo una variable
    int cantActualizaciones = 2;
    Elemento vuelosActualizados[cantActualizaciones] = {
        {2101, 0, 55, 0, 15},
        {2105, 1, 22, 2, 10},
    };
    for(int i = 0; i < cantActualizaciones; i++)
        actualizarVuelo(cola, vuelosActualizados[i]);

    // Cuarto paso: Reordeno la cola por la hora de llegada final
    ordenarColaPorHoraDeLlegadaFinal(cola);
    cout << "\nNUEVA HORA DE LLEGADA:\n";
    cout << left << setw(8) << "Avion" << setw(20) << "Hora de llegada";
    cout << setw(25) << "Nueva hora de llegada" << endl;
    imprime(cola);

	return 0;
}
