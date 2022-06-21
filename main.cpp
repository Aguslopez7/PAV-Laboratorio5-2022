#include <ctime>
#include <iostream>
#include <string>
#include <list>

#include "Fabrica.h"
#include "Definiciones.h"
#include "DtFechaHora.h"
#include "DtCategoria.h"
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

Fabrica *fabrica;
ICAgregarCategoria *icAgregarCategoria;
ICIniciarSesion *icIniciarSesion;
ICCerrarSesion *icCerrarSesion;
ICInfoJuego *icInfoJuego;
ICAltaUsuario *icAltaUsuario;
ICIniciarPartida *icIniciarPartida;
ICAgregarVideojuego *icAgregarVideojuego;
ICSuscribirseaVideojuego *icSuscribirseaVideojuego;

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
        system("sleep 1");
        cout << COLOR_BW << "] " << int(progress * 100.0) << " %\r" << COLOR_RESET;
        cout.flush();
        progress += 1;
    }
    system("sleep 3");
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
        system("sleep 1");
        cout << COLOR_BW << "] " << int(progressBar * 100.0) << " %\r" << COLOR_RESET;
        cout.flush();
        progressBar += progress;
    }
    system("sleep 1");
    cout << endl;
    system("clear");
}

void DoneMessage()
{
    system("clear");
    progress = 0.25;
    cout << longSpace << longTab << COLOR_G << "┌──────────────────────────────────────────────┐" << endl;
    cout << longTab << "│     ✅ Operacion Realizada Correctamente!    │" << endl;
    cout << longTab << "├──────────────────────────────────────────────┤" << endl;
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                        ▄▄                    │\n";
    cout << longTab << "│                       █░█                    │\n";
    cout << longTab << "│                      ▄▀░█                    │\n";
    cout << longTab << "│               ████▄▄▄▀░░▀▀▀▀▄                │\n";
    cout << longTab << "│               ████░░░░░░░░░░█                │\n";
    cout << longTab << "│               ████░░░░░░░░░░█                │\n";
    cout << longTab << "│               ████▄▄▄░░░░░░░█                │\n";
    cout << longTab << "│               ▀▀▀▀   ▀▀▀▀▀▀▀                 │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "│                                              │\n";
    cout << longTab << "└──────────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2");
}

void ErrorMessage()
{
    system("clear");
    cout << longTab << COLOR_R << "┌───────────────────────────────────────────────┐" << endl;
    cout << longTab << COLOR_R << "│          ❌ Se ha detectado un Error          │" << endl;
    cout << longTab << COLOR_R << "└───────────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2");
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
                    system("sleep 1");
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
                    system("sleep 1");
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

