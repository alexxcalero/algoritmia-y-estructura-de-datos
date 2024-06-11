/*
 * Proyecto : LAB2-2024_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 15 de mayo de 2024, 00:31
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "Cola.h"
#include "Elemento.h"
#include "funcionesCola.h"
using namespace std;

int main(int argc, char** argv) {
	Cola pacientes;
	construir(pacientes);

	ifstream arch("Pacientes.txt", ios::in);
	if(!arch.is_open()) {
		cout << "ERROR: No se pudo abrir el archivo de Pacientes.txt\n";
		exit(1);
	}

	Elemento paciente;
	int dia, mes, anho, fecha;
	char codigo[7], c;
	while(1) {
		arch >> dia;
		if(arch.eof()) break;
		arch >> c >> mes >> c >> anho >> codigo;
		fecha = anho * 10000 + mes * 100 + dia;
		paciente.fecha = fecha;
		strcpy(paciente.codigo, codigo);
		encolar(pacientes, paciente);
	}

	imprime(pacientes);

	return 0;
}
