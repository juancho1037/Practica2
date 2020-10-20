/*Problema 14. Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
imprima la matriz rotada 90, 180 y 270 grados.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>
using std::setw;
using std::setprecision;

using namespace std;

void imprimirMatriz(int **matriz, int n);
void rotarMatriz(int **matriz, int **matrizR, int n);
void llenar(int **matriz, int n);

int **matriz=NULL, **matrizR=NULL;; //Definimos puntero tipo matriz

int main()
{
    int n = 0;
    cout<<endl<<"                    ....:::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<" .....::: Programa para Rotar una matriz de dimension (nxn)"<<endl<<endl;
    cout<<"         ....:::: Ingrese la dimesion de la matriz: ";cin>>n;

    //Reservamos memoria para la matriz original
    matriz = new int *[n];
    for (int i=0;i<n;i++) {
        matriz[i] = new int[n];
    }

    //Reservamos memoria para la matrizR donde se almacenara la matriz rotada
    matrizR = new int *[n];
    for (int i=0;i<n;i++) {
        matrizR[i] = new int[n];
    }

    int num =1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            *(*(matriz+i)+j) = num; //puntero matriz [i][j]
            num++;
        }
    }

    cout<<endl<<"...::: Matriz original:"<<endl;
    imprimirMatriz(matriz, n);cout<<endl;

    cout<<endl<<"...::: Matriz rotada 90 grados "<<endl;
    rotarMatriz(matriz, matrizR,n);cout<<endl;
    imprimirMatriz(matrizR,n);
    cout<<endl;

    cout<<endl<<"...::: Matriz rotada 180 grados "<<endl;
    rotarMatriz(matrizR, matriz,n);cout<<endl;
    imprimirMatriz(matriz,n);
    cout<<endl;

    cout<<endl<<"...::: Matriz rotada 270 grados "<<endl;
    rotarMatriz(matriz, matrizR,n);cout<<endl;
    imprimirMatriz(matrizR,n);
    cout<<endl;

    //Eliminamos la memoria reservaba para matriz original
    for (int a=0;a<n;a++) {
        delete [] matriz[a];
    }
    delete matriz;

    //Eliminamos la memoria reservaba para matrizR
    for (int a=0;a<n;a++) {
        delete [] matrizR[a];
    }
    delete matrizR;
    cout<<endl;
    return 0;
}

void imprimirMatriz(int **matriz, int n){
    for (int a=0;a<n;a++) {
        cout<<setw(10)<<endl;
        for (int b=0;b<n;b++) {
            if(n*n>=100){ //Condiciones sobre el indice de la matriz para imprimirla correctamente
                if(*(*(matriz+a)+b)>=100)
                    cout <<setw(4)<< *(*(matriz+a)+b) <<setw(2);
                else if(*(*(matriz+a)+b)>=10)
                    cout <<setw(4)<< *(*(matriz+a)+b)<<setw(3);
                else
                    cout <<setw(4)<< *(*(matriz+a)+b) <<setw(3); //Cuando los numeros solo son de un digito
            }
            else{        //Condiciones sobre el indice de la matriz cuando la dimension es menor a 100
                if(*(*(matriz+a)+b)>=10)
                    cout <<setw(4)<< *(*(matriz+a)+b)<<setw(3);
                else
                    cout <<setw(4)<< *(*(matriz+a)+b) <<setw(2);
            }
        }
    }
}

void rotarMatriz(int **matriz, int **matrizR, int n){   //matriz original, matrizR rotada

    for (short int fr=0, fo=0 ; fr<n ; fr++, fo++) { //Ciclo para recorrer las dos filas de las matrices al tiempo
        for (short int cr=0, co=n-1; cr<n ; cr++, co--) { //Ciclo para recorrer las columnas de las matrices al tiempo
            (*(*(matrizR+fr)+cr)) = (*(*(matriz+co)+fo));
        }
    }
}


void llenar(int **matriz, int n){

    for(int i = 0; i<n ; i++){ //Creacion de la matriz original nxn
        for(int j = 0 ; j<n ; j++){
            *(*(matriz+i)+j) = 0;
        }
    }
}
