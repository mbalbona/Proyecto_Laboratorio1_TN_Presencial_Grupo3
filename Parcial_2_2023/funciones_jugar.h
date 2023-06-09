#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED

///Funcion para tirar dado
int tiraDado(){
    int  numero = 10;

    return (rand() % numero) + 1;
}

///Mostramos las estatuas del jugador
void mostrar_estatuillas(string *estatuillas_jugador, int tam){

    for(int i = 0; i < tam; i++){
        if((estatuillas_jugador[i] != " ") || (estatuillas_jugador[i] != "Ninguna")){
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
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
        }else{
            ultimoDado = tiraDado();
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;

            if(ultimoDado == dadoAnterior){
                system("cls");
                cout<<"Los dados se repitieron. Se vuelve a tirar."<<endl;
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
        if(vEstatuas[i] != " "){
            cout<<i+1<<")"<<vEstatuas[i]<<endl;
        }
    }
    cout<<endl;
    cout<<"Opcion a elegir: ";
    cin>>opc;

    return opc;
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
                        cout<<"HAS OBTENIDO LA ESTATUA SELECCIONADA: CANGREJO"<<endl;
                        return "cangrejo";
                        }
                        break;
        case 1:  if(dado1 < 5 && dado2 < 5){
                        cout<<"HAS OBTENIDO LA ESTATUA SELECCIONADA: HORMIGA"<<endl;
                        return "hormiga";
                        }
                        break;
        case 2:   if((dado1 + dado2) == 7){
                        cout<<"HAS OBTENIDO LA ESTATUA SELECCIONADA: MEDUSA"<<endl;
                        return "medusa";
                        }
                        break;
        case 3:   if((dado1 == 1 && dado2 == 10) || (dado1 == 10 && dado2 == 1)){
                        cout<<"HAS OBTENIDO LA ESTATUA SELECCIONADA: ANGUILA"<<endl;
                        return"anguila";
                        }
                        break;
        case 4: if(((dado1 + 1) == dado2) || (dado2 + 1) == dado1){
                        cout<<"HAS OBTENIDO LA ESTATUA SELECCIONADA: "<<endl;
                        return "salamandra";
                        }
                        break;
    }

    cout<<"NO HAS OBTENIDO NIGUNA ESTATUILLA"<<endl;
    return nada;


}

///Interfaz de jugador seleccionando por cual estatua jugara

int seleccion_estatuilla_jugadores(int empieza, int noEmpieza, string jugador, string *jugadores, string *vEstatuas, int tam, string *estatuas_j1, string *estatuas_j2){
            int opcion_elegida;

            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[empieza]<<"\t\t\t\t";
            cout<<jugadores[noEmpieza]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuas_j1, tam);
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuas_j2, tam);
            cout<<endl;
            cout<<"Por que estatuilla lanzaras "<<jugador<<"?"<<endl;
            opcion_elegida = lanzamiento_estatuilla(vEstatuas, 5);

            system("cls");
            return opcion_elegida;

}


///Lanzamiento de estatuillas
///SE AGREGARON LOS PARAMETROS EMPIEZA Y NOEMPIEZA PARA PASARLOS A JUGADORES ASI MANTIENE LOS NOMBRES EN SU LUGAR

string lanzamiento_jugador(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string opcion, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas){
    while(true){
            system("cls");

            int dado1, dado2;
            string no_obtuvo = "No obtuvo";

            string condicion, estatua_obtenida;

            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<jugadores[empieza]<<"\t\t\t\t";
            cout<<jugadores[noEmpieza]<<endl;
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j1, tam);
            cout<<"\n";
            cout<<"\t\t";
            cout<<"ESTATUILLAS: ";
            mostrar_estatuillas(estatuillas_j2, tam);
            cout<<endl;
            cout<<"---------------------------------------------------"<<endl;
            cout<<endl;
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

            cout<<"Segundo dado: ";
            dado2 = tiraDado();
            cout<<dado2<<endl;
            cout<<endl;

            estatua_obtenida = obtencion_estatua(dado1,dado2,vEstatuas,tam,opcion);

            if(estatua_obtenida == "Nada"){
                system("pause");
                system("cls");
                return no_obtuvo;
            }else{
                system("pause");
                system("cls");
                return estatua_obtenida;
            }

    }
}


#endif // FUNCIONES_JUGAR_H_INCLUDED

