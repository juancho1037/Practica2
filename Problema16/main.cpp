/*Problema 16. En una malla de 2x2, realizando únicamente movimientos hacia la derecha y hacia abajo hay 6
posibles caminos para llegar de la esquina superior izquierda a la inferior derecha como se observa en la Figura 7.
Escriba un programa que reciba un numero n y calcule el número de caminos posibles en una cuadricula de nxn.
Nota: la salida del programa debe ser:
Para una malla de 2x2 puntos hay 6 caminos.
*/
#include <iostream>
using namespace std;


double factorial(int n);

int main(){

    int k=0; //tamaño de la cuadricula
    double caminos=0;  //Numero de caminos posibles en la malla


    cout<<endl<<'\t'<<'\t'<<'\t'<<"             ...::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<'\t'<<'\t'<<"   ...::: Caminos posibles para una cuadricula de dimension nxn. "<<endl;
    cout<<endl<<'\t'<<'\t'<<"   ...:::  Ingrese la dimension de la cuadricula, entero positivo: ";
    cin>>k;

    if(k>=0){
        caminos = factorial(2*k)/(factorial(k)*factorial(k));  //caminos = (2k)!/(k!k!)
        cout<<endl<<'\t'<<'\t'<<"         ...:::  Para una malla de "<<k<<"x"<<k<<" existen "<<caminos<<" caminos."<<endl<<endl;
    }
}

double factorial(int n){
    double fac = 1;         //Factorial inicia en 1 porque 0!=1
    for(int i = 1; i<=n ; i++)
        fac *=i;               // n! = n*(n-1)*(n-2)...*2*1
    return fac;
}
