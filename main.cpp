#include <unistd.h>

#include <ctime>
#include <iostream>

#include "Fabrica.h"
#include "Definiciones.h"
#include "DtFechaHora.h"
#include "Juego.h"
#include "Jugador.h"
#include "TipoPago.h"
#include "Sesion.h"

using namespace std;

string longTab = "";
string longSpace = "";
string msg;     // mensaje - menuCargarPartida
float progress; // tiempo de carga - closeBar

/********** Referenciar Interfaces **********/

Fabrica* fabrica;
ICAgregarCategoria* icAgregarCategoria;
ICIniciarSesion* icIniciarSesion;
ICCerrarSesion* icCerrarSesion;
ICInfoJuego* icInfoJuego;
ICAltaUsuario* icAltaUsuario;
ICIniciarPartida* icIniciarPartida;
ICAgregarVideojuego* icAgregarVideojuego;
ICSuscribirseaVideojuego* icSuscribirseaVideojuego;

/********** Instanciar Fabrica con las Interfaces **********/

void cargarFabrica()
{
    fabrica = Fabrica::getInstancia();
    icAgregarCategoria = fabrica->getICAgregarCategoria();
    icIniciarSesion = fabrica->getICIniciarSesion();
    icCerrarSesion = fabrica->getICCerrarSesion();
    icInfoJuego = fabrica->getICInfoJuego();
    icAltaUsuario = fabrica->getICAltaUsuario();
    icIniciarPartida = fabrica->getICIniciarPartida();
    icAgregarVideojuego = fabrica->getICAgregarVideojuego();
    icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
}

/********** Barra de Carga - Principal **********/

void loadBar()
{
    float progress = 0.0;
    cout << endl;
    while (progress < 1.1)
    {
        int barWidth = 68;
        cout << longTab << COLOR_BW << "  LOADING... [" << COLOR_RESET;
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                cout << COLOR_G << "▓" << COLOR_RESET;
            else if (i == pos)
                cout << COLOR_G << "▒" << COLOR_RESET;
            else
                cout << " ";
        }
        sleep(1);
        cout << COLOR_BW << "] " << int(progress * 100.0) << " %\r" << COLOR_RESET;
        cout.flush();
        progress += 1;
    }
    sleep(3);
    cout << endl;
    system("clear");
}

/********** Barra de Carga 2 **********/

void closeBar(float progress)
{
    float progressBar = 0;
    cout << "\n"
         << longTab << COLOR_BW << "\t\t   LOADING..." << COLOR_RESET << endl;
    cout << endl;
    while (progressBar < 1.1)
    {
        int barWidth = 5;
        cout << longTab << "\t  " << COLOR_BW << "       [ " << COLOR_RESET;
        int pos = barWidth * progressBar;
        for (int i = 0; i < barWidth; ++i)
        {
            if (i < pos)
                cout << COLOR_G << "■ " << COLOR_RESET;
            else if (i == pos)
                cout << COLOR_LG << "■" << COLOR_RESET;
            else
                cout << " ";
        }
        sleep(1);
        cout << COLOR_BW << "] " << int(progressBar * 100.0) << " %\r" << COLOR_RESET;
        cout.flush();
        progressBar += progress;
    }
    sleep(1);
    cout << endl;
    system("clear");
}

/********** Welcome Banner **********/

