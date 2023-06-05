#ifndef FUNCIONES_JUGAR_H_INCLUDED
#define FUNCIONES_JUGAR_H_INCLUDED

int tiraDado(){
    int  numero = 10;

    return ( rand() % numero) + 1;
}

void mostrar_estatuillas(string estatuillas_jugador[], int tam){
    for(int i = 0; i < tam; i++){
        cout<<estatuillas_jugador[i];
    }
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
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;
        }else{
            ultimoDado = tiraDado();
            cout<<"Al jugador "<<jugadores[i]<<" le salio el numero: "<<ultimoDado<<endl;

            if(ultimoDado < dadoAnterior){
                jugador = jugadores[i];
                return jugador;
            }
        }
    }

    return jugador;
}

#endif // FUNCIONES_JUGAR_H_INCLUDED
