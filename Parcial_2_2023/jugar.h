#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"


void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {"Ninguna"};
    string estatuillas_j2[5] = {"Ninguna"};
    string empieza;
    bool primer_turno = false;

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
    cout<<"El primer jugador en empezar es: "<<empieza<<endl;
    system("pause");
    system("cls");
    ///Comienza la fase de expecidicion
    while(true){
        if(primer_turno == false){
            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[0]<<"\t\t";
            cout<<jugadores[1]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j1, 5);
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j2, 5);
            cout<<endl;
            system("pause");
            system("cls");

            primer_turno = true;
        }
    }
    ///Comienza la fase final


}

#endif // JUGAR_H_INCLUDED
