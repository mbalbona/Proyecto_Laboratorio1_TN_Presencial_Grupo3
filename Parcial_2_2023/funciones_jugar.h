#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED

int tiraDado(){
    int  numero = 10;

    return ( rand() % numero) + 1;
}
void mostrarEstatuillas(jugador){
    for
}


string primerTurno(string jugadores[2]){
    int dadoAnterior, ultimoDado;
    string jugador;

    atras:

    for(int i = 0; i < 2 ; i++){
        if(i == 0){
            ultimoDado = tiraDado();
            dadoAnterior = ultimoDado;
            jugador = jugadores[i];
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado;
        }else{
            ultimoDado = tiraDado();
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado;

            if(ultimoDado < dadoAnterior){
                jugador = jugadores[i];
                return jugador;
            }
        }
    }

    return jugador;
}

void faseExpedicion(string jugadores[2], string empieza, string vEstatuillas[5], string estatuillas_jugadores[2][5]){
    bool primerTurno = false

        if(primerTurno == false){
            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"-----------------------------------------------"<<endl;
            cout<<jugadores[0]<<"\t\t\t";
            cout<<jugadores[1]<<endl;
            cout<<"ESTATUILLAS: \t\t";
            cout<<"ESTATUILLAS: \t\t";
            cout<<endl;
            cout<<"Por que estatuilla lanzaras "<<empieza<<"?"<<endl;
            primerTurno = true
        }else{
            cout<<"IRWIN'S REVENGE - FASE DE EXPEDICION"<<endl;
            cout<<"-----------------------------------------------"<<endl;
            cout<<jugadores[0]<<"\t\t\t";
            cout<<jugadores[1]<<endl;
            cout<<"ESTATUILLAS: \t\t";
            cout<<"ESTATUILLAS: \t\t";
            cout<<endl;
            cout<<"Por que estatuilla lanzaras "<<empieza<<"?"<<endl;
        }

}
#endif // FUNCIONES_JUGAR_H_INCLUDED
