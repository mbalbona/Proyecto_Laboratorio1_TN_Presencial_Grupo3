#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED

int tiraDado(){
    int  numero = 10;

    return ( rand() % numero) + 1;
}

string primerTurno(string j1, string j2){
    int dadoAnterior, ultimoDado;

    atras:
    cout<<"-----------------------------------------------"<<endl;
    cout<<"QUIEN COMENZARA?"<<endl;
    cout<<endl;
    ///Tira primer dado J1
    dadoAnterior = tiraDado();
    cout<<"El jugador "<<j1<<" saco el dado numero: "<<dadoAnterior<<endl;
    ///Tira primer dado J2
    ultimoDado = tiraDado();
    cout<<"El jugador "<<j2<<" saco el dado numero: "<<ultimoDado<<endl;
    if(ultimoDado == dadoAnterior){
        system("cls");
        cout<<"SACARON DADOS IGUALES SE VOLVERA A TIRAR EL DADO"<<endl;
        system("pause");
        system("cls");
        goto atras;
    }else if(ultimoDado > dadoAnterior){
        cout<<"EL PRIMER TURNO SERA PARA EL JUGADOR "<<j1<<endl;
        return j1;
    }
    else{
        cout<<"EL PRIMER TURNO SERA PARA EL JUGADOR " <<j2<<endl;
        return j2;
    }
    cout<<"-----------------------------------------------"<<endl;

}

void faseExpedicion(string j1, string j2, int turno){
    cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
    cout<<"-----------------------------------------------"<<endl;
    cout<<j1<<"\t\t\t";
    cout<<j2<<endl;
    cout<<"ESTATUILLAS: \t\t";
    cout<<"ESTATUILLAS: \t\t";
}
#endif // FUNCIONES_JUGAR_H_INCLUDED
