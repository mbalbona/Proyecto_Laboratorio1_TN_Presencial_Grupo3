#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED


///Funcion para tirar dado (10 caras)
int tiraDado(){
    int  numero = 10;

    return (rand() % numero) + 1;
}

///Dado de 6 caras
int tiraDado_6_caras(){
    int  numero = 6;

    return (rand() % numero) + 1;
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
int primerTurno(string jugadores[2]){
    int dadoAnterior, ultimoDado;
    int jugador;

    atras:
    for(int i = 0; i < 2 ; i++){
        if(i == 0){
            ultimoDado = tiraDado();
            dadoAnterior = ultimoDado;
            jugador = i;
            cout<<endl;
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
        }else{
            ultimoDado = tiraDado();
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

///Funcion que determina si ganaste o no ganaste una estatua
string obtencion_estatua(int dado1, int dado2, string *vEstatuas, int tam, string opcion){
    int opc;
    string nada = "Nada";


    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == opcion){
            opc = i;
        }
    }

    switch(opc){
        case 0: if((dado1 % 2 == 0 && dado2 % 2 == 1) || (dado1 % 2 == 1 && dado2 % 2 == 0)){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: CANGREJO"<<endl;

                        return "Cangrejo";
                        }
                        break;
        case 1:  if(dado1 < 5 && dado2 < 5){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: HORMIGA"<<endl;
                        return "Hormiga";
                        }
                        break;
        case 2:   if((dado1 + dado2) == 7){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: MEDUSA"<<endl;
                        return "Medusa";
                        }
                        break;
        case 3:   if((dado1 == 1 && dado2 == 10) || (dado1 == 10 && dado2 == 1)){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: ANGUILA"<<endl;
                        return"Aguila";
                        }
                        break;
        case 4: if(((dado1 + 1) == dado2) || (dado2 + 1) == dado1){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: SALAMANDRA"<<endl;
                        return "Salamandra";
                        }
                        break;
    }

    cout<<">NO HAS OBTENIDO NIGUNA ESTATUILLA"<<endl;
    return nada;


}

///Funcion que determina si ganaste o no ganaste una estatua MALDICION SALAMANDRA
string obtencion_estatuaMS(int dado1, int dado2, int dado3, string *vEstatuas, int tam, string opcion){
    int opc;
    string nada = "Nada";

    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == opcion){
            opc = i;
        }
    }

    switch(opc){
        case 0: if((dado1 % 2 == 0 && dado2 % 2 == 1) || (dado1 % 2 == 1 && dado2 % 2 == 0)|| (dado1 % 2 == 0 && dado3 % 2 == 1) || (dado1 % 2 == 1 && dado3 % 2 == 0) || (dado2 % 2 == 0 && dado3 % 2 == 1)||(dado2 % 2 == 1 && dado3 % 2 == 0)) {
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: CANGREJO"<<endl;

                        return "Cangrejo";
                        }
                        break;
        case 1:  if(dado1 < 5 && dado2 < 5 || dado1 < 5 && dado3 < 5 || dado2 < 5 && dado3 < 5){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: HORMIGA"<<endl;
                        return "Hormiga";
                        }
                        break;
        case 2:   if((dado1 + dado2) == 7 || (dado1+dado3)== 7 || (dado2+dado3)== 7){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: MEDUSA"<<endl;
                        return "Medusa";
                        }
                        break;
        case 3:   if((dado1 == 1 && dado2 == 10) || (dado1 == 10 && dado2 == 1) || (dado1 == 1 && dado3==10) || (dado1 == 10 && dado3 == 1) || (dado2 == 1 && dado3==10) || (dado2 == 10 && dado3 == 1)){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: ANGUILA"<<endl;
                        return"Aguila";
                        }
                        break;
        case 4: if(((dado1 + 1) == dado2) || (dado2 + 1) == dado1){
                        cout<<">HAS OBTENIDO LA ESTATUA SELECCIONADA: SALAMANDRA"<<endl;
                        return "Salamandra";
                        }
                        break;
    }

    cout<<">NO HAS OBTENIDO NIGUNA ESTATUILLA"<<endl;
    return nada;

}

///Interfaz de jugador seleccionando por cual estatua jugara

