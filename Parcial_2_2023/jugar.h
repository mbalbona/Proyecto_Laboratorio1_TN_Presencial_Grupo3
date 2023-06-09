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

    ///MODIFICACION DE LOS JUGADORES EN LOS DADOS, ESTO SE RELACIONA CON EL CAMBIO DE TURNOS
    /*
        ///Seleccion de primer turno
         empieza = primerTurno(jugadores);
         ///noEmpieza = empieza-1;
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
    */

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

             ///CODIGO DE CAMBIOS DE TURNO Y SELECCION DE ESTATUILLAS
             /*
                                    opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                ///Lanzamiento de dados con opciones de estatuillas iguales
                if(opcion_elegidaJ1==opcion_elegidaJ2){
                    lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas);
                        ///cout<<lanzamiento_j1<<endl;
                        system("pause");
                        if(lanzamiento_j1!="No obtuvo"){
                            ///Agrego el valor de lanzamiento_J1 al vector de estatuillas_J1
                                estatuillas_j1[opcion_elegidaJ1-1]=lanzamiento_j1;
                                ///Lanza jugador 2
                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas);
                            system("pause");
                                    if(lanzamiento_j2!="No obtuvo"){
                                        cout<<"------------------------------------------------------------------------"<<endl;
                                        cout<<"Ambos Jugadores elegieron las mismas estatuillas, pero gano el jugador: "<<jugadores[empieza]<<endl;
                                        cout<<endl;
                                        system("pause");
                                        system("cls");
                                    }
                                    system("cls");
                        }else{
                            lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas)
                                ///cout<<lanzamiento_j2<<endl;
                                system("pause");
                                system("cls");
                                if(lanzamiento_j2!="No obtuvo"){
                                ///Agrego el valor de lanzamiento_J2 al vector de estatuillas_J2
                                    estatuillas_j2[opcion_elegidaJ2-1]=lanzamiento_j2;
                                }
                    }
                    ///ESTE ELSE TODABIA FALTA ARRGLEGAR COMO LAS IGUALACIONES DE LAS OPCIONES
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
             */

            //primer_turno = true;
        }/*else{
            turno_primer_jugador();
            turno_segundo_jugador();

        }*/
    }
    ///Comienza la fase final

}

#endif // JUGAR_H_INCLUDED
