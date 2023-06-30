#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED
#include "jugar.h"
void estadisticas (){
    system("cls");
    string jugadores[2]={};

    int total[2]={0};

    cout<<" IRWIN'S REVENGE - FASE FINAL "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;

    cout<<"HITO\t\t\t"<<jugadores[0]<<"\t\t"<<jugadores[1]<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Estatuilla \t\t+"<<puntos_estatuillas[0]<<" PDV\t\t"<<puntos_estatuillas[1]<<" PDV"<<endl;
    cout<<"Estatuilla++ \t\t+"<<puntos_estatuillas_primerIntento[0]<<" PDV\t\t"<<puntos_estatuillas_primerIntento[1]<<" PDV"<<endl;
    cout<<"Ganador \t\t+"<<puntos_ganador_faseFinal[0]<<" PDV\t\t"<<puntos_ganador_faseFinal[1]<<" PDV"<<endl;
    cout<<"Ganador++ \t\t"<<puntos_ganador_sinEstatuillas[0]<<" PDV\t\t"<<puntos_ganador_sinEstatuillas[1]<<" PDV"<<endl;
    cout<<"Estatuilla-- \t\t"<<puntos_rivalObtiene[0]<<" PDV\t\t"<<puntos_rivalObtiene[1]<<" PDV"<<endl;
    cout<<"Lanzamiento \t\t"<<puntos_lanzamientoJ[0]<<" PDV\t\t"<<puntos_lanzamientoJ[1]<<" PDV"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    ///SUMA EL TOTAL DE PUNTOS DE CADA JUGADOR
    for(int i=0; i<2; i++){
        total[i] = puntos_estatuillas[i] + puntos_estatuillas_primerIntento[i] + puntos_ganador_faseFinal[i] + puntos_ganador_sinEstatuillas[i] + puntos_rivalObtiene[i] + puntos_lanzamientoJ[i];
    }

    cout<<"TOTAL\t\t\t"<<total[0]<<" PDV\t\t"<<total[1]<<" PDV"<<endl;
    cout<<endl;
    ///VERIFICA EL GANADOR CON EL JUGADOR QUE GANO LA FASE FINAL SIN IMPORTAR EL PUNTAJE.
    if(puntos_ganador_faseFinal[0]!=0 || puntos_ganador_sinEstatuillas!=0){
        cout<<"GANADOR: "<<jugadores[0]<<" con "<<total[0]<<" puntos de victoria."<<endl;
    }else{
        cout<<"GANADOR: "<<jugadores[1]<<" con "<<total[1]<<" puntos de victoria."<<endl;
    }

    cout<<endl;
    system("pause");
    system("cls;");

}

#endif // ESTADISTICAS_H_INCLUDED
