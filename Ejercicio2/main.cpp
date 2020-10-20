/*
La función que se ilustra a continuación calcula el promedio de los elementos de un arreglo de tamaño
n. promedio y suma apuntan a variables que la función modifica por referencia. Desafortunadamente, la función
contiene errores; encuéntralos y corrígelos, de tal manera que su operación sea correcta.

void fun_c(double *a, int n, double *promedio, double *suma)
{
    int i;
    suma = 0.0;
    for (i = 0; i < n; i++)
    suma += (a + i);
    promedio = suma / n;
}
*/


#include <iostream>

using namespace std;

//Prototipo de la funcion
void fun_c(int *a, int n, int *promedio, int *suma);

int main(){

    int n, prom=0,sum=0;
    int *a;//apuntador al valor
    int *promedio=&prom;
    int *suma=&sum;
    cout<<endl<<'\t'<< "...::: Calculo del promedio de los elementos de un arreglo. "<<endl;
    cout<<endl<<'\t'<<"            ...::: Ingrese el tamano del arreglo: ";cin>>n;
    cout<<endl;

    int array[n];
    array[0]=0;
    a=&(array[0]);
    fun_c(a , n , promedio , suma);
    cout<<"                                 ...::: promedio: "<<*promedio<<endl<<endl;
}

void fun_c(int *a, int n, int *promedio, int *suma){
    *suma = 0.0;
    for (int i = 0; i < n; i++){
        *suma += (*a + i);
    }
    *promedio = *suma / n;
}
