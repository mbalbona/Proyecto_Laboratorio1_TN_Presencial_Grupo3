#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED


///Funcion para tirar dado (10 caras)
int tiraDado(int *vDados, int tam, bool modoDios){
    int numero = 10;

    if(!modoDios){
        for(int i = 0; i < tam; i++){
            vDados[i] = (rand() % numero) + 1;
        }
    }else{
        atras:
        for(int i = 0; i < tam; i++){

            cout<<"Ingrese el dado numero "<<i+1<<": ";
            cin>>vDados[i];
            cout<<endl;
            if(vDados[i] > 10 || vDados[i] < 1){
                cout<<"INGRESE UN VALOR DENTRO DEL RANGO DE UN DADO DE 10 CARAS!!"<<endl;
                system("pause");
                system("cls");
                goto atras;
            }
        }
    }
}

///Dado de 6 caras
int tiraDado_6_caras(int *vDados, bool modoDios){
    int  numero = 6;

    if(!modoDios){
        for(int i = 0; i < 5; i++){
            vDados[i] = (rand() % numero) + 1;
        }
    }else{
        atras:
        for(int i = 0; i < 5; i++){
            cout<<"Ingrese el dado numero "<<i+1<<": ";
            cin>>vDados[i];
            cout<<endl;
            if(vDados[i] > 6 || vDados[i] < 1){
                cout<<"INGRESE UN VALOR DENTRO DEL RANGO DE UN DADO DE 6 CARAS!!"<<endl;
                system("pause");
                system("cls");
                goto atras;
            }
        }
    }
}

///Mostramos las estatuas del jugador
void mostrar_estatuillas(string *estatuillas_jugador, int tam){

    for(int i = 0; i < tam; i++){
        if(estatuillas_jugador[i] != ""){
            cout<<estatuillas_jugador[i]<<" ";
        }
    }

}

///Funcion para utilizar el jugador elegido para el primer turno y su primer turno completo
int primerTurno(string jugadores[2], bool modoDios){

    int dadoAnterior, ultimoDado, numero = 10;
    int jugador;

    atras:
    for(int i = 0; i < 2 ; i++){
        if(i == 0){
            ultimoDado = (rand() % numero) + 1;
            dadoAnterior = ultimoDado;
            jugador = i;
            cout<<endl;
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
        }else{
            ultimoDado = (rand() % numero) + 1;
            cout<<endl;
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;

            if(ultimoDado == dadoAnterior){
                system("cls");
                cout<<endl;
                cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
                cout<<endl;
                cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
                cout<<"Los dados se repitieron. Se vuelve a tirar."<<endl;
                cout<<endl;
                system("Pause");
                system("cls");
                goto atras;
            }
            else if(ultimoDado < dadoAnterior){
                jugador = i;
                return jugador;
            }
        }
    }

    return jugador;
}

///Funcion para elegir por cual estatuilla vamos a jugar este turno
int lanzamiento_estatuilla(string *vEstatuas, int tam){
    int opc;
    for(int i = 0; i < 5; i++){
        if(vEstatuas[i] != ""){
            cout<<i+1<<")"<<vEstatuas[i]<<endl;
        }
    }
    cout<<endl;
    cout<<"Opcion a elegir: ";
    cin>>opc;

    if((opc > 5) || (opc < 1)){
        return -1;
    }else if(vEstatuas[opc-1].length() == 0){
        return -1;
    }else if(opc > 0 && opc < 6){
        return opc;
    }
}

///Funcion para mostrar la condicion de obtencion de la estatua
string condicion_estatua(string *vEstatuas, int tam, string opcion){
    int opc;
    string vCondicion[5] = {};

    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == opcion){
            opc = i;
        }
    }

    for(int i = 0; i < tam; i++){
        if(i == 0){
            vCondicion[i] = "Uno de sus dados debe ser par y otro de sus dados impar";
        }else if(i == 1){
            vCondicion[i] = "Al menos dos dados deben ser menores a 5.";
        }else if(i == 2){
            vCondicion[i] = "La suma de dos de los dados lanzados debe dar exactamente siete.";
        }else if(i == 3){
            vCondicion[i] = "Dos de los dados lanzados deberan devolver los numeros 1 y 10.";
        }else if(i == 4){
            vCondicion[i] = "Los dados lanzados deben ser consecutivos. Por ejemplo: (1 y 2) (2 y 3) (9 y 10).";
        }
    }

    return vCondicion[opc];
}

