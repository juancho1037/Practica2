/*Problema 15. Elabore un programa que permita hallar la intersección entre un par de rectángulos. Represente
los rectángulos como arreglos de 4 datos de la siguiente manera:
Los primeros 2 datos corresponden a las coordenadas de la esquina superior izquierda del rectángulo (x,y)
como se observa en la Figura 5.
Los siguientes 2 datos representan el ancho y la altura del rectángulo como se observa en la Figura 5.

Implemente una función que reciba 2 arreglos que representen los rectángulos A y B, y por referencia retorne un
rectángulo C (con la misma estructura descrita anteriormente) que corresponda a la intersección de A y B como se
observa en la Figura 6.
Ejemplo: Si se ingresan los rectángulos A y B representados por los arreglos {0, 0, 8, 4} y {5, 2, 6, 7}, el rectángulo
intersección C debe ser el arreglo {5, 2, 3, 2}.
*/
#include <iostream>
using namespace std;

bool intersection(int *r1, int *r2, int *IN);

int main(){

    int rec1[4], rec2[4], sec[4];    //rectangulos 1 y 2, sec corresponde a su interseccion

    cout<<endl<<"Ingrese el rectangulo 1 (x, y, ancho, alto). Un dato a la vez: "<<endl;
    for(int i = 0; i<4; i++){
        cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"...::: " ;
        cin>> *(rec1+i);
    }


    cout<<endl<<"Ingrese el rectangulo 2 (x, y, ancho, alto). Un dato a la vez: "<<endl;
    for(int i = 0; i<4; i++){
        cout<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"...::: " ;
        cin>> *(rec2+i);
    }


    cout<<endl<<"El rectangulo interseccion corresponde a: ";

    if(intersection(rec1,rec2,sec) == true)    // if true, se ha encontrado la interseccion
        cout<<"{"<<*(sec)<<","<<*(sec+1)<<","<<*(sec+2)<<","<<*(sec+3)<<"}"<<endl<<endl;

    else if (intersection(rec2,rec1,sec)== true) //vectores en orden contrario
        cout<<"{"<<*(sec)<<","<<*(sec+1)<<","<<*(sec+2)<<","<<*(sec+3)<<"}"<<endl<<endl;

    else cout<<endl<<"Interseccion vacia. "<<endl;  //Se han revisdo todos los casos, no hay interseccion

}


bool intersection(int *r1, int *r2, int *IN){        //r1={x,y,w,h}, r2={x',y',w'h'}

    if(*(r1)<= *(r2)){                               //si  x <= x'
        if(*(r1+1)>= *(r2+1)){                       //si  y >= y'
            if((*(r2)<=*(r1)+*(r1+2)) & (*(r2+1)>=*(r1+1)-*(r1+3))){      //si (x' <= x+w) & (y' >= y-h) hay interseccion
                *(IN)= *(r2);         // x', y' pertenecen a la interseccion
                *(IN+1)= *(r2+1);
                if(*(r2) + *(r2+2) <= *(r1)+*(r1+2)) //si x'+w' <= x + w
                    *(IN+2)= *(r2+2)  ;              //w' pertenece a la interseccion
                else *(IN+2)= *(r1)+*(r1+2)-*(r2);   // x+w-x' pertenece a la interseccion
                if(*(r2+1)-*(r2+3) >= *(r1+1)-*(r1+3)) // si y'-h' >= y-h
                    *(IN+3)= *(r2+3); //h' pertenece a la interseccion
                else *(IN+3)= -*(r1+1)+*(r1+3)+*(r2+1); // -y+h+y' pertenece a la interseccion
                return true;
            }
        }
        else{
            if((*(r2)<= *(r1)+*(r1+2)) & (*(r1+1)>= *(r2+1)-*(r2+3))){   //si (x' <= x+w) & (y >= y'-h') hay interseccion
                *(IN)=*(r2);         //x' pertenece a la interseccion
                *(IN+1)=*(r1+1);     //y  pertenece a la interseccion
                if(*(r1)+*(r1+2) <= *(r2)+*(r2+2)) //si x+w <= x'+w'
                    *(IN+2) = *(r1)+*(r1+2)-*(r2); // x+w-x' pertenece a la interseccion
                else *(IN+2) = *(r2+2);            //w' pertenece a la interseccion
                if(*(r1+1)-*(r1+3) <= *(r2+1)-*(r2+3)) // si y-h <= y'-h'
                    *(IN+3) = -*(r2+1)+*(r2+3)+*(r1+1);  //-y'+h'+y pertenece a la interseccion
                else *(IN+3) = *(r1+3); //h pertenece a la interseccion
                return true;
            }
        }

    }
    return false;
}
