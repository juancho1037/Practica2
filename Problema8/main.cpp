/*Problema 8. Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
generando una cadena que no tiene números y otra con los números que había en la cadena original.
Ejemplo: Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
Nota: la salida del programa debe ser:
Original: abc54rst.
Texto: abcrst. Numero: 54.
*/
#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;

void Separar(char *mezcla,char *numeros, char *letras ,int longitud);


int main(){

    int longitud;
    char original [100]={};
    char *mezcla=NULL, *numeros=NULL, *letras=NULL;

    mezcla = new char[100];
    mezcla = original;

    cout<<endl<<'\t'<<'\t'<<"   ...::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<'\t'<<'\t'<<"...::: Ingrese una palabra: ";
    gets(original);
    longitud=strlen(original); //dice la longitud del arreglo.

    char num [100]={};
    numeros = new char[100];
    numeros = num;

    char letr [100]={};
    letras = new char [100];
    letras = letr;

    cout<<endl;
    Separar(mezcla, numeros, letras, longitud);
    cout<<endl;

    delete mezcla; delete numeros; delete letras;
    return 0;
}

void Separar(char *mezcla, char *numeros, char *letras ,int longitud){

    int n=0;
    int l=0;

    for(int i=0; i<longitud; i ++){ //Ciclo para separar los numeros del arreglo inicial
        if (mezcla[i]>=48 and mezcla[i]<=57){
            numeros[n]=mezcla[i];
            n++;
        }
        else if ((mezcla[i]<=90 && mezcla[i]>=65) || (mezcla[i]<=122 && mezcla[i]>=97)){
            letras[l]=mezcla[i];
            l++;
        }
    }
    cout<<endl<<'\t'<<'\t'<<"...::: Texto: "<<letras<<"  "<<"...::: Numeros: "<<numeros<<endl;
}
