#include <iostream>
#include <string.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#include "funciones.h"
#include "TestDados.h"
#include "rlutil.h"



int main(){
    int v[3], tam=3,Puntosjugada=0,casos,Tiro=0,AcumulacionPTS=0,TiroFallido=0,Buncos=0,PuntosTotales=0,PuntosTotalesconFallidos=0,MAXPTS=0,MAXBUNCO=0,JUEGO=0;
    int i,Ronda=0;
    bool cicloinfinito = true;

    string Nombre,MAXNOMBRE;
    while (cicloinfinito)
    {
        setBackgroundColor(CYAN);
        casos = MenuPrincipalBunco();

        switch(casos){
            case 9: system("cls");
                    JUEGO++;///Este contador lo hice para el caso en el que se entre a la opción de ver la puntuación mas alta sin haber jugado una partida anteriormente.
                    cout<<"Nombre del jugador : "<<endl;
                    cin>>Nombre;
                    cout<<endl;
                    system("cls");
                    for(i=1;i<7;i++){
                    Ronda = i;
                    while(AcumulacionPTS<21){///El ACUMULACIONPTS sirve para que se llegue a la condición de los 21 puntos de la ronda
                    Tiro++;
                    cargarAleatorio(v,tam,6);
                    Puntosjugada=AnalisisDados(v,tam,Ronda,Puntosjugada);
                    AcumulacionPTS+=Puntosjugada;
                    PuntosTotales+=Puntosjugada;///El PuntosTotales sirve para acumular los puntos de todas las rondas sin contar los -2 puntos que se da cuando se falla una jugada
                    PuntosTotalesconFallidos+=Puntosjugada;///El PuntosTotalesconFallidos sirve para tener el puntaje final que serian los PuntosTotales junto con los jugadas fallidas en donde se le resta 2 PTS
                    if(Puntosjugada==0){
                    TiroFallido++;
                    PuntosTotalesconFallidos=PuntosTotalesconFallidos-2;
                    }
                    if(Puntosjugada==21)Buncos++;
                    system("cls");
                    MenuDeDados(v);
                    cout << "\n" << "\n" << "\n" << "\n" <<endl;
                    if(Puntosjugada==21){
                    cout<<"¡¡Obtuviste Bunco!!"<<endl;
                    cout<<"-----------------------------"<<endl;}
                    cout<<"PUNTAJE DE LA RONDA: "<<Puntosjugada<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"TURNO DE "<<Nombre<< " | "<<"RONDA NUMERO "<<Ronda<<" | "<<" PUNTAJE ACUMULADO: "<<PuntosTotales<< " PUNTOS"<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"VECES QUE OBTUVO BUNCO : "<<Buncos<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"LANZAMIENTOS : "<<Tiro<<endl<<endl;
                    system("pause");
                    system("cls");
                    }
                    system("cls");
                    if(Ronda+1<7){
                cout<<"RONDA NUMERO "<<Ronda+1<<endl;
                cout<<"-------------------"<<endl;
                cout<<"PUNTAJE "<<Nombre<<" : "<<PuntosTotales<<endl;
                cout<<"BUNCOS : "<<Buncos<<endl;
                cout<<"Tiros Fallidos: "<<TiroFallido<<endl;
                cout<<"LANZAMIENTOS "<<Tiro<<endl;
                cout<<"-------------------"<<endl;
                AcumulacionPTS=0;
                Puntosjugada=0;
                system("pause");
                system("cls");
                    }
                        }
                system("cls");
                cout<<"Puntos totales :"<<PuntosTotalesconFallidos<<endl;
                if(PuntosTotalesconFallidos>MAXPTS){///Este if es para analizar si se logro una máxima puntuación y si es así guardar los datos ya que hay una opción del menú para ver esos datos
                MAXBUNCO=Buncos;
                MAXNOMBRE=Nombre;}
                AcumulacionPTS=0;///Acá vuelvo a poner todo en 0 menos a los datos del anterior if para que se pueda jugar devuelta y se intente superar el récord anterior
                Puntosjugada=0;
                Tiro=0;
                TiroFallido=0;
                PuntosTotales=0;
                Buncos=0;
                PuntosTotalesconFallidos=0;
                system("pause");
                system("cls");
                break;
            case 10:
                    system("cls");
                    JUEGO++;
                    cout<<"Nombre del jugador : "<<endl;
                    cin>>Nombre;
                    cout<<endl;
                    system("cls");
                    for(i=1;i<7;i++){
                    Ronda = i;
                    cout<<"RONDA : "<<Ronda<<endl;
                    while(AcumulacionPTS<21){
                    Tiro++;
                    cargarDados(v,tam);
                    Puntosjugada=AnalisisDados(v,tam,Ronda,Puntosjugada);
                    AcumulacionPTS+=Puntosjugada;
                    PuntosTotales+=Puntosjugada;
                    PuntosTotalesconFallidos+=Puntosjugada;
                    if(Puntosjugada==0){
                    TiroFallido++;
                    PuntosTotalesconFallidos=PuntosTotalesconFallidos-2;
                    }
                    if(Puntosjugada==21)Buncos++;
                    system("cls");
                    MenuDeDados(v);
                    cout << "\n" << "\n" << "\n" << "\n" <<endl;
                    if(Puntosjugada==21){
                    cout<<"¡¡Obtuviste Bunco!!"<<endl;
                    cout<<"-----------------------------"<<endl;}
                    cout<<"PUNTAJE DE LA RONDA: "<<Puntosjugada<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"TURNO DE "<<Nombre<< " | "<<"RONDA NUMERO "<<Ronda<<" | "<<" PUNTAJE ACUMULADO: "<<PuntosTotales<< " PUNTOS"<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"VECES QUE OBTUVO BUNCO : "<<Buncos<<endl;
                    cout<<"-----------------------------"<<endl;
                    cout<<"LANZAMIENTOS : "<<Tiro<<endl<<endl;
                    system("pause");
                    system("cls");
                    }
                    system("cls");
                    if(Ronda+1<7){
                    cout<<"RONDA NUMERO "<<Ronda+1<<endl;
                    cout<<"-------------------"<<endl;
                    cout<<"PUNTAJE "<<Nombre<<" : "<<PuntosTotales<<endl;
                    cout<<"BUNCOS : "<<Buncos<<endl;
                    cout<<"Tiros Fallidos: "<<TiroFallido<<endl;
                    cout<<"LANZAMIENTOS "<<Tiro<<endl;
                    cout<<"-------------------"<<endl;
                    AcumulacionPTS=0;
                    Puntosjugada=0;
                    system("pause");
                    system("cls");
                    }
                        }
                    system("cls");
                    cout<<"Puntos totales :"<<PuntosTotalesconFallidos<<endl;
                    if(PuntosTotalesconFallidos>MAXPTS){
                    MAXPTS=PuntosTotalesconFallidos;
                    MAXBUNCO=Buncos;
                    MAXNOMBRE=Nombre;}
                    AcumulacionPTS=0;
                    Puntosjugada=0;
                    Tiro=0;
                    TiroFallido=0;
                    PuntosTotales=0;
                    Buncos=0;
                    PuntosTotalesconFallidos=0;
                    system("pause");
                    system("cls");
                        break;
             case 11:   system("cls");
                        if(JUEGO>0){
                        cout<<"MEJOR JUGADOR : "<<endl;
                        cout<<"------------------------"<<endl;
                        cout<<"NOMBRE : "<<MAXNOMBRE<<endl;
                        cout<<"MAYOR PUNTUACION : "<<MAXPTS<<endl;
                        cout<<"CANTIDAD DE BUNCOS REALIZADOS : "<<MAXBUNCO<<endl;
                        system("pause");
                        system("cls");
                        }
                        else{
                        cout<<"ERROR : No se realizo ningun juego"<<endl<<endl;
                        system("pause");
                        system("cls");}
                        break;
            case 12:
                    system("cls");
                    exit(0);
                    break;
                    system("cls");
        }

    }return 0;
}