int seleccion_estatuilla_jugadores(int empieza, int noEmpieza, string jugador, string *jugadores, string *vEstatuas, int tam, string *estatuas_j1, string *estatuas_j2){

            int opcion_elegida;
            atras:
            cout<<"\tIRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[empieza]<<"\t\t\t\t";
            cout<<jugadores[noEmpieza]<<endl;
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
void maldicion_cangrejo(string *, string , int *, string *);
void maldicion_hormiga(string *, string , int *);
bool maldicion_medusa(string *, string , int *);
void maldicion_aguila(string *, string , int *);
void maldicion_salamandra(string *, string , int *);


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
            medusa = 1;
            return medusa;
            break;
        case 3: cout<<"LA MALDICION DEL AGUILA SE ACTIVA!"<<endl;
            aguila = 2;
            return aguila;
            break;
        case 4: cout<<"LA MALDICION DE LA SALAMANDRA SE ACTIVA!"<<endl;
            salamandra = 3;
            return salamandra;
            break;
    }

}

void maldicion_cangrejo(string *jugadores, string jugador, int *puntosJugador, string *vEstatuas){
    system("cls");

    int pos, dado, rival;
    bool esta_cangrejo = false;

    for(int i = 0; i < 2; i++){
        if(jugadores[i] == jugador){
            pos = i;
        }
    }

    for(int i = 0; i < 5; i++){
            if(vEstatuas[i] == "Cangrejo"){
                esta_cangrejo = true;
            }
    }
    if(pos==0){
        rival=1;
    }else{
        rival=0;
    }

    if(esta_cangrejo = true){
        cout<<"EL JUGADOR "<<jugadores[rival]<<" DEBE TIRAR UN DADO, POR LA MALDICION DEL CANGREJO."<<endl;
        system("pause");
        dado = tiraDado();

        cout<<"SALIO DADO: "<<dado<<endl;

        puntosJugador[pos] -= dado;

        cout<<"EL JUGADOR "<<jugadores[pos]<<" PIERDE "<<dado<<" PUNTOS DEBIDO A LA MALDICION DEL CANGREJO."<<endl;
    }
}

void maldicion_hormiga(string *jugadores, string jugador, int *puntosJugador){
    system("cls");

    int dado1, dado2, pos, rival;

    for(int i = 0; i < 2; i++){
        if(jugadores[i] == jugador){
            pos = i;
        }
    }

    if(pos==0){
        rival=1;
    }else{
        rival=0;
    }
    cout<<"EL JUGADOR "<<jugadores[rival]<<" DEBE TIRAR DOS DADO, POR LA MALDICION DE LA HORMIGA."<<endl;
    system("pause");

    dado1 = tiraDado();
    dado2 = tiraDado();

    cout<<"SALIO DADO 1: "<<dado1<<endl;
    cout<<"SALIO DADO 2: "<<dado2<<endl;

    puntosJugador[pos] -= (dado1 + dado2);

    cout<<"EL JUGADOR "<<jugadores[pos]<<" PIERDE "<<(dado1+dado2)<<" PUNTOS DEBIDO A LA MALDICION DE LA HORMIGA."<<endl;
}

void maldicion_aguila(string *jugadores, string jugador, int *puntosJugador){

}
void maldicion_salamandra(string *jugadores, string jugador, int *puntosJugador){

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

string lanzamiento_jugador(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string opcion, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas, int *puntosJugadores, bool llaveSalamandra){
    while(true){
            system("cls");

            int dado1, dado2, dado3;

            string no_obtuvo = "No obtuvo";

            string condicion, estatua_obtenida;

            cout<<"\tIRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[empieza]<<"\t\t\t\t";
            cout<<jugadores[noEmpieza]<<endl;
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

                cout<<"Primer dado: ";
                dado1 = tiraDado();
                cout<<dado1<<endl;
                cout<<endl;

                cout<<"Segundo dado: ";
                dado2 = tiraDado();
                cout<<dado2<<endl;
                cout<<endl;

                if(llaveSalamandra){
                    cout<<"Tercer dado: ";
                    dado3 = tiraDado();
                    cout<<dado3<<endl;
                    cout<<endl;
                }

                if(llaveSalamandra){
                    estatua_obtenida = obtencion_estatuaMS(dado1,dado2,dado3,vEstatuas,tam,opcion);
                }else{
                    estatua_obtenida = obtencion_estatua(dado1,dado2,vEstatuas,tam,opcion);
                }


            if(estatua_obtenida == "Nada"){
                system("pause");
                system("cls");
                return no_obtuvo;
            }else{
                comprobar_maldicion(vEstatuas, tam, estatua_obtenida, jugadores, jugador, puntosJugadores);
                system("pause");
                system("cls");
               return estatua_obtenida;
            }
    }
}

#endif // FUNCIONES_JUGAR_H_INCLUDED

