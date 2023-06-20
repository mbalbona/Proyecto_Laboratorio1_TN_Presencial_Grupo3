#ifndef FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
#define FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED

int contadorEstatuillas(string *estatuillas_Jugador, int tam){
        int contador_Estatuillas{0};
        for(int i=0; i<tam; i++){
            if(estatuillas_Jugador[i]!=""){
                contador_Estatuillas++;
            }
        }
        return contador_Estatuillas;
}
string obtencion_escalera(int dado1, int dado2,int dado3,int dado4,int dado5 ){
    int opc=1;
    string sigue = "SIGUE";
    string ganaste = "GANASTE";
            if( (dado1 != dado2) && (dado1!=dado3) && (dado1!=dado4)&& (dado1!=dado5) && (dado2 != dado3)&& (dado2!=dado4) && (dado2!=dado5) && (dado3 != dado4) && (dado3 != dado5) && (dado4!=5) && (dado1+dado2+dado3+dado4+dado5) == 15){
                cout<<">HAS OBTENIDO UNA ESCALERA"<<endl;
                system("pause");
                system("cls");
                return ganaste;
                  }else{
                return sigue;
                  }
}

string lanzamiento_jugador_faseFinal(int empieza, int noEmpieza, string *jugadores, int tam,  string jugador, string *estatuillas_j1, string *estatuillas_j2, string *vEstatuas){
    while(true){
            system("cls");

            int dado1, dado2, dado3, dado4, dado5;

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

                dado1 = tiraDado_6_caras();
                dado2 = tiraDado_6_caras();
                dado3 = tiraDado_6_caras();
                dado4 = tiraDado_6_caras();
                dado5 = tiraDado_6_caras();


                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "|  " << dado1 << "  | "<< "|  " << dado2 << "  | "<< "|  " << dado3 << "  | "<< "|  " << dado4 << "  | "<< "|  " << dado5 << "  |\n";
                cout << "|     | "<< "|     | "<< "|     | "<< "|     | "<< "|     |\n";
                cout << "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+ "<< "+-----+\n";

                obtencionEscalera = obtencion_escalera(dado1,dado2,dado3, dado4, dado5);
                system("pause");
                system("cls");
               return obtencionEscalera;
    }
}

#endif // FUNCIONES_JUGAR_FASEFINAL_H_INCLUDED
