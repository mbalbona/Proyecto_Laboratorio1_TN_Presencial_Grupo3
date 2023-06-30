#ifndef FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
#define FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED

///FUNCION CONTAR ESTATUAS
int contadorEstatuillas(string *estatuillas_Jugador, int tam){
        int contador_Estatuillas=0;

        for(int i=0; i<tam; i++){
            if(estatuillas_Jugador[i]!= ""){
                contador_Estatuillas++;
            }
        }
        return contador_Estatuillas;
}

///FUNCION BUSCAR LAS 3 ESTATUAS QUE MODIFICAN LOS DADOS
string buscarEstatua(string *estatua, int tam){
    for(int i=0; i<tam; i++){
        if(estatua[i] == "Medusa"){
            return "Medusa";
        }else if(estatua[i] == "Salamandra"){
            return "Salamandra";
        }else if(estatua[i] == "Hormiga"){
            return "Hormiga";
        }else if(estatua[i] == "Aguila"){
            return "Aguila";
        }
    }
}

///FUNCION QUE COMPRUEBA ESCALERA

int comprobar_dado(int *vDado, int tam){
     ///DECLARAMOS UN VECTOR AUXILIAR PARA NO MODIFICAR EL VECTOR ORIGINAL DADO QUE ES UN PUNTERO
     int vecAux[5];
     int aux;

     for(int i = 0; i < tam; i++){
        vecAux[i] == vDado[i];
     }

     ///ORDENAMOS EL VECTOR AUXILIAR
     for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - i - 1; j++) {
            if (vecAux[j] > vecAux[j + 1]) {
                aux = vecAux[j];
                vecAux[j] = vecAux[j + 1];
                vecAux[j + 1] = aux;
            }
        }
    }

    ///CON EL VECTOR AUXILIAR ORDENADO VEMOS SI ES ESCALERA
    for (int i = 0; i < tam - 1; i++) {
        if (vecAux[i] != vecAux[i + 1] - 1) {
            return 0;  // No es una escalera
        }
    }

    return 1;
}

///FUNCION QUE COMPRUEBA SI HAY ESCALERA CORTA O NO
int escalera_corta(int *vDado, int tam){
    int cont = 0;

      for (int i = 1; i < tam; i++) {
        if (vDado[i] != vDado[i-1] + 1) {
            return 0;  // No es una escalera corta
        }
        else{
           cont++;
        }
      }

        ///SI EL CONTADOR ES IGUAL A CUATRO SIGNIFICA HAY 4 NUMEROS CONSECUTIVOS LO CUAL SE TRADUCE EN UNA ESCALERA CORTA
       if(cont == 4){
               return 1; //Escalera corta
       }
}

///FUNCION COMPROBAR ESCALERA
string obtencion_escalera(int *vDado, bool llaveMedusa, bool llaveSalamandra ){

    int iguales = 0;

        ///COMPRUEBA SI TIENE LA LLAVE MEDUSA PARA VER BUSCAR LA ESLERA COMUN O BIEN DADOS IGUALES
            if(llaveMedusa){
                if(comprobar_dado(vDado, 5) == 1){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return "GANASTE";
                    }else{
                        for(int i = 0; i < 5; i++){
                                if(vDado[i] == vDado[0]){
                                       iguales++;
                                }
                        }
                        if(iguales == 5){
                            cout<<">HAS GANADO, CON TODOS LOS DADOS IGUALES (BENEFICIO DE LA MEDUSA)"<<endl;
                            return "GANASTE";
                        }
                    }
            }

            ///COMPRUEBA SI TIENE LA LLAVE SALAMANDRA
            if(llaveSalamandra){
                if(comprobar_dado(vDado, 5) == 1){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return "GANASTE";
                    }
                    else if(escalera_corta(vDado, 5) == 1) {
                        cout<<">HAS GANADO, CON UNA ESCALERA CORTA (BENEFICIO DE LA SALAMANDRA)"<<endl;
                        return "GANASTE";
                    }
            }

        return "SIGUE";

}

string lanzamiento_jugador_faseFinal(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas, bool llaveMedusa, bool llaveSalamandra,bool aguilaActiva, int valorDadoH, bool modoDios, bool cangrejo){
    while(true){
            system("cls");

            int dadoSelecionado, dadoNuevo;
            int vDado[5] = {};

            string no_obtuvo = "No obtuvo";

            string obtencionEscalera;

            tirada:
            cout<<"\tIRWIN'S REVENGE - FASE FINAL"<<endl;
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
            cout<<"LANZAMIENTO"<<endl;
            cout<<endl;


            tiraDado_6_caras(vDado, modoDios);

                atras:
                atrasH:
                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "|  " << vDado[0] << "  | "<< "|  " << vDado[1] << "  | "<< "|  " << vDado[2] << "  | "<< "|  " << vDado[3]<< "  | "<< "|  " << vDado[4] << "  |\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";

                if(aguilaActiva){
                    cout<<"¿Que dado desea modificar?"<<endl;
                    cout<<"Indique el numero de dado: ";
                    cin>>dadoSelecionado;
                    cout<<"Indique el nuevo valor del dado: ";
                    cin>>vDado[dadoSelecionado-1];
                    cout<<endl;

                    aguilaActiva=false;
                    goto atras;

                }

                if(valorDadoH != 0){
                    dado:
                    cout<<"Que dado desea cambiar:";
                    cin>>dadoSelecionado;

                    if( (dadoSelecionado < 0) || (dadoSelecionado > 5) ){
                        cout<<"VALOR INVALIDO! ELIJA NUEVAMENTE EL DADO A CAMBIAR."<<endl;
                        cout<<endl;
                        goto dado;
                    }else{
                        vDado[dadoSelecionado-1] = valorDadoH;
                    }

                    goto atrasH;
                }

                obtencionEscalera = obtencion_escalera(vDado, llaveMedusa, llaveSalamandra);

                if( (primer_turno_final == true) && (obtencionEscalera == "SIGUE") && (cangrejo == true) ) {
                    cout<<"AL SER EL PRIMER TURNO DE LA FASE FINAL Y POSEER LA ESTATUA DEL CANGREJO VUELVE A TIRAR NUEVAMENTE!"<<endl;
                    system("pause");
                    system("cls");
                    primer_turno_final = false;
                    goto tirada;
                }else if( (primer_turno_final == true) && (obtencionEscalera != "SIGUE") && (cangrejo == true) ){
                    return "GANASTE";
                }

                system("pause");
                system("cls");

               return obtencionEscalera;
    }
}

#endif // FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
