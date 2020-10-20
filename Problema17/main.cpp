/*Problema 17. Dos números a y b (a != b) son amigables si la suma de los divisores de a (excluyéndose el mismo)
es igual a b, y viceversa. Ej: los divisores de 220 son 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 y 110; y suman 284. Los divisores
de 284 son 1, 2, 4, 71 y 142; y suman 220. Entonces 220 y 284 son amigables. Escribir un programa que reciba un
número y halle la suma de todos los números amigables menores al número ingresado.
Nota: la salida del programa debe ser:
El resultado de la suma es: 504.
*/
#include <iostream>

using namespace std;

bool amigable(int n);

int main(){

    int k=0, sum = 0;

    cout<<endl<<'\t'<<'\t'<<'\t'<<"      ...::: HOLA SEBASTIAN "<<endl;
    cout<<endl<<'\t'<<'\t'<<"   ...::: Numeros Amigables de un numero. "<<endl;
    cout<<endl<<'\t'<<'\t'<< "::: Ingrese un numero entero positivo: ";
    cin>>k;

    for(int i=0; i<k; i++)
        if(amigable(i)==true) //fuerza bruta, Hallar todos los numeros amigables menores que k
            sum += i;
    cout<<endl<<"...::: La suma de todos los numeros amigables menores que "<<k<<" es: "<<sum<<endl<<endl;
}


int sumDivisor(int n){
    int sum=0;
    for(int i=1; i<n; i++)   //El ciclo revisa todos enteros en el intervalo [1,n]
        if(n%i==0)
            sum+=i;     //Si i es divisor, es agregado a sum
    return sum;
}


bool amigable(int n){
    int amigo = 0;
    amigo = sumDivisor(n);   //amigo es la suma de los divisores de n
    if(n==sumDivisor(amigo)) //Si la  suma de los divisores de amigo es n, los numeros son amigables
        if(amigo != n)  //No contar los numeros perfectos, amigos de si mismos :'(
            return true;
    return false;
}
