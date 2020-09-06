//Enunciado.
/*
Con ayuda del debugger, examine la representación en memoria del arreglo array y responda las siguientes preguntas.
1.1 ¿Cuál es su dirección en memoria?
1.2 ¿Cuántos bytes se dedican para almacenar cada elemento de array?
2. ¿Cuál es la dirección y el contenido en memoria del elemento array[3]?
3. Describa el efecto que tiene la función fun_b, sobre el arreglo array.
*/

#include <iostream>
using namespace std;

//Prototipo de funciones

void fun_a(int *px, int *py);
void fun_b(int a[], int tam);


int main()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    fun_b(array, 10);

    cout<<"1.1 ¿Cuál es su dirección en memoria?"<<endl;
    cout<<"Respuesta:la direccion de memoria de Array es: "<< &array<<endl;

    cout<<"¿Cuántos bytes se dedican para almacenar cada elemento de array?"<<endl;
    cout<<"Respuesta: Se dedican 2 bytes para almacenar cada elemento del array."<<endl;

    cout<<"¿Cuál es la dirección y el contenido en memoria del elemento array[3]?"<<endl;
    cout<<"Respuesta: La direccion de memoria de Array[3] es:"<<&array[3]<<"y el contenido de array[3]:"<<array[3]<<endl;

    cout<<"Describa el efecto que tiene la función fun_b, sobre el arreglo array:"<<endl;
    cout<<"La funcion b lo que hace es intercambiar los datos que estan almacenados\n";
    cout<<"en el arreglo array, los que estan de primeros los pone de ultimos y los\n";
    cout<<"que estan de ultimos los pone de primeros.\n";
}

//Definicion de funciones

void fun_a(int *px, int *py) //Esta funcion recibe dos apuntadores por valor a enteros
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam) //Esta funcion recibe un arreglo de enteros y un entero.
{
    int f, l;
    int *b = a;
    for (f = 0, l = tam -1; f < l; f++, l--)
    {
    fun_a(&b[f], &b[l]);
    }
}