void welcomeBanner()
{
    system("clear");
    cout << longTab << "╔═════════════════════════════════════════════════════════════════════════════════════╗" << endl;
    cout << longTab << "║" << COLOR_G << "░██╗░░░░░░░██╗███████╗██╗░░░░░░█████╗░░█████╗░███╗░░░███╗███████╗" << COLOR_SB << "   ████████╗░█████╗░" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_G << "░██║░░██╗░░██║██╔════╝██║░░░░░██╔══██╗██╔══██╗████╗░████║██╔════╝" << COLOR_SB << "   ╚══██╔══╝██╔══██╗" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_G << "░╚██╗████╗██╔╝█████╗░░██║░░░░░██║░░╚═╝██║░░██║██╔████╔██║█████╗░░" << COLOR_SB << "   ░░░██║░░░██║░░██║" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_G << "░░████╔═████║░██╔══╝░░██║░░░░░██║░░██╗██║░░██║██║╚██╔╝██║██╔══╝░░" << COLOR_SB << "   ░░░██║░░░██║░░██║" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_G << "░░╚██╔╝░╚██╔╝░███████╗███████╗╚█████╔╝╚█████╔╝██║░╚═╝░██║███████╗" << COLOR_SB << "   ░░░██║░░░╚█████╔╝" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_G << "░░░╚═╝░░░╚═╝░░╚══════╝╚══════╝░╚════╝░░╚════╝░╚═╝░░░░░╚═╝╚══════╝" << COLOR_SB << "   ░░░╚═╝░░░░╚════╝░" << COLOR_RESET << "║" << endl;
    cout << longTab << "║" << COLOR_P << "\t░██████╗░░█████╗░███╗░░░███╗███████╗██╗░░░░░░█████╗░███╗░░██╗██████╗░" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_P << "\t██╔════╝░██╔══██╗████╗░████║██╔════╝██║░░░░░██╔══██╗████╗░██║██╔══██╗" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_P << "\t██║░░██╗░███████║██╔████╔██║█████╗░░██║░░░░░███████║██╔██╗██║██║░░██║" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_P << "\t██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░██║░░░░░██╔══██║██║╚████║██║░░██║" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_P << "\t╚██████╔╝██║░░██║██║░╚═╝░██║███████╗███████╗██║░░██║██║░╚███║██████╔╝" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_P << "\t░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝╚══════╝╚═╝░░╚═╝╚═╝░░╚══╝╚═════╝░" << COLOR_RESET << "         ║" << endl;
    cout << longTab << "║" << COLOR_BW << "\t\t\t\t ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄" << COLOR_RESET << "                                 ║" << endl;
    cout << longTab << "║" << COLOR_BW << "\t\t\t\t█░░░█░░░░░░░░░░▄▄░██░█" << COLOR_RESET << "                                ║" << endl;
    cout << longTab << "║" << COLOR_BW << "\t\t\t\t█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█" << COLOR_RESET << "                                ║" << endl;
    cout << longTab << "║" << COLOR_BW << "\t\t\t\t█░░░▀░░░▄▄▄▄▄░░██░▀▀░█" << COLOR_RESET << "                                ║" << endl;
    cout << longTab << "║" << COLOR_BW << "\t\t\t\t ▀▄▄▄▄▄▀     ▀▄▄▄▄▄▄▀" << COLOR_RESET << "                                 ║" << endl;
    cout << longTab << "╚═════════════════════════════════════════════════════════════════════════════════════╝" << endl;
    cout << longTab << COLOR_LG << "\t\t\t\t     Version 2.0" << COLOR_RESET << endl;
    loadBar();
}

/********** Menu Custom Display **********/

void menuCustomDisplay()
{
    system("clear");
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║            ♦ Set Menu Position ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╠════════════════════════════════════════════╣\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║            1) Mover " << COLOR_BG << "ARRIBA " << COLOR_RESET << "                ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║            2) Mover " << COLOR_BG << "ABAJO " << COLOR_RESET << "                 ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║            3) Mover " << COLOR_BG << "IZQUIERDA " << COLOR_RESET << "             ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║            4) Mover " << COLOR_BG << "DERECHA " << COLOR_RESET << "               ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║            5) Finalizar                    ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "╚════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
}

/********** Menu Display Mode **********/

