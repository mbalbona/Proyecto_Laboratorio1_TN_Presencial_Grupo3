#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"

void jugar(){
    system("cls");
    string j1,j2, empieza;
    int turno = 0;
    ///Estatuas             0 - Arena; 1 - Tierra; 2 - Agua; 3 - Aire; 4 - Fuego
    string vElementos[5] = {"Cangrejo", "Hormiga", "Medusa", "Aguila", "Salamandra"};
    ///Pide nombre de ambos jugadores
    cout<<"Nombre del jugador 1: ";
    cin>>j1;
    cout<<"Nombre del jugador 2: ";
    cin>>j2;

    ///Limpiamos la pantalla
    system("cls");

    ///Seleccion de primer turno
    empieza = primerTurno(j1,j2);
    system("pause");
    system("cls");
    ///Comienza la fase de expecidicion
    faseExpedicion(j1,j2,turno);
    system("pause");
    system("cls");
    ///Comienza la fase final


}

#endif // JUGAR_H_INCLUDED
