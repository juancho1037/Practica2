/*Problema 12. Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
mágico.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;
void imprimirMatriz(int **matriz, int n);
void verificar(int **matriz, int n);

int **matriz=NULL;

int main()
{
    int n;
    cout<<endl<<"              ...::: Verificacion de una matriz, es magica o no?"<<endl;
    cout<<endl<<"     ...::: Ingrese la dimension (nxn) de la matriz cuadrada deseada: ";
    cin>>n;

    //Reserva de memoria para la matriz magica
    matriz = new int*[n];
    for (short int c=0;c<n;c++) {
        matriz[c] = new int[n];
    }

    //Llenado de la matriz por el usuario
    for(short int i=0;i<n;i++){
        for(short int c=0;c<n;c++){
            cout<<"       ....:::: Ingrese la posicion ["<<i<<"] ["<<c<<"]: ";
            cin>>*(*(matriz+i)+c);
        }
    }

    cout<<endl;
    imprimirMatriz(matriz,n);
    cout<<endl;
    verificar(matriz, n);
    cout<<endl;

    //Eliminamos la memoria reservaba para la matriz magica
    for (int a=0;a<21;a++) {
        delete [] matriz[a];
    }
    delete matriz;
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

void verificar(int **matriz, int n){
    int sumatoria=0,recordatorio=0,confirmacion=0;

    for(int f=0;f<n;f++){
        for(int co=0;co<n;co++){
            sumatoria+=matriz[f][co];
        }
        if (f==0){
            recordatorio=sumatoria;
        }
        else if (recordatorio!=sumatoria){
            confirmacion=1;
            cout<<"...::: la matriz ingresada no es un cuadrado magico "<<endl;
            break;
        }
        sumatoria=0;
    }
    if(confirmacion!=1){
        for(int co=0;co<n;co++){
            for(int f=0;f<n;f++){
                sumatoria+=matriz[f][co];
            }
            if (recordatorio!=sumatoria){
                confirmacion=1;
                cout<<"...::: la matriz ingresada no es un cuadrado magico "<<endl;
                break;
            }
            sumatoria=0;
        }
    }
    if(confirmacion!=1){
        for(int d=0;d<n;d++){
            sumatoria+=matriz[d][d];
        }
        if (recordatorio!=sumatoria){
            confirmacion=1;
            cout<<"...::: la matriz ingresada no es un cuadrado magico "<<endl;
        }
        else{
            cout<<"...::: la matriz si corresponde a la descripccion de cuadrado magico"<<endl;
        }
    }
}