void menuDisplay()
{
    system("clear");
    cout << longTab << "╔═══════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║  ♦ Select Display Mode ♦  ║" << COLOR_RESET << endl;
    cout << longTab << "╠═══════════════════════════╣" << endl;
    cout << longTab << "║         1. Left           ║" << endl;
    cout << longTab << "║         2. Center         ║" << endl;
    cout << longTab << "║         3. Custom         ║" << endl;
    cout << longTab << "╚═══════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    string addTab("\t");
    string addSpace("\n");
    int type;
    cin >> type;
    switch (type)
    {
    case 1:
        longTab = "";
        longSpace = "";
        break;
    case 2:
        longTab = "\t\t\t\t\t\t\t\t\t\t\t";
        longSpace = "\n\n\n\n\n\n\n\n\n\n";
        break;
    case 3:
    {
        system("clear");
        menuCustomDisplay();
        int op;
        cin >> op;
        string addTab("\t");
        string addSpace("\n");
        while (op != 5)
        {
            switch (op)
            {
            case 1:
                if (longSpace.length() <= 0)
                {
                    cout << "\n"
                         << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                    sleep(1);
                }
                else if (longSpace.length() == 1)
                {
                    longSpace = "";
                }
                else
                {
                    longSpace.erase(longSpace.length() - 2); // removes last 2 characters;
                }
                break;
            case 2:
                longSpace.append(addSpace);
                break;
            case 3:
                if (longTab.length() <= 0)
                {
                    cout << "\n"
                         << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                    sleep(1);
                }
                else if (longTab.length() == 1)
                {
                    longTab = "";
                }
                else
                {
                    longTab.erase(longTab.length() - 2); // removes last 2 characters
                }
                break;
            case 4:
                longTab.append(addTab);
                break;
            }
            system("clear");
            menuCustomDisplay();
            cin >> op;
        }
    }
    }
    system("clear");
}

/********** Mensaje de inicio y Carga **********/

void initialization()
{
    progress = 0.25;
    cout << longSpace << longTab << COLOR_P << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│  ⏳ Iniciando Sesión, Por Favor Espere...  │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│ ──▒▒▒▒▒▒" << COLOR_R << "──▒▒▒▒▒▒" << COLOR_SB << "──▒▒▒▒▒▒" << COLOR_O << "──▒▒▒▒▒▒" << COLOR_Y << "───▄████▄  " COLOR_P "│" << endl;
    cout << longTab << "│ ─▒─▄▒─▄▒" << COLOR_R << "─▒─▄▒─▄▒" << COLOR_SB << "─▒─▄▒─▄▒" << COLOR_O << "─▒─▄▒─▄▒" << COLOR_Y << "──███▄█▀   " COLOR_P "│" << endl;
    cout << longTab << "│ ─▒▒▒▒▒▒▒" << COLOR_R << "─▒▒▒▒▒▒▒" << COLOR_SB << "─▒▒▒▒▒▒▒" << COLOR_O << "─▒▒▒▒▒▒▒" << COLOR_Y << "─▐████──█─█" COLOR_P "│" << endl;
    cout << longTab << "│ ─▒▒▒▒▒▒▒" << COLOR_R << "─▒▒▒▒▒▒▒" << COLOR_SB << "─▒▒▒▒▒▒▒" << COLOR_O << "─▒▒▒▒▒▒▒" << COLOR_Y << "──█████▄   " COLOR_P "│" << endl;
    cout << longTab << "│ ─▒─▒─▒─▒" << COLOR_R << "─▒─▒─▒─▒" << COLOR_SB << "─▒─▒─▒─▒" << COLOR_O << "─▒─▒─▒─▒" << COLOR_Y << "───▀████▀  " COLOR_P "│" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
    closeBar(progress);
}

/********** Menu Tipo de Partida **********/

void menuTipoDePartida()
{
    cout << longTab << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│         Selecciona Tipo de Partida         │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│          1. 👤 Partida Individual          │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│          2. 👥 Partida Multijugador        │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
}

