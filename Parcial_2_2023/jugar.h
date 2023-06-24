#ifndef JUGAR_H_INCLUDED
#define JUGAR_H_INCLUDED

///FUNCION Y VARIABLES DE ALCANCE GLOBAL
///ESTAMOS AL TANTO DE QUE NO ES RECOMENDABLE USAR VARIABLES GLOBALES DE SER POSIBLE

///FUNCION QUE ORDENA EL DADO Y COMPRUEBA LA ESCALERA
int comprobar_dado(int *vDado, int tam){
    int aux;

    ///ORDENAMOS EL VECTOR CON EL METODO BURBUJA
    for (int i = 0; i < tam-1; i++) {
        for (int j = 0; j < tam-i-1; j++) {
            if (vDado[j] > vDado[j+1]) {
                aux = vDado[j];
                vDado[j] = vDado[j+1];
                vDado[j+1] = aux;
            }
        }
    }

    ///COMPROBAMOS SI ESTAN ORDENADOS O NO

    for (int i = 1; i < tam-1; i++) {
        if (vDado[i] != vDado[i-1] + 1){
            return 0;  // No es escalera
        }
    }

    return 1; //Escalera
}

bool modoDiosActivado = false;



///FIN VARIABLES GLOABALES

#include "funciones_jugar.h"
#include "funciones_jugar_faseFinal.h"

