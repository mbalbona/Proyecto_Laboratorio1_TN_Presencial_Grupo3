#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

#include "funciones_jugar.h"
#include "funciones_jugar_faseFinal.h"

void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {"Cangrejo", "Hormiga"};
    string estatuillas_j2[5] = {"Medusa", "Aguila", "Salamandra"};

    string primer_lanzamiento;
    string lanzamiento_j1, lanzamiento_j2;

    int  jugadorAguila;
    int empieza, noEmpieza;
    int opcion_elegidaJ1, opcion_elegidaJ2;

    int puntosJugadores[2] = {0};

    bool primer_turno = false;
    bool llaveSalamandraJ1 = false;
    bool llaveSalamandraJ2 = false;


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

    bool aguila_activa = false;

    ///Comienza la fase de expecidicion
    while(false){
        system("cls");
                ///Seleccion de estatua por la que jugara

                opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                if(aguila_activa){
                        /// LA MALDICION DEL AGUILA: UN JUGADOR TIRA DOBLE EL RESTO DE LA FASE

                        ///PREGUNTA SI EL QUE SACO LA ESTATUA AGUILA ES "EMPIEZA", PARA QUE TIRE DOS VECES "NOEMPIEZA"
                    if(jugadorAguila == empieza){
                            ///AQUI LANZA JUGAR "EMPIEZA"
                        lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ1);

                            cout<<endl;
                            cout<<"AQUI COMIENZA LA PRIMER TIRADA DEL JUGADOR RIVAL - 'NO EMPIEZA'"<<endl;
                            system("pause");

                            ///PRIMER LANZAMIENTO DE JUGADOR "NOEMPIEZA"
                        lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                        ///ESTANDO DENTRO DE LA MALDICION DEL AGUILA SE PREGUNTA SI AMBAS OPCIONES SON IGUALES
                        if(opcion_elegidaJ1==opcion_elegidaJ2){

                             if(lanzamiento_j1 != "No obtuvo"){

                                ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j1 == "Salamandra"){
                                            llaveSalamandraJ2=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {""};


                                ///PREGUNTA SI JUGADOR "NOEMPIEZA" TAMBIEN SACO LA MISMA ESTATUA
                                    if(lanzamiento_j2 != "No obtuvo"){
                                        //system("cls");
                                        cout<<endl;
                                        cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                        cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                        system("pause");
                                        //system("cls");

                                            //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }
                                        opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                        lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);
                                    }
                              }
                                  ///SE EVALUA LANZAMIENTO JUGADOR "NOEMPIEZA", CORRESPONDIENTE A LA PRIMERA TIRADA

                                     if(lanzamiento_j2 != "No obtuvo"){
                                        ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                        ///Se elimina la estatua conseguida para que no se liste mas
                                            vEstatuillas[opcion_elegidaJ2-1] = {""};
                                         }

                                         //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }
                                cout<<endl;
                                cout<<"AQUI COMIENZA LA SEGUNDA TIRADA DEL JUGADOR RIVAL - 'NOEMPIEZA'"<<endl;
                                system("pause");

                                ///SE VUELVE A PEDIR LA OPCIONES XQ NO SABEMOS SI ANTERIORMENTE OBTUVO LA ESTATUA SELECCIONADA
                                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                                    if(lanzamiento_j2!= "No obtuvo"){
                                        ///Se agrega la estatua obtenida por el jugador
                                            estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                        ///Se elimina la estatua conseguida para que no se liste mas
                                            vEstatuillas[opcion_elegidaJ2-1] = {""};
                                        }
                                    ///FIN EVALUACIONES DE TIRADAS DE AMBOS JUGADORES DONDE AMBOS SI ELEGIERON LAS MISMAS OPCIONES
                                    ///EL PROGRAMA IGNORA TODO HASTA LAS LA LINEA 293
                            }else{
                                ///JUEGO DONDE LAS OPCIONES SON DIFERENTES PARA CADA JUGADOR
                                ///SE EVALUA LANZAMIENTO JUGADOR EMPIEZA

                                 if(lanzamiento_j1 != "No obtuvo"){

                                    ///Se agrega la estatua obtenida por el jugador
                                    estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j1 == "Salamandra"){
                                            llaveSalamandraJ2=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                    vEstatuillas[opcion_elegidaJ1-1] = {""};
                                 }

                                    //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }
                                 ///SE EVALUA LANZAMIENTO JUGADOR NOEMPIEZA

                                 if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                    estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                                     }

                                     //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }

                                 ///COMIENZO DE TIRADAS JUGADOR "NOEMPIEZA"
                                    cout<<"AQUI COMIENZA LA SEGUNDA TIRADA DEL JUGADOR RIVAL - 'NOEMPIEZA'"<<endl;
                                    system("pause");
                                    //system("cls");

                                ///SEGUNDO LANZAMIENTO DEL JUGADOR "NOEMPIEZA"

                                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                                if(lanzamiento_j2 != "No obtuvo"){
                                            ///Se agrega la estatua obtenida por el jugador
                                                estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                            ///Se elimina la estatua conseguida para que no se liste mas
                                                vEstatuillas[opcion_elegidaJ2-1] = {""};
                                    }
                                }

                                //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }
                                ///FIN EVALUACIONES DE TIRADAS DE AMBOS JUGADORES CON OPCIONES DIFERENTES
                                ///EL PROGRAMA IGNORA TODO HASTA LAS LA LINEA 293
                    }else{

                        ///EL JUGADOR "NOEMPIEZA" FUE EL QUE OBTUVO EL AGUILA, POR ENDE JUGADOR "EMPIEZA" TIRA DOS VECES.

                        cout<<"AQUI COMIENZA LA PRIMER TIRADA DEL JUGADOR - 'EMPIEZA'"<<endl;
                        system("pause");
                        //system("cls");

                        ///PRIMER LANZAMIENTO JUGADOR NOEMPIEZA

                        lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1);

                        if(lanzamiento_j1 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j1 == "Salamandra"){
                                            llaveSalamandraJ2=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ1-1] = {""};
                            }

                            //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }

                         cout<<"AQUI COMIENZA LA SEGUNDA TIRADA DEL JUGADOR - 'EMPIEZA'"<<endl;
                         system("pause");
                         //system("cls");

                        ///SEGUNDO LANZAMIENTO
                        ///SE VUELVE A PEDIR LA OPCIONES XQ NO SABEMOS SI ANTERIORMENTE OBTUVO LA ESTATUA SELECCIONADA
                        opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                        ///lanzamiento_aguila_jugador = lanzamiento_aguila(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores);
                        lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1);

                        ///CONDICION PARA QUE J2 NO TIRE DOS VECES.
                        bool paso_lanzamiento_j2=false;

                        ///EVALUO SI "EMPIEZA" OBTUVO UNA ESTATUA
                        if(lanzamiento_j1 != "No obtuvo"){

                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j1 == "Salamandra"){
                                            llaveSalamandraJ2=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ1-1] = {""};

                                //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }

                                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                                paso_lanzamiento_j2=true;

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                    cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                    system("pause");
                                    system("cls");
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);
                                }
                            }
                        ///PREGUNTO SI PASO DE LANZAMIENTO ESTA FALSE ES PORQUE TODAVIA NO TIRO EL J2, SI ES TRUE ES QUE YA TIRO Y NO PUEDO TIRAR DE NUEVO.
                                if(!paso_lanzamiento_j2){
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2);
                                }

                                if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                                    }

                                //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                            if(recorrer_estatuas(vEstatuillas,5) == 0){
                                                    break;
                                               }
                        }

                }else{

                    ///JUEGO DONDE AMBOS JUGADORES TIRAN POR TURNO
                    ///Se lanzan los dados

                    lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1);
                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                }

                    ///AQUI SE EVALUAR LAS OPCIONES Y OBTENCIONES DE JUEGO NORMAL

                    ///Lanzamiento de dados con opciones de estatuillas iguales
                    if(opcion_elegidaJ1 == opcion_elegidaJ2){
                            if(lanzamiento_j1 != "No obtuvo"){

                                ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                                if(lanzamiento_j1 == "Aguila"){
                                    jugadorAguila = empieza;
                                    aguila_activa=true;
                                }
    ///----------------------------------------------------------------------------------------------------------
                                if(lanzamiento_j1 == "Salamandra"){
                                    llaveSalamandraJ2=true;
                                }
    ///___________________________________________________________________________________________________________
                                ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {""};

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                    cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                    system("pause");
                                    system("cls");
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);

                                }

                        }
                            if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                                        if(lanzamiento_j2 == "Aguila"){
                                            jugadorAguila = noEmpieza;
                                            aguila_activa=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                            }
                        }

                            ///Lanzamiendo dados con opciones diferente
                            if(opcion_elegidaJ1 != opcion_elegidaJ2){
                                 if(lanzamiento_j1 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                                        if(lanzamiento_j1 == "Aguila"){
                                                jugadorAguila = empieza;
                                                aguila_activa=true;
                                            }
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j1 == "Salamandra"){
                                            llaveSalamandraJ2=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ1-1] = {""};
                                 }
                                 if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                                        if(lanzamiento_j2 == "Aguila"){
                                                jugadorAguila = noEmpieza;
                                                aguila_activa=true;
                                            }
    ///----------------------------------------------------------------------------------------------------------
                                        if(lanzamiento_j2 == "Salamandra"){
                                            llaveSalamandraJ1=true;
                                        }
    ///----------------------------------------------------------------------------------------------------------
                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                                 }
                            }

                ///Si toca Medusa
                int contMedusa = 0;

                if(lanzamiento_j1 == "Medusa"){
                           while(contMedusa != 3){
                                //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                if(recorrer_estatuas(vEstatuillas,5) == 0){
                                        break;
                                   }
                                       opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza,jugadores[noEmpieza], jugadores, vEstatuillas,5, estatuillas_j1, estatuillas_j2);
                                        lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2);
                                            if(lanzamiento_j2 != "No obtuvo"){
                                                ///Se agrega la estatua obtenida por el jugador
                                                    estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;
    ///----------------------------------------------------------------------------------------------------------
                                                        if(lanzamiento_j2 == "Salamandra"){
                                                            llaveSalamandraJ1=true;
                                                        }
    ///----------------------------------------------------------------------------------------------------------
                                                ///Se elimina la estatua conseguida para que no se liste mas
                                                    vEstatuillas[opcion_elegidaJ2-1] = {""};
                                                }
                                }

                                contMedusa++;
                            }

                if(lanzamiento_j2 == "Medusa"){
                            while(contMedusa != 3){
                                //FUNCIONES QUE VERIFICA QUE TODABIA HAY ESTATUAS EN JUEGO
                                if(recorrer_estatuas(vEstatuillas,5) == 0){
                                    break;
                                }
                                    opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza,jugadores[empieza], jugadores, vEstatuillas,5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ1);

                                        if(lanzamiento_j1 != "No obtuvo"){
                                            ///Se agrega la estatua obtenida por el jugador
                                            estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;
    ///----------------------------------------------------------------------------------------------------------
                                                if(lanzamiento_j1 == "Salamandra"){
                                                    llaveSalamandraJ2=true;
                                                }
    ///----------------------------------------------------------------------------------------------------------
                                            ///Se elimina la estatua conseguida para que no se liste mas
                                            vEstatuillas[opcion_elegidaJ1-1] = {""};
                                        }
                                contMedusa++;
                            }
                }
                system("cls");

                   if(recorrer_estatuas(vEstatuillas,5) == 0){
                        break;
                   }
        }
    ///Comienza la fase final
    while(true){
        cout<<endl;
        cout<<"BIENVENIDOS A LA FASE FINAL"<<endl;
        cout<<endl;
        ///CONTAMOS ESTATUAS PARA SABER QUIEN ES EL PRIMERO.
        int contador_J1, contador_J2;

        contador_J1 = contadorEstatuillas(estatuillas_j1, 5);
        contador_J2 = contadorEstatuillas(estatuillas_j1, 5);

        int aux;

        if(contador_J1>contador_J2){
            cout<<"EMPIEZA EL JUGADOR "<<jugadores[empieza]<<endl;
            system("pause");
        }else{
            cout<<"EMPIEZA EL JUGADOR "<<jugadores[noEmpieza]<<endl;
            system("pause");
            aux=empieza;
            empieza=noEmpieza;
            noEmpieza=aux;
        }
        system("cls");

        while(true){
                lanzamiento_j1 = lanzamiento_jugador_faseFinal(empieza, noEmpieza, jugadores, 5, jugadores[empieza], estatuillas_j1, estatuillas_j2, vEstatuillas);

            if(lanzamiento_j1=="GANASTE"){
                cout<<"FIN DEL JUEGO"<<endl;
                system("pause");
                system("cls");
                break;
            }
            lanzamiento_j2 = lanzamiento_jugador_faseFinal(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], estatuillas_j1, estatuillas_j2, vEstatuillas);

            if(lanzamiento_j2=="GANASTE"){
                cout<<"FIN DEL JUEGO"<<endl;
                system("pause");
                system("cls");
                break;
            }
        }
        break;
    }

}

#endif // JUGAR_H_INCLUDED
