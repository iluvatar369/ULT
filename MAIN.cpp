/**
Datos
Proyecto SIMULACIÓN DE PELEA
Diego Emilio Barrera Hernández
A01366802


Descripción: Esta es la cuarta entrega de la clase Programación Orientado a Objetos.
El programa nos muestra una simulación de un juego de pelea, dónde tu eres el que
interactúa para que la batalla siga avanzando.
Serás un héroe de cualquier juego(En este caso solamente de ZELDA) y vencerás al Jefe Final de ese juego.
Solo tienes un Tilt Attack y un Smash Attack
El Tilt Attack puede ser un ataque crítico, pero solo es un 50% tener eso
Y el Smash Attack se cargará cada tres turnos.
Si tú y tu oponente alcanzan el% 300 de su daño, el juego terminará
El ganador será el jugador que tenga menos porcentaje de daño al final de la partida.
*/

//se llaman las clases creadas
#include"GAME.h"
#include"CHARACTER.h"
#include"TLOZELDA.h"
#include"GANONDORF.h"
#include"FINALFANTASY.h"
#include"SEPHIROTH.h"
#include<conio.h>
#include<iostream>//para imprimir.

using namespace std; //para no utilizar nuevamete std

int main(){
    //SE CREA EL OBJETO DE LA CLASE SMASH Y SE DA LA BIENVENIDA
    GAME smash("--PokeSmash--", "version:POO2");
    smash.welcome();
    cout<<smash.getname()<<"\n";
    cout<<smash.getversion()<<"\n"<<endl;
    cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __"<<endl;
    cout<<"|                                   RULES:                                             |"<<endl;
    cout<<"|You will be a hero of any game and you will need to defeat the Final Boss of that game|"<<endl;
    cout<<"|You only have a Tilt Attack and Smash Attack                                          |"<<endl;
    cout<<"|The Tilt Attack can be a Critic Attack, but it is only a 50% of having that           |"<<endl;
    cout<<"|And the Smash Attack will be charged every three turns                                |"<<endl;
    cout<<"|If you and your opponent reach the %300 of damage the game will end                   |"<<endl;
    cout<<"|The winner will be the player that has less damage percentage                         |"<<endl;
    cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __|"<<endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout<<"\nWhich game do you want? (1)THE LEGEND OF ZELDA or (2)FINAL FANTASY"<<endl;
    int saga;
    cin>>saga;
    cout<<"\n";
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    if (saga==1){

        cout<<"\n";
        cout<<"L E T - S T A R T!"<<endl;
        /*
        smash.agregar();
        cout<<"\n";
        smash.mostrar();
        cout<<"\n";
        */

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///SE CREAN LOS OBJETOS CPN BASE EN EL POLIMORFISMO CREADO DEL METDODO ShowInfoGame() DE LA CLASE CHARACTER
        CHARACTER *muestraInf[1];///APUNTADOR PARA EL POLIMORFISMO
        muestraInf[0] = new TLOZELDA ("THE LEGEND OF ZELDA", "Best Game in the world","The one without a fary");///OBJETO DE TLOZELDA
        muestraInf[0] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)
        cout<<"\n";

        muestraInf[1] = new GANONDORF ("THE LEGEND OF ZELDA", "Dark master and the one with millions sisters");///OBJETO DE GANONDORF
        muestraInf[1] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)


        //smash.mostrar();
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout<<"\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

        int GD=0;
        int LD=0;//variables para el ciclo y el ataque especial
        int turn=0;

        while(GD<300||LD<300){//CICLO PARA LA SOMULACIÓN DE PELEA
            turn++;
            TLOZELDA link ("The Legend Of Zelda", LD, 15, turn, "LINK", false, 0);//se utilizó el primer constructor(SOBRECARGA)
            GANONDORF ganon ("The Legend Of Zelda", GD, 15, turn, "GANONDORF", false, 0);
            cout<<"--TURN:"<<link.GetTurn()<<"--"<<endl;
            cout<<"\n";
            cout<<"It is your turn"<<endl;
            link.GetMagicBar();//Llamada para el ataque especial
            link.Triforce(ganon);//Llamada para el ataque especial

            GD=ganon.DamageRecive(link.GetTiltAttack());

            cout<<"\n";
            cout<<"Now Ganondorfs Turn"<<endl;
            ganon.GetMagicG();//Llamada para el ataque especial
            ganon.Punch(link);//Llamada para el ataque especial

            LD=link.DamageRecive(ganon.GetTiltAttack());

            cout<<" _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
            cout<<"|GANONDORFs DAMAGE %"<<ganon.GetDamagePer()<<"  |"<<endl;
            cout<<"|LINKs DAMAGE %"<<link.GetDamagePer()<<"       |"<<endl;
            cout<<"|_ _ _ _ _ _ _ _ _ _ _ _|";
            cout<<"\n";
            cout<<"------------------------------------------------------------------------------------------------------------------------";

            }

        if(GD<LD){//Si gana el jefe
            cout<<"GAME!\n";
            cout<<"You have met with a terrible fate!!\nHavent you?\nTHE DARK MASTER WINS!!"<<endl;
        }

        else if(LD<GD){//si gana el heroe
            cout<<"GAME!\n";
            cout<<"One more time you save Hyrule!! YOU WIN!!"<<endl;
        }
        else{
            cout<<"\n";
            cout<<"OH MY GOSH!! IT WAS A TIE!\nMay be you can win in the next game"<<endl;
        }
        delete muestraInf[0];
        delete muestraInf[1];
}
    else if(saga==2){
        cout<<"\n";
        cout<<"L E T - S T A R T!"<<endl;
        /*
        smash.agregar();
        cout<<"\n";
        smash.mostrar();
        cout<<"\n";
        */

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ///SE CREAN LOS OBJETOS CON BASE EN EL POLIMORFISMO CREADO DEL METDODO ShowInfoGame() DE LA CLASE CHARACTER
        CHARACTER *muestraInf[1];///APUNTADOR PARA EL POLIMORFISMO
        muestraInf[0] = new FINALFANTASY ("FINAL FANTASY", "Best remake in the E3 of 2019","Soldier 1st class");///OBJETO DE FINALFANTASY
        muestraInf[0] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)
        cout<<"\n";

        muestraInf[1] = new SEPHIROTH ("FINAL FANTASY", "In fact, he don't has limit break and he is Aeris brother");///OBJETO DE SEPHIROTH
        muestraInf[1] -> ShowInfoGame();///MOSTRAR INFORMACION (POLIMORFISMO) (SOBREESCRITURA)


        //smash.mostrar();
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        cout<<"\n";
        cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;

        int GD=0;
        int LD=0;//variables para el ciclo y el ataque especial
        int turn=0;

        while(GD<300||LD<300){//CICLO PARA LA SOMULACIÓN DE PELEA
            turn++;
            FINALFANTASY cloud ("Final Fantasy", LD, 15, turn, "CLOUD", false, 0);//se utilizó el primer constructor(SOBRECARGA)
            SEPHIROTH sephiroth ("Final Fantasy", GD, 15, turn, "SEPHIROTH", false, 0);
            cout<<"--TURN:"<<cloud.GetTurn()<<"--"<<endl;
            cout<<"\n";
            cout<<"It is your turn"<<endl;
            cloud.GetLimitBreakF();//Llamada para el ataque especial
            cloud.Mako(sephiroth);//Llamada para el ataque especial

            GD=sephiroth.DamageRecive(cloud.GetTiltAttack());

            cout<<"\n";
            cout<<"Now Sephiroths Turn"<<endl;
            sephiroth.GetLimitBreakS();//Llamada para el ataque especial
            sephiroth.Masamune(cloud);//Llamada para el ataque especial

            LD=cloud.DamageRecive(sephiroth.GetTiltAttack());

            cout<<" _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
            cout<<"|SEPHIROTHs DAMAGE %"<<sephiroth.GetDamagePer()<<"  |"<<endl;
            cout<<"|CLOUDs DAMAGE %"<<cloud.GetDamagePer()<<"       |"<<endl;
            cout<<"|_ _ _ _ _ _ _ _ _ _ _ _|";
            cout<<"\n";
            cout<<"------------------------------------------------------------------------------------------------------------------------";

            }

        if(GD<LD){//Si gana el jefe
            cout<<"GAME!\n";
            cout<<"You have met with a terrible fate!!\nHavent you?\nSEPHIROTH WINS!!"<<endl;
        }

        else if(LD<GD){//si gana el heroe
            cout<<"GAME!\n";
            cout<<"One more time you save Hyrule!! CLOUD WIN!!"<<endl;
        }
        else{
            cout<<"\n";
            cout<<"OH MY GOSH!! IT WAS A TIE!\nMay be you can win in the next game"<<endl;
        }
        delete muestraInf[0];
        delete muestraInf[1];
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    getch();
    return 0;
}
