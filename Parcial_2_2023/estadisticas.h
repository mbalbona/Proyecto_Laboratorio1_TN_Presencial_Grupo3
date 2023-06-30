#ifndef ESTADISTICAS_H_INCLUDED
#define ESTADISTICAS_H_INCLUDED
#include "jugar.h"
void estadisticas (){
    system("cls");

    int total[2]={0};

    cout<<" IRWIN'S REVENGE - FASE FINAL "<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    cout<<endl;

    if((jugadores[empieza] == "") && (jugadores[noEmpieza] == "")){
        cout<<"HITO\t\t\t"<<"Steve"<<"\t\t"<<"Irwim"<<endl;
    }else{
    cout<<"HITO\t\t\t"<<jugadores[empieza]<<"\t\t"<<jugadores[noEmpieza]<<endl;
    }

    cout<<"-----------------------------------------------------------"<<endl;
    cout<<"Estatuilla \t\t+"<<puntos_estatuillas[empieza]<<" PDV\t\t"<<puntos_estatuillas[noEmpieza]<<" PDV"<<endl;
    cout<<"Estatuilla++ \t\t+"<<puntos_estatuillas_primerIntento[empieza]<<" PDV\t\t"<<puntos_estatuillas_primerIntento[noEmpieza]<<" PDV"<<endl;
    cout<<"Ganador \t\t+"<<puntos_ganador_faseFinal[empieza]<<" PDV\t\t"<<puntos_ganador_faseFinal[noEmpieza]<<" PDV"<<endl;
    cout<<"Ganador++ \t\t"<<puntos_ganador_sinEstatuillas[empieza]<<" PDV\t\t"<<puntos_ganador_sinEstatuillas[noEmpieza]<<" PDV"<<endl;
    cout<<"Estatuilla-- \t\t"<<puntos_rivalObtiene[empieza]<<" PDV\t\t"<<puntos_rivalObtiene[noEmpieza]<<" PDV"<<endl;
    cout<<"Lanzamiento \t\t"<<puntos_lanzamientoJ[empieza]<<" PDV\t\t"<<puntos_lanzamientoJ[noEmpieza]<<" PDV"<<endl;
    cout<<"SAC \t\t\t"<<puntos_SAC[empieza]<<" PDV \t\t\t"<<puntos_SAC[noEmpieza]<<" PDV"<<endl;
    cout<<"-----------------------------------------------------------"<<endl;
    ///SUMA EL TOTAL DE PUNTOS DE CADA JUGADOR
    for(int i=0; i<2; i++){
        total[i] = puntos_estatuillas[i] + puntos_estatuillas_primerIntento[i] + puntos_ganador_faseFinal[i] + puntos_ganador_sinEstatuillas[i] + puntos_rivalObtiene[i] + puntos_lanzamientoJ[i] + puntos_SAC[i];
    }

    cout<<"TOTAL\t\t\t"<<total[empieza]<<" PDV\t\t"<<total[noEmpieza]<<" PDV"<<endl;
    cout<<endl;
    if(total[empieza]!= 0 && total[noEmpieza]!= 0){
        ///VERIFICA EL GANADOR CON EL JUGADOR QUE GANO LA FASE FINAL SIN IMPORTAR EL PUNTAJE.
        if(puntos_ganador_faseFinal[empieza]!=0 || puntos_ganador_sinEstatuillas[empieza]!=0){
            cout<<"GANADOR: "<<jugadores[empieza]<<" con "<<total[empieza]<<" puntos de victoria."<<endl;
        }else{
            cout<<"GANADOR: "<<jugadores[noEmpieza]<<" con "<<total[noEmpieza]<<" puntos de victoria."<<endl;
        }
    }


    cout<<endl;
    system("pause");
    system("cls;");

}

#endif // ESTADISTICAS_H_INCLUDED
