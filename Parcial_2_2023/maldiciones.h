#ifndef MALDICIONES_H_INCLUDED
#define MALDICIONES_H_INCLUDED

#include "funciones_jugar.h"


void maldicion_cangrejo(string *jugadores, string jugador, int *puntosJugador, string *vEstatuas){
    system("cls");

    int pos, rival, numero = 10;
    int dado[1] = {};

    bool esta_cangrejo = false;

    for(int i = 0; i < 2; i++){
        if(jugadores[i] == jugador){
            pos = i;
        }
    }

    for(int i = 0; i < 5; i++){
            if(vEstatuas[i] == "Cangrejo"){
                esta_cangrejo = true;
            }
    }
    if(pos==0){
        rival=1;
    }else{
        rival=0;
    }

    if(esta_cangrejo = true){
        cout<<"EL JUGADOR "<<jugadores[rival]<<" DEBE TIRAR UN DADO, POR LA MALDICION DEL CANGREJO."<<endl;
        tiraDado(dado,5,modoDiosActivado);
        cout<<endl;
        cout<<"SALIO DADO: "<<dado[0]<<endl;

        puntosJugador[pos] -= dado[0];

        cout<<"EL JUGADOR "<<jugadores[pos]<<" PIERDE "<<dado[0]<<" PUNTOS DEBIDO A LA MALDICION DEL CANGREJO."<<endl;
    }
}


void maldicion_hormiga(string *jugadores, string jugador, int *puntosJugador){
    system("cls");

    int vDado[2] = {}, pos, rival;

    for(int i = 0; i < 2; i++){
        if(jugadores[i] == jugador){
            pos = i;
        }
    }

    if(pos==0){
        rival=1;
    }else{
        rival=0;
    }
    cout<<"EL JUGADOR "<<jugadores[rival]<<" DEBE TIRAR DOS DADO, POR LA MALDICION DE LA HORMIGA."<<endl;
    system("pause");

    tiraDado(vDado, 2 ,modoDiosActivado);

    cout<<"SALIO DADO 1: "<<vDado[0]<<endl;
    cout<<"SALIO DADO 2: "<<vDado[1]<<endl;

    puntosJugador[pos] -= (vDado[0] + vDado[1]);

    cout<<"EL JUGADOR "<<jugadores[pos]<<" PIERDE "<<(vDado[0] + vDado[1])<<" PUNTOS DEBIDO A LA MALDICION DE LA HORMIGA."<<endl;
}

void maldicion_aguila(){}
void maldicion_salamandra(){}

#endif // MALDICIONES_H_INCLUDED