void menuCargarPartida(string msg)
{
    system("clear");
    progress = 0.25;
    cout << longSpace << longTab << COLOR_P << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│  ⏳ Iniciando Partida, por favor Espere... │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│             ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄           │\n";
    cout << longTab << "│            █░░░█░░░░░░░░░░▄▄░██░█          │\n";
    cout << longTab << "│            █░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█          │\n";
    cout << longTab << "│            █░░░▀░░░▄▄▄▄▄░░██░▀▀░█          │\n";
    cout << longTab << "│             ▀▄▄▄▄▄▀     ▀▄▄▄▄▄▄▀           │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
    cout << longTab << COLOR_LG << msg << COLOR_RESET << endl;
    closeBar(progress);
    cout << longSpace << longTab << COLOR_G << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│     [✔] Partida Iniciada Correctamente!    │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                       ▄▄                   │\n";
    cout << longTab << "│                      █░█                   │\n";
    cout << longTab << "│                     ▄▀░█                   │\n";
    cout << longTab << "│              ████▄▄▄▀░░▀▀▀▀▄               │\n";
    cout << longTab << "│              ████░░░░░░░░░░█               │\n";
    cout << longTab << "│              ████░░░░░░░░░░█               │\n";
    cout << longTab << "│              ████▄▄▄░░░░░░░█               │\n";
    cout << longTab << "│              ▀▀▀▀   ▀▀▀▀▀▀▀                │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2");
    system("clear");
}

/***************************************************
 *                                                  *
 *              Operaciones Principales             *
 *                                                  *
 ***************************************************/

/*-------------------------------------------------*
 *                 Menu Agregar Datos               *
 *--------------------------------------------------*/

void menuCargarDatos()
{
    // sistema->cargarDatosPredeterminados();
    system("clear");
    progress = 0.25;
    cout << longSpace << longTab << COLOR_P << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│   ⏳ Cargando Datos, por favor Espere...   │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│             ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄           │\n";
    cout << longTab << "│            █░░░█░░░░░░░░░░▄▄░██░█          │\n";
    cout << longTab << "│            █░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█          │\n";
    cout << longTab << "│            █░░░▀░░░▄▄▄▄▄░░██░▀▀░█          │\n";
    cout << longTab << "│             ▀▄▄▄▄▄▀     ▀▄▄▄▄▄▄▀           │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
    closeBar(progress);
    cout << longSpace << longTab << COLOR_G << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│      [✔] Datos Cargados Correctamente!     │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                       ▄▄                   │\n";
    cout << longTab << "│                      █░█                   │\n";
    cout << longTab << "│                     ▄▀░█                   │\n";
    cout << longTab << "│              ████▄▄▄▀░░▀▀▀▀▄               │\n";
    cout << longTab << "│              ████░░░░░░░░░░█               │\n";
    cout << longTab << "│              ████░░░░░░░░░░█               │\n";
    cout << longTab << "│              ████▄▄▄░░░░░░░█               │\n";
    cout << longTab << "│              ▀▀▀▀   ▀▀▀▀▀▀▀                │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2");
}

/*---------------------------------------------------*
 *                 Menu Alta Usuario                  *
 *----------------------------------------------------*/

