#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED

void estadisticas (){
    system("cls");
    string jugadores[2]={};

    jugadores[0]="STEVE";
    jugadores[1]="IRWIN";

    int puntosEstatuilla[2]={15, 10};
    int puntosEstautillasM[2]={10, 10};
    int puntosGanador[2]={15, 0};
    int puntosGandorFF[2]={0, 0};
    int puntosEstatuillasR[2]={-6, -9};
    int puntosLanzamiento[2]={-7, -6};

    int total[2]={0};

    cout<<" IRWIN'S REVENGE - FASE FINAL "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"HITO\t\t\t"<<jugadores[0]<<"\t\t"<<jugadores[1]<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Estatuilla \t\t+"<<puntosEstatuilla[0]<<" PDV\t\t"<<puntosEstatuilla[1]<<" PDV"<<endl;
    cout<<"Estatuilla++ \t\t+"<<puntosEstautillasM[0]<<" PDV\t\t"<<puntosEstautillasM[1]<<" PDV"<<endl;
    cout<<"Ganador \t\t+"<<puntosGanador[0]<<" PDV\t\t"<<puntosGanador[1]<<" PDV"<<endl;
    cout<<"Ganador++ \t\t"<<puntosGandorFF[0]<<" PDV\t\t"<<puntosGandorFF[1]<<" PDV"<<endl;
    cout<<"Estatuilla-- \t\t"<<puntosEstatuillasR[0]<<" PDV\t\t"<<puntosEstatuillasR[1]<<" PDV"<<endl;
    cout<<"Lanzamiento \t\t"<<puntosLanzamiento[0]<<" PDV\t\t"<<puntosLanzamiento[1]<<" PDV"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    ///SUMA EL TOTAL DE PUNTOS DE CADA JUGADOR
    for(int i=0; i<2; i++){
        total[i] = puntosEstatuilla[i] + puntosEstatuillasR[i] + puntosEstautillasM[i] + puntosGanador[i] + puntosGandorFF[i] + puntosLanzamiento[i];
    }

    cout<<"TOTAL\t\t\t"<<total[0]<<" PDV\t\t"<<total[1]<<" PDV"<<endl;
    cout<<endl;
    ///VERIFICA EL GANADOR CON EL JUGADOR QUE GANO LA FASE FINAL SIN IMPORTAR EL PUNTAJE.
    if(puntosGanador[0]!=0 || puntosGandorFF!=0){
        cout<<"GANADOR: "<<jugadores[0]<<" con "<<total[0]<<" puntos de victoria."<<endl;
    }else{
        cout<<"GANADOR: "<<jugadores[1]<<" con "<<total[1]<<" puntos de victoria."<<endl;
    }

    cout<<endl;
    system("pause");
    system("cls;");

}

#endif // ESTADISTICAS_H_INCLUDED
