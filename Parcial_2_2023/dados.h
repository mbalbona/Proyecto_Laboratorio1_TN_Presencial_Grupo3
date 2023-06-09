#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

void dibujarCuadrado(int posx ,int posy);
void dibujarDado(int,int,int);
void dibujarPuntos(int,int,int);


#include<iostream>
#include "rlutil.h"
using namespace std;
#include "dados.h"

    ///Funcion para dibujar
void dibujarCuadrado(int posx,int posy){
rlutil:: setColor(rlutil::WHITE);
for(int x=0;x<7;x++){
   for(int y=0;y<3;y++){
//llamo y uso la libreria
 rlutil::locate(x+posx, y+posy);
        cout<<(char) 219<<endl;
   }
}
}
//funcion para dibujar dado
void dibujarDado(int numero,int posx,int posy ){
dibujarCuadrado(posx,posy);
dibujarPuntos( numero, posx, posy);
}

//dibujar puntos.
void dibujarPuntos(int numero,int posx,int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
switch(numero){
case 1:
    rlutil::locate(posx+3, posy+1);
    cout<<(char) 254;
    break;

case 2:

    rlutil::locate(posx+5, posy+1);
    cout<<(char) 220;
    break;
    rlutil::locate(posx+1,posy+2);
    cout<<(char) 223;
    break;

}




}
#endif // DADOS_H_INCLUDED
