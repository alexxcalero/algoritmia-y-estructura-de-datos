/*
 * Proyecto : EX1-2024_1-P3-A
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 18 de mayo de 2024, 08:07
 */

#include <iostream>
using namespace std;

// En todos los merge, paso como parametro el n (cantidad de elementos totales del arreglo)
// para de esta manera poder saber de que tamanho crear mi arreglo auxiliar donde
// ire guardando el arreglo ordenado
void mergeID(int id[], int impacto[], int riesgo[], int ini, int med, int fin, int n) {
    int auxId[n]{}, auxImpacto[n]{}, auxRiesgo[n]{};
    int p, q, m;
    for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
        if(id[p] < id[q]) {
            auxId[m] = id[p];
            auxImpacto[m] = impacto[p];
            auxRiesgo[m] = riesgo[p];
            p++;
        } else {
            auxId[m] = id[q];
            auxImpacto[m] = impacto[q];
            auxRiesgo[m] = riesgo[q];
            q++;
        }
    }
    while(p <= med) {  // En caso hayan elementos en la primera mitad
        auxId[m] = id[p];
        auxImpacto[m] = impacto[p];
        auxRiesgo[m] = riesgo[p];
        p++;
        m++;
    }
    while(q <= fin) {  // En caso hayan elementos en la segunda mitad
        auxId[m] = id[q];
        auxImpacto[m] = impacto[q];
        auxRiesgo[m] = riesgo[q];
        q++;
        m++;
    }
    for(int i = ini; i <=fin; i++) {  // Paso al arreglo original
        id[i] = auxId[i];
        impacto[i] = auxImpacto[i];
        riesgo[i] = auxRiesgo[i];
    }
}

void ordenarPorID(int id[], int impacto[], int riesgo[], int ini, int fin, int n) {
    if(ini == fin)
        return;

    int med = (ini + fin) / 2;
    ordenarPorID(id, impacto, riesgo, ini, med, n);
    ordenarPorID(id, impacto, riesgo, med + 1, fin, n);
    mergeID(id, impacto, riesgo, ini, med, fin, n);
}

void mergeImpacto(int id[], int impacto[], int riesgo[], int ini, int med, int fin, int n) {
    int auxId[n]{}, auxImpacto[n]{}, auxRiesgo[n]{};
    int p, q, m;
    for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
        if(impacto[p] < impacto[q]) {  // Verifico primero los impactos
            auxId[m] = id[p];
            auxImpacto[m] = impacto[p];
            auxRiesgo[m] = riesgo[p];
            p++;
        } else if(impacto[p] > impacto[q]) {
            auxId[m] = id[q];
            auxImpacto[m] = impacto[q];
            auxRiesgo[m] = riesgo[q];
            q++;
        } else {  // Si son iguales los impactos, verifico los riesgos
            if(riesgo[p] < riesgo[q]) {
                auxId[m] = id[p];
                auxImpacto[m] = impacto[p];
                auxRiesgo[m] = riesgo[p];
                p++;
            } else if(riesgo[p] > riesgo[q]) {
                auxId[m] = id[q];
                auxImpacto[m] = impacto[q];
                auxRiesgo[m] = riesgo[q];
                q++;
            } else {  // Si son iguales los impactos y los riesgos, verifico por id
                if(id[p] < id[q]) {
                    auxId[m] = id[p];
                    auxImpacto[m] = impacto[p];
                    auxRiesgo[m] = riesgo[p];
                    p++;
                } else {
                    auxId[m] = id[q];
                    auxImpacto[m] = impacto[q];
                    auxRiesgo[m] = riesgo[q];
                    q++;
                }
            }
        }
    }
    while(p <= med) {  // En caso hayan elementos en la primera mitad
        auxId[m] = id[p];
        auxImpacto[m] = impacto[p];
        auxRiesgo[m] = riesgo[p];
        p++;
        m++;
    }
    while(q <= fin) {  // En caso hayan elementos en la segunda mitad
        auxId[m] = id[q];
        auxImpacto[m] = impacto[q];
        auxRiesgo[m] = riesgo[q];
        q++;
        m++;
    }
    for(int i = ini; i <=fin; i++) {  // Paso al arreglo original
        id[i] = auxId[i];
        impacto[i] = auxImpacto[i];
        riesgo[i] = auxRiesgo[i];
    }
}

void ordenarPorImpacto(int id[], int impacto[], int riesgo[], int ini, int fin, int n) {
    if(ini == fin)
        return;

    int med = (ini + fin) / 2;
    ordenarPorImpacto(id, impacto, riesgo, ini, med, n);
    ordenarPorImpacto(id, impacto, riesgo, med + 1, fin, n);
    mergeImpacto(id, impacto, riesgo, ini, med, fin, n);
}