///Comprobamos vector de dados para activar maldiciones en fase de expedicion
string comprobar_dado_expedicion(int *vDados, int tam, bool llaveSalamandra, string opcion){

    if(llaveSalamandra){
        if( (opcion == "Cangrejo") && (vDados[0] % 2 == 0) && (vDados[1] % 2 == 1) || (vDados[1] % 2 == 0) && (vDados[2] % 2 == 1) || (vDados[0] % 2 == 0) && (vDados[2] % 2 == 1)){
                return "Cangrejo";
            }
        else if( (opcion == "Hormiga") && (vDados[0] < 5) && (vDados[1] < 5) || (vDados[1] < 5) && (vDados[2] < 5) || (vDados[0] < 5) && (vDados[2] < 5) ){
            return "Hormiga";
        }
        else if( (opcion == "Medusa") && (vDados[0] + vDados[1]) == 7 || (vDados[1] + vDados[2]) == 7 || (vDados[0] + vDados[2]) == 7){
            return "Medusa";
        }
        else if( (opcion == "Aguila") && (vDados[0] == 1) && (vDados[1] == 10) || (vDados[1] == 1) && (vDados[0] == 10) || (vDados[0] == 1) && (vDados[2] == 10) || (vDados[2] == 1) && (vDados[0] == 10 || (vDados[2] == 1) && (vDados[1] == 10)) || (vDados[1] == 1) && (vDados[2] == 10)){
            return "Aguila";
        }

    }else{
        if( (opcion == "Cangrejo") && (vDados[0] % 2 == 0) && (vDados[1] % 2 == 1) ){
                return "Cangrejo";
            }
        else if( (opcion == "Hormiga") && (vDados[0] < 5) && (vDados[1] < 5) ){
            return "Hormiga";
        }
        else if( (opcion == "Medusa") && ((vDados[0] + vDados[1]) == 7) ){
            return "Medusa";
        }
        else if( (opcion == "Aguila") && (vDados[0] == 1) && (vDados[1] == 10) ){
            return "Aguila";
        }
        else if( comprobar_dado(vDados, 2) == 1 ){
            return "Salamandra";
        }
    }
}

///Funcion que determina si ganaste o no ganaste una estatua
string obtencion_estatua(int *vDados, string *vEstatuas, int tam, string opcion, bool llaveSalamandra){
    int opc;

    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == opcion){
            opc = i;
        }
    }

    switch(opc){
        case 0: if(comprobar_dado_expedicion(vDados, 3, llaveSalamandra, opcion) == "Cangrejo"){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: CANGREJO"<<endl;
                        return "Cangrejo";
                        }
                        break;
        case 1:  if(comprobar_dado_expedicion(vDados, 3, llaveSalamandra, opcion) == "Hormiga"){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: HORMIGA"<<endl;
                        return "Hormiga";
                        }
                        break;
        case 2:   if(comprobar_dado_expedicion(vDados, 3, llaveSalamandra, opcion) == "Medusa"){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: MEDUSA"<<endl;
                        return "Medusa";
                        }
                        break;
        case 3:   if(comprobar_dado_expedicion(vDados, 3, llaveSalamandra, opcion) == "Aguila"){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: AGUILA"<<endl;
                        return"Aguila";
                        }
                        break;
        case 4: if(comprobar_dado_expedicion(vDados, 3, llaveSalamandra, opcion) == "Salamandra"){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: SALAMANDRA"<<endl;
                        return "Salamandra";
                        }
                        break;
    }

    cout<<">NO HAS OBTENIDO NIGUNA ESTATUILLA"<<endl;
    return "Nada";

}


///Interfaz de jugador seleccionando por cual estatua jugara

