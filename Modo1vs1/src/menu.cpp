#include <iostream>

#include "../include/menu.h"

using namespace std;

int menuPrincipal()
{
    int opcion;

    do
    {
        cout << "\n====================";
        cout << "\n   POKEMON GAME";
        cout << "\n====================";
        cout << "\n1. Modo Versus";
        cout << "\n2. Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

    } while (opcion < 1 || opcion > 2);

    return opcion;
}