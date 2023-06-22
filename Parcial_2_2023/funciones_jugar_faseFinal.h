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

///FUNCION BUSCAR ESTATUA MEDUSA
bool buscarEstatuaM(string *estatua, int tam){
    for(int i=0; i<tam; i++){
        if(estatua[i] == "Medusa"){
            return true;
        }
    }
     return false;
}

///FUNCIONA BUSCAR ESTATUA SALAMANDRA
bool buscarEstatuaS(string *estatua, int tam){
    for(int i=0; i<tam; i++){
        if(estatua[i] == "Salamandra"){
            return true;
        }
    }
    return false;
}

bool buscarEstatuaA(string *estatuaAguila, int tam){
    for(int i=0; i<tam; i++){
        if(estatuaAguila[i] == "Aguila"){
            return true;
        }
    }
    return false;
}

///FUNCION COMPROBAR ESCALERA
string obtencion_escalera(int dado1, int dado2,int dado3,int dado4,int dado5, bool llaveMedusa, bool llaveSalamandra ){

    string sigue = "SIGUE";
    string ganaste = "GANASTE";

        ///COMPRUEBA SI TIENE LA LLAVE MEDUSA PARA VER BUSCAR LA ESLERA COMUN O BIEN DADOS IGUALES
            if(llaveMedusa){
                if( (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 15 || (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 20 ){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return ganaste;
                    }else if(dado1 == dado2 && dado2 == dado3 && dado3 == dado4 && dado4 == dado5){
                            cout<<">HAS GANADO, CON TODOS LOS DADOS IGUALES (BENEFICIO DE LA MADUSA)"<<endl;
                        return ganaste;
                    }
            }

            ///COMPRUEBA SI TIENE LA LLAVE SALAMANDRA
            if(llaveSalamandra){
                if( (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 15 || (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 20 ){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return ganaste;
                          }else if (dado1 == 1 && dado2 == 2 && dado3 == 3 && dado4 == 4 || dado1 == 2 && dado2 == 3 && dado3 == 4 && dado4 == 5 || dado1 == 3 && dado2 == 4 && dado3 == 5 && dado4 == 6) {
                        cout<<">HAS GANADO, CON UNA ESCALERA CORTA (BENEFICIO DE LA SALAMANDRA)"<<endl;
                        return ganaste;
                    }else{
                        return sigue;
                    }
            }

            ///COMPRUEBA LA ESCALERA DE TODOS LOS DADOS SIN IMPORTAR EL ORDEN.
                if( (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 15 || (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 20 ){
                        cout<<">HAS GANADO, CON UNA ESCALERA"<<endl;
                        return ganaste;
                          }else{
                        return sigue;
                          }

}

string lanzamiento_jugador_faseFinal(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas, bool llaveMedusa, bool llaveSalamandra,bool aguilaActiva, bool modoDios){
    while(true){
            system("cls");

            int dado1, dado2, dado3, dado4, dado5, dadoSelecionado, dadoNuevo;

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


            if(!modoDios){
                system("pause");
                dado1 = tiraDado_6_caras();
                dado2 = tiraDado_6_caras();
                dado3 = tiraDado_6_caras();
                dado4 = tiraDado_6_caras();
                dado5 = tiraDado_6_caras();
            }else{
                cout<<"Ingrese valor primer dado: ";
                cin>>dado1;
                cout<<"Ingrese valor segundo dado: ";
                cin>>dado2;
                cout<<"Ingrese valor tercer dado: ";
                cin>>dado3;
                cout<<"Ingrese valor cuarto dado: ";
                cin>>dado4;
                cout<<"Ingrese valor quinto dado: ";
                cin>>dado5;
            }



                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "|  " << dado1 << "  | "<< "|  " << dado2 << "  | "<< "|  " << dado3 << "  | "<< "|  " << dado4 << "  | "<< "|  " << dado5 << "  |\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";

                if(aguilaActiva){

                    cout<<"¿Que dado desea modificar?"<<endl;
                    cout<<"Indique el numero de dado: ";
                    cin>>dadoSelecionado;
                    cout<<"Indique el nuevo valor del dado: ";
                    cin>>dadoNuevo;
                    cout<<endl;

                        if(dadoSelecionado==1){
                            dado1=dadoNuevo;
                        }else if (dadoSelecionado==2){
                            dado2=dadoNuevo;
                        }else if (dadoSelecionado==3){
                            dado3=dadoNuevo;
                        }else if (dadoSelecionado==4){
                            dado4=dadoNuevo;
                        }else if (dadoSelecionado==5){
                            dado5=dadoNuevo;
                        }

                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "|  " << dado1 << "  | "<< "|  " << dado2 << "  | "<< "|  " << dado3 << "  | "<< "|  " << dado4 << "  | "<< "|  " << dado5 << "  |\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";

                }


                obtencionEscalera = obtencion_escalera(dado1,dado2,dado3, dado4, dado5, llaveMedusa, llaveSalamandra);
                system("pause");
                system("cls");
               return obtencionEscalera;
    }
}

#endif // FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
