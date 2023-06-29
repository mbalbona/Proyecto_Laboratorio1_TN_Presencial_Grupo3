#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

#include "jugar.h"
#include "estadisticas.h"
#include "creditos.h"


void menu(){
    atras:
    while(true){
        int opc;
        char opcSalir;
        cout<<"\tIRWIN'S REVENGE"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"1 - JUGAR PARA DOS JUGADORES"<<endl;
        cout<<"2 - ESTADISTICAS"<<endl;
        cout<<"3 - CREDITOS"<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<endl;
        cout<<"Elija una opcion: ";
        cin>>opc;
        if(opc < 0 || opc > 3){
            cout<<"INGRESE UNA OPCION CORRECTA!"<<endl;
            system("pause");
            system("cls");
            goto atras;
        }
        switch(opc){
            case 1: jugar();
                break;
            case 2: estadisticas();
                break;
            case 3: creditos();
                break;
            case 0:
                cout<<endl;
                cout<<"Esta seguro que desea salir del juegos - Y/N ";
                cin>>opcSalir;

                switch(opcSalir){
                    case 'N':
                            system("cls");
                            menu();
                       break;
                    case 'n':
                            system("cls");
                            menu();
                        break;
                    case 'Y':
                            return;
                        break;
                    case 'y':
                            return;
                        break;
                    default:
                            cout<<"Ingreso un valor incorrecto."<<endl;
                            system("pause");
                            system("cls");
                            menu();
                        break;
            }
        }
    }

}

#endif // MENUES_H_INCLUDED
