#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"

void jugar(){
    system("cls");
    string jugadores[2] = {}, empieza;
    string estatuillas_jugadores[2][5] = {};

    ///Estatuas             0 - Arena; 1 - Tierra; 2 - Agua; 3 - Aire; 4 - Fuego
    const string vEstatuilas[5] = {"Cangrejo", "Hormiga", "Medusa", "Aguila", "Salamandra"};
    ///Pide nombre de ambos jugadores
    for(int i = 0; i < 2 ; i++){
        cout<<"Ingrese el nombre del jugador numero "<<i<<": ";
        cin>>jugadores[i];
    }

    ///Limpiamos la pantalla
    system("cls");

    ///Seleccion de primer turno
    empieza = primerTurno(jugadores);
    system("pause");
    system("cls");
    ///Comienza la fase de expecidicion
    faseExpedicion(jugadores,empieza, vEstatuilas, estatuillas_jugadores);
    system("pause");
    system("cls");
    ///Comienza la fase final


}

#endif // JUGAR_H_INCLUDED
