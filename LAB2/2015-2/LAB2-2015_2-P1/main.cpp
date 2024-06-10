/*
 * Proyecto : LAB2-2015_2-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 19:37
 */

#include <iostream>
using namespace std;

void triangulo(int a, int b) {
	if(a > b) return;  // Caso base

	for(int i = 0; i < a; i++)
		cout << "* ";
	cout << endl;

	triangulo(a + 1, b);  // Llamada recursiva

	for(int i = 0; i < a; i++)
		cout << "* ";
	cout << endl;
}

int main(int argc, char** argv) {
	int a = 3, b = 5;
	triangulo(a, b);
	return 0;
}