void menuAltaUsuario()
{
    system("clear");
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 👤 Agregar Usuario ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
    string email, pass;
    int num, num2;
    cout << longTab << "♦ Ingrese su Email: ";
    cin >> email;
    cout << longTab << "♦ Ingrese su Password: ";
    cin >> pass;
    icAltaUsuario->datosComunes(email, pass);
    cout << longTab << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│               Seleccione Rol               │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│             1. 🔧 Desarrollador            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│             2. 🎮 Jugador                  │\n";
    cout << longTab << "│                                            │\n"; //✅✅🔁
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> num;
    bool cond = true;
    switch (num)
    {
    case 1:
    {
        string nomEmp;
        cout << longTab << "♦ Ingrese el nombre de la empresa: ";
        cin >> nomEmp;
        icAltaUsuario->datosEmpresa(nomEmp);
        try
        {
            icAltaUsuario->altaUsuario();
            cout << COLOR_G << longTab << "\n✅ El usuario fue agregado con exito!!" << COLOR_RESET << endl;
        }
        catch (invalid_argument &e)
        {
            cout << "\n"
                 << longTab << COLOR_Y << "┌─────────────────────────────────────────┐" << endl;
            cout << longTab << e.what() << endl;
            cout << longTab << "└─────────────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2");
        }
    }
    break;
    case 2:
    {
        string nick, desc;
        cout << longTab << "♦ Ingrese nickname: ";
        cin >> nick;
        cout << longTab << "♦ Ingrese una breve descripcion: ";
        cin >> desc;
        icAltaUsuario->datosJugador(nick, desc);
        do
        {
            try
            {
                icAltaUsuario->altaUsuario();
                cout << longTab << COLOR_G << "\n✅ El usuario fue agregado con exito!!" << COLOR_RESET << endl;
                cond = false;
            }
            catch (invalid_argument &e)
            {
                cout << "\n"
                     << longTab << COLOR_Y << "┌─────────────────────────────────────────┐" << endl;
                cout << longTab << e.what() << endl;
                cout << longTab << "└─────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 1");
                cout << longTab << "┌────────────────────────────────────────────┐" << endl;
                cout << longTab << "│   ¿Deseas volver a ingresar el nickname?   │" << endl;
                cout << longTab << "├────────────────────────────────────────────┤\n";
                cout << longTab << "│                                            │\n";
                cout << longTab << "│                                            │\n";
                cout << longTab << "│               1. 🔁 REINTENTAR             │\n";
                cout << longTab << "│                                            │\n";
                cout << longTab << "│               2. ❌ CANCELAR               │\n";
                cout << longTab << "│                                            │\n"; //✅✅🔁
                cout << longTab << "│                                            │\n";
                cout << longTab << "└────────────────────────────────────────────┘" << endl;
                cout << longTab << "❯ Opción: ";
                cin >> num2;
                switch (num2)
                {
                case 1:
                    cout << longTab << "♦ Ingrese nickname: ";
                    cin >> nick;
                    icAltaUsuario->ingNickname(nick);
                    break;
                case 2:
                    icAltaUsuario->cancelar();
                    cond = false;
                    break;
                }
            }
        } while (cond);
    }
    break;
    }
}

/*------------------------------------------------------*
 *                 Menu Iniciar Sesion                   *
 *-------------------------------------------------------*/

void menuIniciarSesion()
{
    system("clear");
    int cond;
    cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ 👤 Bienvenido ♦               ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               1) Iniciar Sesion              ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               2) Registrarse                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        system("clear");
        cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
        cout << longTab << "╚════════════════════════════════════════════╝\n";
        string email, pass;
        cout << longTab << "♦ Ingrese su Email: ";
        cin >> email;
        cout << longTab << "♦ Ingrese su Password: ";
        cin >> pass;
        if (icIniciarSesion->ingresarDatos(email, pass))
        {
            initialization();
        }
        else
        {
            system("clear");
            cout << longSpace << COLOR_R << "[ERROR] Usuario No Encontrado, Por Favor Ingrese Nuevamente" << COLOR_RESET << endl;
            cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
            cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
            cout << longTab << "╚════════════════════════════════════════════╝\n";
            string email, pass;
            cout << longTab << "♦ Ingrese su Email: ";
            cin >> email;
            cout << longTab << "♦ Ingrese su Password: ";
            cin >> pass;
        }
    }
    break;
    case 2:
    {
        menuAltaUsuario();
    }
    break;
    }
}

/*-----------------------------------------------------*
 *               Menu Cerrar Sesion                     *
 *------------------------------------------------------*/

void menuCerrarSesion()
{
    system("clear");
    cout << "♦ Esta seguro que desea Cerrar Sesion?" << endl;
    cout << "♦ 1/0" << endl;
    int cond;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icCerrarSesion->cerrarSesion();
        cout << "♦ Se cerro correctamente la sesion." << endl;
        cout << "♦ Saludos." << endl;
    }
    break;
    }
}

/*-------------------------------------------------------*
 *               Menu Agregar Categoria                   *
 *--------------------------------------------------------*/

