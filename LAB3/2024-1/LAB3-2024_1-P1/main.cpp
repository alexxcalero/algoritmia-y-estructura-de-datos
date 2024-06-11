/*
 * Proyecto : LAB3-2024_1-P1
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 08:05
 */

#include <iostream>
using namespace std;

int min(int a, int b) {
    return a < b ? a : b;
}

int hallarSumaCentro(int arr[], int ini, int med, int fin) {
    int suma;
    int sumaIzq = 9999;  // Variable para guardar la suma minima por la izquierda
    int sumaDer = 9999;  // Variable para guardar la suma minima por la derecha

    suma = 0;  // Seteo el acumulador en cero
    for(int i = med; i >= ini; i--) {
        suma += arr[i];
        // Si la suma parcial acumulada es menor
        // a la suma que ya tengo por la izquierda
        // guardo el nuevo valor de la minima suma parcial
        if(suma < sumaIzq)
            sumaIzq = suma;
    }

    suma = 0;  // Vuelvo a setear el acumulador en cero
    for(int i = med; i <= fin; i++) {
        suma += arr[i];
        // Si la suma parcial acumulada es menor
        // a la suma que ya tengo por la derecha
        // guardo el nuevo valor de la minima suma parcial
        if(suma < sumaDer)
            sumaDer = suma;
    }

    // Voy a retornar el minimo de:
    //  - La suma obtenida por la izquierda
    //  - La suma obtenida por la derecha
    //  - O la suma del lado de la izquierda mas la suma del lado por la derecha
    //    restandole el valor del medio, porque sino lo estoy sumando dos veces
    return min(sumaIzq, min(sumaDer, sumaIzq + sumaDer - arr[med]));
}

int hallarMaximaSuma(int arr[], int ini, int fin) {
    // Si solo queda un elemento en el arreglo, voy a retornar el valor
    if(ini == fin)
        return arr[ini];

    // Hallo el medio del arreglo
    int med = (ini + fin) / 2;
    int sumIzq = hallarMaximaSuma(arr, ini, med);       // Suma parcial por la izquierda
    int sumDer = hallarMaximaSuma(arr, med + 1, fin);   // Suma parcial por la derecha
    int sumMed = hallarSumaCentro(arr, ini, med, fin);  // Suma parcial por el medio

    // Retorno la minima suma parcial
    return min(sumIzq, min(sumDer, sumMed));
}

int main(int argc, char** argv) {
    // Primer juego de datos
    int arr[] = {2, 5, -6, 2, 3, -1, -5, 6};
    int n = 8;

    // Segundo juego de datos
//    int arr[] = {2, -3, 4, -5, -7};
//    int n = 5;

    // Tercer juego de datos
//    int arr[] = {-4, 5, 6, -4, 3, -1, -5, 6};
//    int n = 8;

    int maxAcumulacion = hallarMaximaSuma(arr, 0, n - 1);
    cout << "La acumulacion negativa mas alta es " << maxAcumulacion << endl;

    return 0;
}
