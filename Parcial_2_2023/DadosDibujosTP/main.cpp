#include<iostream>
#include "rlutil.h"
#include "dados.h"

using namespace std;


int main(){

 dibujarDado(1,1,5);
dibujarDado(2,10,5);
dibujarDado(3,20,5);
dibujarDado(4,30,5);
dibujarDado(5,40,5);
dibujarDado(6,50,5);

//muevo el return para que se veo mejor el dado.
rlutil::locate(1,24);
return 0;}

