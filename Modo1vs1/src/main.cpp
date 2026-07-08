#include <iostream>

#include "../include/menu.h"
#include "../include/equipos.h"
#include "../include/combate.h"

using namespace std;

int main()
{
    int opcion;

    do
    {
        opcion = menuPrincipal();

        switch (opcion)
        {
        case 1:
            seleccionarEquipos();
            combate();
            break;

        case 2:
            cout << "\nGracias por jugar\n";
            break;
        }

    } while (opcion != 2);

    return 0;
}