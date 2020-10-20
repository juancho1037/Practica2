/*Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
y luego imprima cuantas veces se repite cada letra en el arreglo.*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using std::setw;
using std::setprecision;

using namespace std;

void llenar(char *letras);
void ContarLetras(char *letras);


// Esta función imprime 200 letras aleatorias.
int main()
{
    char *letras;
    char abcdario [200]={};
    letras = new char[200];
    letras = abcdario;

    cout<<setw(10)<<"...::: Arreglo de letras aleatorio: "<<endl<<endl;
    llenar(letras);
    cout<<endl<<endl;
    cout<<setw(10)<<"...::: Cantidad de letras en el Arreglo: "<<endl<<endl;
    ContarLetras(letras);

    delete letras;
    return 0;
}

void llenar(char *letras){

    srand(time(NULL));
    int num=0;

    for(unsigned short i = 0; i <200; i++){
        num = 65 + rand() % (89 - 65);//obtiene una letra al azar.
        char l=num;
        letras[i]=l;
        cout<<l<<setw(3);
    }
}

void ContarLetras(char *letras){

    char abc;
    int cont=0;
    abc=65;

    for(int i= 0; i <=50; i++){
        for(int j=0; j<=200; j ++){//cuenta las letras repetidas.
            if (letras[j]==abc){
                cont++;//Cuenta la cantidad de veces que la letra esta en el arreglo
            }
        }
        cout<<setw(5)<<abc<<" = "<<cont<<setw(5)<<endl;
        abc ++;
        i++;
        cont=0;
    }
    cout<<endl;
}
