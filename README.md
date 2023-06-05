# Proyecto_Laboratorio1_TN_Presencial_Grupo3
# Este repositorio esta destinado al proyecto del juego denominado "Irwin's Revenge"
# Participantes
 - Juan Pablo Rajoy
 - Pineda Walter Jesus
 - Mateo Balbona Arvigo

*Irwin's Revenge* es un juego de dados de dos jugadores en el que intervienen el azar y la astucia.
El objetivo general del juego es ganar la Fase Final y sumar la mayor cantidad de puntos de victoria. La suma de este puntaje depende de diferentes situaciones que se pueden dar en el juego y que más adelante se explicarán.

El juego se divide en dos fases que llamaremos Fase de expedición y Fase final. Obviamente, la fase de expedición sucede primero y luego comienza la fase final. La Fase de Expedición proporcionará elementos que se utilizarán en la Fase Final por lo que ambas son muy importantes.
Antes de comenzar la fase de expedición los jugadores deberán tirar un dado de diez caras. Quien obtenga el dado menor comienza. Si ambos obtuvieron el mismo número deberán tirar de nuevo hasta que alguno de ellos obtenga el dado más chico.

# Fase de Expedición
Durante la Fase de Expedición el objetivo es obtener la mayor cantidad de estatuillas. Son cinco en total y están relacionados a cinco elementos del Planeta Tierra.
Los elementos, que en el juego también son conocidos como niveles, son: Arena, Tierra, Agua, Aire y Fuego.

Las estatuillas de cada elemento son:

Arena → Cangrejo		
Tierra → Hormiga		
Agua → Medusa	
Aire → Águila		
Fuego → Salamandra

En la fase de expedición, cada jugador va alternando de a un turno a la vez en el que deben primero elegir verbalmente qué estatuilla desean obtener. Ambos jugadores pueden elegir la misma estatuilla. En el caso que el primero en lanzar obtenga la estatuilla y, por lo tanto, se la quede. El otro jugador debe anunciar verbalmente otra estatuilla antes de lanzar.
Luego de elegir la estatuilla por la que en ese turno jugarán, deberán lanzar dos dados de 10 caras (salvo excepción de maldición de la salamandra)  y la obtención de la estatuilla se determina a partir de una serie de reglas. Si el jugador obtiene la estatuilla, se la queda y ya no puede perderla. La estatuilla le proporcionará al jugador una bendición en la Fase Final y una maldición en la Fase de Expedición (que puede perjudicarlo o bien beneficiar al rival).

# Las estatuillas

![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/52fa404e-2668-4272-81b8-0556a55500b4)


![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/cb1afe2d-8ae0-4000-802e-d9090256245e)


La Fase de Expedición termina cuando no quedan estatuillas en juego. A partir de ese momento, comienza la Fase Final siendo el primero en tirar aquel jugador que haya obtenido más estatuillas.

Fase Final
La Fase Final es quien determina al ganador del juego. En esta fase se utilizan 5 dados de 6 caras. Ganará la fase final aquel jugador que primero obtenga una escalera. La escalera es una tirada en la que todos los dados son correlativos. Por ejemplo:
1, 2, 3, 4, 5
2, 3, 4, 5, 6

Cabe aclarar que el orden de los dados no es importante para completar el hito de la Fase Final por lo que los siguientes lanzamientos también son exitosos:
2, 3, 5, 1, 4
6, 2, 5, 4, 3

Las únicas excepciones a las reglas de victoria en la fase final mencionadas anteriormente son las siguientes:

        - Quien tenga la estatuilla de la medusa podrá ganar también con la obtención de 5 dados iguales. Por ejemplo: (1, 1, 1, 1, 1); (3, 3, 3, 3, 3); etc.

        - Quien tenga la estatuilla de la salamandra podrá ganar con una escalera más corta. Sólo 4 de los 5 dados deberán ser correlativos. Ejemplos de lanzamientos exitosos podrían ser: (1, 2, 3, 4, 1); (2, 3, 4, 5, 2); (3, 4, 5, 6, 1); etc.

Una vez finalizada la partida se deben computar los Puntos de Victoria que se especifican a continuación:

![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/4a28eb6b-3d21-4b20-9c7f-5b22d9319b38)

Actividad
Se pide desarrollar en C/C++ el juego Irwin's Revenge haciendo uso de un proyecto de Aplicación de Consola.
El juego debe contar con un menú principal con las siguientes opciones:

![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/46a628f7-ed10-4684-baa3-0d4219ad63e3)


La opción jugar, debe permitir iniciar un nuevo juego de Irwin's Revenge. Antes de comenzar el juego debe solicitar a los jugadores sus respectivos nombres.
Luego, en la Fase de Expedición, el juego debe mostrar la información necesaria para que los usuarios puedan jugarlo. Esto, como mínimo, debe ser: las estatuillas que tiene en su haber cada jugador, la estatuilla por la que lanza cada jugador en esa ronda, el nombre del jugador que está tirando y la tirada de dados del jugador actual.
Antes de comenzar la Fase de Expedición se le debe preguntar a cada jugador cuál es la estatuilla por la que lanzará. Ambos jugadores podrían elegir la misma estatuilla. Si el primero de ellos obtiene la estatuilla que ambos jugadores disputaban. El juego debe solicitarle al otro jugador otra estatuilla antes de lanzar.
El juego nunca debe permitir elegir a un jugador una estatuilla que no está disponible.

![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/feaa86bc-80fb-456f-839a-f1c9d3ccf369)

Ejemplo de interfaz previa al lanzamiento de dados en la Fase de Expedición


![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/8f31fdc4-ad25-4b0f-af04-59a436ddca52)


Al finalizar la Fase de Expedición, debe comenzar la Fase Final. 

![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/6b9822a3-7a56-4908-a5b5-077fadbe9031)


![imagen](https://github.com/mbalbona/Proyecto_Laboratorio1_TN_Presencial_Grupo3/assets/119949692/a09bd409-cedc-4043-a689-9e1e75e99fe4)

La opción estadísticas, debe mostrar el nombre del jugador que haya obtenido la mayor cantidad de puntos de victoria y dicha cantidad.

La opción créditos, debe mostrar los apellidos, nombres y legajos de los integrantes del equipo. Así como también el nombre del equipo y los datos del creador del juego.

La opción salir, debe salir del juego previa confirmación del usuario.

# Aclaraciones
 - El juego desarrollado debe cumplir con el reglamento tal y como se aclara en el documento. Sin embargo, las interfaces del programa pueden modificarse para embellecerlo, darle una impronta personal, mejorarlo, etc. Por ejemplo, puede incluirse en el menú principal una opción que explique sucintamente las reglas del juego.
 - El juego debe realizar la tirada de dados de manera aleatoria.
 - Si el primer jugador se llama LAB1 entonces los dados no deben ser aleatorios para ninguno de los dos jugadores y se deben solicitar por ingreso de teclado.

# Créditos
 - Imagen de Steve Irwin creada por TinyPixelBlock.
 - Caricaturas de Irwin y su familia por Google Doodle
 - Juego inventado por Gonzalo Ligero - gonzalo.ligero@alumnos.frgp.utn.edu.ar 
 - Reglamento adaptado para TP por Gonzalo Ligero y Angel Simón
