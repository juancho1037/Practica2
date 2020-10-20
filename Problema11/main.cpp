/*Problema 11. Escriba un programa que permita manejar las reservas de asientos en una sala de cine, los asientos de
la sala de cine están organizados en 15 filas con 20 asientos cada una. El programa debe mostrar una representación
de la sala que indique que asientos están disponibles y cuales se encuentran reservados. Además debe permitir
realizar reservas o cancelaciones al ingresar la fila (letras A-O) y el número del asiento (números 1-20).
Donde + representa los asientos reservados y - representa los asientos disponibles.
*/
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

void imprimir(char **sala_cine);
void Menu();

char **sala_cine=NULL; //variable global para que todas las funciones la puedan modificar

int main()
{
    //Reserva de Memoria.
    sala_cine = new char*[21];
    for (short int a=0;a<21;a++) {
        sala_cine[a] = new char[15];
    }

    //Ciclos de llenado de mi matriz con los asientos de la sala de cine.
    for(int i=1;i<21;i++){
        for(int j=0;j<15;j++)
            sala_cine[i][j]='-';
    }

    imprimir(sala_cine);
    cout<<endl;
    Menu();

    //Eliminamos la memoria reservaba para sala_cine
    for (int a=0;a<21;a++) {
        delete [] sala_cine[a];
    }
    delete sala_cine;
    return 0;
}

void imprimir(char **sala_cine){

    cout<<endl<<"        ....:::: SISTEMA DE RESERVA DE ASIENTOS EN EL CINE "<<endl;
    cout<<endl<<"               .....::::: ASIENTOS DISPONIBLES"<<endl<<endl;
    short int num=1;
    cout<<"    ";
    for (short int n=0;n<1;n++) {
        for (short int col=1;col<21;col++) {
            if(num >=10)
                cout<<setw(3)<<num;
            else
                cout<<setw(2)<<num<<" ";
            num ++;
        }
    }
    cout<<endl;
    for (int i=0,l=0;i<15 && l<15;i++,l++){ //Ciclo de recorrido y/o impresion de las letras de cada fila del cine.
            *(*(sala_cine+0)+i)='A'+l;
    }
    for(int j=0;j<15;j++){ //Ciclo de recorrido de las filas para empezar a imprimir mi tablero de reservas
        for(int i=0;i<21;i++) //Ciclo de recorrido de las columnas para empezar a imprimir mi tablero de columnas
            cout<<setw(3)<<*(*(sala_cine+i)+j)<<setw(2); // Impresion de mi tablero.
        cout<<endl;
    }
}

void Menu(){

    int opcion ,silla;
    char fila;

    do {
        cout<<endl;
        cout<<'\t'<<'\t'<<":::  MENU:"<<endl<<"            1 - Resevar "<<endl<<"            2 - Cancelar "<<endl<<"            0 - Salir "<<endl<<endl;
        cout<<"            :::  ";
        cin>>opcion;

        switch(opcion){
        case 1:{
            cout<<'\t'<<"    :::  Ingrese la fila: "; cin>>fila;
            if(fila>111||((fila<97) && (fila>79))){
                cout<<'\t'<<":::  Por Favor ingrese una opcion valida "<<endl;
                break;
            }
            cout<<'\t'<<"    :::  Ingrese el numero de la silla: ";cin>>silla;
            if(silla>20){
                cout<<'\t'<<":::  Por Favor ingrese una opcion valida "<<endl;
                break;
            }
            if(fila>96 && fila<111)
                *(*(sala_cine+silla)+(fila-97))='+';
            else
                *(*(sala_cine+silla)+(fila-65))='+';
            imprimir(sala_cine);
            break;
        }

        case 2:{
            cout<<'\t'<<"    :::  Ingrese la fila: "; cin>>fila;
            if(fila>111||((fila<97) && (fila>79))){
                cout<<":::  Por Favor ingrese una opcion valida "<<endl;
                break;
            }
            cout<<'\t'<<"    :::  Ingrese el numero de la silla: "; cin>>silla;
            if(silla>20){
                cout<<'\t'<<"::: Ingrese una opcion valida "<<endl;
                break;
            }
            if(fila>96 && fila<111)
                *(*(sala_cine+silla)+(fila-97))='-';
            else
                *(*(sala_cine+silla)+(fila-65))='-';
            imprimir(sala_cine);
            break;
        }
        default:
            cout<<'\t'<<":::  Por Favor ingrese una opcion valida "<<endl;
        }
        system("cls");
        imprimir(sala_cine);
    }while (opcion != 0);
}

