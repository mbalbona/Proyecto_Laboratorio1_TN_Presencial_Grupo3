#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"


void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {"Ninguna"};
    string estatuillas_j2[5] = {"Ninguna"};

    string primer_lanzamiento;
    string lanzamiento_j1, lanzamiento_j2;

    int empieza, noEmpieza;
    int opcion_elegidaJ1, opcion_elegidaJ2;
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
    noEmpieza = empieza-1;
    cout<<"El primer jugador en empezar es: "<<jugadores[empieza]<<endl;
    system("pause");
    system("cls");

    ///Comienza la fase de expecidicion
    while(true){
        if(primer_turno == false){
            ///Pide al jugador seleccionar por cual estatua jugara
            opcion_elegidaJ1 = seleccion_estatuilla_jugadores(jugadores[0], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
            opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[1], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

            ///Lanzamiento de dados jugadores
            lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas);
            system("pause");
            lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2], estatuillas_j2, estatuillas_j2, vEstatuillas);

            ///Ambos seleccionaron la misma estatua y ambos obtienen esa estatua
            cout<<endl;
            cout<<lanzamiento_j1<<endl;
            cout<<lanzamiento_j2<<endl;
            system("pause");
            system("cls");
            if(lanzamiento_j1 == lanzamiento_j2 && lanzamiento_j1 != "No obtuvo"){
                    cout<<"Ambos han seleccionado y obtenido la misma estatua, por lo tanto el jugador "<<jugadores[0]<<" se lleva la estatua y el jugador "<<jugadores[1]<<
                    " tiene que volver a seleccionar otra estatua"<<endl;

                    system("pause");
                    system("cls");

                    estatuillas_j1[buscar_estatua(vEstatuillas,5,lanzamiento_j1)] = {vEstatuillas[buscar_estatua(vEstatuillas,5,lanzamiento_j1)]};

                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[1], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                    lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2], estatuillas_j2, estatuillas_j2, vEstatuillas);


            }else if(lanzamiento_j1 != "No obtuvo"){
                estatuillas_j1[buscar_estatua(vEstatuillas,5,lanzamiento_j1)] = {vEstatuillas[buscar_estatua(vEstatuillas,5,lanzamiento_j1)]};
                mostrar_estatuillas(estatuillas_j1,5);
                cout<<endl;
            }else if(lanzamiento_j2 != "No obtuvo"){
                estatuillas_j2[buscar_estatua(vEstatuillas,5,lanzamiento_j1)] = {vEstatuillas[buscar_estatua(vEstatuillas,5,lanzamiento_j2)]};
                mostrar_estatuillas(estatuillas_j2,5);
                cout<<endl;
            }

             system("pause");

            //primer_turno = true;
        }/*else{
            turno_primer_jugador();
            turno_segundo_jugador();

        }*/
    }
    ///Comienza la fase final

}

#endif // JUGAR_H_INCLUDED
