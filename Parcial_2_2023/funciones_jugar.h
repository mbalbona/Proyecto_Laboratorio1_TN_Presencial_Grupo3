#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED

int tiraDado(){
    int  numero = 10;

    return ( rand() % numero) + 1;
}

void mostrar_estatuillas(string estatuillas_jugador[], int tam){
    for(int i = 0; i < tam; i++){
        cout<<estatuillas_jugador[i];
    }
}


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

int lanzamiento_estatuilla(string *vEstatuas, int tam){
    int opc;
    for(int i = 0; i < 5; i++){
        cout<<i+1<<")"<<vEstatuas[i]<<endl;
    }
    cout<<endl;
    cout<<"Opcion a elegir: ";
    cin>>opc;

    return opc;
}

string condicion_estatua(string *vEstatuas, int tam, string opcion){
    int opc;
    string vCondicion[5] = {};
    for(int i = 0; i < tam; i++){
        if( vEstatuas[i] == opcion){
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

void  obtencion_estatua(int dado1, int dado2, string *vEstatuas, int tam, string opcion){
    int opc;

    for(int i = 0; i < tam; i++){
        if(vEstatuas[i] == opcion){
            opc = i;
        }
    }

    switch(opc){
        case 0: if((dado1 % 2 == 0 && dado2 % 2 == 1) || (dado1 % 2 == 1 && dado2 % 2 == 0)){
                        cout<<"Cangrejo"<<endl;
                        return;
                        }
                        break;
        case 1:  if(dado1 < 5 && dado2 < 5){
                        cout<<"Hormiga"<<endl;
                        return;
                        }
                        break;
        case 2:   if((dado1 + dado2) == 7){
                        cout<<"Medusa"<<endl;
                        return;
                        }
                        break;
        case 3:   if((dado1 == 1 && dado2 == 10) || (dado1 == 10 && dado2 == 1)){
                        cout<<"Aguila"<<endl;
                        return;
                        }
                        break;
        case 4: if(((dado1 + 1) == dado2) || (dado2 + 1) == dado1){
                        cout<<"Salamandra"<<endl;
                        return;
                        }
                        break;
    }

    cout<<"NO HAS OBTENIDO NIGUNA ESTATUILLAS"<<endl;
    return;


}

void lanzamiento_primer_turno(string *jugadores, string jugador, string opcion, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas){
    while(true){
    system("cls");
    int dado1, dado2;

    string condicion;

    cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<jugadores[0]<<"\t\t\t\t";
    cout<<jugadores[1]<<endl;
    cout<<"ESTATUILLAS: ";
    mostrar_estatuillas(estatuillas_j1, 5);
    cout<<"\t\t";
    cout<<"ESTATUILLAS: ";
    mostrar_estatuillas(estatuillas_j2, 5);
    cout<<endl;
    cout<<"---------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"TURNO DE "<<jugador<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"ESTATUILLA OBJETIVO: "<<opcion<<endl;
    condicion = condicion_estatua(vEstatuas,5,opcion);
    cout<<"CONDICIONES DE OBTENCION: "<<condicion<<endl;

    cout<<"Primer dado: ";
    dado1 = tiraDado();
    cout<<dado1<<endl;

    cout<<"Segundo dado: ";
    dado2 = tiraDado();
    cout<<dado2<<endl;

    obtencion_estatua(dado1, dado2, vEstatuas, 5, opcion);

    system("pause");
    }
}
#endif // FUNCIONES_JUGAR_H_INCLUDED
