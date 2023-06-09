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

    ///MODIFICACION DE LOS JUGADORES EN LOS DADOS, ESTO SE RELACIONA CON EL CAMBIO DE TURNOS

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

    ///Comienza la fase de expecidicion
    while(true){
        system("cls");
        if(primer_turno == false){
                ///Seleccion de estatua por la que jugara

                opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                ///Se lanzan los dados

                ///Lanza jugador 1
                lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas);

                ///Lanza jugador 2
                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas);

                ///Lanzamiento de dados con opciones de estatuillas iguales
                if(opcion_elegidaJ1 == opcion_elegidaJ2){
                        if(lanzamiento_j1 != "No obtuvo"){
                                ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                                ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {" "};

                                system("pause");
                                system("cls");

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"Al haber seleccionado las mismas estatuas el jugador "<<jugadores[empieza]<<" ha ganado la estatua."<<endl;
                                    cout<<"Por favor seleccionar una nueva estatua de la siguiente lista: "<<endl;
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas);

                                }
                        }
                        system("pause");
                        system("cls");
                    }

                    if(opcion_elegidaJ1 != opcion_elegidaJ2){
                         if(lanzamiento_j1 != "No obtuvo"){
                            ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                            ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {" "};
                         }
                         if(lanzamiento_j2 != "No obtuvo"){
                            ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                            ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ2-1] = {" "};
                         }
                         system("pause");
                    }
                }else{
                    ///Lanzamiento de dados jugadores
                    lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas);
                    system("pause");
                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas);
                    system("pause");
                    if(lanzamiento_j1!="No obtuvo"){
                       ///Agrego el valor de lanzamiento_J1 al vector de estatuillas_J1
                         estatuillas_j1[opcion_elegidaJ1-1]=lanzamiento_j1;
                         }
                    if(lanzamiento_j2!="No obtuvo"){
                                ///Agrego el valor de lanzamiento_J2 al vector de estatuillas_J2
                                    estatuillas_j2[opcion_elegidaJ2-1]=lanzamiento_j2;
                                }
                    system("cls");
                }
        }
    ///Comienza la fase final

}

#endif // JUGAR_H_INCLUDED
