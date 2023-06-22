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
        }
    }
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

    int escalera = 0;

        ///COMPRUEBA SI TIENE LA LLAVE MEDUSA PARA VER BUSCAR LA ESLERA COMUN O BIEN DADOS IGUALES
            if(llaveMedusa){
                if(comprobar_dado(vDado, 5) == 1){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return "GANASTE";
                    }else{
                        for(int i = 0; i < 5; i++){
                                if(vDado[i] != vDado[0]){
                                        return "SIGUE";
                                }
                        }
                        cout<<">HAS GANADO, CON TODOS LOS DADOS IGUALES (BENEFICIO DE LA MADUSA)"<<endl;
                        return "GANASTE";
                    }
            }

            ///COMPRUEBA SI TIENE LA LLAVE SALAMANDRA
            if(llaveSalamandra){
                if(comprobar_dado(vDado, 5) == 1){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return "GANASTE";
                          }else if (escalera_corta(vDado, 5) == 1) {
                        cout<<">HAS GANADO, CON UNA ESCALERA CORTA (BENEFICIO DE LA SALAMANDRA)"<<endl;
                        return "GANASTE";
                    }else{
                        return "SIGUE";
                    }
            }

            ///COMPRUEBA LA ESCALERA DE TODOS LOS DADOS SIN IMPORTAR EL ORDEN.
                if(comprobar_dado(vDado, 5) == 1){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return "GANASTE";
                    }else{
                        return "SIGUE";
                    }

}

string lanzamiento_jugador_faseFinal(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas, bool llaveMedusa, bool llaveSalamandra,bool aguilaActiva, int valorDadoH, bool modoDios){
    while(true){
            system("cls");

            int dadoSelecionado, dadoNuevo;
            int vDado[5] = {};

            string no_obtuvo = "No obtuvo";

            string obtencionEscalera;

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

            for(int i = 0; i < 5; i++){
                cout<<vDado[i]<<" ";
            }
            system("pause");

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
                    cout<<"Que dado desea cambiar :";
                    cin>>dadoSelecionado;

                    vDado[dadoSelecionado-1] = valorDadoH;

                    valorDadoH=0;
                    goto atrasH;
                }

                obtencionEscalera = obtencion_escalera(vDado, llaveMedusa, llaveSalamandra);
                system("pause");
                system("cls");
               return obtencionEscalera;
    }
}

#endif // FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
