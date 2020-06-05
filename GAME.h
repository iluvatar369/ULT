#ifndef GAME_H //se establece para la clase
#define GAME_H
#include "CHARACTER.h" //se establece para composición
#include "TLOZELDA.h"
#include<iostream> //para imprimir.
//#include <string>
//#include <sstream>
using namespace std;

//const int MAX = 1000;

class GAME{//CLASE JUEGO
    private://atributos
        string nameG;
        string version;
        //CHARACTER *character[MAX];
    public://metodos
        GAME(string NameG, string ver);
        //void agregar();
        //void mostrar();
        string getname();
        string getversion();
        void welcome();
};

//Constructor 1
GAME::GAME(string NameG, string ver){
    nameG=NameG;
    version=ver;

}

//obtener nombre
string GAME::getname(){
    return nameG;
}

//obtener version
string GAME::getversion(){
    return version;
}

//bienvenida
void GAME::welcome(){
    cout<<"¡WELCOME! \nAND THIS IS!!"<<endl;
}
/*
void GAME::agregar(){
    int jugadores=0;
    character[jugadores] = new TLOZELDA ("THE LEGEND OF ZELDA", "Best Game in the world", "The hero of time");
    jugadores++;
    cout<<character[jugadores];
}


void GAME::mostrar(){
  //Ciclo que recorre el arreglo e imprime cada objeto.
    stringstream aux;
	for(int i=0; i<1 ;i++)
        aux << character[i];
}
*/

#endif // GAME_H
