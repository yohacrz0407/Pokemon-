#include <iostream>
#include <string>

#include "../include/equipos.h"
#include "../include/datos.h"

using namespace std;

void seleccionarEquipos()
{
    char respuesta;

    do
    {
        for (int jugador = 0; jugador < 2; jugador++) // bucle para que ambos jugadores seleccionen sus equipos
        {
            cout << "\nIngrese el nombre del Jugador "
                 << jugador + 1 << ": ";
            cin >> nombre[jugador];

            cout << "\nTurno de " << nombre[jugador] << endl;

            cout << "\nLista de Pokemon:\n";

            for (int i = 0; i < 10; i++)
            {
                cout << i + 1
                     << ". "
                     << pokemon[i]
                     << " | HP: "
                     << vidaBase[i]
                     << " | ATK: "
                     << ataqueBase[i]
                     << " | DEF: "
                     << defensaBase[i]
                     << endl;
            }

            cout << "\nSeleccione 3 Pokemon:\n";

            for (int i = 0; i < 3; i++)
            {
                bool repetido;

                do
                {
                    repetido = false;

                    cout << "Pokemon " << i + 1 << " (1-10): ";
                    cin >> equipo[jugador][i];

                    if (equipo[jugador][i] < 1 || equipo[jugador][i] > 10)
                    {
                        cout << "\nPokemon invalido.\n";
                        continue;
                    }

                    for (int j = 0; j < i; j++)
                    {
                        if (equipo[jugador][i] == equipo[jugador][j])
                        {
                            repetido = true;
                            cout << "\nEse Pokemon ya fue seleccionado en tu equipo.\n";
                        }
                    }

                    // Verificar que no lo haya escogido el otro jugador
                    if (jugador == 1)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            if (equipo[1][i] - 1 == equipo[0][j])
                            {
                                repetido = true;
                                cout << "\nEse Pokemon ya fue seleccionado por el Jugador 1.\n";
                                break;
                            }
                        }
                    }

                } while (equipo[jugador][i] < 1 || equipo[jugador][i] > 10 || repetido);

                equipo[jugador][i]--;
            }
        }

        cout << "\n========================";
        cout << "\nEquipos Seleccionados";
        cout << "\n========================\n";

        for (int jugador = 0; jugador < 2; jugador++)
        {
            cout << "\n"
                 << nombre[jugador]
                 << ":\n";

            for (int i = 0; i < 3; i++)
            {
                cout << "- "
                     << pokemon[equipo[jugador][i]]
                     << endl;
            }
        }

        cout << "\nDesean realizar cambios? (S/N): ";
        cin >> respuesta;

    } while (respuesta == 'S' || respuesta == 's');

    cout << "\nComenzando combate...\n";
}

int seleccionarPokemonVivo(int jugador, int vivos[])
{
    int opcion;
    int disponibles[3];
    int cantidad = 0;

    cout << "\n============================";
    cout << "\nTurno de " << nombre[jugador];
    cout << "\nSeleccione el Pokemon para iniciar la batalla";
    cout << "\n============================";
    cout << "\nPokemon disponibles:\n";

    for (int i = 0; i < 3; i++)
    {
        if (vivos[i] == 1)
        {
            cout << cantidad + 1
                 << ". "
                 << pokemon[equipo[jugador][i]]
                 << endl;

            disponibles[cantidad] = i;
            cantidad++;
        }
    }

    do
    {
        cout << "\nSeleccione Pokemon: ";
        cin >> opcion;

        if (opcion < 1 || opcion > cantidad)
        {
            cout << "\nOpcion invalida. Seleccione un Pokemon disponible.\n";
        }

    } while (opcion < 1 || opcion > cantidad);

    return disponibles[opcion - 1];
}