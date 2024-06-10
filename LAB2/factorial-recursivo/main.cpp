/*
 * Proyecto : factorial-recursivo
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 12 de abril de 2024, 22:35
 */

#include <iostream>
using namespace std;

long long factorial(int n) {
	if(n == 1)
		return 1;
	return n * factorial(n - 1);
}

int main(int argc, char** argv) {
	int n = 8;
	long long f = factorial(n);
	cout << "El factorial de " << n << " es " << f << endl;
	return 0;
}
