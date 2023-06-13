#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"

void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {""};
    string estatuillas_j2[5] = {""};

    string primer_lanzamiento;
    string lanzamiento_j1, lanzamiento_j2;

    string lanzamiento_Medusa;

    int empieza, noEmpieza;
    int opcion_elegidaJ1, opcion_elegidaJ2;

    int suma_j1,suma_j2;
    int puntosJugadores[2] = {0};

    bool primer_turno = false;



    ///Estatuas                0 - Arena; 1 - Tierra; 2 - Agua; 3 - Aire; 4 - Fuego
    string vEstatuillas[5] = {"Cangrejo", "Hormiga", "Medusa", "Aguila", "Salamandra"};


    ///Pide nombre de ambos jugadores
    for(int i = 0; i < 2 ; i++){
        cout<<endl;
        cout<<"Ingrese el nombre del jugador numero "<<i+1<<": ";
        cin>>jugadores[i];
    }

    ///Limpiamos la pantalla
    system("cls");

    ///Seleccion de primer turno
    empieza = primerTurno(jugadores);
    if(empieza==0){
        noEmpieza=1;
    }else{
        noEmpieza=0;
    }
    cout<<endl;
    cout<<"El primer jugador en empezar es: "<<jugadores[empieza]<<endl;
    cout<<endl;
    system("pause");
    system("cls");

    bool bandera= false;
    ///Comienza la fase de expecidicion
    while(true){
        system("cls");
                ///Seleccion de estatua por la que jugara

                opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);


                ///Se lanzan los dados

                lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores);
                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores);


                ///Lanzamiento de dados con opciones de estatuillas iguales
                if(opcion_elegidaJ1 == opcion_elegidaJ2){
                        if(lanzamiento_j1 != "No obtuvo"){

                                ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                                ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {""};

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                    cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                    system("pause");
                                    system("cls");
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores);

                                }

                        }
                            if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                            }
                }

                ///Lanzamiendo dados con opciones diferente
                if(opcion_elegidaJ1 != opcion_elegidaJ2){
                     if(lanzamiento_j1 != "No obtuvo"){
                        ///Se agrega la estatua obtenida por el jugador
                            estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                        ///Se elimina la estatua conseguida para que no se liste mas
                            vEstatuillas[opcion_elegidaJ1-1] = {""};
                     }
                     if(lanzamiento_j2 != "No obtuvo"){
                        ///Se agrega la estatua obtenida por el jugador
                            estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                        ///Se elimina la estatua conseguida para que no se liste mas
                            vEstatuillas[opcion_elegidaJ2-1] = {""};
                     }
                }
                        system("cls");

                   if(recorrer_estatuas(vEstatuillas,5) == 0){
                        break;
                   }
        }
    ///Comienza la fase final

}

#endif // JUGAR_H_INCLUDED
