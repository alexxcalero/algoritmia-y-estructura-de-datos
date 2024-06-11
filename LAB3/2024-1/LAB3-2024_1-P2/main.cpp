/*
 * Proyecto : LAB3-2024_1-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 11 de mayo de 2024, 08:42
 */

#include <iostream>
using namespace std;

int hallarPotenciaMaxima(int arr[], int ini, int fin) {
    int med = (ini + fin) / 2;

    // Si el valor del arreglo en la posicion del medio es mayor a la
    // de sus costados. Quiere decir que ya encontre la potencia maxima
    if(arr[med] > arr[med - 1] && arr[med] > arr[med + 1])
        return arr[med];

    // Si el valor del arreglo en la posicion del medio es mayor o igual
    // a la que esta a su izquierda, quiere decir que tengo que ir para
    // la derecha para seguir buscando el valor maximo del arreglo
    if(arr[med] >= arr[med - 1])
        return hallarPotenciaMaxima(arr, med, fin);
    else
        return hallarPotenciaMaxima(arr, ini, med);
}

int hallarPosicionInicial(int arr[], int ini, int fin) {
    int med = (ini + fin) / 2;

    // Ya encontre la posicion donde inicia la radiacion
    // porque a la izquiera del uno hay un numero negativo o cero
    if(arr[med] == 1 && arr[med - 1] <= 0)
        return med;

    // Ya encontre el cero o numero negativo que esta mas a la derecha
    // porque a la derecha hay un uno (empieza la radiacion)
    if(arr[med] <= 0 && arr[med + 1] == 1)
        return med + 1;  // Retorno med + 1, porque yo quiero la posicion del 1

    // Si el numero es positivo me voy para la izquierda
    // para seguir buscando el negativo que esta mas a la derecha
    if(arr[med] > 0)
        return hallarPosicionInicial(arr, ini, med - 1);
    else
        return hallarPosicionInicial(arr, med + 1, fin);
}

int main(int argc, char** argv) {
    // Primer juego de datos
    int arr[] = {0, -1, 0, -1, 0, 1, 1, 2, 2, 3, 2, 2, 1, 1};
    int n = 14;

    // Segundo juego de datos
//    int arr[] = {-1, 0, -1, 0, 1, 1, 2, 2, 3, 3, 4, 3, 3, 2, 2, 1, 1};
//    int n = 17;

    int posInicial = hallarPosicionInicial(arr, 0, n - 1);

    // Paso la posicion inicial donde inicia la radiacion
    // para no tener que evaluar la zona de numeros negativos o ceros
    int potenciaMaxima = hallarPotenciaMaxima(arr, posInicial, n - 1);

    cout << "La radiacion empieza a " << posInicial << " km. ";
    cout << "Potencia maxima " << potenciaMaxima << " megatones\n";

    return 0;
}
