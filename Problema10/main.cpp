/*Problema 10. Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo

usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su equivalente ará-
bigo:

M: 1000
D: 500
C: 100
L: 50
X: 10
V: 5
I: 1
Los números romanos se forman usando estos caracteres en base a dos reglas:
Si un carácter esta seguido por uno de igual o menor valor, su valor se suma al total.
Si un carácter esta seguido por uno de mayor valor, su valor se resta del total.
Ejemplo: CC=200, CD=400, DC=600, DCLXVI=666, CLXXIV=174.
Nota: la salida del programa debe ser:
El número ingresado fue: DCLXVI
Que corresponde a: 666.
*/

#include <iostream>
#include <conio.h>
#include <cstring>

using namespace std;
void convertir( int &numero);
int buscar(char c);

int main()
{
    const int valor[8] = {00,1000,500,100,50,10,5,1};
    int resultado=0, i=0, ultimoV=0;

    bool bandera=true;

    char C[]="";
    char c;
    cout<<endl<<"                    ....:::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<"    .....::: Programa para convertir numeros Romanos a sistema arabigo "<<endl<<endl;
    cout<<"          ...::: Ingrese el numero, porfavor ingresar mayusculas: "; cin>>C;

    int dimension = strlen(C);

    while (bandera && i<dimension) {
        int posicion = 0;
        c=C[i];
        posicion = buscar(c);

        if (posicion>=0)
        {
            posicion+=1;
            resultado = resultado + valor[posicion];
            if(valor[posicion]>ultimoV){
                resultado -= 2*ultimoV;
            }
            ultimoV = valor[posicion];
        }
        else{
            bandera =false;
            resultado = -1;
        }
        i++;
    }
    cout<<endl<<"       ...::: El numero ingresado, convertido es: "<<resultado<<endl<<endl;
    return 0;
}

int buscar(char c){
    const char simbolo[8]={'M','D','C','L','X','V','I','\0'};
    for (short int i=0;i<8;i++) {
        if (c == simbolo[i])
            return i;
    }
}
