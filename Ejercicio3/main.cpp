/*Ejercicio 3. Se tiene la siguiente declaración e inicialización para el arreglo b:
unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
La Figura 1, que se presenta a continuación, ilustra la representación del arreglo b en memoria. Complete la
numeración de las direcciones de memoria, en notación hexadecimal, para cada elemento del arreglo b.

Determine de acuerdo a lo ilustrado en la Figura 1 el valor correspondiente de las siguientes expresiones:
b
b+2
*(b+2)
*(b+2)+1
*(*(b+2)+1)
b[3][1]
*b++
*
*/
#include <iostream>
using std::ostream;
using namespace std;

//Creacion de manipulador de flujo personalizado
ostream& tab(ostream& salida){
    return salida<<'\t';
}

int main()
{
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

    cout<<endl<< tab <<" La direccion de memoria : 0x0A12 "<<" = b[0][0] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A14 "<<" = b[0][1] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A16 "<<" = b[1][0] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A18 "<<" = b[1][1] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A1A "<<" = b[2][0] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A1C "<<" = b[2][1] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A1E "<<" = b[3][0] "<<endl;
    cout<<endl;
    cout<<endl<< tab <<" La direccion de memoria : 0x0A10 "<<" = b[3][1] "<<endl;
    cout<<endl;
    cout<<"____________________________________________"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" b =  0x0A12"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" b+2 = 0xA1A"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" *(b+2) = 0xA1A"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" *(b+2)+1 = 0xA1C"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" *(*(b+2)+1) = 39"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" b[3][1] = 3"<<endl;
    cout<<endl;
    cout<<endl<< tab <<" *b++ = Error."<<endl;
}
