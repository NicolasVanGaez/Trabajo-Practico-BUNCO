#ifndef TestDados_H_INCLUDED
#define TestDados_H_INCLUDED
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "rlutil.h"
#include <dos.h>

using namespace std;
using namespace rlutil;
#define ABAJO 80
#define ARRIBA 72
#define ENTER 13



//FUNCIONES PARA EL MENU

void tituloAnimado() {

    int xcol;
    // primera linea
    setColor(YELLOW);
    locate(14, 2); printf("%c", 201);
    locate(14, 3); printf("%c", 186);
    locate(14, 4); printf("%c", 200);


    for (xcol = 15; xcol <= 116; xcol++) {

        locate(xcol, 2); printf("%c", 205);
        locate(xcol, 4); printf("%c", 205);

        Sleep(3);
    }

    locate(116, 2); printf("%c", 187);
    locate(116, 3); printf("%c", 186);
    locate(116, 4); printf("%c", 188);

    //SEGUNDA LINEA

    char vtitulo[] = "BUNCO";
    int vlongitud;
    vlongitud = strlen(vtitulo);
    int vcentro = (((80 - vlongitud) / 2) + 1);

    for (xcol = 49; xcol <= vcentro; xcol++) {
    }
        locate(xcol, 3); printf(vtitulo);
    }

int MenuPrincipalBunco() {
    int x = 40, y = 9;
    tituloAnimado();
    setBackgroundColor(GREY);
    setColor(RED);
    locate(35, 8); cout << endl;
    locate(35, 9); cout << "      JUEGO NUEVO PARA UN JUGADOR" << endl;
    locate(35, 10); cout << "      MODO SIMULADO(CARGA DE DADOS MANUAL)" << endl;
    locate(35, 11); cout << "      MOSTRAR PUNTUACION MAS ALTA" << endl;
    locate(35, 12); cout << "      SALIR" << endl;

    locate(x, y); printf("*"); //a partir de aca es para utilizar las flechas del teclado
    bool elegir = false;
    while (!elegir) {
        if (_kbhit()) {
            locate(x, y); printf(" ");
            char tecla = _getch();
            if (tecla == ENTER) { elegir = true; return y; }
            if (tecla == ARRIBA && y > 9) locate(x, y--);
            if (tecla == ABAJO && y < 12) locate(x, y++);
            locate(x, y); printf("*");
        }
    }
}

void dadouno() { // la funcion que dibuja al dado en la primera posicion

    // HORIZONTAL
    for (int i = 2; i < 10; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(2, i); printf("%c", 186);
        locate(10, i); printf("%c", 186);
    }
    ///ESQUINAS
    locate(2, 3); printf("%c", 201);
    locate(2, 7); printf("%c", 200);
    locate(10, 3); printf("%c", 187);
    locate(10, 7); printf("%c", 188);
}

void dadoDos() {// la funcion que dibuja al dado en la segunda posicion

    // HORIZONTAL
    for (int i = 13; i < 20; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(12, i); printf("%c", 186);
        locate(20, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(12, 3); printf("%c", 201);
    locate(12, 7); printf("%c", 200);
    locate(20, 3); printf("%c", 187);
    locate(20, 7); printf("%c", 188);
}

void dadoTres() {// la funcion que dibuja al dado en la tercera posicion

    // HORIZONTAL
    for (int i = 23; i < 30; i++) {
        locate(i, 3); printf("%c", 205);
        locate(i, 7); printf("%c", 205);
    }
    // VERTICAL
    for (int i = 4; i < 7; i++) {
        locate(22, i); printf("%c", 186);
        locate(30, i); printf("%c", 186);
    }
    //ESQUINAS
    locate(22, 3); printf("%c", 201);
    locate(22, 7); printf("%c", 200);
    locate(30, 3); printf("%c", 187);
    locate(30, 7); printf("%c", 188);
}

//La idea de esta funcion es dependiendo de el valor de i,mostrar el dado
void MenuDeDados(int v[]) {    // dibujalos dados respecto a los valores que se le entreguen en las distintas posiciones
    int i;
    dadouno(); dadoDos(); dadoTres();
    for (i = 0; i <5; i++) {
        switch (v[i]) {
        /*dado 1*/ case 1:
            if (i == 0) { locate(6, 5); printf("%c", 254); }
            if (i == 1) { locate(16, 5); printf("%c", 254); }
            if (i == 2) { locate(26, 5); printf("%c", 254); }
            if (i == 3) { locate(36, 5); printf("%c", 254); }
            if (i == 4) { locate(46, 5); printf("%c", 254); }

            ; break;

        /*dado 2*/ case 2:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(14, 4); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 4); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            ; break;
        /*dado 3*/  case 3:
            if (i == 0) {
                locate(6, 5); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(16, 5); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
            }

            if (i == 2) {
                locate(26, 5); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
            }

            if (i == 3) {
                locate(36, 5); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
            }

            if (i == 4) {
                locate(46, 5); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
            }

            ; break;
         /*dado 4*/ case 4:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }

            if (i == 1) {
                locate(14, 4); printf("%c", 254);

                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }

            if (i == 2)

            {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }


            if (i == 3)

            {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            break;

        /*dado 5*/ case 5:
            if (i == 0)
            {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(6, 5); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }
            if (i == 1)
            {
                locate(14, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(16, 5); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2)
            {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(26, 5); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(36, 5); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4)
            {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(46, 5); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }

            break;

        /*dado 6*/  case 6:
            if (i == 0) {
                locate(4, 4); printf("%c", 254);
                locate(4, 6); printf("%c", 254);
                locate(8, 4); printf("%c", 254);
                locate(4, 5); printf("%c", 254);
                locate(8, 5); printf("%c", 254);
                locate(8, 6); printf("%c", 254);
            }
            if (i == 1) {
                locate(14, 4); printf("%c", 254);
                locate(14, 6); printf("%c", 254);
                locate(18, 4); printf("%c", 254);
                locate(14, 5); printf("%c", 254);
                locate(18, 5); printf("%c", 254);
                locate(18, 6); printf("%c", 254);
            }
            if (i == 2) {
                locate(24, 4); printf("%c", 254);
                locate(24, 6); printf("%c", 254);
                locate(28, 4); printf("%c", 254);
                locate(24, 5); printf("%c", 254);
                locate(28, 5); printf("%c", 254);
                locate(28, 6); printf("%c", 254);
            }
            if (i == 3) {
                locate(34, 4); printf("%c", 254);
                locate(34, 6); printf("%c", 254);
                locate(38, 4); printf("%c", 254);
                locate(34, 5); printf("%c", 254);
                locate(38, 5); printf("%c", 254);
                locate(38, 6); printf("%c", 254);
            }
            if (i == 4) {
                locate(44, 4); printf("%c", 254);
                locate(44, 6); printf("%c", 254);
                locate(48, 4); printf("%c", 254);
                locate(44, 5); printf("%c", 254);
                locate(48, 5); printf("%c", 254);
                locate(48, 6); printf("%c", 254);
            }
            break;
        }
    }
}
#endif // FUNCIONESGENERALA_H_INCLUDED
