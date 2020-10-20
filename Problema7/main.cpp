/*Problema 7. Escriba un programa que reciba una cadena de caracteres y elimine los caracteres repetidos.
Ejemplo: se recibe bananas debe mostrar bans.
Nota: la salida del programa debe ser: Original: bananas. Sin repetidos: bans.
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

void Eliminar(char *letras, char *res);

int main(){
    char cadena[20];
    char *letras=NULL;
    letras = new char[20];
    letras = cadena;

    char resultado[50]="";
    char *res=NULL;
    res = new char[50];
    res = resultado;

    cout<<endl<<"                  ...::: HOLA SEBASTIAN "<<endl<<endl;
    cout<<endl<<"...::: Eliminando caracteres repetidos en una cadena "<<endl;
    cout<<endl<<"               ...::: Ingrese una cadena: ";
    gets(cadena);
    cout<<endl<<"  ...::: la cadena original es: "<<cadena<<endl<<endl;

    Eliminar(letras, res);
    cout<<endl;

    delete letras; delete res;
    return 0;
}

void Eliminar(char *letras, char *res){

    short int i=0, j=0;
    while (letras[i]){ //recorre toda la frase que ingresa el usuario.
        if (!strchr(res,letras[i]))// devuelve NULL si no encuentra la cadena[i] en el resultado.
            res[j++]=letras[i];
        i++;
    }
    res[j]='\0';
    cout<<"  ...::: la cadena sin caracteres repetidos es: "<<res<<endl<<endl;
}