void menuAgregarCategoria()
{
    system("clear");
    int id, cond;
    string genero, plataforma;
    cout << "♦ Estas son las categorias existentes: " << endl;
    icAgregarCategoria->listarDtCategorias();
    cout << "♦ Ingrese los nuevos datos de la categoria que desea agregar: " << endl;
    cout << "♦ Ingrese su id: " << endl;
    cin >> id;
    cout << "♦ Ingrese su genero: " << endl;
    cin >> genero;
    cout << "♦ Ingrese la plataforma: " << endl;
    cin >> plataforma;
    icAgregarCategoria->solictarDatos(id, genero, plataforma);
    cout << "♦ Desea confirmar esta nueva categoria? " << endl;
    cout << "♦ 1/0" << endl;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icAgregarCategoria->confirmarCategoria();
        cout << "♦ Se agrego correctamente la nueva categoria." << endl;
    }
    break;
    case 0:
    {
        icAgregarCategoria->cancelar();
    }
    break;
    }
}

/*---------------------------------------------------*
 *               Menu Agregar Videojuego              *
 *----------------------------------------------------*/

void menuAgregarVideojuego()
{
    system("clear");
    int costo, cond, x;
    string nombre, desc, genero, plataforma;
    cout << "♦ Ingrese el nombre del videojuego: " << endl;
    cin >> nombre;
    cout << "♦ Ingrese la descripcion del videojuego: " << endl;
    cin >> desc;
    cout << "♦ Ingrese el costo de la suscripcion: " << endl;
    cin >> costo;
    cout << "♦ Categorias: " << endl;
    icAgregarCategoria->listarDtCategorias();
    DtCategoria *nuevoDt;
    do
    {
        cout << "♦ Quiere seguir agregando categorias?" << endl;
        cout << "♦ 1/0" << endl;
        cin >> x;
        cout << "♦ Ingrese categoria: " << endl;
        cout << "\t♦ Ingrese el genero: " << endl;
        cin >> genero;
        cout << "\t♦ Ingrese la plataforma: " << endl;
        cin >> plataforma;
        nuevoDt = new DtCategoria(genero, plataforma);
        icAgregarVideojuego->agregarCategoria(nuevoDt);
    } while (x == 0);
    cout << "Nombre: " << nombre << endl;
    cout << "Descripcion: " << desc << endl;
    cout << "Costo: " << costo << endl;
    cout << "Email: " << icIniciarSesion->getEmail() << endl;
    cout << "♦ Desea confirmar este videojuego? " << endl;
    cout << "♦ 1/0" << endl;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icAgregarVideojuego->solicitarInfo(nombre, desc, costo);
        icAgregarVideojuego->confirmarJuego();
        cout << "♦ Se agrego correctamente el videojuego." << endl;
    }
    break;
    case 0:
    {
        icAgregarVideojuego->cancelar();
    }
    break;
    }
}

/*---------------------------------------------------*
 *               Menu Iniciar Partida                 *
 *----------------------------------------------------*/

void menuIniciarPartida()
{
    system("clear");
    int cond;
    string nom;
    bool cont = false;
    int cond2, dur, jug;
    //icIniciarPartida->listarVideoJuegosSuscripcionActiva();
    cout << "♦ Ingrese el nombre del juego que desea jugar: " << endl;
    cin >> nom;
    icIniciarPartida->seleccionarVideojuego(nom);
    cout << "♦ La partida sera (1)ultijugador o (0)ndividual ?" << endl;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        cout << "♦ La partida sera trasmitida en vivo?" << endl;
        cout << "♦ Ingrese 1 en el caso de serlo: " << endl;
        cin >> cond2;
        if (cond2 == 1)
        {
            cont = true;
        }
        cout << "♦ Ingrese la duracion: " << endl;
        cin >> dur;
        cout << "♦ Ingrese la cantidad de jugadores: " << endl;
        cin >> jug;
        icIniciarPartida->datoMultijugador(cont, dur, jug);
    }
    break;
    case 0:
    {
        cout << "♦ La partida es una continuacion de alguna anterior?" << endl;
        cout << "♦ Ingrese 1 en el caso de serlo: " << endl;
        cin >> cond2;
        if (cond2 == 1)
        {
            cont = true;
        }
        cout << "♦ Ingrese la duracion: " << endl;
        cin >> dur;
        icIniciarPartida->datoIndividual(cont, dur);
    }
    break;
    }
    cout << "♦ Desea confirmar y poder empezar con su partida?" << endl;
    cout << "♦ 1/0" << endl;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icIniciarPartida->altaPartida();
        cout << "♦ Se creo correctamente la partida." << endl;
    }
    break;
    case 0:
    {
        icIniciarPartida->cancelar();
        cout << "♦ Se cancelo con exito la creacion de la partida." << endl;
    }
    break;
    }
}