void logInScreen()
{
    system("clear");
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
    icAltaUsuario = fabrica->getICAltaUsuario();
    system("clear");
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 👤 Agregar Usuario ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
    string email;
    string pass;
    string nomEmp="";
    int num, num2;
    cout << longTab << "♦ Ingrese su Email: ";
    cin >> email;
    if (!(icAltaUsuario->checkUser(email)))
    {
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
            cout << longTab << "♦ Ingrese el nombre de la empresa: ";
            cin >> nomEmp;
            icAltaUsuario->datosEmpresa(nomEmp);
            try
            {
                icAltaUsuario->altaUsuario();
                DoneMessage();
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
            bool x;
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
                    cond = false;
                    DoneMessage();
                }
                catch (invalid_argument &e)
                {
                    cout << "\n"
                         << longTab << COLOR_Y << "┌─────────────────────────────────────────┐" << endl;
                    cout << longTab << e.what() << endl;
                    cout << longTab << "└─────────────────────────────────────────┘" << COLOR_RESET << endl;
                    system("sleep 2");
                    cout << longTab << "┌────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│   ¿Deseas volver a ingresar el nickname?   │" << endl;
                    cout << longTab << "├────────────────────────────────────────────┤\n";
                    cout << longTab << "│                                            │\n";
                    cout << longTab << "│                1. Reintentar               │\n";
                    cout << longTab << "│                                            │\n";
                    cout << longTab << "│                2. Cancelar                 │\n";
                    cout << longTab << "│                                            │\n"; //✅✅🔁❌
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
    else
    {
        cout << "\n"
             << "♦ Ese email ya existe." << endl;
        system("sleep 2");
        menuAltaUsuario();
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
    cout << longTab << "║               1. Iniciar Sesion              ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               2. Registrarse                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        if (icAltaUsuario->hayUsuarios())
        {
            system("clear");
            bool cond2 = true;
            cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
            cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
            cout << longTab << "╚════════════════════════════════════════════╝\n";
            string email, pass;
            cout << longTab << "♦ Ingrese su Email: ";
            cin >> email;
            cout << longTab << "♦ Ingrese su Password: ";
            cin >> pass;
            do
            {
                if (icIniciarSesion->ingresarDatos(email, pass))
                {
                    logInScreen();
                    cond2 = false;
                }
                else
                {
                    system("clear");
                    cout << longSpace << COLOR_R << "[ERROR] Usuario No Encontrado, Por Favor Ingrese Nuevamente" << COLOR_RESET << "\n"
                         << endl;
                    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
                    cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
                    cout << longTab << "╚════════════════════════════════════════════╝\n";
                    cout << longTab << "♦ Ingrese su Email: ";
                    cin >> email;
                    cout << longTab << "♦ Ingrese su Password: ";
                    cin >> pass;
                }
            } while (cond2);
        }
        else
        {
            system("clear");
            cout << COLOR_R << "[ERROR] No se puede inciar sesion ya que no hay usuarios registrados en el sistema" << COLOR_RESET << endl;
            system("sleep 3");
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

bool menuCerrarSesion()
{
    system("clear");
    bool retorno = false;
    cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║             ♦ 👤 Cerrar Sesion ♦             ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║                  1. Confirmar                ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║                  0. Cancelar                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    int cond;
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icCerrarSesion->cerrarSesion();
        retorno = true;
        DoneMessage();
        return retorno;
    }
    break;
    }
    return retorno;
}

/*-------------------------------------------------------*
 *               Menu Agregar Categoria                   *
 *--------------------------------------------------------*/

void menuAgregarCategoria()
{
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Agregar Categoria ♦          ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    int cond;
    string genero, plataforma, desc;
    if (icAgregarCategoria->hayCategorias())
    {
        cout << "♦ Estas son las categorias existentes: " << "\n" << endl;
        list<DtCategoria *> lista = icAgregarCategoria->listarDtCategorias();
        for (list<DtCategoria *>::iterator it = lista.begin(); it != lista.end(); ++it)
        {
            cout << "♦ " << "[id: " << (*it)->getId() << "] " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
        }
    }
    cout << "♦ Ingrese los nuevos datos de la categoria que desea agregar ♦ " << "\n" << endl;
    cout << "♦ Ingrese una breve descripcion: "; 
    cin >> desc;
    cout << "♦ Ingrese su genero: ";
    cin >> genero;
    cout << "♦ Ingrese la plataforma: ";
    cin >> plataforma;
    icAgregarCategoria->solictarDatos(desc, genero, plataforma);
    cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
    cout << longTab << "│               Confirmar Categoria             │" << endl;
    cout << longTab << "├───────────────────────────────────────────────┤\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "│                   1. Aceptar                  │\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "│                   0. Cancelar                 │\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "└───────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icAgregarCategoria->confirmarCategoria();
        DoneMessage();
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
    icAgregarVideojuego = fabrica->getICAgregarVideojuego();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Agregar Videojuego ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    int costo = 0, cond, x = 2, id = 0;
    string nombre, desc;
    cout << "♦ Ingrese el nombre del videojuego: ";
    cin >> nombre;
    cout << "♦ Ingrese la descripcion del videojuego: ";
    cin >> desc;
    cout << "♦ Ingrese el costo de la suscripcion: ";
    cin >> costo;
    cout << "♦ Categorias ♦ "
         << "\n"
         << endl;
    list<DtCategoria*> listaDt = icAgregarCategoria->listarDtCategorias();
    for (list<DtCategoria*>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
    {
        cout << "♦ "
             << "[id: " << (*it)->getId() << "] " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
    }
    DtCategoria *nuevoDtCat;
    while (x != 0)
    {
        cout << "\n"
             << "♦ Ingrese el id de la categoria: ";
        cin >> id;
        nuevoDtCat = icAgregarCategoria->buscarCat(id);
        icAgregarVideojuego->agregarCategoria(nuevoDtCat);
        cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
        cout << longTab << "│   ¿Deseas volver a ingresar otra Categoria?   │" << endl;
        cout << longTab << "├───────────────────────────────────────────────┤\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   1. Aceptar                  │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   0. Cancelar                 │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "└───────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> x;
    }
    cout << "\n" << "♦ Nombre: " << nombre << endl;
    cout << "♦ Descripcion: " << desc << endl;
    cout << "♦ Costo: " << costo << endl;
    cout << "♦ Email: " << icIniciarSesion->getEmail() << "\n" << endl;
    cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
    cout << longTab << "│        Agregar Videojuego a la Biblioteca     │" << endl;
    cout << longTab << "├───────────────────────────────────────────────┤\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "│                   1. Aceptar                  │\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "│                   0. Cancelar                 │\n";
    cout << longTab << "│                                               │\n";
    cout << longTab << "└───────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond)
    {
    case 1:
    {
        icAgregarVideojuego->solicitarInfo(nombre, desc, costo);
        icAgregarVideojuego->confirmarJuego();
        DoneMessage();
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
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Iniciar Partida ♦            ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    int cond;
    string nom;
    bool cont = false;
    int cond2, dur, jug;
    if (icInfoJuego->hayJuegos())
    {
        list<DtJuego*> listaActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        for(list<DtJuego*>::iterator it = listaActiva.begin(); it != listaActiva.end(); ++it){
            (*it)->imprimirSuscripto();
        }
        cout << "\n" << "♦ Ingrese el nombre del juego que desea jugar: " << endl;
        cin >> nom;
        icIniciarPartida->seleccionarVideojuego(nom);
        cout << longTab << "┌──────────────────────────────────────────────┐" << endl;
        cout << longTab << "│         Selecciona Tipo de Partida           │" << endl;
        cout << longTab << "├──────────────────────────────────────────────┤\n";
        cout << longTab << "│                                              │\n";
        cout << longTab << "│                                              │\n";
        cout << longTab << "│          1. 👤 Partida Individual            │\n";
        cout << longTab << "│                                              │\n";
        cout << longTab << "│          2. 👥 Partida Multijugador          │\n";
        cout << longTab << "│                                              │\n";
        cout << longTab << "│                                              │\n";
        cout << longTab << "└──────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> cond;
        switch (cond)
        {
        case 2:
        {
            cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
            cout << longTab << "│            Desea Transmitir en Vivo?          │" << endl;
            cout << longTab << "├───────────────────────────────────────────────┤\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "│                   1. Aceptar                  │\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "│                   0. Cancelar                 │\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "└───────────────────────────────────────────────┘" << endl;
            cout << longTab << "❯ Opción: ";
            cin >> cond2;
            if (cond2 == 1)
            {
                cont = true;
            }
            cout << "♦ Ingrese la duracion de la partida: " << endl;
            cin >> dur;
            cout << "♦ Ingrese la cantidad de jugadores: " << endl;
            cin >> jug;
            icIniciarPartida->datoMultijugador(cont, dur, jug, cond);
        }
        break;
        case 1:
        {
            cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
            cout << longTab << "│           Desea Continuar la Partida?         │" << endl;
            cout << longTab << "├───────────────────────────────────────────────┤\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "│                   1. Aceptar                  │\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "│                   0. Cancelar                 │\n";
            cout << longTab << "│                                               │\n";
            cout << longTab << "└───────────────────────────────────────────────┘" << endl;
            cout << longTab << "❯ Opción: ";
            cin >> cond2;
            if (cond2 == 1)
            {
                cont = true;
            }
            cout << "♦ Ingrese la duracion de la partida: " << endl;
            cin >> dur;
            icIniciarPartida->datoIndividual(cont, dur, cond);
        }
        break;
        }
        cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
        cout << longTab << "│             Desea Iniciar Partida?            │" << endl;
        cout << longTab << "├───────────────────────────────────────────────┤\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   1. Aceptar                  │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   0. Cancelar                 │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "└───────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> cond;
        switch (cond)
        {
        case 1:
        {
            icIniciarPartida->altaPartida(); // hacer esto
            DoneMessage();
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
    else
    {
        cout << "\n"
             << "♦ No existen videojuegos en el sistema." << endl;
        system("sleep 2");
    }
}

/*---------------------------------------------------*
 *            Menu Suscribirse a Videojuego           *
 *----------------------------------------------------*/

void menuSuscribirseAVideojuego()
{
    system("clear");
    cout << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║        ♦ Suscribirse a Videojuego ♦        ║" << COLOR_RESET << endl;
    cout << "╚════════════════════════════════════════════╝\n";
    if (icInfoJuego->hayJuegos())
    {
        cout << "♦ Juegos con Suscripcion Activa ♦" << "\n" << endl;
        list<DtJuego*> listaDtActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        for(list<DtJuego*>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it){
            (*it)->imprimirSuscripto();
        }
        cout << "♦ Juegos sin Suscripcion Activa ♦" << "\n" << endl;
        list<DtJuego*> listaDt = icSuscribirseaVideojuego->listarLosJuegosSinSub();
        for(list<DtJuego*>::iterator it = listaDt.begin(); it != listaDt.end(); ++it){
            (*it)->imprimirSuscripto();
        }
        string nombre;
        TipoPago tipoPago;
        cout << "\n" << "♦ Nombre del videoJuego al cual quiere suscribirse: ";
        cin >> nombre;
        if(icSuscribirseaVideojuego->ingresarNombre(nombre)){
            if(!(icSuscribirseaVideojuego->tieneSuscripcion())){
                int tipo, cond;
                cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
                cout << longTab << "│           Seleccione el Tipo de Pago          │" << endl;
                cout << longTab << "├───────────────────────────────────────────────┤\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "│                   1. Debito                   │\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "│                   0. Credito                  │\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "└───────────────────────────────────────────────┘" << endl;
                cout << longTab << "❯ Opción: ";
                cin >> tipo;
                if (tipo == 1)
                {
                    tipoPago = DEBITO;
                }
                else if (tipo == 2)
                {
                    tipoPago = CREDITO;
                }
                cout << "\n";
                cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
                cout << longTab << "│        Desea Suscribirse al Videojuego?       │" << endl;
                cout << longTab << "├───────────────────────────────────────────────┤\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "│                   1. Aceptar                  │\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "│                   0. Cancelar                 │\n";
                cout << longTab << "│                                               │\n";
                cout << longTab << "└───────────────────────────────────────────────┘" << endl;
                cout << longTab << "❯ Opción: ";
                cin >> cond;
                switch (cond)
                {
                case 1:
                {
                    icSuscribirseaVideojuego->SuscribirseAVideojuego(tipoPago);
                    DoneMessage();
                }
                break;
                case 0:
                {
                    icSuscribirseaVideojuego->cancelar();
                }
                break;
                }
            }else{
                cout << "\n"
                     << "⛔ Ya tiene una suscripcion activa para este juego."<<endl;
                system("sleep 2");
            }
        }else{
            cout << "\n"
                << "♦ No existe ese videojuego." << endl;
            system("sleep 2");
        }
    }
    else
    {
        cout << "\n"
             << "♦ No existen videojuegos en el sistema." << endl;
        system("sleep 2");
    }
}

/*---------------------------------------------------*
 *            Menu Ver Info de Videojuego             *
 *----------------------------------------------------*/

void menuVerInfoVideojuego()
{
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║   ♦ Ver Informacion de un Videojuego ♦   ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string name;
    if (icInfoJuego->hayJuegos())
    {
        cout << "♦ Juegos ingresados en el sistema ♦ " << "\n"
             << endl;
        list<string> list = icInfoJuego->listarJuegos();
        for (std::list<string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            cout << "> " << *it << endl;
        }
        cout << "\n" << "♦ Ingrese el nombre del cual desee informacion: ";
        cin >> name;
        DtJuego* juego = icInfoJuego->selectJuego(name);
        juego->imprimirVerInfo();     
        system("sleep 4");
    }
    else
    {
        cout << "\n" << "♦ No existen videojuegos en el sistema." << endl;
        system("sleep 2");
    }
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

bool menuPlayer()
{
    system("clear");
    int opcion;
    bool entro = false, aux;
    do
    {
        statusBar();
        cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
        cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
        cout << longTab << COLOR_SB << "║                   [Player]                   ║" << COLOR_RESET << endl;
        cout << longTab << "╠══════════════════════════════════════════════╣\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     1) 🎲 Cargar Datos de Prueba             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     2) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Suscribirse a videojuego           ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Iniciar Partida                    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🔴 Ver información de videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🟡 Asignar puntaje a videojuego       ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Cancelar suscripción a videojuego  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     8) 🟡 Buscar videojuego por categoría    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     9) 🟡 Ranking de videojuegos             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║    10) 🟡 Ver partidas de un videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     0) 🚪 Salir                              ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
        cout << longTab << "❯ Opción: ";
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
                cout << "\n" << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                cout << longTab << "│   🔔 Ya Has Cargado los Datos de Prueba!   │" << endl;
                cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2");
            }
            break;
        case 2:
            aux = menuCerrarSesion();
            if (aux)
            {
                entro = true;
                return entro;
            }
            break;
        case 3:
            menuSuscribirseAVideojuego();
            break;
        case 4:
            menuIniciarPartida();
            break;
        case 5:
            menuVerInfoVideojuego();
            break;
        case 6:
            // menuAsignarPuntajeAVideojuego();
            break;
        case 7:
            // menuCancelarSuscripcionAVideojuego();
            break;
        case 8:
            // menuBuscarVideojuegoPorCategoria();
            break;
        case 9:
            // menuRankingDeVideojuegos();
            break;
        case 10:
            // menuVerPartidaDeUnVideojuego();
            break;
        }
    } while (opcion != 0);
    return entro;
}

bool menuDev()
{
    system("clear");
    int opcion;
    bool entro = false, aux;
    do
    {
        statusBar();
        cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
        cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
        cout << longTab << COLOR_SB << "║                  [Developer]                 ║" << COLOR_RESET << endl;
        cout << longTab << "╠══════════════════════════════════════════════╣\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     1) 🎲 Cargar Datos de Prueba             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     2) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Agregar Categoría                  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Agregar Videojuego                 ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🔴 Ver información de videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🔴 Eliminar videojuego                ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Buscar videojuego por categoría    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     8) 🟡 Ranking de videojuegos             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     9) 🟡 Ver partidas de un videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     0) 🚪 Salir                              ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
        cout << longTab << "❯ Opción: ";
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
            aux = menuCerrarSesion();
            if (aux)
            {
                entro = true;
                return entro;
            }
            break;
        case 3:
            menuAgregarCategoria();
            break;
        case 4:
            menuAgregarVideojuego();
            break;
        case 5:
            menuVerInfoVideojuego();
            break;
        case 6:
            // menuEliminarVideojuego();
            break;
        case 7:
            // menuBuscarVideojuegoPorCategoria();
            break;
        case 8:
            // menuRankingDeVideojuegos();
            break;
        case 9:
            // menuVerPartidaDeUnVideojuego();
            break;
        }
    } while (opcion != 0);
    return entro;
}

/********** Logica del Menu Principal **********/

int main()
{
    cargarFabrica();
    /*welcomeBanner();
    menuDisplay();*/
    bool x;
    do
    {
        do
        {
            menuIniciarSesion();
        } while ((icIniciarSesion->signUp() == false) || (icAltaUsuario->hayUsuarios() == false));

        if (icIniciarSesion->usuarioConectado())
        {
            x = menuDev();
        }
        else
        {
            x = menuPlayer();
        }
    } while (x == true);

    exit();
}
