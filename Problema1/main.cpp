/*
 * Se necesita un programa que permita determinar la m�nima combinaci�n de billetes y monedas para
una cantidad de dinero determinada. Los billetes en circulaci�n son de $50.000, $20.000, $10.000, $5.000, $2.000
y $1.000, y las monedas son de $500, $200, $100 y $50. Hacer un programa que entregue el n�mero de billetes
y monedas de cada denominaci�n para completar la cantidad deseada. Si por medio de los billetes y monedas
disponibles no se puede lograr la cantidad deseada, el sistema deber� decir lo que resta para lograrla. Use arreglos
y ciclos para realizar el programa.*/
#include <iostream>
#include <iomanip>
using std::setw;
using std::setprecision;

using namespace std;

//Prototipo de la Funcion
void MonedasADevolver(const int *, int dinero);

int main()
{
    const int denominacion[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int dinero;

    cout<< "                              ...::: HOLA SEBASTIAN"<<endl<<endl;
    cout<< "    .....::: Calculo de cambio de billetes y monedas para una cantidad de dinero."<<endl<<endl;
    cout << "                            ...::: Ingrese un valor: ";cin>>dinero; cout<< endl;


    MonedasADevolver(denominacion,dinero); //le entregamos a nuestra funcion el arreglo y la cantidad de dinero que ingresa el usuario
    return 0;
}

//Definicion de la Funcion
void MonedasADevolver(const int *denominacion, int dinero)
{
    for(int i=0;i<10;i++){
        int cantidad= dinero/(*(denominacion+i));
        cout<<setw(45)<<*(denominacion+i)<<": "<<cantidad<<endl;
        dinero%=*(denominacion+i);
    }
    cout<<endl;
    cout<<setw(47)<<"Resto: "<<dinero<<endl;
}