/*---------------------------------------------------*
 *            Menu Suscribirse a Videojuego           *
 *----------------------------------------------------*/

void menuSuscribirseAVideojuego()
{
    system("clear");
    cout << "╔════════════════════════════════════════════╗\n";
    cout << COLOR_SB << "║           ♦ 🎯 Suscribirse ♦          ║" << COLOR_RESET << endl;
    cout << "╚════════════════════════════════════════════╝\n";
    /*se lista el nombre y costo por tipo
    de suscripción de cada videojuego del sistema, mostrando en listas
    separadas aquellos para los cuales el jugador tiene actualmente una
    suscripción activa y por otro lado el resto*/
    DtFechaHora *fh = new DtFechaHora(10, 6, 2022, 20, 51);
    string nombre;
    TipoPago tipoPago;
    int tipo = 0, x = 0, costo = 50, cond;
    cout << "♦ Nombre del VideoJuego: ";
    cin >> nombre;
    // Si el jugador ya tiene una sub para ese juego
    cout << "⛔ Ya tiene una suscripcion activa para este juego";
    // si no tiene una sub:
    cout << "Ingrese 1 para pagar con Debito o 2 para Credito: ";
    cin >> tipo;
    if (tipoPago == 1)
    {
        tipoPago = DEBITO;
    }
    else if (tipoPago == 2)
    {
        tipoPago = CREDITO;
    }
    cout << "♦ Desea confirmar la suscripcion? " << endl;
    cout << "♦ 1/0" << endl;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        // icSuscribirseaVideojuego->Suscripcion(tipoPago,costo,fh,Usuario);
        cout << "♦ Se suscribió videojuego." << endl;
    }
    break;
    case 0:
    {
        // icSuscribirseaVideojuego->cancelar();
    }
    break;
    }
}

/*---------------------------------------------------*
 *            Menu Ver Info de Videojuego             *
 *----------------------------------------------------*/

void menuVerInfoVideojuego()
{
    system("clear");
}

/*---------------------------------------------------*
 *               Menu Eliminar Videojuego             *
 *----------------------------------------------------*/

void menuEliminarVideojuego()
{
    system("clear");
}

/*------------------------------------------*
 *                 Exit Screen               *
 *-------------------------------------------*/

void exit()
{
    system("clear");
    progress = 1;
    cout << longSpace << longTab << COLOR_P << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│  ❌ Cerrando Sesión, Por Favor Espere...   │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│" << COLOR_R << "   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  " << COLOR_P << "│\n";
    cout << longTab << "│" << COLOR_R << "   ░░█▀▀░▄▀█░█▀▄▀█░█▀▀░░░█▀█░█░█░█▀▀░█▀█░░  " << COLOR_P << "│\n";
    cout << longTab << "│" << COLOR_R << "   ░░█▄█░█▀█░█░▀░█░██▄░░░█▄█░▀▄▀░██▄░█▀▄░░  " << COLOR_P << "│\n";
    cout << longTab << "│" << COLOR_R << "   ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░  " << COLOR_P << "│\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    closeBar(progress);
}

