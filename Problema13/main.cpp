/*Problema 13. Se tiene una fotografía digitalizada de una porción de la galaxia NGC 1300 que está ubicada a
61.000.000 de años luz del planeta Tierra. La representación digital de la imagen está constituida por una matriz
de números enteros; en la cual, cada uno representa la cantidad de luz en ese punto de la imagen, así:

0  3   4  0   0  0  6   8
5  13  6  0   0  0  2   3
2  6   2  7   3  0  10  0
0  0   4  15  4  1  6   0
0  0   7  12  6  9  10  4
5  0   6  10  6  4  8   0

Elabore y pruebe una función que reciba un puntero a la matriz de enteros como argumento y que retorne el número
de estrellas encontradas en la imagen. Ignore las posibles estrellas que puedan existir en los bordes de la matriz.

*/

#include <iostream>

using namespace std;

int ContarEstrellas(int (*array)[8],int filas,int columnas);

int main(){

    cout<<endl<<"                    ....:::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<"    .....::: Programa para contar estrellas en una imagen "<<endl<<endl;

    int matriz[6][8] ={{0,3,4,0,0,0,6,8},{5,13,6,0,0,0,2,3},{2,6,2,7,3,0,10,0},{0,0,4,15,4,1,6,0},{0,0,7,12,6,9,10,4},{5,0,6,10,6,4,8,0}};
    int numEstrellas=ContarEstrellas(matriz,6,8);

    cout << "           ...::: Hay " <<numEstrellas<<" estrellas en la imagen."<< endl<<endl;
}

int ContarEstrellas(int (*array)[8],int filas, int columnas){

    int estrellas = 0;
    for(int i=1;i<filas-1;i++){
        for(int j=1;j<columnas-1;j++){
            int estrella=(*(*(array+i)+j) + *(*(array+i)+(j-1)) + *(*(array+i)+(j+1)) + *(*(array+(i+1))+j) + *(*(array+(i-1))+j))/5;
            if(estrella >6)estrellas++;
        }
    }
    return estrellas;
}


