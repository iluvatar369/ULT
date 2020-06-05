#ifndef GANONDORF_H
#define GANONDORF_H
#include"TLOZELDA.h"//llamar clase TLOZELDA
#include"CHARACTER.h"//llamar clase jugador
#include<iostream> //para imprimir.

using namespace std;

class GANONDORF:public CHARACTER{//CLASE GANONDORF (hija), con herencia a PERSONAJE
    private://Atributos
        string info;
        string NameG;
        bool MagicG;
        int SmashG;
    public://Metodos
        GANONDORF(string, int, int, int, string, bool, int);
        GANONDORF(string, string);
        string ShowNameG();
        void ShowInfoGame();///metodo polimorfismo sobrescrito
        int Punch(CHARACTER &c);
        bool GetMagicG();
};

//Constructor 1
GANONDORF::GANONDORF(string game, int dam, int tilt, int turno, string nameG, bool magicG, int smashG):CHARACTER(game, dam, tilt, turno){
    NameG=nameG;
    MagicG=magicG;
    SmashG=smashG;
}

GANONDORF::GANONDORF(string game, string information):CHARACTER(game){
    info=information;
}

void GANONDORF::ShowInfoGame(){///metodo de polimorfismo para esta clase  y sobrescritura de clase ABSTRACTA
    cout<<"Extra -Ganondorf- info: ";
    cout<<info;
}

//Mostrar nombre del jugador
string GANONDORF::ShowNameG(){
    cout<<NameG;
    return NameG;
}

//Obtener el ataque especial dependiendo del metodo (GetMagicG)
int GANONDORF::Punch(CHARACTER &c){//Apunta directamente a un objeto creado en CHARACTER
    if(MagicG==true){//Si cuenta con magia(TRUE) vale 40
        SmashG=40;
        c.DamageRecive(40);//recive da�o el objeto de CHARACTER
        cout<<"GANONDORF used DINs FIRE of 40!!!"<<endl;
    }
    else{//vale 0
        SmashG=0;
        c.DamageRecive(0);//No recive da�o
    }
    return SmashG;
}

//Obtener la magia
bool GANONDORF::GetMagicG(){
    if(Turn%3==0){//Si el turno del jugador es div entre 3
        MagicG=true;//tendr� magia
    }
    else{
        MagicG=false;//sino no tendr� magia
    }
    return MagicG;
}

#endif // GANONDORF_H
