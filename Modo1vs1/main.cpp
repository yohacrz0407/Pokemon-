#include <iostream>
#include <string>

using namespace std;
int menuPrincipal();                                  // Función para mostrar el menú principal y obtener la opción del usuario
void seleccionarEquipos();                            // Función para que los jugadores seleccionen sus equipos de Pokémon
void combate();                                       // Función para manejar el combate entre los Pokémon seleccionados
int seleccionarPokemonVivo(int jugador, int vivos[]); // Función para seleccionar un Pokémon vivo del equipo del jugador
string ataque1[10] = {
    "Impactrueno",
    "Lanzallamas",
    "Pistola Agua",
    "Latigo Cepa",
    "Bola Sombra",
    "Garra Dragon",
    "Esfera Aural",
    "Golpe Cuerpo",
    "Psiquico",
    "Shuriken Agua"};

string ataque2[10] = {
    "Ataque Rapido",
    "Garra Metal",
    "Placaje",
    "Hoja Afilada",
    "Hipnosis",
    "Vuelo",
    "Patada Baja",
    "Descanso",
    "Confusion",
    "Doble Equipo"};

string ataque3[10] = {
    "Cola de Hierro",
    "Anillo Igneo",
    "Hidrobomba",
    "Rayo Solar",
    "Pesadilla",
    "Cometa Draco",
    "Pulso Dragon",
    "Hiperrayo",
    "Premonicion",
    "Tajo Umbrio"};
int defensaBase[10] = {
    15,
    20,
    35,
    30,
    10,
    25,
    18,
    40,
    15,
    18};
string pokemon[10] = {
    "Pikachu",
    "Charizard",
    "Blastoise",
    "Venusaur",
    "Gengar",
    "Dragonite",
    "Lucario",
    "Snorlax",
    "Gardevoir",
    "Greninja"};

string nombre[2];
int equipo[2][3];

int vidaBase[10] = {
    100,
    130,
    150,
    140,
    100,
    160,
    120,
    180,
    110,
    120};

int ataqueBase[10] = {
    30,
    40,
    25,
    28,
    35,
    45,
    38,
    20,
    32,
    37};

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

    } while (opcion < 1 || opcion > cantidad);

    return disponibles[opcion - 1];
}

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