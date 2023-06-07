#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"


void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {"Ninguna"};
    string estatuillas_j2[5] = {"Ninguna"};

    int empieza;
    int opcion_elegida;
    bool primer_turno = false;

    ///Estatuas                0 - Arena; 1 - Tierra; 2 - Agua; 3 - Aire; 4 - Fuego
    string vEstatuillas[5] = {"Cangrejo", "Hormiga", "Medusa", "Aguila", "Salamandra"};


    ///Pide nombre de ambos jugadores
    for(int i = 0; i < 2 ; i++){
        cout<<"Ingrese el nombre del jugador numero "<<i+1<<": ";
        cin>>jugadores[i];
    }

    ///Limpiamos la pantalla
    system("cls");

    ///Seleccion de primer turno
    empieza = primerTurno(jugadores);
    cout<<"El primer jugador en empezar es: "<<jugadores[empieza]<<endl;
    system("pause");
    system("cls");
    ///Comienza la fase de expecidicion
    while(true){
        if(primer_turno == false){
            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[0]<<"\t\t\t\t";
            cout<<jugadores[1]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j1, 5);
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j2, 5);
            cout<<endl;
            cout<<"Por que estatuilla lanzaras "<<jugadores[empieza]<<"?"<<endl;
            opcion_elegida = lanzamiento_estatuilla(vEstatuillas, 5);
            lanzamiento_primer_turno(jugadores, 5,jugadores[empieza], vEstatuillas[opcion_elegida-1], estatuillas_j1, estatuillas_j2,vEstatuillas);

            system("pause");
            system("cls");

            primer_turno = true;
        }else{
            /*turno_primer_jugador();
            turno_segundo_jugador();*/

        }
    }
    ///Comienza la fase final

}

#endif // JUGAR_H_INCLUDED
