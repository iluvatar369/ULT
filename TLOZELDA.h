#ifndef TLOZELDA_H
#define TLOZELDA_H
#include"GANONDORF.h"//llamada de clase ganondorf
#include"CHARACTER.h"//Llamada de clase jugador
#include<iostream> //para imprimir.

using namespace std;

class TLOZELDA:public CHARACTER{//CLASE TLOZELDA (hija), con herencia a PERSONAJE
    private://Atributos
        string NameZ;
        bool MagicBar;
        int SmashT;
        string info;
        string infoPlayer;
    public://Metodos
        //SOBRECARGA
        TLOZELDA(string, int, int, int, string, bool, int);
        TLOZELDA(string, int, int, int, string, bool, int, string);//SOBRECARGA PARA UNA SOBREESCRITURA
        TLOZELDA(string,string,string);
        TLOZELDA(): NameZ(""), info(""), infoPlayer(""){};
        void ShowInfoGame();///metodo polimorfismo y sobrescritura de clase abstracta
        string ShowNameZ();
        int Triforce(GANONDORF &g);
        bool GetMagicBar();
};

//Constructor 1
TLOZELDA::TLOZELDA(string game, int dam, int tilt, int turno, string nameZ, bool magicBar, int smashT):CHARACTER(game, dam, tilt, turno){
    NameZ=nameZ;
    MagicBar=magicBar;
    SmashT=smashT;
}

//Constructor 2 (SOBRECARGA)
TLOZELDA::TLOZELDA(string game, int dam, int tilt, int turno, string nameZ, bool magicBar, int smashT, string inf)
:CHARACTER(game, dam, tilt, turno){
    info=inf;
}

TLOZELDA::TLOZELDA(string game, string information, string infPlayer):CHARACTER(game){
    info=information;
    infoPlayer=infPlayer;
}

//Mostrar la informaci�n del juego(SUBREESCRITURA)
void TLOZELDA::ShowInfoGame(){///metodo de polimorfismo para esta clase y sobrescritura de clase ABSTRACTA
    cout<<"You chose ";
    cout<<Game;
    cout<<"\nExtra game info: ";
    cout<<info<<"\n";
    cout<<"\nYou will be Link and your enemy Ganondorf"<<endl;
    cout<<"Extra -Link- info: ";
    cout<<infoPlayer;
}

//Mostrar el nombre del personaje
string TLOZELDA::ShowNameZ(){
    cout<<NameZ;
    return NameZ;
}

//Obtener el ataque especial dependiendo del metodo (GetMagicBar)
int TLOZELDA::Triforce(GANONDORF &g){//apuntando directamente a la clase GANONDORF
    if(MagicBar==true){//Si la barra de magia esta llena(TRUE)
        int SA;//variable para selecci�n
        cout<<"Do yo want to do your Smash Attack? 1)YES...any other number)NO"<<endl;
        cin>>SA;
        if (SA==1){//Si la selecci�n es 1 vale 43
            SmashT=40;
            g.DamageRecive(40);
            cout<<"You used FAROREs WIND of 40!!!"<<endl;
        }
    }
    else{//SINO vale 0
        SmashT=0;
        g.DamageRecive(0);
    }
    return SmashT;
}

//Obtener la barra de magia
bool TLOZELDA::GetMagicBar(){
    if(Turn%3==0){//Si el turno del jugador es div entre 3
        MagicBar=true;//la barra estar� llena
    }
    else{
        MagicBar=false;//sino estar� vac�a
    }
    return MagicBar;
}

#endif // TLOZELDA_H
