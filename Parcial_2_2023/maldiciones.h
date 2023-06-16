#ifndef MALDICIONES_H_INCLUDED
#define MALDICIONES_H_INCLUDED

#include "funciones_jugar.h"


void maldicion_cangrejo(string *jugadores, string jugador, int *puntosJugadores){
    system("cls");
    int dado, pos;

    dado = tiraDado();



    for(int i = 0; i < 2; i++){

    if(jugadores[i] == jugador){
            pos = i;
        }
    }

    puntosJugadores[pos] -= dado;

    cout<<"EL DADO LANZADO DEBIDO A LA MALDICION DEL CANGREJO ES: "<<dado<<endl;
    cout<<endl;
    cout<<"EL JUGADOR "<<jugadores[pos]<<" PERDERA "<<puntosJugadores[pos]<<" PUNTOS DEBIDO A LA MALDICION"<<endl;
    system("pause");
}


void maldicion_hormiga(){}
void maldicion_medusa(){}
void maldicion_aguila(){}
void maldicion_salamandra(){}

#endif // MALDICIONES_H_INCLUDED
