#ifndef SEPHIROTH_H
#define SEPHIROTH_H
#include"FINALFANTASY.h"//llamar clase FINALFANTSY
#include"CHARACTER.h"//llamar clase jugador
#include<iostream> //para imprimir.

using namespace std;

class SEPHIROTH:public CHARACTER{//CLASE SEPHIROTH (hija), con herencia a PERSONAJE
    private://Atributos
        string info;
        string NameS;
        bool LimitBreakS;
        int SmashS;
    public://Metodos
        SEPHIROTH(string, int, int, int, string, bool, int);
        SEPHIROTH(string, string);
        string ShowNameS();
        void ShowInfoGame();///metodo polimorfismo sobrescrito
        int Masamune(CHARACTER &c);
        bool GetLimitBreakS();
};

//Constructor 1
SEPHIROTH::SEPHIROTH(string game, int dam, int tilt, int turno, string nameS, bool limitBreakS, int smashS):CHARACTER(game, dam, tilt, turno){
    NameS=nameS;
    LimitBreakS=limitBreakS;
    SmashS=smashS;
}

SEPHIROTH::SEPHIROTH(string game, string information):CHARACTER(game){
    info=information;
}

void SEPHIROTH::ShowInfoGame(){///metodo de polimorfismo para esta clase  y sobrescritura de clase ABSTRACTA
    cout<<"Extra -SEPHIROTH- info: ";
    cout<<info;
}

//Mostrar nombre del jugador
string SEPHIROTH::ShowNameS(){
    cout<<NameS;
    return NameS;
}

//Obtener el ataque especial dependiendo del metodo (GetLimitBreakS)
int SEPHIROTH::Masamune(CHARACTER &c){//Apunta directamente a un objeto creado en CHARACTER
    if(LimitBreakS==true){//Si cuenta con magia(TRUE) vale 40
        SmashS=40;
        c.DamageRecive(40);//recive daño el objeto de CHARACTER
        cout<<"SEPHIROTH used his MASAMUNE of 40!!!"<<endl;
    }
    else{//vale 0
        SmashS=0;
        c.DamageRecive(0);//No recive daño
    }
    return SmashS;
}

//Obtener la magia
bool SEPHIROTH::GetLimitBreakS(){
    if(Turn%3==0){//Si el turno del jugador es div entre 3
        LimitBreakS=true;//tendrá magia
    }
    else{
        LimitBreakS=false;//sino no tendrá magia
    }
    return LimitBreakS;
}

#endif // SEPHIROTH_H