int seleccion_estatuilla_jugadores(string jugador, string *jugadores, string *vEstatuas, int tam, string *estatuas_j1, string *estatuas_j2){

            int opcion_elegida;

            atras:
            cout<<"\tIRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[0]<<"\t\t\t\t";
            cout<<jugadores[1]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuas_j1, tam);
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuas_j2, tam);
            cout<<endl;
            cout<<endl;
            cout<<"Por que estatuilla lanzaras "<<jugador<<"?"<<endl;
            opcion_elegida = lanzamiento_estatuilla(vEstatuas, 5);

            if(opcion_elegida == -1){
                cout<<endl;
                cout<<"OPCION INCORRECTA. INGRESE UN VALOR CORRECTO."<<endl;
                system("pause");
                system("cls");
                goto atras;
            }

            system("cls");
            return opcion_elegida;

}

///DECLARAMOS LAS FUNCIONES DE LAS MALDICIONES

#include "maldiciones.h"

int comprobar_maldicion(string *vEstatuas, int tam, string estatua_obtenida, string *jugadores, string jugador, int *puntosJugadores){
    int opc, aguila = 0, salamandra = 0, medusa = 0;

    ///Obtenemos la posicion de la estatua que se obtuvo
    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == estatua_obtenida){
            opc = i;
        }
    }

    ///Comprobamos que maldicion obtuvo
    switch(opc){
        case 0: cout<<"LA MALDICION DEL CANGREJO SE ACTIVA!"<<endl;
            system("pause");
            maldicion_cangrejo(jugadores, jugador, puntosJugadores, vEstatuas);
            break;
        case 1: cout<<"LA MALDICION DE LA HORMIGA SE ACTIVA!"<<endl;
            maldicion_hormiga(jugadores, jugador, puntosJugadores);
            break;
        case 2: cout<<"LA MALDICION DE LA MEDUSA SE ACTIVA!"<<endl;
            break;
        case 3: cout<<"LA MALDICION DEL AGUILA SE ACTIVA!"<<endl;
            break;
        case 4: cout<<"LA MALDICION DE LA SALAMANDRA SE ACTIVA!"<<endl;
            break;
    }

}


///FIN DE FUNCIONES DE MALDICIONES

///FUNCION PARA RECORRER LAS ESTATUAS Y DETERMINAR EL FIN DE LA FASE DE EXPEDICION
int recorrer_estatuas(string *vEstatuas, int tam){
    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == ""){
            cont++;
        }
    }

    if(cont == 5){
        return 0;
        }
        else{
            return 1;
    }
}

///Lanzamiento de estatuillas

string lanzamiento_jugador(string *jugadores, int tam,  string jugador, string opcion, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas, int *puntosJugadores, bool llaveSalamandra, bool modoDiosActivado){
    while(true){
            system("cls");

            int vDados[3] = {};

            string no_obtuvo = "No obtuvo";

            string condicion, estatua_obtenida;

            cout<<"\tIRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[0]<<" "<<puntosJugadores[0]<<"\t\t\t\t";
            cout<<jugadores[1]<<" "<<puntosJugadores[1]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j1, tam);
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j2, tam);
            cout<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"TURNO DE "<<jugador<<endl;
            cout<<"-------------------------"<<endl;
            cout<<"ESTATUILLA OBJETIVO: "<<opcion<<endl;
            condicion = condicion_estatua(vEstatuas,tam,opcion);
            cout<<"CONDICIONES DE OBTENCION: "<<condicion<<endl;
            cout<<"-------------------------"<<endl;

            tiraDado(vDados, 2,  modoDiosActivado);

            cout<<"DADO 1: "<<vDados[0]<<endl;
            cout<<"DADO 2: "<<vDados[1]<<endl;
            cout<<endl;

            estatua_obtenida = obtencion_estatua(vDados,vEstatuas, tam,opcion, llaveSalamandra);

            if(estatua_obtenida == "Nada"){
                system("pause");
                system("cls");
                return no_obtuvo;
            }else{
                comprobar_maldicion(vEstatuas,5,estatua_obtenida,jugadores,jugador,puntosJugadores);
                system("pause");
                system("cls");
               return estatua_obtenida;
            }
    }
}


#endif // FUNCIONES_JUGAR_H_INCLUDED