void jugar(){
    system("cls");
    string jugadores[2] = {};
    string estatuillas_j1[5] = {""};
    string estatuillas_j2[5] = {""};

    int jugadorAguila = 0;

    string primer_lanzamiento;
    string lanzamiento_j1, lanzamiento_j2;

    int empieza, noEmpieza;
    int opcion_elegidaJ1, opcion_elegidaJ2;
    int cont_medusa = 0;
    int puedeLanzarJ1 = 1;
    int puedeLanzarJ2 = 1;
    int medusa_activa = 0;

    int puntosJugadores[2] = {0};

    bool aguila_activa = false;
    bool primer_turno = true;
    bool llaveSalamandraJ1 = false;
    bool llaveSalamandraJ2 = false;


    ///Estatuas                0 - Arena; 1 - Tierra; 2 - Agua; 3 - Aire; 4 - Fuego
    string vEstatuillas[5] = {"Cangrejo", "Hormiga", "Medusa", "Aguila", "Salamandra"};


    ///Pide nombre de ambos jugadores
    for(int i = 0; i < 2 ; i++){
        cout<<endl;
        cout<<"Ingrese el nombre del jugador numero "<< i+1 <<": ";
        cin>>jugadores[i];
        if(jugadores[0] == "LAB1"){
            modoDiosActivado = true;
            system("cls");
            cout<<endl;
            cout<<endl;
            cout<<"\t\t >>> MODO DIOS ACTIVADO <<<"<<endl;
            cout<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            jugadores[1] = "LAB1-J2";
            break;
        }
    }

    ///Limpiamos la pantalla
    system("cls");

    if(!modoDiosActivado){
        ///Seleccion de primer turno
        empieza = primerTurno(jugadores, modoDiosActivado);
        if(empieza == 0){
            noEmpieza = 1;
        }else{
            noEmpieza = 0;
        }
        cout<<endl;
        cout<<"El primer jugador en empezar es: "<<jugadores[empieza]<<endl;
        cout<<endl;
        system("pause");
        system("cls");


    }else{
        empieza = 0;
        noEmpieza = 1;
    }
    ///Comienza la fase de expecidicion
    while(true){
        system("cls");

                ///Seleccion de estatua por la que jugara
                ///Se lanzan los dados

                    ///Verificamos que ambos jugadores puedan seleccionar una estatua y lanzar los dados
                    if(puedeLanzarJ1 == 1){
                        if(puedeLanzarJ2 == 1){
                            cout<<endl;
                            cout<<"Entre en donde los dos son 1"<<endl;
                            cout<<puedeLanzarJ1<<" "<<puedeLanzarJ2<<endl;
                            system("pause");
                            opcion_elegidaJ1 = seleccion_estatuilla_jugadores(jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                            opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                            if(primer_turno = true){
                                lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);
                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
                                primer_turno = false;
                            }else{
                                lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);
                                if(lanzamiento_j1 != "No obtuvo"){
                                    jugador1_obtuvo(lanzamiento_j1, vEstatuillas, estatuillas_j1, opcion_elegidaJ1);
                                }
                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
                                jugador2_obtuvo(lanzamiento_j2, vEstatuillas, estatuillas_j2, opcion_elegidaJ2);
                            }
                        }
                    }

                    ///Verificamos si unicamente el jugador dos puede lanzar, de ser asi selecciona estatua y lanza los dados
                    if(puedeLanzarJ2 == 1){
                        if(puedeLanzarJ1 == 0){
                            cout<<endl;
                            cout<<"Entre en donde lanza j2 no obtuvo medusa y el j1 si obtuvo"<<endl;
                            cout<<puedeLanzarJ1<<" "<<puedeLanzarJ2<<endl;
                            system("pause");
                            opcion_elegidaJ1 = -1;
                            lanzamiento_j1 = "No obtuvo";
                            opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                            lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
                        }
                    }

                    ///Verificamos si unicamente el jugador uno puede lanzar, de ser asi selecciona estatua y lanza los dados
                    if(puedeLanzarJ1 == 1){
                        if(puedeLanzarJ2 == 0){
                            cout<<endl;
                            cout<<"Entre en donde j1 no obtuvo la medusa y el j2 si obtuvo"<<endl;
                            cout<<puedeLanzarJ1<<" "<<puedeLanzarJ2<<endl;
                            system("pause");
                            opcion_elegidaJ2 = -1;
                            lanzamiento_j2 = "No obtuvo";
                            opcion_elegidaJ1 = seleccion_estatuilla_jugadores(jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                            lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);
                        }
                    }

                    ///Lanzamiento de dados con opciones de estatuillas iguales
                    if(opcion_elegidaJ1 == opcion_elegidaJ2){

                            ///Entra aca si ambos jugadores sacaron la misma estatua
                            if( (lanzamiento_j1 == lanzamiento_j2) && (lanzamiento_j1 != "No obtuvo" && lanzamiento_j2 != "No obtuvo") ){

                                jugador1_obtuvo(lanzamiento_j1, vEstatuillas, estatuillas_j1, opcion_elegidaJ1);

                                ///Pedimos seleccionar otra estatuilla al jugador 2 y lanza nuevamente el dado
                                system("cls");
                                cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA!"<<endl;
                                system("pause");
                                system("cls");
                                cout<<endl;
                                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);

                            }else if(lanzamiento_j1 != lanzamiento_j2){ ///Entra aca si ambos jugadores eligieron la misma estatua pero solo uno obtuvo una de ellas
                                jugador1_obtuvo(lanzamiento_j1, vEstatuillas, estatuillas_j1, opcion_elegidaJ1);
                                jugador2_obtuvo(lanzamiento_j2, vEstatuillas, estatuillas_j2, opcion_elegidaJ2);
                            }

                        }

                    ///Lanzamiendo dados con opciones diferente
                    if(opcion_elegidaJ1 != opcion_elegidaJ2){
                            system("cls");
                            system("pause");
                            jugador1_obtuvo(lanzamiento_j1, vEstatuillas, estatuillas_j1, opcion_elegidaJ1);
                            jugador2_obtuvo(lanzamiento_j2, vEstatuillas, estatuillas_j2, opcion_elegidaJ2);
                        }

                    ///Verifica si alguno de los dos tiene la estatua medusa en su poder y si es asi el jugador que la posea*
                    ///*no pueda lanzar durante 3 turnos
                    for(int i = 0; i < 5; i++){
                        if(estatuillas_j1[i] == "Medusa"){
                            puedeLanzarJ1 = 0;
                            medusa_activa = 1;
                        }
                        else if(estatuillas_j2[i] == "Medusa"){
                            puedeLanzarJ2 = 0;
                            medusa_activa = 1;
                        }
                    }

                ///Verifica si la maldicion de medusa esta activa
                if(medusa_activa == true){
                    cont_medusa++;
                    if(cont_medusa == 4){
                        if(puedeLanzarJ1 == 0){
                            puedeLanzarJ1 = 1;
                        }else if(puedeLanzarJ2 == 0){
                            puedeLanzarJ2 = 1;
                        }
                   }
                }

                   if(recorrer_estatuas(vEstatuillas,5) == 0){
                        break;
                   }
        }

    ///Comienza la fase final
    while(true){
            ///BENEFICIO DE LA HORMIGA
        int valorDadoBeneficioHormigaJ1;
        int valorDadoBeneficioHormigaJ2;
        bool estatuaHormiga_J1 = false;

         if(buscarEstatua(estatuillas_j1, 5) == "Hormiga"){
            estatuaHormiga_J1 = true;
         }

        if(estatuaHormiga_J1){
            cout<<"Beneficio de la Hormiga"<<endl;
            cout<<"El jugador "<<jugadores[empieza]<<" debe elegir un numero del 1 al 6: ";
            cin>>valorDadoBeneficioHormigaJ1;
        }else{
            cout<<"Beneficio de la Hormiga"<<endl;
            cout<<"El jugador "<<jugadores[noEmpieza]<<" debe elegir un numero del 1 al 6: ";
            cin>>valorDadoBeneficioHormigaJ2;
        }

        cout<<endl;
        cout<<"BIENVENIDOS A LA FASE FINAL"<<endl;
        cout<<endl;

        ///CONTAMOS ESTATUAS PARA SABER QUIEN ES EL PRIMERO.
        int contador_J1 = 0, contador_J2 = 0;
        bool estatuaMedusa_J1 = false;
        bool estatuaMedusa_J2 = false;
        bool estatuaSalamandra_J1 = false;
        bool estatuaSalamandra_J2 = false;
        bool aguila_J1 = false;
        bool aguila_J2 = false;

        contador_J1 = contadorEstatuillas(estatuillas_j1, 5);
        contador_J2 = contadorEstatuillas(estatuillas_j2, 5);

        int aux;
        string vectorAuxiliar[5]={""};

        ///DETERMINAR EL ORDEN DE TIRADA DE LOS JUGADORES DEPENDIENDO DE LA CANTIDAD DE ESTATUILLAS
        if(contador_J1>contador_J2){
            cout<<"EMPIEZA EL JUGADOR "<<jugadores[empieza]<<endl;
            system("pause");
        }else{
            cout<<"EMPIEZA EL JUGADOR "<<jugadores[noEmpieza]<<endl;
            system("pause");
            ///SE CAMBIAN LOS VALOS PARA QUE LOS NOMBRES SE ENCUENTRE ORDENADOS
            aux = empieza;
            empieza = noEmpieza;
            noEmpieza = aux;

            /// SE CAMBIEN EL VALOR DEL DADO DE LA HORMIGA
            valorDadoBeneficioHormigaJ1=valorDadoBeneficioHormigaJ2;
            valorDadoBeneficioHormigaJ2=0;

            ///SE COPIA EL VALOR DEL VECTOR EMPIEZA A NOEMPIEZA Y VICEVERSA;
            for(int i=0; i<5; i++){
                vectorAuxiliar[i]=estatuillas_j1[i];
                estatuillas_j1[i]=estatuillas_j2[i];
                estatuillas_j2[i]=vectorAuxiliar[i];
            }
        }
        system("cls");

        ///SE REALIZAN LAS BUSQUEDAS DE LAS ESTATUILLAS MEDUSA Y SALAMANDRA

        if(buscarEstatua(estatuillas_j1, 5) == "Medusa"){
            estatuaMedusa_J1 = true;
        }else if(buscarEstatua(estatuillas_j2, 5) == "Medusa"){
            estatuaMedusa_J2 = true;
        }else if(buscarEstatua(estatuillas_j1, 5) == "Salamandra"){
            estatuaSalamandra_J1 = true;
        }else if(buscarEstatua(estatuillas_j2, 5) == "Salamandra"){
            estatuaSalamandra_J2 = true;
        }else if(buscarEstatua(estatuillas_j1, 5) == "Aguila"){
            aguila_J1 = true;
        }else if(buscarEstatua(estatuillas_j2, 5) == "Aguila"){
            aguila_J2 = true;
        }


        while(true){
                lanzamiento_j1 = lanzamiento_jugador_faseFinal(empieza, noEmpieza, jugadores, 5, jugadores[empieza], estatuillas_j1, estatuillas_j2, vEstatuillas, estatuaMedusa_J1, estatuaSalamandra_J1, aguila_J1, valorDadoBeneficioHormigaJ1, modoDiosActivado);

            if(lanzamiento_j1 == "GANASTE"){
                cout<<"FIN DEL JUEGO"<<endl;
                system("pause");
                system("cls");
                break;
            }
            lanzamiento_j2 = lanzamiento_jugador_faseFinal(empieza, noEmpieza, jugadores, 5, jugadores[noEmpieza], estatuillas_j1, estatuillas_j2, vEstatuillas, estatuaMedusa_J2, estatuaSalamandra_J2, aguila_J2, valorDadoBeneficioHormigaJ2,  modoDiosActivado);

            if(lanzamiento_j2 == "GANASTE"){
                cout<<"FIN DEL JUEGO"<<endl;
                system("pause");
                system("cls");
                break;
            }
        }
        break;
    }

}

