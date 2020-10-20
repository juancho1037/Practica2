/*Problema 4. Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
y retorne dicho número. Escriba un programa de prueba.
Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123.
*/
#include <iostream>
#include <iomanip> //Libreria de control de flujo
#include <cstring> //Libreria de funciones para manipulacion y manejo de candenas
#include <stdlib.h> //libreria new y delete
using std::strcmp;
using std::setw;

using namespace std;


int main(){

    char *palabra1=NULL;
    char p1[20]="";
    palabra1 = new char[20];
    palabra1 = p1;

    long long int num=0;

    cout <<endl<<setw(45)<< "...::: HOLA SEBASTIAN" << endl<<endl;

    cout<<"...::: Programa para convertir una cadena de caracteres numericos a enteros."<<endl<<endl;

    cout <<setw(55)<< "...::: Ingresa la cadena de numeros: ";
    cin>>p1;
    cout<<endl;

    num = atoi(palabra1);

    cout << "...::: Ingrese un numero entero para operar con el anterior numero ingresado: ";
    int prueba=0, suma=0;
    cin>>prueba;
    suma = num+prueba;  //se realiza una suma para demostrar que el numero efectivamente es un entero.
    cout<<endl;
    cout <<setw(55)<< "....:::: El resultado de la prueba es:   " << suma <<endl<<endl;

    delete palabra1;
    return 0;
}

