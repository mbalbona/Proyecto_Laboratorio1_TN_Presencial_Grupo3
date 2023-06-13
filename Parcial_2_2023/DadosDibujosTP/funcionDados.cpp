#include<iostream>
#include "rlutil.h"
using namespace std;
#include "dados.h"

    ///Funcion para dibujar
void dibujarCuadrado(int posx,int posy){
rlutil:: setColor(rlutil::WHITE);
for(int x=0;x<8;x++){
   for(int y=0;y<4;y++){
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
    rlutil::locate(posx+0, posy+1);
    cout<<(char) 254;
   rlutil::locate(posx+1, posy+1);
    cout<<(char) 223;
      rlutil::locate(posx+2, posy+0);
    cout<<(char) 220;
      rlutil::locate(posx+3, posy+0);
    cout<<(char) 254;
      rlutil::locate(posx+3, posy+1);
    cout<<(char) 219;
        rlutil::locate(posx+3, posy+2);
    cout<<(char) 219;
      rlutil::locate(posx+3, posy+3);
    cout<<(char) 223;


    break;

case 2:

    rlutil::locate(posx+0, posy+0);
    cout<<(char) 220;
     rlutil::locate(posx+1, posy+0);
    cout<<(char) 223;
      rlutil::locate(posx+2, posy+0);
    cout<<(char) 223;
     rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+4, posy+0);
    cout<<(char) 254;
       rlutil::locate(posx+4, posy+1);
    cout<<(char) 219;
    rlutil::locate(posx+4, posy+2);
    cout<<(char) 223;
     rlutil::locate(posx+3, posy+2);
    cout<<(char) 223;
     rlutil::locate(posx+2, posy+2);
    cout<<(char) 254;
     rlutil::locate(posx+1, posy+2);
    cout<<(char) 254;
      rlutil::locate(posx+0, posy+2);
    cout<<(char) 220;
     rlutil::locate(posx+0, posy+3);
    cout<<(char) 254;
         rlutil::locate(posx+1, posy+3);
    cout<<(char) 254;
         rlutil::locate(posx+2, posy+3);
    cout<<(char) 254;
      rlutil::locate(posx+3, posy+3);
    cout<<(char) 254;
  rlutil::locate(posx+4, posy+3);
    cout<<(char) 254;
  rlutil::locate(posx+5, posy+3);
    cout<<(char) 254;

    break;
    case 3:
      rlutil::locate(posx+0, posy+0);
    cout<<(char) 254;
          rlutil::locate(posx+1, posy+0);
    cout<<(char) 223;
      rlutil::locate(posx+2, posy+0);
    cout<<(char) 223;
      rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
        rlutil::locate(posx+4, posy+0);
    cout<<(char) 220;
  rlutil::locate(posx+4, posy+1);
    cout<<(char) 219;
      rlutil::locate(posx+3, posy+1);
    cout<<(char) 220;
       rlutil::locate(posx+2, posy+1);
    cout<<(char) 220;
      rlutil::locate(posx+4, posy+2);
    cout<<(char) 219;
      rlutil::locate(posx+3, posy+3);
    cout<<(char) 223;
      rlutil::locate(posx+2, posy+3);
    cout<<(char) 223;
        rlutil::locate(posx+1, posy+3);
    cout<<(char) 223;
       rlutil::locate(posx+0, posy+3);
    cout<<(char) 223;
    break;

     case 4:
           rlutil::locate(posx+0, posy+1);
    cout<<(char) 220;
     rlutil::locate(posx+1, posy+1);
    cout<<(char) 254;
     rlutil::locate(posx+2, posy+1);
    cout<<(char) 223;
    rlutil::locate(posx+3, posy+0);
    cout<<(char) 220;
       rlutil::locate(posx+4, posy+0);
    cout<<(char) 254;
     rlutil::locate(posx+5, posy+0);
    cout<<(char) 219;
      rlutil::locate(posx+5, posy+1);
    cout<<(char) 219;
    rlutil::locate(posx+5, posy+2);
    cout<<(char) 219;
    rlutil::locate(posx+5, posy+3);
    cout<<(char) 219;
      rlutil::locate(posx+0, posy+2);
    cout<<(char) 223;
      rlutil::locate(posx+1, posy+2);
    cout<<(char) 223;
       rlutil::locate(posx+2, posy+2);
    cout<<(char) 223;
      rlutil::locate(posx+3, posy+2);
    cout<<(char) 223;
  rlutil::locate(posx+4, posy+2);
    cout<<(char) 223;

    break;
     case 5:
          rlutil::locate(posx+0, posy+0);
    cout<<(char) 219;
         rlutil::locate(posx+1, posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+2, posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
       rlutil::locate(posx+4, posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+5, posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+6, posy+0);
    cout<<(char) 223;
       rlutil::locate(posx+0, posy+1);
    cout<<(char) 219;
      rlutil::locate(posx+1, posy+1);
    cout<<(char) 220;
          rlutil::locate(posx+2, posy+1);
    cout<<(char) 220;
          rlutil::locate(posx+3, posy+1);
    cout<<(char) 220;
          rlutil::locate(posx+4, posy+1);
    cout<<(char) 220;
      rlutil::locate(posx+5, posy+1);
    cout<<(char) 220;
          rlutil::locate(posx+6, posy+2);
    cout<<(char) 219;
      rlutil::locate(posx+6, posy+3);
    cout<<(char) 223;
      rlutil::locate(posx+0, posy+3);
    cout<<(char) 220;
     rlutil::locate(posx+1, posy+3);
    cout<<(char) 220;
 rlutil::locate(posx+2, posy+3);
    cout<<(char) 220;
 rlutil::locate(posx+3, posy+3);
    cout<<(char) 220;
     rlutil::locate(posx+4, posy+3);
    cout<<(char) 220;
     rlutil::locate(posx+5, posy+3);
    cout<<(char) 220;
    break;
     case 6:
         rlutil::locate(posx+0, posy+0);
    cout<<(char) 219;
     rlutil::locate(posx+1, posy+0);
    cout<<(char) 223;
     rlutil::locate(posx+2, posy+0);
    cout<<(char) 223;
     rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
 rlutil::locate(posx+4, posy+0);
    cout<<(char) 223;
     rlutil::locate(posx+5, posy+0);
    cout<<(char) 219;
    rlutil::locate(posx+0, posy+1);
    cout<<(char) 219;
       rlutil::locate(posx+0, posy+2);
    cout<<(char) 219;
       rlutil::locate(posx+0, posy+3);
    cout<<(char) 219;
         rlutil::locate(posx+1, posy+3);
    cout<<(char) 220;
       rlutil::locate(posx+2, posy+3);
    cout<<(char) 220;
       rlutil::locate(posx+3, posy+3);
    cout<<(char) 220;
       rlutil::locate(posx+4, posy+3);
    cout<<(char) 220;
       rlutil::locate(posx+5, posy+3);
    cout<<(char) 219;
    rlutil::locate(posx+5, posy+2);
    cout<<(char) 219;
     rlutil::locate(posx+1, posy+2);
    cout<<(char) 223;
      rlutil::locate(posx+2, posy+2);
    cout<<(char) 223;
  rlutil::locate(posx+3, posy+2);
    cout<<(char) 223;
  rlutil::locate(posx+4, posy+2);
    cout<<(char) 223;
break;
     case 7:

    cout<<(char) 223;
      rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
      rlutil::locate(posx+4, posy+0);
    cout<<(char) 223;
          rlutil::locate(posx+5, posy+0);
    cout<<(char) 223;
          rlutil::locate(posx+6, posy+0);
    cout<<(char) 219;
        rlutil::locate(posx+6, posy+1);
    cout<<(char) 219;
        rlutil::locate(posx+6, posy+2);
    cout<<(char) 219;
        rlutil::locate(posx+6, posy+3);
    cout<<(char) 219;
        rlutil::locate(posx+5, posy+2);
    cout<<(char) 223;
      rlutil::locate(posx+7, posy+2);
    cout<<(char) 223;
      rlutil::locate(posx+4, posy+2);
    cout<<(char) 223;
    break;
     case 8:
          rlutil::locate(posx+0, posy+2);
    cout<<(char) 219;
      rlutil::locate(posx+1, posy+1);
    cout<<(char) 220;
 rlutil::locate(posx+2, posy+1);
    cout<<(char) 220;
 rlutil::locate(posx+3, posy+1);
    cout<<(char) 220;
         rlutil::locate(posx+4, posy+2);
    cout<<(char) 219;
          rlutil::locate(posx+1, posy+3);
    cout<<(char) 223;
 rlutil::locate(posx+2, posy+3);
    cout<<(char) 223;
 rlutil::locate(posx+3, posy+3);
    cout<<(char) 223;
    rlutil::locate(posx+0, posy+1);
    cout<<(char) 223;
        rlutil::locate(posx+0, posy+0);
    cout<<(char) 220;
      rlutil::locate(posx+1, posy+0);
    cout<<(char) 223;
        rlutil::locate(posx+2, posy+0);
    cout<<(char) 223;
        rlutil::locate(posx+3, posy+0);
    cout<<(char) 223;
         rlutil::locate(posx+4, posy+1);
    cout<<(char) 223;
       rlutil::locate(posx+4, posy+0);
    cout<<(char) 220;
    break;
     case 9:
                 rlutil::locate(posx+0, posy+1);
    cout<<(char) 219;
     rlutil::locate(posx+0, posy+0);
    cout<<(char) 219;
         rlutil::locate(posx+1,posy+0);
    cout<<(char) 223;
       rlutil::locate(posx+2,posy+0);
    cout<<(char) 223;
   rlutil::locate(posx+3,posy+0);
    cout<<(char) 223;
  rlutil::locate(posx+4,posy+0);
    cout<<(char) 223;

  rlutil::locate(posx+5,posy+0);
    cout<<(char) 223;
         rlutil::locate(posx+6,posy+0);
    cout<<(char) 219;
     rlutil::locate(posx+6,posy+1);
    cout<<(char) 219;
 rlutil::locate(posx+6,posy+2);
    cout<<(char) 219;
     rlutil::locate(posx+6,posy+3);
    cout<<(char) 219;
           rlutil::locate(posx+1,posy+1);
    cout<<(char) 220;
      rlutil::locate(posx+2,posy+1);
    cout<<(char) 220;
      rlutil::locate(posx+3,posy+1);
    cout<<(char) 220;
 rlutil::locate(posx+4,posy+1);
    cout<<(char) 220;
 rlutil::locate(posx+5,posy+1);
    cout<<(char) 220;
       rlutil::locate(posx+5,posy+3);
    cout<<(char) 220;

   rlutil::locate(posx+4,posy+3);
    cout<<(char) 220;
   rlutil::locate(posx+3,posy+3);
    cout<<(char) 220;
   rlutil::locate(posx+2,posy+3);
    cout<<(char) 220;
   rlutil::locate(posx+1,posy+3);
    cout<<(char) 220;

  rlutil::locate(posx+0,posy+3);
    cout<<(char) 219;


}

}


