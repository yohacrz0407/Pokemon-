#include <iostream>
#include <string>

#include "../include/combate.h"
#include "../include/equipos.h"
#include "../include/datos.h"

using namespace std;


void combate()
{
    int vivosJ1[3] = {1, 1, 1};
    int vivosJ2[3] = {1, 1, 1};

    int derrotadosJ1 = 0;
    int derrotadosJ2 = 0;

    cout << "\n===== COMBATE =====\n";

    int pokeJ1 = seleccionarPokemonVivo(0, vivosJ1);
    int pokeJ2 = seleccionarPokemonVivo(1, vivosJ2);

    int indice1 = equipo[0][pokeJ1];
    int indice2 = equipo[1][pokeJ2];

    int vida1 = vidaBase[indice1];
    int vida2 = vidaBase[indice2];

    while (derrotadosJ1 < 3 && derrotadosJ2 < 3)
    {
        cout << "\n===================================";
        cout << "\nEs el turno de " << nombre[0];
        cout << "\nPresione ENTER para continuar...";
        cout << "\n===================================\n";

        cin.ignore();
        cin.get();
        int ataqueElegido;
        int dano;

        cout << "\n"
             << pokemon[indice1]
             << " HP: "
             << vida1
             << "/"
             << vidaBase[indice1];

        cout << "\n"
             << pokemon[indice2]
             << " HP: "
             << vida2
             << "/"
             << vidaBase[indice2];

        cout << "\n1. " << ataque1[indice1];
        cout << "\n2. " << ataque2[indice1];
        cout << "\n3. " << ataque3[indice1];

        do
        {
            cout << "\nSeleccione: ";
            cin >> ataqueElegido;

            if (ataqueElegido < 1 || ataqueElegido > 3)
            {
                cout << "\nOpcion invalida. Solo es valido un numero del 1 al 3.\n";
            }

        } while (ataqueElegido < 1 || ataqueElegido > 3);

        switch (ataqueElegido)
        {
        case 1:
            dano = ataqueBase[indice1] -
                   (defensaBase[indice2] / 2);
            break;

        case 2:
            dano = ataqueBase[indice1] + 10 -
                   (defensaBase[indice2] / 2);
            break;

        case 3:
            dano = ataqueBase[indice1] + 20 -
                   (defensaBase[indice2] / 2);
            break;

        default:
            dano = 1;
        }

        if (dano < 1)
        {
            dano = 1;
        }

        vida2 = vida2 - dano;

        if (vida2 < 0)
        {
            vida2 = 0;
        }

        cout << "\n"
             << pokemon[indice1]
             << " uso "
             << (ataqueElegido == 1 ? ataque1[indice1] : ataqueElegido == 2 ? ataque2[indice1]
                                                                            : ataque3[indice1])
             << " e hizo "
             << dano
             << " de dano";

        cout << "\nVida restante de "
             << pokemon[indice2]
             << ": "
             << vida2
             << endl;

        if (vida2 <= 0)
        {
            cout << "\n"
                 << pokemon[indice2]
                 << " ha sido derrotado\n";

            vivosJ2[pokeJ2] = 0;
            derrotadosJ2++;

            if (derrotadosJ2 == 3)
                break;

            pokeJ2 = seleccionarPokemonVivo(1, vivosJ2); // Selecciona un nuevo Pokémon vivo para el jugador 2

            indice2 = equipo[1][pokeJ2]; // Actualiza el índice del nuevo Pokémon seleccionado
            vida2 = vidaBase[indice2];   // Actualiza la vida del nuevo Pokémon seleccionado
        }

        cout << "\n===================================";
        cout << "\nEs el turno de " << nombre[1];
        cout << "\nPresione ENTER para continuar...";
        cout << "\n===================================\n";

        cin.ignore();
        cin.get();

        cout << "\n"
             << pokemon[indice1]
             << " HP: "
             << vida1
             << "/"
             << vidaBase[indice1];

        cout << "\n"
             << pokemon[indice2]
             << " HP: "
             << vida2
             << "/"
             << vidaBase[indice2];

        cout << "\n1. " << ataque1[indice2];
        cout << "\n2. " << ataque2[indice2];
        cout << "\n3. " << ataque3[indice2];
        do
        {
            cout << "\nSeleccione: ";
            cin >> ataqueElegido;

            if (ataqueElegido < 1 || ataqueElegido > 3)
            {
                cout << "\nOpcion invalida. Solo es valido un numero del 1 al 3.\n";
            }

        } while (ataqueElegido < 1 || ataqueElegido > 3);

        switch (ataqueElegido)
        {
        case 1:
            dano = ataqueBase[indice2] -
                   (defensaBase[indice1] / 2);
            break;

        case 2:
            dano = ataqueBase[indice2] + 10 -
                   (defensaBase[indice1] / 2);
            break;

        case 3:
            dano = ataqueBase[indice2] + 20 -
                   (defensaBase[indice1] / 2);
            break;

        default:
            dano = 1;
        }

        if (dano < 1)
        {
            dano = 1;
        }

        vida1 = vida1 - dano;

        if (vida1 < 0)
            vida1 = 0;

        cout << "\n"
             << pokemon[indice2]
             << " uso "
             << (ataqueElegido == 1 ? ataque1[indice2] : ataqueElegido == 2 ? ataque2[indice2]
                                                                            : ataque3[indice2])
             << " e hizo "
             << dano
             << " de dano";

        cout << "\nVida restante de "
             << pokemon[indice1]
             << ": "
             << vida1
             << endl;

        if (vida1 <= 0)
        {
            cout << "\n"
                 << pokemon[indice1]
                 << " ha sido derrotado\n";

            vivosJ1[pokeJ1] = 0;
            derrotadosJ1++;

            if (derrotadosJ1 == 3)
                break;

            pokeJ1 = seleccionarPokemonVivo(0, vivosJ1);

            indice1 = equipo[0][pokeJ1];
            vida1 = vidaBase[indice1];
        }
    }

    cout << "\n====================\n";

    if (derrotadosJ1 == 3)
    {
        cout << nombre[1]
             << " GANA LA BATALLA\n";
    }
    else
    {
        cout << nombre[0]
             << " GANA LA BATALLA\n";
    }
}