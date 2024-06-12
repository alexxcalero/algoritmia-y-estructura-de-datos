/*
 * Proyecto : EX1-2023_1-P3
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 16 de mayo de 2024, 10:41
 */

#include <iostream>
#include <fstream>
#include "Lista.h"
#include "funciones.h"
using namespace std;

void leerDatos(int &numPelas, int &cantGuerreros, Lista &guerreros) {
	ifstream arch("Guerreros.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo Guerreros.txt.\n";
		exit(1);
	}
	arch >> numPelas >> cantGuerreros;
	for(int i = 0; i < cantGuerreros; i++) {
		int guerrero;
		arch >> guerrero;
		insertarAlFinal(guerreros, guerrero);
	}
	cout << "Lista de Guerreros: ";
	imprime(guerreros);
	cout << endl;
}

void asignarGuerreros(Lista &guerreros, Lista &ejerBowser, Lista &ejerPeach, Lista &ejerDonkey,
		int &ataqueTotalBowser, int &ataqueTotalPeach, int &ataqueTotalDonkey) {
	Nodo *recorrido = guerreros.cabeza;
	while(recorrido) {
		int guerrero = recorrido->elemento;
		int lista = guerrero % 10;
		guerrero /= 10;
		if(lista == 1) {
			insertarOrdenado(ejerBowser, guerrero);
			ataqueTotalBowser += guerrero;
		}
		else if(lista == 2) {
			insertarOrdenado(ejerPeach, guerrero);
			ataqueTotalPeach += guerrero;
		}
		else if(lista == 3) {
			insertarOrdenado(ejerDonkey, guerrero);
			ataqueTotalDonkey += guerrero;
		}
		recorrido = recorrido->siguiente;
	}
	cout << "Los ejercitos formados son:\n";
	cout << "Ejercito 1 - Bowser: "; imprime(ejerBowser);
	cout << "Nivel de ataque total del Ejercito 1: " << ataqueTotalBowser << endl << endl;
	cout << "Ejercito 2 - Peach: "; imprime(ejerPeach);
	cout << "Nivel de ataque total del Ejercito 2: " << ataqueTotalPeach << endl << endl;
	cout << "Ejercito 3 - Donkey Kong: "; imprime(ejerDonkey);
	cout << "Nivel de ataque total del Ejercito 3: " << ataqueTotalDonkey << endl << endl;
}

void fusionarEjercitos(Lista &ejercito1, Lista &ejercito2) {
	if(ejercito1.cola->elemento < ejercito2.cabeza->elemento) {
		ejercito1.cola->siguiente = ejercito2.cabeza;
		ejercito1.cola = ejercito2.cola;
	} else if(ejercito2.cola->elemento < ejercito1.cabeza->elemento) {
		ejercito2.cola->siguiente = ejercito1.cabeza;
		ejercito1.cabeza = ejercito2.cabeza;
	} else {
		Nodo *ini = nullptr;
		Nodo *fin = nullptr;
		while(!esListaVacia(ejercito1) && !esListaVacia(ejercito2)) {
			if(ejercito1.cabeza->elemento <= ejercito2.cabeza->elemento) {
				if(ini == nullptr)
					ini = ejercito1.cabeza;
				else
					fin->siguiente = ejercito1.cabeza;
				fin = ejercito1.cabeza;
				ejercito1.cabeza = ejercito1.cabeza->siguiente;
			} else {
				if(ini == nullptr)
					ini = ejercito2.cabeza;
				else
					fin->siguiente = ejercito2.cabeza;
				fin = ejercito2.cabeza;
				ejercito2.cabeza = ejercito2.cabeza->siguiente;
			}
		}
		if(!esListaVacia(ejercito1)) {
			fin->siguiente = ejercito1.cabeza;
			fin = ejercito1.cola;
		}
		if(!esListaVacia(ejercito2)) {
			fin->siguiente = ejercito2.cabeza;
			fin = ejercito2.cola;
		}
		ejercito1.cabeza = ini;
		ejercito1.cola = fin;
	}
}

void simularBatalla(int numPeleas, Lista &ejerBowser, Lista &ejerPeach, Lista &ejerDonkey,
		int &ataqueTotalBowser, int &ataqueTotalPeach, int &ataqueTotalDonkey) {
	bool seUnioDonkey = false;
	Nodo *aux1, *aux2;
	while(!esListaVacia(ejerBowser) && !esListaVacia(ejerPeach)) {
		cout << "Inicia la batalla:\n";
		cout << "Ejercito 1 - Bowser: "; imprime(ejerBowser);
		cout << "Ejercito 2 - Peach: "; imprime(ejerPeach);
		aux1 = ejerBowser.cabeza;
		aux2 = ejerPeach.cabeza;
		for(int i = 1; i <= 2; i++) {
			cout << "Pelea " << i << ": ";
			cout << aux1->elemento << " vs " << aux2->elemento;
			if(aux1->elemento > aux2->elemento) {
				cout << ", gana " << aux1->elemento << endl;
				ataqueTotalPeach -= aux2->elemento;
				ejerPeach.cabeza = aux2->siguiente;
			} else {
				cout << ", gana " << aux2->elemento << endl;
				ataqueTotalBowser -= aux1->elemento;
				ejerBowser.cabeza = aux1->siguiente;
			}
			if(aux1->siguiente != nullptr && aux2->siguiente != nullptr) {
				aux1 = aux1->siguiente;
				aux2 = aux2->siguiente;
			} else break;
		}

		cout << "Nivel de ataque total del Ejercito 1: " << ataqueTotalBowser << endl;
		cout << "Nivel de ataque total del Ejercito 2: " << ataqueTotalPeach << endl;

		if(ataqueTotalBowser > ataqueTotalPeach && seUnioDonkey == false) {
			cout << "El ejercito de Donkey Kong se une al ejercito de Peach\n\n";
			fusionarEjercitos(ejerPeach, ejerDonkey);
			ataqueTotalPeach += ataqueTotalDonkey;
			seUnioDonkey = true;
		} else {
			cout << "Ya no se puede unir nadie al ejercito de Peach\n\n";
		}
	}

	if(ataqueTotalPeach == 0) cout << "Gana la batalla Bowser\n";
	if(ataqueTotalBowser == 0) cout << "Gana la batalla Peach\n";
}

int main(int argc, char** argv) {
	int numPeleas;
	int cantGuerreros;
	Lista guerreros;
	construir(guerreros);
	leerDatos(numPeleas, cantGuerreros, guerreros);

	Lista ejerBowser, ejerPeach, ejerDonkey;
	int ataqueTotalBowser, ataqueTotalPeach, ataqueTotalDonkey;
	ataqueTotalBowser = ataqueTotalPeach = ataqueTotalDonkey = 0;
	construir(ejerBowser);
	construir(ejerPeach);
	construir(ejerDonkey);
	
	asignarGuerreros(guerreros, ejerBowser, ejerPeach, ejerDonkey,
					 ataqueTotalBowser, ataqueTotalPeach, ataqueTotalDonkey);

	simularBatalla(numPeleas, ejerBowser, ejerPeach, ejerDonkey, ataqueTotalBowser,
				   ataqueTotalPeach, ataqueTotalDonkey);

	return 0;
}