/*if(aguila_activa){
                        /// LA MALDICION DEL AGUILA: UN JUGADOR TIRA DOBLE EL RESTO DE LA FASE

                        ///PREGUNTA SI EL QUE SACO LA ESTATUA AGUILA ES "EMPIEZA", PARA QUE TIRE DOS VECES "NOEMPIEZA"
                    if(jugadorAguila == empieza){

                        ///AQUI LANZA EL JUGADOR QUE EMPEZO
                        lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);

                            cout<<endl;
                            cout<<"AQUI COMIENZA LA PRIMER TIRADA DEL JUGADOR RIVAL - 'NO EMPIEZA'"<<endl;
                            system("pause");

                            ///PRIMER LANZAMIENTO DE JUGADOR "NOEMPIEZA"
                        lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);

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
                                        opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                        lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
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
                                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);

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

                                opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);

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

                        lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);

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
                        opcion_elegidaJ1 = seleccion_estatuilla_jugadores(jugadores[empieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);

                        ///lanzamiento_aguila_jugador = lanzamiento_aguila(empieza, noEmpieza, jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores);
                        lanzamiento_j1 = lanzamiento_jugador(jugadores, 5, jugadores[empieza], vEstatuillas[opcion_elegidaJ1-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ1, modoDiosActivado);

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

                                lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);

                                paso_lanzamiento_j2=true;

                                if(lanzamiento_j2 != "No obtuvo"){
                                    system("cls");
                                    cout<<"AL HABER SELECCIONADO LAS MISMAS ESTATUILLAS, EL JUGADOR "<<jugadores[empieza]<<" HA GANADO."<<endl;
                                    cout<<"POR FAVOR SELECCIONA NUEVAMENTE UNA ESTATUILLA: "<<endl;
                                    system("pause");
                                    system("cls");
                                    opcion_elegidaJ2 = seleccion_estatuilla_jugadores(jugadores[noEmpieza], jugadores, vEstatuillas, 5, estatuillas_j1, estatuillas_j2);
                                    lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2, vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
                                }
                            }
                        ///PREGUNTO SI PASO DE LANZAMIENTO ESTA FALSE ES PORQUE TODAVIA NO TIRO EL J2, SI ES TRUE ES QUE YA TIRO Y NO PUEDO TIRAR DE NUEVO.
                                if(!paso_lanzamiento_j2){
                                    lanzamiento_j2 = lanzamiento_jugador(jugadores, 5, jugadores[noEmpieza], vEstatuillas[opcion_elegidaJ2-1], estatuillas_j1, estatuillas_j2,vEstatuillas, puntosJugadores, llaveSalamandraJ2, modoDiosActivado);
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
                }*/
#endif // JUGAR_H_INCLUDED
