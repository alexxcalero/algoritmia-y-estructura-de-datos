/*
 * Proyecto : LAB2-2023_2-P2
 * Archivo  : main.cpp
 * Autor    : Alex Calero Revilla
 * Codigo   : 20206455
 * Fecha    : 4 de junio de 2024, 11:07
 */

#include <iostream>
#define N 7
#define NO_ENCONTRADO -1
using namespace std;

int encontrarSkyNerd(int matriz[N][N], int n, int candidato, int retador) {
    if((candidato == retador) || (retador >= n)) {
        int suma_col = 0, cant_ceros = 0;

        for(int fil = 0; fil < n; fil++)
            suma_col += matriz[fil][candidato];

        for(int col = 0; col < n; col++)
            if(matriz[candidato][col] == 0)
                cant_ceros++;

        // Retorno la posicion del candidato, que ahora hemos confirmado que es
        // SkyNerd, ya que la suma en esa columna da cero, y la cantidad de ceros
        // en su fila solo es uno, que seria el de el mismo, ya que no se envia
        // paquetes a el mismo
        if(suma_col == 0 && cant_ceros == 1)
            return candidato;
        else
            return NO_ENCONTRADO;
    }

    // Si el candidato no manda paquetes al retador, entonces el retador pasa a
    // ser SkyNerd. Caso contrario, el candidato sigue siendo candidato, y el
    // retador aumenta en uno su posicion para seguir comparando.
    if(matriz[candidato][retador] == 0)
        return encontrarSkyNerd(matriz, n, retador, retador + 1);
    else
        return encontrarSkyNerd(matriz, n, candidato, retador + 1);
}

int main(int argc, char** argv) {
	int matriz[N][N] = {{0  , 0 , 0 , 0 , 0, 0  , 0 },
                        {10 , 0 , 20, 30, 0, 20 , 40},
                        {0  , 0 , 0 , 0 , 0, 100, 0 },
                        {0  , 0 , 0 , 0 , 0, 80 , 0 },
                        {50 , 10, 5 , 10, 0, 100, 4 },
                        {100, 0 , 0 , 0 , 0, 0  , 0 },
                        {0  , 0 , 0 , 0 , 0, 0  , 0 }};

//    int matriz[N][N] = {{0  , 10, 10, 10, 20, 10 , 10},
//                        {10 , 0 , 20, 30, 0 , 20 , 40},
//                        {0  , 0 , 0 , 0 , 0 , 100, 0 },
//                        {0  , 0 , 0 , 0 , 0 , 80 , 0 },
//                        {50 , 10, 5 , 10, 0 , 100, 4 },
//                        {100, 0 , 0 , 0 , 0 , 0  , 0 },
//                        {0  , 0 , 0 , 0 , 0 , 0  , 0 }};

	int n = 7;
    int pos_sky_nerd = encontrarSkyNerd(matriz, n, 0, 1);

    if(pos_sky_nerd == NO_ENCONTRADO)
        cout << "SkyNerd no esta en la red\n";
    else
        cout << "SkyNerd ha sido detectado en el servido: " << pos_sky_nerd + 1 << '\n';

	return 0;
}
