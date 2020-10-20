/*Problema 3. Haga una función que compare 2 cadenas de caracteres y retorno un valor lógico verdadero si son
iguales y falso en caso contrario, no olvide también tener en cuenta la longitud de las cadenas. Escriba un programa
de prueba.
*/

#include <iostream>
#include <iomanip> //Libreria de control de flujo
#include <cstring> //Libreria de funciones para manipulacion y manejo de candenas
#include <stdlib.h> //libreria new y delete
using std::strcmp;
using std::setw;

using namespace std;
void Comprobar(char *palabra1,char *palabra2);

int main(){

    char *palabra1=NULL, *palabra2=NULL;
    char p1[20]="";
    char p2[20]="";

    palabra1 = new char[20];
    palabra2 = new char[20];
    palabra1 = p1;
    palabra2 = p2;

    cout<<endl<<setw(40)<< "...::: HOLA SEBASTIAN" << endl<<endl;

    cout<<"...::: Programa para verificar si dos palabras son iguales."<<endl<<endl;

    cout <<setw(40)<< "...::: Ingresa una palabra: ";
    cin>>p1;
    cout<<endl;
    cout <<setw(40)<< "...::: Ingresa otra palabra: ";
    cin>>p2;
    cout<<endl;

    Comprobar(palabra1,palabra2);
    cout<<endl;

    delete palabra1; delete palabra2;
    return 0;
}

void Comprobar(char *frase1,char *frase2){

    int valor=5;
    valor = strcmp(frase1,frase2);
    if(valor == 0)
        cout<<setw(50)<<"...::: Las palabras ingresadas son iguales"<<endl;
    else
        cout<<setw(50)<<"...::: Las palabras ingresadas son diferentes"<<endl;
}

