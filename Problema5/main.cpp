/*Problema 5. Haga una función que reciba un numero entero (int) y lo convierta a cadena de caracteres. Use
parámetros por referencia para retornar la cadena. Escriba un programa de prueba.
Ejemplo: si recibe un int con valor 123, la cadena que se retorne debe ser “123”.
*/

#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>

using namespace std;

//Creacion de manipulador de flujo personalizado
ostream& tab(ostream& salida){
    return salida<<'\t';
}

void Convertir(int numero,int digitos,char caracteres[]);

int main(){

   int numero;
   cout <<endl<<setw(45)<< "...::: HOLA SEBASTIAN" << endl<<endl;
   cout <<endl<< tab << tab << "...::: Ingrese un numero: ";
   cin>>numero;
   cout<<endl;
   int aux=numero,digitos=0;

   while(aux!=0){
        digitos+=1;//cuenta los digitos.
        aux=aux/10;
   }

   char caracteres[digitos];//crea una cadena de caracteres del tamaño de digitos que ingreso el usuario
   char *ptrC=NULL;

   ptrC = new char[digitos];
   ptrC = caracteres;

   Convertir(numero,digitos,ptrC);
   cout<<endl;

   delete ptrC;
}

void Convertir(int numero,int digitos,char caracteres[]){//Convierte el numero que ingresó el usuario a cadena.
    digitos=digitos-1;

    for(int i=0;i<=digitos;i++){
        int base=pow(10,(digitos-i));
        caracteres[i]=(numero/base)+48;//lo convierte en ASCII
        numero%=base;
    }
    cout<< tab <<caracteres<<endl; //Ingresa cada elemento como char en el arreglo.
}