void mergeRiesgo(int id[], int impacto[], int riesgo[], int ini, int med, int fin, int n) {
    int auxId[n]{}, auxImpacto[n]{}, auxRiesgo[n]{};
    int p, q, m;
    for(p = ini, q = med + 1, m = ini; p <= med && q <= fin; m++) {
        if(riesgo[p] < riesgo[q]) {  // Verifico primero los riesgos
            auxId[m] = id[p];
            auxImpacto[m] = impacto[p];
            auxRiesgo[m] = riesgo[p];
            p++;
        } else if(riesgo[p] > riesgo[q]) {
            auxId[m] = id[q];
            auxImpacto[m] = impacto[q];
            auxRiesgo[m] = riesgo[q];
            q++;
        } else {  // Si son iguales los riesgos, verifico los impactos
            if(impacto[p] < impacto[q]) {
                auxId[m] = id[p];
                auxImpacto[m] = impacto[p];
                auxRiesgo[m] = riesgo[p];
                p++;
            } else if(impacto[p] > impacto[q]) {
                auxId[m] = id[q];
                auxImpacto[m] = impacto[q];
                auxRiesgo[m] = riesgo[q];
                q++;
            } else {  // Si son iguales los riesgos y los impactos, verifico por id
                if(id[p] < id[q]) {
                    auxId[m] = id[p];
                    auxImpacto[m] = impacto[p];
                    auxRiesgo[m] = riesgo[p];
                    p++;
                } else {
                    auxId[m] = id[q];
                    auxImpacto[m] = impacto[q];
                    auxRiesgo[m] = riesgo[q];
                    q++;
                }
            }
        }
    }
    while(p <= med) {  // En caso hayan elementos en la primera mitad
        auxId[m] = id[p];
        auxImpacto[m] = impacto[p];
        auxRiesgo[m] = riesgo[p];
        p++;
        m++;
    }
    while(q <= fin) {  // En caso hayan elementos en la segunda mitad
        auxId[m] = id[q];
        auxImpacto[m] = impacto[q];
        auxRiesgo[m] = riesgo[q];
        q++;
        m++;
    }
    for(int i = ini; i <=fin; i++) {  // Paso al arreglo original
        id[i] = auxId[i];
        impacto[i] = auxImpacto[i];
        riesgo[i] = auxRiesgo[i];
    }
}

void ordenarPorRiesgo(int id[], int impacto[], int riesgo[], int ini, int fin, int n) {
    if(ini == fin)
        return;

    int med = (ini + fin) / 2;
    ordenarPorRiesgo(id, impacto, riesgo, ini, med, n);
    ordenarPorRiesgo(id, impacto, riesgo, med + 1, fin, n);
    mergeRiesgo(id, impacto, riesgo, ini, med, fin, n);
}

void ordenarArreglo(int id[], int impacto[], int riesgo[], int n, int tipoOrdenamiento) {
    if(tipoOrdenamiento == 0) {  // Si el parametro es 0, ordeno por riesgo
        ordenarPorRiesgo(id, impacto, riesgo, 0, n-1, n);
        for(int i = 0; i < n; i++)
            cout << id[i] << "-" << impacto[i] << "-" << riesgo[i] << " ";
        cout << "por Nivel de Riesgo\n";
    } else if(tipoOrdenamiento == 1) {  // Si el parametro es 1, ordeno por impacto
        ordenarPorImpacto(id, impacto, riesgo, 0, n-1, n);
        for(int i = 0; i < n; i++)
            cout << id[i] << "-" << impacto[i] << "-" << riesgo[i] << " ";
        cout << "por Impacto\n";
    } else if(tipoOrdenamiento == 2){  // Si el parametro es 0, ordeno por id
        ordenarPorID(id, impacto, riesgo, 0, n-1, n);
        for(int i = 0; i < n; i++)
            cout << id[i] << "-" << impacto[i] << "-" << riesgo[i] << " ";
        cout << "por ID de Riesgo\n";
    } else {  // Si el parametro es cualquier otro numero, no hay ordenamiento
        cout << "Ingrese el tipo de ordenamiento correctamente\n";
    }
}

int main(int argc, char** argv) {
	int id[] = {4, 1, 5, 7, 6, 3 , 2};
    int impacto[] = {1, 2, 3, 2, 3, 2, 1};
    int riesgo[] = {3, 4, 9, 2, 6, 6, 2};
    int n = 7;

    cout << "Lista de riesgos: (ID - Impacto - Nivel de riesgo)\n";
    for(int i = 0; i < n; i++)
        cout << id[i] << "-" << impacto[i] << "-" << riesgo[i] << " ";
    cout << endl;
    
    // Creo mi funcion general, pasandole un parametro
    // para saber que ordenamiento realizar
    ordenarArreglo(id, impacto, riesgo, n, 0);
    ordenarArreglo(id, impacto, riesgo, n, 1);
    ordenarArreglo(id, impacto, riesgo, n, 2);

	return 0;
}
