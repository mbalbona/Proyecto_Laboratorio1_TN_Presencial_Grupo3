#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

#include "jugar.h"

void menu(){

    while(true){
        int opc;
        cout<<"IRWIN'S REVENGE"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"1 - JUGAR PARA DOS JUGADORES"<<endl;
        cout<<"2 - ESTADISTICAS"<<endl;
        cout<<"3 - CREDITOS"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        switch(opc){
            case 1: jugar();
                break;
       /*     case 2: estadisticas();
                break;
            case 3: creditos();
                break;*/
            case 0: return;
        }
    }

}

#endif // MENUES_H_INCLUDED
