/*Problema 6. Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por ma-
yúsculas, los demás caracteres no deben ser alterados.

Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
Nota: la salida del programa debe ser: Original: Man-zana. En mayuscula: MAN-ZANA.
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using std::setw;

using namespace std;

void Cambiar(char *arreglo, int longitud);

int main(){
    int longitud;
    char arreglo [50]={};

    cout<<endl<<'\t'<<'\t'<<'\t'<<"      ...::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<'\t'<<'\t'<<"...::: Cambiando letras minusculas por mayusculas "<<endl;
    cout<<endl<<'\t'<<'\t'<<'\t'<<"   ...::: Ingrese una palabra: "; gets(arreglo); cout<<endl<<endl;

    longitud=strlen(arreglo);    // Obtenemos la longitud del arreglo.

    Cambiar(arreglo,longitud);
    cout<<endl;
    return 0;
}

void Cambiar(char *arreglo, int longitud){

    char letra;
    cout<<setw(30);

    for(int i=0; i<longitud; i ++){
        letra=arreglo[i];

        if (arreglo[i]<=122 and arreglo[i]>=97){
            arreglo[i]=arreglo[i]-32;
            letra=arreglo[i];
            cout<<letra;
        }
        else{
            letra=arreglo[i];
            cout<<letra;
        }
    }
    cout<<endl<<endl;
}
