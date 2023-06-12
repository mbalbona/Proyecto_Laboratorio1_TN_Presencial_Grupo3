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
    int jugadorMedusa;
    int opcion_elegidaJ1, opcion_elegidaJ2;

    int opcion_elegida_Medusa;

    int dado1,dado2,suma_j1,suma_j2;
    int maldicion_j1{0};
    int maldicion_j2{0};
    int maldicion_total{0};

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

                /*while(bandera){
                    cout<<endl;
                    cout<<"LA MALDICION DE LA MEDUSA COMIENZA, TIENE 3 LANZAMIENTOS EL JUGADOR: "<<jugadores[jugadorMedusa]<<endl;
                    system("pause");
                    system("cls");
                    for(int i=0; i<3; i++)
                    {
                        ///OPCION DE ESTATUILLA DENTRO LA MALDICION DE LA MEDUSA
                        opcion_elegida_Medusa = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[jugadorMedusa], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                        ///LANZAMIENDO DENTRO DE LA MALDICION DE LA MEDUSA
                        lanzamiento_Medusa = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[jugadorMedusa], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, dado1, dado2);
                        if(lanzamiento_Medusa != "No obtuvo"){
                                if(jugadorMedusa==0){
                                        ///AQUI CARGAR LA ESTATUA DEL JUGAR EMPIEZA
                                     ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j1[opcion_elegida_Medusa-1] = lanzamiento_Medusa;

                                        ///Maldicion de la Estatua Obtenida
                                        maldicion_total = maldicion(lanzamiento_Medusa, maldicion_j1, suma_j2, bandera);

                                        maldicion_j2=maldicion_total;

                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                                }else{
                                    ///AQUI CARGA LA ESTATUA DEL JUGADOR NoEMPIEZA
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegida_Medusa-1] = lanzamiento_Medusa;

                                        ///Maldicion de la Estatua Obtenida
                                        maldicion_total = maldicion(lanzamiento_Medusa, maldicion_j2, suma_j1, bandera);

                                        maldicion_j2=maldicion_total;

                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                                }

                            }///LLAVE DEL IF SI ES QUE OBTUVO LA ESTATUA
                    }///FIN CICLO FOR, TERMINA LA MALDICION DE LA MEDUSA


                    bandera=false;
                    cout<<"FINALIZA LA MALDICION DE LA MEDUSA, AMBOS JUGADORES VUELVEN A LANZAR."<<endl;
                    system("pause");
                    system("cls");
                }*/

                ///Seleccion de estatua por la que jugara

                opcion_elegidaJ1 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);


                ///Se lanzan los dados

                ///Lanza jugador 1
                dado1 = tiraDado();
                //cout<<dado1<<endl;
                //system("pause");
                dado2 = tiraDado();
                //cout<<dado2<<endl;
                //system("pause");
                suma_j1=dado1+dado2;
                //cout<<suma_j1<<endl;
                //system("pause");
                lanzamiento_j1 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, sumaj1);

                ///Lanza jugador 2
                dado1 = tiraDado();
                //cout<<dado1<<endl;
                //system("pause");
                dado2 = tiraDado();
                //cout<<dado2<<endl;
                //system("pause");
                suma_j2=dado1+dado2;
                //cout<<suma_j2<<endl;
                //system("pause");
                lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, suma_j2);


                ///Lanzamiento de dados con opciones de estatuillas iguales
                if(opcion_elegidaJ1 == opcion_elegidaJ2){
                        if(lanzamiento_j1 != "No obtuvo"){

                                ///Se agrega la estatua obtenida por el jugador
                                estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                                ///Maldicion de la Estatua Obtenida
                                maldicion_total = maldicion(lanzamiento_j1, maldicion_j1, suma_j2, bandera);

                                if(maldicion_total == 1){
                                    bandera=true;
                                    jugadorMedusa=noEmpieza;
                                    maldicion_total--;
                                }

                                maldicion_j1=maldicion_total;


                                ///Se elimina la estatua conseguida para que no se liste mas
                                vEstatuillas[opcion_elegidaJ1-1] = {""};

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                    cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                    system("pause");
                                    system("cls");
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(empieza, noEmpieza, jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    dado1 = tiraDado();
                                    dado2 = tiraDado();
                                    lanzamiento_j2 = lanzamiento_jugador(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, dado1, dado2);

                                }

                        }
                            if(lanzamiento_j2 != "No obtuvo"){
                                    ///Se agrega la estatua obtenida por el jugador
                                        estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                                        ///Maldicion de la Estatua Obtenida
                                        maldicion_total = maldicion(lanzamiento_j2, maldicion_j2, suma_j1, bandera);
                                        if(maldicion_total == 1){
                                            bandera=true;
                                            jugadorMedusa=empieza;
                                            maldicion_total--;
                                        }
                                        maldicion_j2=maldicion_total;

                                    ///Se elimina la estatua conseguida para que no se liste mas
                                        vEstatuillas[opcion_elegidaJ2-1] = {""};
                            }
                }

                ///Lanzamiendo dados con opciones diferente
                if(opcion_elegidaJ1 != opcion_elegidaJ2){
                     if(lanzamiento_j1 != "No obtuvo"){
                        ///Se agrega la estatua obtenida por el jugador
                            estatuillas_j1[opcion_elegidaJ1-1] = lanzamiento_j1;

                            ///Maldicion de la Estatua Obtenida
                            maldicion_total = maldicion(lanzamiento_j1, maldicion_j1, suma_j2, bandera);
                            if(maldicion_total == 1){
                                    bandera=true;
                                    jugadorMedusa=noEmpieza;
                                    maldicion_total--;
                                }
                            maldicion_j1=maldicion_total;


                        ///Se elimina la estatua conseguida para que no se liste mas
                            vEstatuillas[opcion_elegidaJ1-1] = {""};
                     }
                     if(lanzamiento_j2 != "No obtuvo"){
                        ///Se agrega la estatua obtenida por el jugador
                            estatuillas_j2[opcion_elegidaJ2-1] = lanzamiento_j2;

                            ///Maldicion de la Estatua Obtenida;
                            maldicion_total = maldicion(lanzamiento_j2, maldicion_j2, suma_j1, bandera);
                            if(maldicion_total == 1){
                                    bandera=true;
                                    jugadorMedusa=empieza;
                                    maldicion_total--;
                                }
                            maldicion_j2=maldicion_total;


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
