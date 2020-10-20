/*Problema 18. Las permutaciones lexicográficas son permutaciones ordenadas numérica o alfabéticamente, por
ejemplo las permutaciones lexicográficas de 0,1 y 2 son: 012, 021, 102, 120, 201, 210. Escribir un programa que
reciba un número n y halle la enésima permutación lexicográfica de los números entre 0 y 9.
Ejemplo: para n= 1000000, la permutación lexicográfica es 2783915460.
Nota: la salida del programa debe ser:
La permutacion numero 1000000 es: 2783915460.
*/
#include <iostream>
using namespace std;

long long factorial(int n);
int popD(int *digitos, int i);
int entrada(int *k, int tam);


int main(){
    int k=0, opcion=0;

    do {
        cout<<endl<<'\t'<<'\t'<<'\t'<<"      ...::: HOLA SEBASTIAN "<<endl;
        cout<<endl<<'\t'<<'\t'<<"  ...::: Enesima permutacion lexicografica "<<endl;
        cout<<endl<<'\t'<<'\t'<<'\t'<<"               .: MENU :. "<<endl;
        cout<<'\t'<<'\t'<<'\t'<<" 1. Permutaciones lexicograficas. "<<endl;
        cout<<'\t'<<'\t'<<'\t'<<" 2. Salir. "<<endl;

        cout<<endl;
        cout<<'\t'<<'\t'<<"...::: Ingresar la opcion: ";
        cin>>opcion;

        switch (opcion) {
        case 1: {
            cout<<'\t'<< "...::: Ingrese el indice la permutacion que desea: ";
            cin>>k;
            int digitos [10]={0,1,2,3,4,5,6,7,8,9};
            int q=0;
            if((k<1) || (k>factorial(10)))    //solo existen 10! permutaciones (3628800)
                cout <<endl<< ":::   La permutacion numero "<<k<<" no existe" <<endl;
            else{
                cout<<endl<< ":::    La permutacion numero "<<k<<" es: ";
                for(int i=9; i>=0; i--){     //Cada ciclo del loop haya una cifra de la permutacion pedida
                    q = entrada(&k,i);       //q, posicion del arreglo donde se encuentra la cifra requerida
                    cout << popD(digitos,q);  //Imprimir la cifra, y borrarla del arreglo
                }
                cout<<endl;
            }
            system("pause");
            break;}
            cout<<endl;
        }
        system("cls");
    } while (opcion != 2);
}

long long factorial(int n){    //Se requiere suficiente espacio para procesar factoriales grandes.
    long long fac = 1;         //Factorial inicia en 1 porque 0!=1
    for(int i = 1; i<=n ; i++)
        fac *=i;               // n! = n*(n-1)*(n-2)...*2*1
    return fac;
}

int popD(int *digitos, int i){ //solo funciona para arreglos con 10 posiciones
    int a = *(digitos+i);
    for(int i=0; i<9; i++)
        *(digitos+i) = *(digitos+i+1);
    return a;               //retorna el elemento eliminado
}

int entrada(int *k, int tam){ //k-esima permutacion, tamaño del arreglo -1
    int r = 0;                //k indice de permutacion inicial, r indice de permutacion restante
    for(int q=1; q<=tam; q++){
        r = *k - q*factorial(tam);  // r = k - q*tam!
        if((0<r) & (r <= factorial(tam))){   //simpre y cuando 0 < r <= tam!
            *k = r;                       //retornar r por referencia, modificando k
            return q;                     //retornar el indice correspondiente
        }
    }
    return 0;
}
