/*Problema 9. Escribir un programa que reciba un número n y lea una cadena de caracteres numéricos, el programa
debe separar la cadena de caracteres en números de n cifras, sumarlos e imprimir el resultado. En caso de no poderse
dividir exactamente en números de n cifras se colocan ceros a la izquierda del primer número.
Ejemplo: Si n=3 y se lee el arreglo 87512395 la suma seria 087+512+395=994.
Nota: la salida del programa debe ser:
Original: 87512395.
Suma: 994.
*/

#include <iostream>
#include <math.h>

using namespace std;

int SumarNumeros(int cifras,int contador,char array[]);

int main()
{
    int cifras,cont=0, Ceros=0;

    char numeros[50];
    cout<<endl<< "...::: Ingrese una cadena de solo numeros: ";
    cin>>numeros;

    cout<<endl<<"        ...::: Ingrese un numero n(cifras): ";
    cin>>cifras;
    cout<<endl<<"                           ...::: Original: "<<numeros<<endl;

    while(1){
        if(numeros[cont]=='\0') break; //Contamos los digitos que tiene la cadena ingresada
        cont++;
    }
    if(cont%cifras!=0){ //primera condicion, si no quedan en grupos de igual tamanio, agregar ceros
        while((cont+Ceros)%cifras!=0){
            Ceros++;
        }
        char c2[cont+Ceros];
        for(int i=0;i<Ceros;i++){
            c2[i]='0';

        }
        for(int j=0;j<cont;j++){
            c2[j+Ceros]=numeros[j];
        }
        int cont1=cont+Ceros;
        cout<<"                               ...::: Suma: "<<SumarNumeros(cifras,cont1,c2)<<endl;
    }
    else{
        cout<<"                               ...::: Suma: "<<SumarNumeros(cifras,cont,numeros)<<endl;
    }
    cout<<endl;
    return 0;
}

int SumarNumeros(int cifras,int contador,char array[]){
    int aux=0,suma=0;
    while(aux<contador){
        for(int i=0;i<cifras;i++){
            suma+=(array[i+aux]-'0')*pow(10,cifras-(i+1));
        }
        aux+=cifras;
    }
    return suma;
}