/********** Barra de Estado **********/

void statusBar()
{
    cout << longSpace << longTab << BG_GRAY << "                                       ➖ 🔲 ❌ " << COLOR_RESET << endl;
    time_t now = time(0);          // current date and time on the current system
    char *date_time = ctime(&now); // convert now to string form
    cout << longTab << BG_BLACK << COLOR_LG << "⦿ Online                " << date_time << COLOR_RESET;
    cout << longTab << COLOR_G << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░░█▀▀░▄▀█░█▀▄▀█░█▀▀░█░░░▄▀█░█▄ █░█▀▄░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░░█▄█░█▀█░█░▀░█░██▄░█▄▄░█▀█░█░▀█░█▄▀░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_P << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
}

/********** Menu Principal (Consola) **********/

void menuPlayer()
{
    system("clear");
    statusBar();
    cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "║                   [Player]                   ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     CD) 🎲 Cargar Datos de Prueba            ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     AU) 🔴 Agregar Usuario                   ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     IS) 🔴 Iniciar Sesion                    ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     CS) 🔴 Cerrar Sesion                     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     SV) 🔴 Suscribirse a videojuego          ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     IP) 🔴 Iniciar Partida                   ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     IV) 🔴 Ver información de videojuego     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     AP) 🟡 Asignar puntaje a videojuego      ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     CS) 🟡 Cancelar suscripción a videojuego ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     VC) 🟡 Buscar videojuego por categoría   ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     RV) 🟡 Ranking de videojuegos            ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     VP) 🟡 Ver partidas de un videojuego     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║      S) 🚪 Salir                             ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
}

void menuDev()
{
    system("clear");
    statusBar();
    cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "║                  [Developer]                 ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     1) 🎲 Cargar Datos de Prueba            ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     2) 🔴 Agregar Usuario                   ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     3) 🔴 Iniciar Sesion                    ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     4) 🔴 Cerrar Sesion                     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     5) 🔴 Agregar Categoría                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     6) 🔴 Agregar Videojuego                ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     7) 🔴 Ver información de videojuego     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     8) 🔴 Eliminar videojuego               ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     9) 🟡 Buscar videojuego por categoría   ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     10) 🟡 Ranking de videojuegos            ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║     11) 🟡 Ver partidas de un videojuego     ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║      0) 🚪 Salir                             ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
}

/********** Logica del Menu Principal **********/

int main()
{
    cargarFabrica();
    /*welcomeBanner();
    menuDisplay();*/
    menuIniciarSesion();
    int opcion;
    do
    {
        if (icIniciarSesion->usuarioConectado())
        {
            menuDev();
        }
        else
        {
            menuPlayer();
        }
        
        cin >> opcion;
        bool data = true;
        switch (opcion)
        {
        case 1:
            if (data)
            {
                menuCargarDatos();
                data = false;
            }
            else
            {
                cout << "\n"
                     << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                cout << longTab << "│   🔔 Ya Has Cargado los Datos de Prueba!   │" << endl;
                cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2");
            }
            break;
        case 2:
            menuAltaUsuario();
            break;
        case 3:
            menuIniciarSesion();
            break;
        case 4:
            menuCerrarSesion();
            break;
        case 5:
            menuAgregarCategoria();
            break;
        case 6:
            menuAgregarVideojuego();
            break;
        case 7:
            menuSuscribirseAVideojuego();
            break;
        case 8:
            menuIniciarPartida();
            break;
        case 9:
            // menuVerInformacionDeVideojuego();
            break;
        case 10:
            // menuEliminarVideojuego();
            break;
        case 11:
            // menuAsignarPuntajeAVideojuego();
            break;
        case 12:
            // menuCancelarSuscripcionAVideojuego();
            break;
        case 13:
            // menuBuscarVideojuegoPorCategoria();
            break;
        case 14:
            // menuRankingDeVideojuegos();
            break;
        case 15:
            // menuVerPartidaDeUnVideojuego();
            break;
        }
    }while(opcion != 0);
    exit();
}
