#include <ctime>
#include <iostream>
<<<<<<< HEAD
#include <list>
#include <string>
=======
#include <string>
#include <list>
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca

#include "Categoria.h"
#include "Definiciones.h"
#include "DtCategoria.h"
#include "DtFechaHora.h"
#include "DtPartida.h"
#include "DtPartidaIndi.h"
#include "DtPartidaMulti.h"
<<<<<<< HEAD
#include "Estadistica.h"
#include "Fabrica.h"
#include "Juego.h"
#include "Jugador.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
=======
#include "DtCategoria.h"
#include "Categoria.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Juego.h"
#include "Jugador.h"
#include "TipoPago.h"
#include "Estadistica.h"
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
#include "Sesion.h"
#include "TipoPago.h"

using namespace std;

string longTab = "";
string longSpace = "";
string msg;      // mensaje - menuCargarPartida
float progress;  // tiempo de carga - closeBar

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
ICEliminarVideojuego *icEliminarVideojuego;
ICAsignarPuntaje *icAsignarPuntaje;
ICCancelarSuscripcion *icCancelarSuscripcion;
ICBuscarPorCategoria *icBuscarPorCategoria;
ICRankingVideojuego *icRankingVideojuego;
ICVerPartidas *icVerPartidas;

/********** Instanciar Fabrica con las Interfaces **********/

void cargarFabrica() {
    fabrica = Fabrica::getInstancia();
    icAgregarCategoria = fabrica->getICAgregarCategoria();
    icIniciarSesion = fabrica->getICIniciarSesion();
    icCerrarSesion = fabrica->getICCerrarSesion();
    icInfoJuego = fabrica->getICInfoJuego();
    icAltaUsuario = fabrica->getICAltaUsuario();
    icIniciarPartida = fabrica->getICIniciarPartida();
    icAgregarVideojuego = fabrica->getICAgregarVideojuego();
    icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
    icEliminarVideojuego = fabrica->getICEliminarVideojuego();
    icAsignarPuntaje = fabrica->getICAsignarPuntaje();
    icCancelarSuscripcion = fabrica->getICCancelarSuscripcion();
    icBuscarPorCategoria = fabrica->getICBuscarPorCategoria();
    icRankingVideojuego = fabrica->getICRankingVideojuego();
    icVerPartidas = fabrica->getICVerPartidas();
}

/********** Barra de Carga - Principal **********/

void loadBar() {
    float progress = 0.0;
    cout << endl;
    while (progress < 1.1) {
        int barWidth = 68;
        cout << longTab << COLOR_BW << "  LOADING... [" << COLOR_RESET;
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
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

<<<<<<< HEAD
void closeBar(float progress) {
=======
void closeBar(float progress)
{

>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    float progressBar = 0;
    cout << "\n"
         << longTab << COLOR_BW << "\t\t   LOADING..." << COLOR_RESET << endl;
    cout << endl;
    while (progressBar < 1.1) {
        int barWidth = 5;
        cout << longTab << "\t  " << COLOR_BW << "       [ " << COLOR_RESET;
        int pos = barWidth * progressBar;
        for (int i = 0; i < barWidth; ++i) {
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

/********** Welcome Banner **********/

void welcomeBanner() {
    system("clear");
    longTab = "\t\t\t\t\t\t\t\t";
    longSpace = "\n\n\n\n\n\n\n";
    cout << longSpace << longTab << "╔═════════════════════════════════════════════════════════════════════════════════════╗" << endl;
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
    longTab = "\t\t\t\t\t\t\t\t\t\t";
    longSpace = "\n\n\n\n\n\n\n\n\n\n";
}

/********** Menu Custom Display **********/

void menuCustomDisplay() {
    system("clear");
    /*longTab="";
    longSpace="";*/
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

void menuDisplay() {
    system("clear");
<<<<<<< HEAD
    longTab = "\t\t\t\t\t\t\t\t\t\t\t\t";
=======
    longTab = "\t\t\t\t\t\t\t\t\t\t\t";
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longSpace << longTab << "╔═══════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║  ♦ Select Display Mode ♦  ║" << COLOR_RESET << endl;
    cout << longTab << "╠═══════════════════════════╣" << endl;
    cout << longTab << "║         1. Default        ║" << endl;
    cout << longTab << "║         2. Center         ║" << endl;
    cout << longTab << "║         3. Custom         ║" << endl;
    cout << longTab << "╚═══════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    string addTab("\t");
    string addSpace("\n");
    int type;
    cin >> type;
<<<<<<< HEAD
    switch (type) {
        case 1:
            longTab = "";
            longSpace = "";
            break;
        case 2:
            longTab = "\t\t\t\t\t\t\t\t\t\t\t";
            longSpace = "\n\n\n\n";
            break;
        case 3: {
=======
    switch (type)
    {
    case 1:
        longTab = "";
        longSpace = "";
        break;
    case 2:
        longTab = "\t\t\t\t\t\t\t\t\t\t";
        longSpace = "\n\n\n\n";
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
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            system("clear");
            menuCustomDisplay();
            int op;
            cin >> op;
            string addTab("\t");
            string addSpace("\n");
            while (op != 5) {
                switch (op) {
                    case 1:
                        if (longSpace.length() <= 0) {
                            cout << "\n"
                                 << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                            cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                            cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                            system("sleep 1");
                        } else if (longSpace.length() == 1) {
                            longSpace = "";
                        } else {
                            longSpace.erase(longSpace.length() - 2);  // removes last 2 characters
                        }
                    break;
                    case 2:
                        if (longSpace.length() == 22) {
                            cout << "\n"
                                 << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                            cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                            cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                            system("sleep 1");
                        } else {
                            longSpace.append(addSpace);
                        }
                    break;
                    case 3:
                        if (longTab.length() <= 0) {
                            cout << "\n"
                                 << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                            cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                            cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                            system("sleep 1");
                        } else if (longTab.length() == 1) {
                            longTab = "";
                        } else {
                            longTab.erase(longTab.length() - 2);  // removes last 2 characters
                        }
                    break;
                    case 4:
                        if (longTab.length() >= 22) {
                            cout << "\n"
                                 << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                            cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                            cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                            system("sleep 1");
                        } else {
                            longTab.append(addTab);
                        }
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

<<<<<<< HEAD
void logInScreen() {
=======
void logInScreen()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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

<<<<<<< HEAD
void DoneMessage() {
=======
void DoneMessage()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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
    system("sleep 2.5");
<<<<<<< HEAD
    system("clear");
}

// No Existen Viedeojuegos
void WarningMessage() {
=======
}

// No Existen Viedeojuegos
void WarningMessage()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << "\n"
         << longTab << COLOR_Y << "┌──────────────────────────────────────────┐" << endl;
    cout << longTab << "│  🔔 No Existen Videojuegos en el Sitema  │" << endl;
    cout << longTab << "└──────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2.5");
}

<<<<<<< HEAD
void menuCargarPartida() {
=======
void menuCargarPartida()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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
    closeBar(progress);
    cout << longSpace << longTab << COLOR_G << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│     ✅ Partida Iniciada Correctamente!     │" << endl;
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
    system("sleep 2.5");
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

<<<<<<< HEAD
bool menuCargarDatos() {
=======
bool menuCargarDatos()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    system("clear");
    int valor;
    bool retorno = false;
    cout << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│      Desea cargar los datos de prueba?     │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                 1. Aceptar                 │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│                 2. Cancelar                │\n";
<<<<<<< HEAD
    cout << longTab << "│                                            │\n";  //✅✅🔁
=======
    cout << longTab << "│                                            │\n"; //✅✅🔁
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> valor;
<<<<<<< HEAD
    if (valor == 1) {
        //ingresamos un desarrollador #1
        icAltaUsuario = fabrica->getICAltaUsuario();
        icAltaUsuario->datosComunes("dev", "dev");
        icAltaUsuario->datosEmpresa("oca");
        icAltaUsuario->altaUsuario();

        //ingresamos un desarrollador #2
        icAltaUsuario = fabrica->getICAltaUsuario();
        icAltaUsuario->datosComunes("dev2", "dev2");
        icAltaUsuario->datosEmpresa("nimble");
        icAltaUsuario->altaUsuario();

        //ingresamos un jugador #1
        icAltaUsuario = fabrica->getICAltaUsuario();
        icAltaUsuario->datosComunes("jug", "jug");
        icAltaUsuario->datosJugador("jugador1", "DescJugador1");
        icAltaUsuario->altaUsuario();
 
        //ingresamos un jugador #2
        icAltaUsuario = fabrica->getICAltaUsuario();
        icAltaUsuario->datosComunes("jug2", "jug2");
        icAltaUsuario->datosJugador("jugador2", "DescJugador2");
        icAltaUsuario->altaUsuario();

        //iniciamos sesion con desarrollador #1
        icIniciarSesion = fabrica->getICIniciarSesion();
        icIniciarSesion->ingresarDatos("dev", "dev");

        //agregamos categoria #1 nueva con desarrollador #1
        icAgregarCategoria = fabrica->getICAgregarCategoria();
        icAgregarCategoria->solictarDatos("DescCategoria1", "Accion", "PS5");
        icAgregarCategoria->confirmarCategoria();

        //agregamos categoria #2 nueva con desarrollador #1
        icAgregarCategoria = fabrica->getICAgregarCategoria();
        icAgregarCategoria->solictarDatos("DescCategoria2", "Moba", "PC");
        icAgregarCategoria->confirmarCategoria();

        //agregamos juego #1 nuevo con desarrollador #1
        icAgregarVideojuego = fabrica->getICAgregarVideojuego();
        Categoria* cat = icAgregarCategoria->buscarCat(1);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("gta", "DescJuego1", 456);
        icAgregarVideojuego->confirmarJuego();

        //agregamos juego #2 nuevo con desarrollador #1
        icAgregarVideojuego = fabrica->getICAgregarVideojuego();
        cat = icAgregarCategoria->buscarCat(2);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("lol", "DescJuego2", 4567);
        icAgregarVideojuego->confirmarJuego();

        //cerramos sesion de desarrollador #1
        icCerrarSesion = fabrica->getICCerrarSesion();
        icCerrarSesion->cerrarSesion();

        //iniciamos sesion con desarrollador #2
        icIniciarSesion = fabrica->getICIniciarSesion();
        icIniciarSesion->ingresarDatos("dev2", "dev2");

        //agregamos categoria #3 nueva con desarrollador #2
        icAgregarCategoria = fabrica->getICAgregarCategoria();
        icAgregarCategoria->solictarDatos("DescCategoria3", "Deporte", "XBOX");
        icAgregarCategoria->confirmarCategoria();

        //agregamos juego #3 nuevo con desarrollador #2
        icAgregarVideojuego = fabrica->getICAgregarVideojuego();
        cat = icAgregarCategoria->buscarCat(3);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("fifa", "DescJuego3", 2000);
        icAgregarVideojuego->confirmarJuego();

        //agregamos juego #4 nuevo con desarrollador #2
        icAgregarVideojuego = fabrica->getICAgregarVideojuego();
        cat = icAgregarCategoria->buscarCat(1);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("cod", "DescJuego4", 47);
        icAgregarVideojuego->confirmarJuego();

        //cerramos sesion de desarrollador #2
        icCerrarSesion = fabrica->getICCerrarSesion();
        icCerrarSesion->cerrarSesion();

        //iniciamos sesion con jugador #1
        icIniciarSesion = fabrica->getICIniciarSesion();
        icIniciarSesion->ingresarDatos("jug", "jug");

        //suscribirse a el juego #1 con jugador #1
        icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
        icSuscribirseaVideojuego->ingresarNombre("gta");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(DEBITO);

        //suscribirse a el juego #2 con jugador #1
        icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
        icSuscribirseaVideojuego->ingresarNombre("lol");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(CREDITO);

        //iniciamos partida indi #1 con jugador #1 al juego #1
        icIniciarPartida = fabrica->getICIniciarPartida();
        icIniciarPartida->seleccionarVideojuego("gta");
        icIniciarPartida->datoIndividual(true, 5, 1);
        icIniciarPartida->altaPartida();

        //iniciamos partida multi #1 con jugador #1 al juego #2
        icIniciarPartida = fabrica->getICIniciarPartida();
        icIniciarPartida->seleccionarVideojuego("lol");
        icIniciarPartida->datoMultijugador(false, 4, 5, 2);
        icIniciarPartida->altaPartida();

        //agregamos puntaje a juego #1 con jugador #1
        icAsignarPuntaje = fabrica->getICAsignarPuntaje();
        icAsignarPuntaje->asignarPuntaje("gta", 4);

        //agregamos puntaje a juego #2 con jugador #1
        icAsignarPuntaje = fabrica->getICAsignarPuntaje();
        icAsignarPuntaje->asignarPuntaje("lol", 2);

        //cerramos sesion con jugador #1
        icCerrarSesion = fabrica->getICCerrarSesion();
        icCerrarSesion->cerrarSesion();
        
        //iniciamos sesion con jugador #2
        icIniciarSesion = fabrica->getICIniciarSesion();
        icIniciarSesion->ingresarDatos("jug2", "jug2");

        //suscribirse a el juego #3 con jugador #2
        icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
        icSuscribirseaVideojuego->ingresarNombre("fifa");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(DEBITO);

        //suscribirse a el juego #2 con jugador #2
        icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
        icSuscribirseaVideojuego->ingresarNombre("lol");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(CREDITO);

        //suscribirse a el juego #4 con jugador #2
        icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
        icSuscribirseaVideojuego->ingresarNombre("cod");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(CREDITO);

        //iniciamos partida indi #1 con jugador #2 al juego #3
        icIniciarPartida = fabrica->getICIniciarPartida();
        icIniciarPartida->seleccionarVideojuego("fifa");
        icIniciarPartida->datoIndividual(false, 7, 1);
        icIniciarPartida->altaPartida();

        //iniciamos partida multi #2 con jugador #1 al juego #2
        icIniciarPartida = fabrica->getICIniciarPartida();
        icIniciarPartida->seleccionarVideojuego("lol");
        icIniciarPartida->datoMultijugador(true, 3, 7, 2);
        icIniciarPartida->altaPartida();

        //iniciamos partida indi #1 con jugador #2 al juego #4
        icIniciarPartida = fabrica->getICIniciarPartida();
        icIniciarPartida->seleccionarVideojuego("cod");
        icIniciarPartida->datoIndividual(false, 2, 1);
        icIniciarPartida->altaPartida();

        //agregamos puntaje a juego #3 con jugador #2
        icAsignarPuntaje = fabrica->getICAsignarPuntaje();
        icAsignarPuntaje->asignarPuntaje("fifa", 5);

        //agregamos puntaje a juego #2 con jugador #2
        icAsignarPuntaje = fabrica->getICAsignarPuntaje();
        icAsignarPuntaje->asignarPuntaje("lol", 5);

        //agregamos puntaje a juego #2 con jugador #2
        icAsignarPuntaje = fabrica->getICAsignarPuntaje();
        icAsignarPuntaje->asignarPuntaje("cod", 1);

        //cerramos sesion con jugador #2
        icCerrarSesion = fabrica->getICCerrarSesion();
=======
    if (valor == 1)
    {
        icAltaUsuario->datosComunes("dev", "dev");
        icAltaUsuario->datosEmpresa("globant");
        icAltaUsuario->altaUsuario();

        icAltaUsuario = fabrica->getICAltaUsuario();
        icAltaUsuario->datosComunes("jug", "jug");
        icAltaUsuario->datosJugador("jugador", "dsfadsg");
        icAltaUsuario->altaUsuario();

        icIniciarSesion->ingresarDatos("dev", "dev");

        icAgregarCategoria->solictarDatos("dsaf", "accion", "pc");
        icAgregarCategoria->confirmarCategoria();

        icAgregarCategoria = fabrica->getICAgregarCategoria();
        icAgregarCategoria->solictarDatos("sdjgsa", "aventura", "play");
        icAgregarCategoria->confirmarCategoria();

        Categoria *cat = icAgregarCategoria->buscarCat(1);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("gta", "hsdgf", 456);
        icAgregarVideojuego->confirmarJuego();

        icAgregarVideojuego = fabrica->getICAgregarVideojuego();
        cat = icAgregarCategoria->buscarCat(2);
        icAgregarVideojuego->agregarCategoria(cat);
        icAgregarVideojuego->solicitarInfo("age", "hdasfadssdgf", 4567);
        icAgregarVideojuego->confirmarJuego();

        icCerrarSesion->cerrarSesion();

        icIniciarSesion->ingresarDatos("jug", "jug");

        icSuscribirseaVideojuego->ingresarNombre("gta");
        icSuscribirseaVideojuego->SuscribirseAVideojuego(DEBITO);

        icIniciarPartida->seleccionarVideojuego("gta");
        icIniciarPartida->datoIndividual(true, 21, 1);
        icIniciarPartida->altaPartida();

>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        icCerrarSesion->cerrarSesion();

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
        cout << longTab << "│      ✅ Datos Cargados Correctamente!      │" << endl;
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
        system("sleep 2.5");
        retorno = true;
    }
    return retorno;
}

// Press Enter to Continue
<<<<<<< HEAD
void pressEnter() {
    std::ios_base::sync_with_stdio(false);
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    cout << "\n"
         << longTab << COLOR_P << "┌───────────────────────────────────────────┐" << endl;
    cout << longTab << "│    📢 Presiona Enter para continuar...    │" << endl;
    cout << longTab << "└───────────────────────────────────────────┘" << COLOR_RESET << endl;
    std::cin.ignore();
}

void mostrarDatosDePrueba() {
=======
void pressEnter(){  
    std::ios_base::sync_with_stdio(false);
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    cout << "\n" << longTab << COLOR_P << "┌────────────────────────────────────┐" << endl;
    cout << longTab << "│  📢 Presiona Enter para continuar  │" << endl;
    cout << longTab << "└────────────────────────────────────┘" << COLOR_RESET << endl;
    std::cin.ignore();
}

void mostrarDatosDePrueba(){
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    system("clear");
    string salida;
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Datos Predefinidos ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
<<<<<<< HEAD

    cout << "\n"<< longTab << COLOR_LG << "❯ Desarrollador #1" << COLOR_RESET << endl;
    cout << longTab <<"└> email: "<< COLOR_SB << "dev" << COLOR_RESET << endl;
    cout << longTab <<"└> pass: " << COLOR_SB << "dev" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Categoria" << COLOR_RESET << endl;
    cout << longTab << "    └> [Genero / Plataforma]: " << COLOR_SB << "Accion / PS5" << COLOR_RESET << endl;
    cout << longTab << "    └> [Genero / Plataforma]: " << COLOR_SB << "Moba / PC" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG <<  "   ♦ Videojuego" << COLOR_RESET << endl;
    cout << longTab << "    └> nombre: " << COLOR_SB << "gta" << COLOR_RESET << endl;
    cout << longTab << "    └> nombre: " << COLOR_SB << "lol" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "❯ Desarrollador #2" << COLOR_RESET << endl;
    cout << longTab <<"└> email: "<< COLOR_SB << "dev2" << COLOR_RESET << endl;
    cout << longTab <<"└> pass: " << COLOR_SB << "dev2" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Categoria" << COLOR_RESET << endl;
    cout << longTab << "    └> [Genero / Plataforma]: " << COLOR_SB << "Deporte / XBOX" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG <<  "    ♦ Videojuego" << COLOR_RESET << endl;
    cout << longTab << "    └> nombre: " << COLOR_SB << "fifa" << COLOR_RESET << endl;
    cout << longTab << "    └> nombre: " << COLOR_SB << "cod" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "❯ Jugador #1" << COLOR_RESET << endl;
    cout << longTab << "└> email: " << COLOR_SB << "jug" << COLOR_RESET << endl;
    cout << longTab << "└> pass: " << COLOR_SB << "jug" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Suscripcion" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "gta" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "lol" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Partida" << COLOR_RESET << endl;
    cout << longTab << "    └> [Individual] - juego: " << COLOR_SB << "gta" << COLOR_RESET << endl;
    cout << longTab << "    └> [Multijugador] - juego: " << COLOR_SB << "lol" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Puntaje" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "gta" << " - 4" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "lol" << " - 2" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "❯ Jugador #2" << COLOR_RESET << endl;
    cout << longTab << "└> email: " << COLOR_SB << "jug2" << COLOR_RESET << endl;
    cout << longTab << "└> pass: " << COLOR_SB << "jug2" << COLOR_RESET << endl;
  
    cout << longTab << COLOR_LG << "    ♦ Suscripcion" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "fifa" << COLOR_RESET  << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "lol" << COLOR_RESET  << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "cod" << COLOR_RESET  << endl;

    cout << longTab << COLOR_LG << "    ♦ Partida" << COLOR_RESET << endl;
    cout << longTab << "    └> [Individual] - juego: " << COLOR_SB << "fifa" << COLOR_RESET << endl;
    cout << longTab << "    └> [Multijugador] - juego: " << COLOR_SB << "lol" << COLOR_RESET << endl;
    cout << longTab << "    └> [Individual] - juego: " << COLOR_SB << "cod" << COLOR_RESET << endl;

    cout << longTab << COLOR_LG << "    ♦ Puntaje" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "fifa" << " - 5" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "lol" << " - 5" << COLOR_RESET << endl;
    cout << longTab << "    └> juego: " << COLOR_SB << "cod" << " - 1" << COLOR_RESET << endl;

=======
    cout << longTab << "♦ Desarrollador: email dev y pass dev" << endl;
    cout << longTab << "♦ Jugador con: email jug y pass jug" << endl;
    cout << longTab << "♦ Categoria: accion / pc" << endl;
    cout << longTab << "♦ Categoria: aventura / play" << endl;
    cout << longTab << "♦ Videojuego: gta" << endl;
    cout << longTab << "♦ Videojuego: age" << endl;
    cout << longTab << "♦ Suscrupcion: gta" << endl;
    cout << longTab << "♦ Partida: gta" << endl;
    // cout << longTab << "♦ Videojuego: age" << endl;
    // cout << longTab << "♦ Videojuego: age" << endl;
    // cout << longTab << "♦ Videojuego: age" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    pressEnter();
}

/*---------------------------------------------------*
 *                 Menu Alta Usuario                  *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuAltaUsuario() {
=======
void menuAltaUsuario()
{
    icAltaUsuario = fabrica->getICAltaUsuario();
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    system("clear");
    icAltaUsuario = fabrica->getICAltaUsuario();
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 👤 Agregar Usuario ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
    string email;
    string pass;
    string nomEmp = "";
    char num, num2;
    cout << longTab << "♦ Ingrese su Email: ";
    cin >> email;
<<<<<<< HEAD
    if (!(icAltaUsuario->checkUser(email))) {
=======
    if (!(icAltaUsuario->checkUser(email)))
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "♦ Ingrese su Password: ";
        cin >> pass;
        icAltaUsuario->datosComunes(email, pass);
        system("clear");
<<<<<<< HEAD
        cout << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
=======
        cout << longTab << "┌────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "│               Seleccione Rol               │" << endl;
        cout << longTab << "├────────────────────────────────────────────┤\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│             1. 🔧 Desarrollador            │\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│             2. 🎮 Jugador                  │\n";
<<<<<<< HEAD
        cout << longTab << "│                                            │\n";
=======
        cout << longTab << "│                                            │\n"; 
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "│                                            │\n";
        cout << longTab << "└────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> num;
        bool cond = true;
<<<<<<< HEAD
        switch (num) {
            case '1': {
                system("clear");
                cout << longSpace<< longTab << "♦ Ingrese el nombre de la empresa: ";
                cin >> nomEmp;
                icAltaUsuario->datosEmpresa(nomEmp);
                icAltaUsuario->altaUsuario();
                DoneMessage();
            } break;
            case '2': {
                system("clear");
                bool x;
                string nick, desc;
                cout << longSpace << longTab << "♦ Ingrese nickname: ";
                cin >> nick;
                cout << longTab << "♦ Ingrese una breve descripcion: ";
                cin >> desc;
                icAltaUsuario->datosJugador(nick, desc);
                do {
                    try {
                        icAltaUsuario->altaUsuario();
                        cond = false;
                        DoneMessage();
                    } catch (invalid_argument &e) {
                        cout << "\n"
                             << longTab << COLOR_Y << "┌────────────────────────────┐" << endl;
                        cout << longTab << e.what() << endl;
                        cout << longTab << "└────────────────────────────┘" << COLOR_RESET << endl;
                        system("sleep 2.5");
                        system("clear");
                        cout << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
                        cout << longTab << "│   ¿Deseas volver a ingresar el nickname?   │" << endl;
                        cout << longTab << "├────────────────────────────────────────────┤\n";
                        cout << longTab << "│                                            │\n";
                        cout << longTab << "│                1. Reintentar               │\n";
                        cout << longTab << "│                                            │\n";
                        cout << longTab << "│                2. Cancelar                 │\n";
                        cout << longTab << "│                                            │\n";
                        cout << longTab << "└────────────────────────────────────────────┘" << endl;
                        cout << longTab << "❯ Opción: ";
                        cin >> num2;
                        switch (num2) {
                            case '1':
                                cout << longTab << "♦ Ingrese nickname: ";
                                cin >> nick;
                                icAltaUsuario->ingNickname(nick);
                                break;
                            case '2':
                                icAltaUsuario->cancelar();
                                cond = false;
                                break;
                        }
                    }
                } while (cond);
            } break;
        }
    } else {
        cout << "\n"
             << longTab << COLOR_Y << "┌───────────────────────────┐" << endl;
        cout << longTab << "│  🔔 Ese Email ya Existe!  │" << endl;
        cout << longTab << "└───────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        menuAltaUsuario();
    }
}

/*------------------------------------------------------*
 *                 Menu Iniciar Sesion 1                 *
 *-------------------------------------------------------*/

bool menuIniciarSesion1() {
    system("clear");
    icIniciarSesion = fabrica->getICIniciarSesion();
    char cond;
    bool retorno = false;
    cout << longSpace << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ 👤 Bienvenido ♦               ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               1. Iniciar Sesion              ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               2. Registrarse                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               3. Cargar Datos                ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond) {
        case '1': {
            if (icAltaUsuario->hayUsuarios()) {
                system("clear");
                bool cond2 = true;
                cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
                cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
                cout << longTab << "╚════════════════════════════════════════════╝\n";
                string email, pass;
                char num2;
                do{
                    cout << longTab << "♦ Ingrese su Email: ";
                    cin >> email;
                    cout << longTab << "♦ Ingrese su Password: ";
                    cin >> pass;
                    if (icIniciarSesion->ingresarDatos(email, pass)) {
                        logInScreen();
                        cond2 = false;
                    } else {
                        cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
                        cout << longTab << "│          ⛔ Usuario No Encontrado           │" << endl;
                        cout << longTab << "└─────────────────────────────────────────────┘\n"<< COLOR_RESET << endl;
                        system("sleep 2.5");
                        system("clear");
                        cout << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
                        cout << longTab << "│    ¿Deseas volver a ingresar al Sistema?   │" << endl;
                        cout << longTab << "├────────────────────────────────────────────┤\n";
                        cout << longTab << "│                                            │\n";
                        cout << longTab << "│                1. Reintentar               │\n";
                        cout << longTab << "│                                            │\n";
                        cout << longTab << "│                2. Cancelar                 │\n";
                        cout << longTab << "│                                            │\n"; 
                        cout << longTab << "└────────────────────────────────────────────┘" << endl;
                        cout << longTab << "❯ Opción: ";
                        cin >> num2;
                        switch (num2) {
                            case '2':
                                cond2 = false;
                            break;
                        }
                    }
                } while (cond2);
            } else {
                system("clear");
                cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
                cout << longTab << "│        ⛔ No se puede inciar sesion         │" << endl;
                cout << longTab << "│                                             │" << endl;
                cout << longTab << "│  No hay Usuarios Registrados en el Sistema  │" << endl;
                cout << longTab << "└─────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 3");
            }
        } break;
        case '2': {
            menuAltaUsuario();
        } break;
        case '3': {
            if (menuCargarDatos() == true) {
                retorno = true;
            }
        } break;
=======
        switch (num)
        {
        case '1':
        {
            system("clear");
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
                system("sleep 2.5");
            }
        }
        break;
        case '2':
        {
            system("clear");
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
                    system("sleep 2.5");
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
                    case '1':
                        cout << longTab << "♦ Ingrese nickname: ";
                        cin >> nick;
                        icAltaUsuario->ingNickname(nick);
                        break;
                    case '2':
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
             << longTab << COLOR_Y << "┌──────────────────────────┐" << endl;
        cout << longTab << "│  🔔 Ese Email ya Existe!  │" << endl;
        cout << longTab << "└──────────────────────────┘" << COLOR_RESET << endl;    
        system("sleep 2.5");
        menuAltaUsuario();
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    }
    return retorno;
}

/*------------------------------------------------------*
<<<<<<< HEAD
 *                 Menu Iniciar Sesion 2                 *
 *-------------------------------------------------------*/

void menuIniciarSesion2() {
    system("clear");
    icIniciarSesion = fabrica->getICIniciarSesion();
    char cond;
=======
 *                 Menu Iniciar Sesion 1                 *
 *-------------------------------------------------------*/

bool menuIniciarSesion1()
{
    icIniciarSesion = fabrica->getICIniciarSesion();
    system("clear");
    char cond;
    bool retorno = false;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longSpace << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ 👤 Bienvenido ♦               ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               1. Iniciar Sesion              ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               2. Registrarse                 ║\n";
    cout << longTab << "║                                              ║\n";
<<<<<<< HEAD
    cout << longTab << "║               3. Mostrar Datos               ║\n";
=======
    cout << longTab << "║               3. Cargar Datos                ║\n";
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
<<<<<<< HEAD
    switch (cond) {
        case '1': {
            system("clear");
=======
    switch (cond)
    {
    case '1':
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
                    cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│          ⛔ Usuario No Encontrado           │" << endl;
                    cout << longTab << "│                                             │" << endl;
                    cout << longTab << "│         Por Favor Ingrese Nuevamente        │" << endl;
                    cout << longTab << "└─────────────────────────────────────────────┘\n"
                         << COLOR_RESET << endl;
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
            cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
            cout << longTab << "│        ⛔ No se puede inciar sesion        │" << endl;
            cout << longTab << "│                                             │" << endl;
            cout << longTab << "│  No hay Usuarios Registrados en el Sistema  │" << endl;
            cout << longTab << "└─────────────────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 3");
        }
    }
    break;
    case '2':
    {
        menuAltaUsuario();
    }
    break;
    case '3':
    {
        if (menuCargarDatos() == true){
            retorno = true;
        }
    }
    break;
    }
    return retorno;
}

/*------------------------------------------------------*
 *                 Menu Iniciar Sesion 2                 *
 *-------------------------------------------------------*/

void menuIniciarSesion2()
{
    icIniciarSesion = fabrica->getICIniciarSesion();
    system("clear");
    char cond;
    cout << longSpace << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║              ♦ 👤 Bienvenido ♦               ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               1. Iniciar Sesion              ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               2. Registrarse                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║               3. Mostrar Datos               ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> cond;
    switch (cond)
    {
    case '1':
    {
        if (icAltaUsuario->hayUsuarios())
        {
            system("clear");
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            bool cond2 = true;
            cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
            cout << longTab << COLOR_SB << "║           ♦ 👤 Iniciar Sesion ♦            ║" << COLOR_RESET << endl;
            cout << longTab << "╚════════════════════════════════════════════╝\n";
            string email, pass;
<<<<<<< HEAD
            char num2;
            do {
                cout << longTab << "♦ Ingrese su Email: ";
                cin >> email;
                cout << longTab << "♦ Ingrese su Password: ";
                cin >> pass;
                if (icIniciarSesion->ingresarDatos(email, pass)) {
                    logInScreen();
                    cond2 = false;
                } else {
                    cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│          ⛔ Usuario No Encontrado           │" << endl;
                    cout << longTab << "└─────────────────────────────────────────────┘\n"<< COLOR_RESET << endl;
                    system("sleep 2.5");
                    system("clear");
                    cout << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│    ¿Deseas volver a ingresar al Sistema?   │" << endl;
                    cout << longTab << "├────────────────────────────────────────────┤\n";
                    cout << longTab << "│                                            │\n";
                    cout << longTab << "│                1. Reintentar               │\n";
                    cout << longTab << "│                                            │\n";
                    cout << longTab << "│                2. Cancelar                 │\n";
                    cout << longTab << "│                                            │\n"; 
                    cout << longTab << "└────────────────────────────────────────────┘" << endl;
                    cout << longTab << "❯ Opción: ";
                    cin >> num2;
                    switch (num2) {
                        case '2':
                            cond2 = false;
                        break;
                    }
                }
            } while (cond2);
        } break;
        case '2': {
            menuAltaUsuario();
        } break;
        case '3': {
            mostrarDatosDePrueba();
        } break;
=======
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
                    cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
                    cout << "│          ⛔ Usuario No Encontrado           │" << endl;
                    cout << "│                                             │" << endl;
                    cout << longTab << "│         Por Favor Ingrese Nuevamente        │" << endl;
                    cout << longTab << "└─────────────────────────────────────────────┘\n"
                         << COLOR_RESET << endl;
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
            cout << longSpace << longTab << COLOR_R << "┌─────────────────────────────────────────────┐" << endl;
            cout << "│        ⛔ No se puede inciar sesion        │" << endl;
            cout << "│                                             │" << endl;
            cout << longTab << "│  No hay Usuarios Registrados en el Sistema  │" << endl;
            cout << longTab << "└─────────────────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 3");
        }
    }
    break;
    case '2':
    {
        menuAltaUsuario();
    }
    break;
    case '3':
    {
        mostrarDatosDePrueba();
    }
    break;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    }
}

/*-----------------------------------------------------*
 *               Menu Cerrar Sesion                     *
 *------------------------------------------------------*/

<<<<<<< HEAD
bool menuCerrarSesion() {
    system("clear");
    icCerrarSesion = fabrica->getICCerrarSesion();
=======
bool menuCerrarSesion()
{
    icCerrarSesion = fabrica->getICCerrarSesion();
    system("clear");
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    bool retorno = false;
    cout << longSpace << longTab << "╔══════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║             ♦ 👤 Cerrar Sesion ♦             ║" << COLOR_RESET << endl;
    cout << longTab << "╠══════════════════════════════════════════════╣\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║                  1. Confirmar                ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "║                  0. Cancelar                 ║\n";
    cout << longTab << "║                                              ║\n";
    cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
    char cond;
    cin >> cond;
<<<<<<< HEAD
    switch (cond) {
        case '1': {
            icCerrarSesion->cerrarSesion();
            retorno = true;
            DoneMessage();
            return retorno;
        } break;
=======
    switch (cond)
    {
    case '1':
    {
        icCerrarSesion->cerrarSesion();
        retorno = true;
        DoneMessage();
        return retorno;
    }
    break;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    }
    return retorno;
}

/*-------------------------------------------------------*
 *               Menu Agregar Categoria                   *
 *--------------------------------------------------------*/

<<<<<<< HEAD
void menuAgregarCategoria() {
    system("clear");
    icAgregarCategoria = fabrica->getICAgregarCategoria();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║          ♦ 👾 Agregar Categoria ♦        ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    char cond;
    string genero, plataforma, desc;
    if (icAgregarCategoria->hayCategorias()) {
        cout << "\n"
             << COLOR_BW << longTab << "         📢  Categorias Existentes          "
             << COLOR_RESET << endl;
             cout << longTab << "────────────────────────────────────────────" << endl;
        list<DtCategoria *> lista = icAgregarCategoria->listarDtCategorias();
        for (list<DtCategoria *>::iterator it = lista.begin(); it != lista.end(); ++it) {
=======
void menuAgregarCategoria()
{
    icAgregarCategoria = fabrica->getICAgregarCategoria();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Agregar Categoria ♦          ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝";
    char cond;
    string genero, plataforma, desc;
    if (icAgregarCategoria->hayCategorias())
    {
        cout << "\n" << longTab << "[ 📢 Categorias Existentes ]\n"
             << endl;
        list<DtCategoria *> lista = icAgregarCategoria->listarDtCategorias();
        for (list<DtCategoria *>::iterator it = lista.begin(); it != lista.end(); ++it)
        {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
            cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
            cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        }
<<<<<<< HEAD
    }
    cout << "\n"
             << COLOR_BW << longTab << "        📢  Ingrese Nueva Categoria         "
             << COLOR_RESET << endl;
             cout << longTab << "────────────────────────────────────────────" << endl;
=======
        pressEnter();
    }
    cout << longTab << "♦ Ingrese una breve descripcion: ";
    cin >> desc;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longTab << "♦ Ingrese su genero: ";
    cin >> genero;
    cout << longTab << "♦ Ingrese la plataforma: ";
    cin >> plataforma;
<<<<<<< HEAD
    cout << longTab << "♦ Ingrese una breve descripcion: ";
    cin >> desc;
    icAgregarCategoria->solictarDatos(desc, genero, plataforma);
    system("clear");
    cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
=======
    icAgregarCategoria->solictarDatos(desc, genero, plataforma);
    cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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
<<<<<<< HEAD
    switch (cond) {
        case '1': {
            icAgregarCategoria->confirmarCategoria();
            DoneMessage();
        } break;
        case '0': {
            icAgregarCategoria->cancelar();
            system("clear");
        } break;
=======
    switch (cond)
    {
    case '1':
    {
        icAgregarCategoria->confirmarCategoria();
        DoneMessage();
        system("clear");
    }
    break;
    case '0':
    {
        icAgregarCategoria->cancelar();
        system("clear");
    }
    break;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    }
}

/*---------------------------------------------------*
 *               Menu Agregar Videojuego              *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuAgregarVideojuego() {
    system("clear");
    icAgregarVideojuego = fabrica->getICAgregarVideojuego();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║         ♦ 🕹  Agregar Videojuego ♦        ║" << COLOR_RESET << endl;
    cout << longTab <<"╚══════════════════════════════════════════╝\n";
    int costo = 0, x = 2, id = 0;
    char cond;
    string nombre, desc;
    cout << longTab << "♦ Ingrese el nombre del Videojuego: ";
=======
void menuAgregarVideojuego()
{
    icAgregarVideojuego = fabrica->getICAgregarVideojuego();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Agregar Videojuego ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    int costo = 0, x = 2, id = 0;
    char cond;
    string nombre, desc;
    cout << longTab << "♦ Ingrese el nombre del videojuego: ";
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cin >> nombre;
    cout << longTab << "♦ Ingrese la descripcion del videojuego: ";
    cin >> desc;
    cout << longTab << "♦ Ingrese el costo de la suscripcion: ";
    cin >> costo;
<<<<<<< HEAD
    if (icAgregarCategoria->hayCategorias()) {
        while (x != 0) {
            cout << longTab << "♦ Seleccionar Categoria: "
                 << "\n"
                 << endl;
            list<DtCategoria *> listaDt = icAgregarCategoria->listarDtCategorias();
            for (list<DtCategoria *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it) {
=======
    if (icAgregarCategoria->hayCategorias())
    {
        while (x != 0)
        {
            cout << "\n"
                << longTab << "♦ Seleccionar Categoria: "
                << "\n"
                << endl;
            list<DtCategoria *> listaDt = icAgregarCategoria->listarDtCategorias();
            for (list<DtCategoria *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
            {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
                cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
                cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
                cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
            }
<<<<<<< HEAD
            cout << "\n"
                 << longTab << "♦ Ingrese el ID de la categoria: ";
            cin >> id;
            if(icBuscarPorCategoria->existeCategoria(id)){
                Categoria* nuevoCat = icAgregarCategoria->buscarCat(id);
                icAgregarVideojuego->agregarCategoria(nuevoCat);
                DoneMessage();
                cout << endl;
                cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
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
                system("clear");
            }else{
                cout << "no existe esa categoria" << endl;
            }
        }
        cout << longSpace << longTab << COLOR_BW << "        📢  Detalles del Videojuego         " << COLOR_RESET << endl;
        cout << longTab << "────────────────────────────────────────────" << endl;
        cout << longTab << COLOR_LG << " ❯ Nombre: " << nombre << endl;
        cout << longTab << " ❯ Descripcion: " << desc << endl;
        cout << longTab << " ❯ Costo: $" << costo << endl;
        cout << longTab << " ❯ Email: " << icIniciarSesion->getEmail() << endl;
        cout << longTab << " ❯ Categorias:" << endl;
        list<DtCategoria *> listaDtCat = icAgregarVideojuego->mostrarCat();
        for (list<DtCategoria *>::iterator it = listaDtCat.begin(); it != listaDtCat.end(); ++it) {
            (*it)->imprimirPar();
        }
        cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
=======
            pressEnter();
            Categoria *nuevoCat;
            cout << "\n"
                 << longTab << "♦ Ingrese el id de la categoria: ";
            cin >> id;
            nuevoCat = icAgregarCategoria->buscarCat(id);
            icAgregarVideojuego->agregarCategoria(nuevoCat);
            cout << endl;
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
            system("clear");
        }
        cout << longTab << "♦ Nombre: " << nombre << endl;
        cout << longTab << "♦ Descripcion: " << desc << endl;
        cout << longTab << "♦ Costo: " << costo << endl;
        cout << longTab << "♦ Email: " << icIniciarSesion->getEmail() << endl;
        cout << longTab << "♦ Categoria: " << "\n" << endl;
        list<DtCategoria*> listaDtCat = icAgregarVideojuego->mostrarCat();
        for(list<DtCategoria*>::iterator it = listaDtCat.begin(); it != listaDtCat.end(); ++it){
            (*it)->imprimirPar();
        }
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        pressEnter();
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
<<<<<<< HEAD
        switch (cond) {
            case '1': {
                icAgregarVideojuego->solicitarInfo(nombre, desc, costo);
                icAgregarVideojuego->confirmarJuego();
                DoneMessage();
            } break;
            case '0': {
                icAgregarVideojuego->cancelar();
                system("clear");
            } break;
        }
    } else {
=======
        switch (cond)
        {
        case '1':
        {
            icAgregarVideojuego->solicitarInfo(nombre, desc, costo);
            icAgregarVideojuego->confirmarJuego();
            DoneMessage();
            system("clear");
        }
        break;
        case '0':
        {
            icAgregarVideojuego->cancelar();
            system("clear");
        }
        break;
        }
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << "\n"
             << longTab << COLOR_R << "┌──────────────────────────────────────┐" << endl;
        cout << longTab << "│  ⛔ No hay Categorias en el Sistema  │" << endl;
        cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
    }
}

/*---------------------------------------------------*
 *               Menu Iniciar Partida                 *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuIniciarPartida() {
    system("clear");
    icIniciarPartida = fabrica->getICIniciarPartida();;
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 🎯 Iniciar Partida ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
=======
void menuIniciarPartida()
{
    icIniciarPartida = fabrica->getICIniciarPartida();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Iniciar Partida ♦            ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝";
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    char cond;
    string nom;
    bool cont = false;
    int cond2, dur, jug;
<<<<<<< HEAD
    if (icInfoJuego->hayJuegos()) {
        list<DtJuego *> listaActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        if(listaActiva.size() > 0){
            cout << "\n"
                << longTab << COLOR_BW << "       📢  Biblioteca de Videojuegos       " << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
            for (list<DtJuego *>::iterator it = listaActiva.begin(); it != listaActiva.end(); ++it) {
                (*it)->imprimirNombre();
            }
            cout << "\n"
                << longTab << "♦ Ingrese el nombre del Videojuego: ";
            cin >> nom;
            system("clear");
            icIniciarPartida->seleccionarVideojuego(nom);
            cout << longSpace<< longTab << "┌──────────────────────────────────────────────┐" << endl;
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
            switch (cond) {
                case '2': {
                    system("clear");
                    cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
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
                    if (cond2 == 1) {
                        cont = true;
                    }
                    cout << longTab << "♦ Ingrese la duracion de la partida: ";
                    cin >> dur;
                    cout << longTab << "♦ Ingrese la cantidad de jugadores: ";
                    cin >> jug;
                    icIniciarPartida->datoMultijugador(cont, dur, jug, cond);
                } break;
                case '1': {
                    system("clear");
                    cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
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
                    if (cond2 == 1) {
                        cont = true;
                    }
                    cout << longTab << "♦ Ingrese la duracion de la partida: ";
                    cin >> dur;
                    icIniciarPartida->datoIndividual(cont, dur, cond);
                } break;
            }
            system("clear");
            cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
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
            switch (cond) {
                case '1': {
                    icIniciarPartida->altaPartida();
                    menuCargarPartida();
                    system("clear");
                } break;
                case '0': {
                    icIniciarPartida->cancelar();
                    system("clear");
                } break;
            }
        }else{
            cout << "\n"
             << longTab << COLOR_Y << "┌────────────────────────────────────────────────────┐" << endl;
        cout << longTab << "│ 🔔 No tienes ninguna suscripcion a un videojuego   │" << endl;
        cout << longTab << "└────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
        }
    } else {
=======
    if (icInfoJuego->hayJuegos())
    {
        cout << longTab << "\n[ ♦ Mi Coleccion de Videojuegos ♦ ]\n"
             << endl;
        list<DtJuego *> listaActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        for (list<DtJuego *>::iterator it = listaActiva.begin(); it != listaActiva.end(); ++it)
        {
            (*it)->imprimirNombre();
        }
        pressEnter();
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del juego que desea jugar: ";
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
        case '2':
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
            cout << longTab << "♦ Ingrese la duracion de la partida: ";
            cin >> dur;
            cout << longTab << "♦ Ingrese la cantidad de jugadores: ";
            cin >> jug;
            icIniciarPartida->datoMultijugador(cont, dur, jug, cond);
        }
        break;
        case '1':
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
            cout << "♦ Ingrese la duracion de la partida: ";
            cin >> dur;
            icIniciarPartida->datoIndividual(cont, dur, cond);
        }
        break;
        }
        system("clear");
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
        case '1':
        {
            icIniciarPartida->altaPartida();
            menuCargarPartida();
            system("clear");
        }
        break;
        case '0':
        {
            icIniciarPartida->cancelar();
            system("clear");
        }
        break;
        }
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *            Menu Suscribirse a Videojuego           *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuSuscribirseAVideojuego() {
    system("clear");
    icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║       ♦ 💰 Suscribirse a Videojuego ♦      ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";                     
    if (icInfoJuego->hayJuegos()) {
        list<DtJuego *> listaDtActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        if (listaDtActiva.size() > 0){
            cout << "\n"
                << longTab << COLOR_BW << "      📢  Juegos con Suscripcion Activa       "
                << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
            for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it) {
                (*it)->imprimirNombreCosto();
                cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
            }
        }else{
            cout << "\n"
            << longTab << COLOR_BW << "      📢  Juegos con Suscripcion Activa       "
            << COLOR_RESET << endl;
            cout << longTab << "────────────────────────────────────────────" << endl;
            cout << "\n"
                 << longTab << COLOR_Y << "┌──────────────────────────────────────────────┐" << endl;
            cout << longTab << "│   🔔 No hay juegos con Suscripcion Activa    │" << endl;
            cout << longTab << "└──────────────────────────────────────────────┘" << COLOR_RESET << endl;
        }
        list<DtJuego *> listaDt = icSuscribirseaVideojuego->listarLosJuegosSinSub();
        if (listaDt.size() > 0){
            cout << "\n\n"
                << longTab << COLOR_BW << "      📢  Juegos sin Suscripcion Activa       "
                << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
            
            for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it) {
                (*it)->imprimirNombreCosto();
                cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
            }
        }else{
            cout << "\n"
                << longTab << COLOR_BW << "      📢  Juegos sin Suscripcion Activa       "
                << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
            cout << "\n"
                 << longTab << COLOR_Y << "┌──────────────────────────────────────────────┐" << endl;
            cout << longTab << "│   🔔 No hay juegos sin Suscripcion Activa    │" << endl;
            cout << longTab << "└──────────────────────────────────────────────┘" << COLOR_RESET << endl;
        }
        string nombre;
        TipoPago tipoPago;
        cout << "\n" << longTab << "♦ Ingrese el nombre del VideoJuego: ";
        cin >> nombre;
        if (icSuscribirseaVideojuego->ingresarNombre(nombre)) {
            if (!(icSuscribirseaVideojuego->tieneSuscripcion())) {
                system("clear");
                int tipo;
                char cond;
                cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
=======
void menuSuscribirseAVideojuego()
{
    icSuscribirseaVideojuego = fabrica->getICSuscribirseaVideojuego();
    system("clear");
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║        ♦ Suscribirse a Videojuego ♦        ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝";
    if (icInfoJuego->hayJuegos())
    {
        cout << "\n" << longTab << "[ 📢 Juegos con Suscripcion Activa ]\n"<< endl;
        list<DtJuego *> listaDtActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it)
        {
            (*it)->imprimirNombreCosto();
        }
        pressEnter();
        cout << "\n" << longTab << "[ 📢 Juegos sin Suscripcion Activa ]\n"<< endl;
        list<DtJuego *> listaDt = icSuscribirseaVideojuego->listarLosJuegosSinSub();
        for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
        {
            (*it)->imprimirNombreCosto();
        }
        string nombre;
        TipoPago tipoPago;
        cout << longTab << "\n"
             << "♦ Nombre del videoJuego al cual quiere suscribirse: ";
        cin >> nombre;
        if (icSuscribirseaVideojuego->ingresarNombre(nombre))
        {
            if (!(icSuscribirseaVideojuego->tieneSuscripcion()))
            {
                system("clear");
                int tipo;
                char cond;
                cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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
<<<<<<< HEAD
                if (tipo == 1) {
                    tipoPago = DEBITO;
                } else if (tipo == 2) {
                    tipoPago = CREDITO;
                }
                system("clear");
                cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
=======
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
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
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
<<<<<<< HEAD
                switch (cond) {
                    case '1': {
                        icSuscribirseaVideojuego->SuscribirseAVideojuego(tipoPago);
                        DoneMessage();
                    } break;
                    case '0': {
                        icSuscribirseaVideojuego->cancelar();
                        system("clear");
                    } break;
                }
            } else {
=======
                switch (cond)
                {
                case '1':
                {
                    icSuscribirseaVideojuego->SuscribirseAVideojuego(tipoPago);
                    DoneMessage();
                    system("clear");
                }
                break;
                case '0':
                {
                    icSuscribirseaVideojuego->cancelar();
                    system("clear");
                }
                break;
                }
            }
            else
            {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
                cout << "\n"
                     << longTab << COLOR_Y << "┌─────────────────────────────────────────────────┐" << endl;
                cout << longTab << "│   🔔 Ya se encuentra Suscripto al Videojuego!   │" << endl;
                cout << longTab << "└─────────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2.5");
            }
<<<<<<< HEAD
        } else {
=======
        }
        else
        {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            cout << "\n"
                 << longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│  ⛔ No Existe ese Videojuego   │" << endl;
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
        }
<<<<<<< HEAD
    } else {
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *            Menu Ver Info de Videojuego             *
 *----------------------------------------------------*/

void menuVerInfoVideojuego() {
    system("clear");
    icInfoJuego = fabrica->getICInfoJuego();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║ ♦ 👁  Ver Informacion de un Videojuego ♦  ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string name;        
    if (icInfoJuego->hayJuegos()) {
        cout << "\n"
             << longTab << COLOR_BW << "  📢  Videojuegos Ingresados en el Sistema  "
             << COLOR_RESET << endl;
             cout << longTab << "────────────────────────────────────────────" << endl;
        list<string> list = icInfoJuego->listarJuegos();
        for (std::list<string>::iterator it = list.begin(); it != list.end(); ++it) {
            cout << longTab << COLOR_LG << "┌────────────────────┐" << endl;
            cout << longTab << "│ ❯ " << *it << endl;
            cout << longTab << "└────────────────────┘" << COLOR_RESET << endl;
        }
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del Videojuego: ";
        cin >> name;
        system("clear");
        DtJuego *juego = icInfoJuego->selectJuego(name);
        cout << "\n"<< longSpace << longTab << COLOR_BW << "          📢  Detalles del Videojugo        " << COLOR_RESET << endl;
        cout << longTab <<  "────────────────────────────────────────────";
        juego->imprimirInfo();
        cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
        pressEnter();
    } else {
=======
    }
    else
    {
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *            Menu Ver Info de Videojuego             *
 *----------------------------------------------------*/

void menuVerInfoVideojuego()
{
    icInfoJuego = fabrica->getICInfoJuego();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║   ♦ Ver Informacion de un Videojuego ♦   ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝";
    string name;
    if (icInfoJuego->hayJuegos())
    {
        cout << "\n" << longTab << "[ 📢 Videojuegos Ingresados en el Sistema ]\n"
             << endl;
        list<string> list = icInfoJuego->listarJuegos();
        for (std::list<string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            cout << longTab << COLOR_LG << "┌────────────────────┐" << endl;
            cout << longTab << "│ ❯ " << *it << endl;
            cout << longTab << "└────────────────────┘" << COLOR_RESET << endl;
        }
        pressEnter();
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del cual desee informacion: ";
        cin >> name;
        DtJuego *juego = icInfoJuego->selectJuego(name);
        juego->imprimirInfo();
        pressEnter();
        system("clear");
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *               Menu Eliminar Videojuego             *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuEliminarVideojuego() {
    system("clear");
    icEliminarVideojuego = fabrica->getICEliminarVideojuego();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║        ♦ 🗑  Eliminar Videojuego ♦        ║" << COLOR_RESET << endl;
=======
void menuEliminarVideojuego()
{
    icEliminarVideojuego = fabrica->getICEliminarVideojuego();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║          ♦ Eliminar Videojuego ♦         ║" << COLOR_RESET << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string nombre;
    char cond;
    Sesion *s = Sesion::getInstancia();
    Usuario *u = s->getUsuario();
<<<<<<< HEAD
    if (icInfoJuego->hayJuegos()) {
        cout << "\n" << longTab << COLOR_BW << "     📢  Videojugos Publicados por " << COLOR_LG << u->getEmail() << COLOR_RESET << endl;
        cout << longTab <<  "────────────────────────────────────────────" << endl;
        list<DtJuego *> lista = icEliminarVideojuego->listarJuegosDev();
        for (list<DtJuego *>::iterator it = lista.begin(); it != lista.end(); ++it) {
            (*it)->imprimirNombre();
        }
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del Videojuego: ";
        cin >> nombre;
        icEliminarVideojuego->seleccionarJuego(nombre);
        system("clear");
        cout << longSpace << longTab << "┌───────────────────────────────────────────────┐" << endl;
=======
    if (icInfoJuego->hayJuegos())
    {
        cout << "\n" << longTab << "║ ♦ Juegos publicados por " << COLOR_LG << u->getEmail() << COLOR_RESET << " ♦ ║"<< "\n" << endl;
        list<DtJuego*> lista = icEliminarVideojuego->listarJuegosDev();
        for (list<DtJuego *>::iterator it = lista.begin(); it != lista.end(); ++it)
        {
            (*it)->imprimirNombre();
        }
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del juego que quiera eliminar: ";
        cin >> nombre;
        icEliminarVideojuego->seleccionarJuego(nombre);
        cout << "\n";
        cout << longTab << "┌───────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "│          Desea Eliminar el Videojuego?        │" << endl;
        cout << longTab << "├───────────────────────────────────────────────┤\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   1. Aceptar                  │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "│                   0. Cancelar                 │\n";
        cout << longTab << "│                                               │\n";
        cout << longTab << "└───────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> cond;
<<<<<<< HEAD
        switch (cond) {
            case '1': {
                icEliminarVideojuego->eliminarVideojuego();
                DoneMessage();
            } break;
            case '0': {
                icEliminarVideojuego->cancelar();
                system("clear");
            } break;
        }
    } else {
=======
        switch (cond)
        {
        case '1':
        {
            icEliminarVideojuego->eliminarVideojuego();
            DoneMessage();
            system("clear");
        }
        break;
        case '0':
        {
            icEliminarVideojuego->cancelar();
            system("clear");
        }
        break;
        }
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *               Menu Asignar Puntaje                 *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuAsignarPuntaje() {
    system("clear");
    icAsignarPuntaje = fabrica->getICAsignarPuntaje();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║          ♦ 📈 Asignar Puntaje ♦          ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";                  
    string nombre;
    int puntaje;
    bool cond = false;
    if (icInfoJuego->hayJuegos()) {
        cout << "\n" << longTab << COLOR_BW << "    📢  Juegos ingresados en el sistema      " << COLOR_RESET << endl;
        cout << longTab << "────────────────────────────────────────────" << endl;
        list<DtJuego *> listaDtActiva = icVerPartidas->listarLosJuegos();
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it) {
            (*it)->imprimirNombreDesc();
            cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
        }
        cout << "\n"
             << longTab << "♦ Ingrese nombre de Videojuego: ";
        cin >> nombre;
        system("clear");
        do {
            cout << "\n" << longSpace << longTab << "┌────────────────────────────────────────────┐" << endl;
=======
void menuAsignarPuntaje()
{
    icAsignarPuntaje = fabrica->getICAsignarPuntaje();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║            ♦ Asignar Puntaje ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string nombre;
    int puntaje;
    bool cond = false;
    if (icInfoJuego->hayJuegos())
    {
        cout << longTab << "[ ♦ Juegos ingresados en el sistema ♦ ]\n"
             << endl;
        list<string> list = icInfoJuego->listarJuegos();
        for (std::list<string>::iterator it = list.begin(); it != list.end(); ++it)
        {
            cout << longTab << COLOR_LG << "┌────────────────────┐" << endl;
            cout << longTab << "│ ❯ " << *it << endl;                  //arreglar la lista 
            cout << longTab << "└────────────────────┘" << COLOR_RESET << endl;
        }
        pressEnter();
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del juego del cual quiera puntuar: ";
        cin >> nombre;
        do
        {
            cout << longTab << "\n┌────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            cout << longTab << "│       Seleccione una Escala de [1 a 5]     │" << endl;
            cout << longTab << "├────────────────────────────────────────────┤\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "│              1. 🔴 Deficiente              │\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "│              2. 🟠 Regular                 │\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "│              3. 🟡 Bueno                   │\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "│              4. 🟢 Muy Bueno               │\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "│              5. 🔵 Excelente               │\n";
            cout << longTab << "│                                            │\n";
            cout << longTab << "└────────────────────────────────────────────┘" << endl;
            cout << longTab << "❯ Opción: ";
            cin >> puntaje;
<<<<<<< HEAD
            if ((puntaje <= 5) && (puntaje >= 1)) {
                icAsignarPuntaje->asignarPuntaje(nombre, puntaje);
                DoneMessage();
                cond = false;
            } else {
=======
            if ((puntaje <= 5) && (puntaje >= 1))
            {
                icAsignarPuntaje->asignarPuntaje(nombre, puntaje);
                DoneMessage();
                system("clear");
                cond = false;
            }
            else
            {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
                cout << COLOR_R << "┌──────────────────────────┐" << endl;
                cout << "│  ⛔ Puntaje Inapropiado  |" << endl;
                cout << longTab << "└──────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2.5");
                system("clear");
                cond = true;
            }
        } while (cond == true);
<<<<<<< HEAD
    } else {
=======
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
        system("clear");
    }
}

/*---------------------------------------------------*
 *              Menu Cancelar Suscripcion             *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuCancelarSuscripcion() {
    system("clear");
    icCancelarSuscripcion = fabrica->getICCancelarSuscripcion();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║        ♦ 🚫 Cancelar Suscripcion ♦       ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string nombre;
    list<DtJuego *> listaDtActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
    if (listaDtActiva.size() > 0) {
        cout << "\n" << longTab << COLOR_BW << "  📢  Videojuegos con Suscripcion Activa  " << COLOR_RESET << endl;
        cout << longTab << "────────────────────────────────────────────" << endl;
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it) {
            (*it)->imprimirNombre();
        }
        cout << "\n"
             << longTab << "♦ Ingrese el nombre del Videojuego: ";
        cin >> nombre;
        if (icSuscribirseaVideojuego->ingresarNombre(nombre)){
            icCancelarSuscripcion->cancelarSuscripcion(nombre);
            DoneMessage();
        }else{
            cout << "\n"
                 << longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│  ⛔ No Existe ese Videojuego   │" << endl;
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
        }
    } else {
        cout << "\n"
             << longTab << COLOR_Y << "┌────────────────────────────────────────────────────┐" << endl;
=======
void menuCancelarSuscripcion()
{
    icCancelarSuscripcion = fabrica->getICCancelarSuscripcion();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║         ♦ Cancelar Suscripcion ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string nombre;
    list<DtJuego *> listaDtActiva = icSuscribirseaVideojuego->listarLosJuegosConSub();
    if (listaDtActiva.size() > 0 ){
        cout << "♦ Estos son sus juegos ♦ "
                << "\n"
                << endl;
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it)
        {
            (*it)->imprimirNombre();
        }
        pressEnter();
        cout << "\n"
                << "♦ Ingrese el nombre del juego del cual quiere cancelar la suscripcion: ";
        cin >> nombre;
        icCancelarSuscripcion->cancelarSuscripcion(nombre);
        DoneMessage();
        system("clear");
    } else
    {
        cout << "\n"
                << longTab << COLOR_Y << "┌────────────────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "│ 🔔 No tienes ninguna suscripcion a un videojuego   │" << endl;
        cout << longTab << "└────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
    }
}

/*---------------------------------------------------*
 *              Menu Buscar por Categoria             *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuBuscarPorCategoria() {
    system("clear");
    icBuscarPorCategoria = fabrica->getICBuscarPorCategoria();
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║        ♦ 🔍 Buscar por Categoria ♦       ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    int idCat;
    list<DtCategoria *> listaDt = icAgregarCategoria->listarDtCategorias();
    if (listaDt.size() > 0) {
        cout << "\n"
             << longTab << COLOR_BW << "  📢 Estas son las categorias del sistema  "
             << COLOR_RESET << endl;
             cout << longTab << "────────────────────────────────────────────" << endl;
        for (list<DtCategoria *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it) {
            cout << longTab << COLOR_LG << "┌────────────────────────────────────┐" << endl;
            cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
            cout << longTab << "└────────────────────────────────────┘" << COLOR_RESET << endl;
        }
        cout << "\n" << longTab << "♦ Ingrese el ID de la categoria: ";
        cin >> idCat;
        if(icBuscarPorCategoria->existeCategoria(idCat)){
            system("clear");
            Categoria* Cat = icBuscarPorCategoria->dameCategoria(idCat);
            cout << "\n" << longSpace << longTab << COLOR_BW << "      📢  Filtrados por Genero:  " << COLOR_LG << Cat->getTipoGenero() << "  " << COLOR_RESET << endl;
            cout << longTab << "────────────────────────────────────────────" << endl;
            list<DtJuego *> listaDtJuego = icBuscarPorCategoria->buscarPorCategoria(idCat);
            for (list<DtJuego *>::iterator it = listaDtJuego.begin(); it != listaDtJuego.end(); ++it) {
                (*it)->imprimirNombreDesc();
                cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
            }
            pressEnter();
            system("clear");
        }else{
            cout << "no existe esa categoria" << endl;
        }
    } else {
        cout << "\n"
             << longTab << COLOR_R << "┌───────────────────────────────────────────┐" << endl;
=======
void menuBuscarPorCategoria()
{
    icBuscarPorCategoria = fabrica->getICBuscarPorCategoria();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║         ♦ Buscar por Categoria ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝";
    int idCat;
    list<DtCategoria *> listaDt = icAgregarCategoria->listarDtCategorias();
    if (listaDt.size() > 0 ){
        cout << "\n" << longTab << "[ 📢 Estas son las categorias del sistema ]\n"
            << endl;
        for (list<DtCategoria *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
        {
            cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
            cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
            cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        }
        pressEnter();
        cout << "\n"
            << longTab << "♦ Ingrese el ID de la categoria por la cual quiera filtrar: ";
        cin >> idCat;
        list<DtJuego *> listaDtJuego = icBuscarPorCategoria->buscarPorCategoria(idCat);
        for (list<DtJuego *>::iterator it = listaDtJuego.begin(); it != listaDtJuego.end(); ++it)
        {
            (*it)->imprimirNombreDesc();
            
        }
        pressEnter();
        DoneMessage();
        system("clear");
    }else
    {
        cout << "\n"
                << longTab << COLOR_R << "┌───────────────────────────────────────────┐" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "│  ⛔ No Existen categorias en el sistema   │" << endl;
        cout << longTab << "└───────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
    }
}

/*---------------------------------------------------*
 *             Menu Ranking de Videojuegos            *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuRankingVideojuegos() {
    system("clear");
    icRankingVideojuego = fabrica->getICRankingVideojuego();
    if (icInfoJuego->hayJuegos()) {
        char cond;
        cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║          ♦ 📊 Ranking de Juegos ♦        ║" << COLOR_RESET << endl;
=======
void menuRankingVideojuegos()
{
    icRankingVideojuego = fabrica->getICRankingVideojuego();
    system("clear");
     if (icInfoJuego->hayJuegos()){
        char cond;
        cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║           ♦ Ranking de Juegos ♦          ║" << COLOR_RESET << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "╚══════════════════════════════════════════╝\n";
        cout << longTab << "┌──────────────────────────────────────────┐" << endl;
        cout << longTab << "│             Ordenar Ranking              │" << endl;
        cout << longTab << "├──────────────────────────────────────────┤\n";
        cout << longTab << "│                                          │\n";
        cout << longTab << "│              1. Puntuacion               │\n";
        cout << longTab << "│                                          │\n";
        cout << longTab << "│              0. Horas Jugadas            │\n";
        cout << longTab << "│                                          │\n";
        cout << longTab << "└──────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> cond;
<<<<<<< HEAD
        switch (cond) {
            case '1': {
                system("clear");
                cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
                cout << longTab << COLOR_SB << "║           ♦ Ranking de Juegos ♦          ║" << COLOR_RESET << endl;
                cout << longTab << "╚══════════════════════════════════════════╝\n";
                cout << "\n" << longTab << COLOR_BW << "         📢  Filtrado por: " << COLOR_LG << "Puntuacion" << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
                list<DtJuego *> listaDt = icRankingVideojuego->listarPorPuntaje();
                for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it) {
                    (*it)->imprimirNomPuntajeHorasP();
                    cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
                }
                pressEnter();
                system("clear");
            } break;
            case '0': {
                system("clear");
                cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
                cout << longTab << COLOR_SB << "║           ♦ Ranking de Juegos ♦          ║" << COLOR_RESET << endl;
                cout << longTab << "╚══════════════════════════════════════════╝\n";
                cout << "\n" << longTab << COLOR_BW << "      📢  Filtrado por: " << COLOR_LG << "Horas Jugadas" << COLOR_RESET << endl;
                cout << longTab << "────────────────────────────────────────────" << endl;
                list<DtJuego *> listaDt = icRankingVideojuego->listarPorDuracion();
                for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it) {
                    (*it)->imprimirNomPuntajeHorasH();
                    cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
                }
                pressEnter();
                system("clear");
            } break;
        }
    } else {
=======
        switch (cond)
        {
        case '1':
        {
            list<DtJuego *> listaDt = icRankingVideojuego->listarPorPuntaje();
            for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
            {
                (*it)->imprimirNomPuntajeHorasP();
            }
            pressEnter();
            DoneMessage();
            system("clear");
        }
        break;
        case '0':
        {
            list<DtJuego *> listaDt = icRankingVideojuego->listarPorDuracion();
            for (list<DtJuego *>::iterator it = listaDt.begin(); it != listaDt.end(); ++it)
            {
                (*it)->imprimirNomPuntajeHorasH();
            }
            pressEnter();
            DoneMessage();
            system("clear");
        }
        break;
        }
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
        system("clear");
    }
}

/*---------------------------------------------------*
 *         Menu Ver Partidas de un Videojuego        *
 *----------------------------------------------------*/

<<<<<<< HEAD
void menuVerPartidas() {
    system("clear");
    icVerPartidas = fabrica->getICVerPartidas();
    if (icInfoJuego->hayJuegos()) {
        cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║       ♦ 👁  Ver Partidas de un Juego ♦    ║" << COLOR_RESET << endl;
        cout << longTab << "╚══════════════════════════════════════════╝\n";
        DtPartida *dtP;
        string nombre;
        cout << "\n"
             << longTab << COLOR_BW << "  📢  Videojuegos Ingresados en el Sistema  "
             << COLOR_RESET << endl;
             cout << longTab << "────────────────────────────────────────────" << endl;
        list<DtJuego *> listaDtActiva = icVerPartidas->listarLosJuegos();
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it) {
            (*it)->imprimirNombreDesc();
            cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
        }
        cout << "\n"
            << longTab << "♦ Ingrese el nombre del Videojuego: ";
        cin >> nombre;
        if (icVerPartidas->checkVideojuego(nombre)) {
            system("clear");
            list<DtPartida *> lista = icVerPartidas->verPartidas(nombre);
            if(lista.size() > 0){
                for (list<DtPartida *>::iterator it = lista.begin(); it != lista.end(); ++it) {
                    DtPartidaIndi *pI = dynamic_cast<DtPartidaIndi *>((*it));
                    if (pI != NULL) {
                        cout << "\n"
                        << longTab << COLOR_BW << "      📢  Detalles Partida Individual       "
                        << COLOR_RESET << endl;
                        cout << longTab << "────────────────────────────────────────────" << endl;
                        pI->imprimirIndi();
                        cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
                    } else {
                        DtPartidaMulti *pM = dynamic_cast<DtPartidaMulti *>((*it));
                        if (pM != NULL) {
                            cout << "\n"
                            << longTab << COLOR_BW << "      📢  Detalles Partida Multijugador     "
                            << COLOR_RESET << endl;
                            cout << longTab << "────────────────────────────────────────────" << endl;
                            pM->imprimirMulti();
                            cout << longTab << COLOR_LG << "────────────────────────────────────────────" << COLOR_RESET << endl;
                        }
                    }
                }
                pressEnter();
                system("clear");
            }else{
                cout << "\n"
                 << longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│   ⛔ No hay partidas asocidas  │" << endl;
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
            system("clear");
            }
        } else {
            cout << "\n"
                 << longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│   ⛔ No existe el videojuego   │" << endl;
=======
void menuVerPartidas()
{
    icVerPartidas = fabrica->getICVerPartidas();
    system("clear");
    if (icInfoJuego->hayJuegos()){
        cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║       ♦ Ver Partidas de un Juego ♦       ║" << COLOR_RESET << endl;
        cout << longTab << "╚══════════════════════════════════════════╝";
        DtPartida *dtP;
        string nombre;
        cout << "\n" << longTab << "[ 📢 Videojuegos Ingresados en el Sistema ]\n"
            << endl;

        list<DtJuego *> listaDtActiva = icVerPartidas->listarLosJuegos();
        for (list<DtJuego *>::iterator it = listaDtActiva.begin(); it != listaDtActiva.end(); ++it)
        {
            (*it)->imprimirNombreDesc();
        }
        pressEnter();
        cout << "\n"
            << longTab << "♦ Ingrese el nombre del juego del cual quiere ver las partidas: ";
        cin >> nombre;
        if(icVerPartidas->checkVideojuego(nombre)){ 
            list<DtPartida *> lista = icVerPartidas->verPartidas(nombre);
            for (list<DtPartida *>::iterator it = lista.begin(); it != lista.end(); ++it)
            {
                DtPartidaIndi *pI = dynamic_cast<DtPartidaIndi *>((*it));
                if (pI != NULL)
                {
                    pI->imprimirIndi();
                    pressEnter();
                }
                else
                {
                    DtPartidaMulti *pM = dynamic_cast<DtPartidaMulti *>((*it));
                    if (pM != NULL)
                    {
                        pM->imprimirMulti();
                        pressEnter();
                    }
                }
            }
                DoneMessage();
                system("clear");
        }else{
            cout << "\n"<< longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│  ⛔ No hay Partidas asociadas  │" << endl;
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
            system("clear");
        }
<<<<<<< HEAD
    } else {
=======
    }
    else
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        WarningMessage();
        system("clear");
    }
}

/*------------------------------------------*
 *                 Exit Screen               *
 *-------------------------------------------*/

void exit() {
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

<<<<<<< HEAD
void statusBar() {
=======
void statusBar()
{
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    system("clear");
    cout << longSpace << longTab << BG_GRAY << "                                       ➖ 🔲 ❌ " << COLOR_RESET << endl;
    time_t now = time(0);           // current date and time on the current system
    char *date_time = ctime(&now);  // convert now to string form
    cout << longTab << BG_BLACK << COLOR_LG << "⦿ Online                " << date_time << COLOR_RESET;
    cout << longTab << COLOR_G << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░░█▀▀░▄▀█░█▀▄▀█░█▀▀░█░░░▄▀█░█▄ █░█▀▄░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░░█▄█░█▀█░█░▀░█░██▄░█▄▄░█▀█░█░▀█░█▄▀░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_P << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
}

/********** Menu Principal (Consola) **********/

<<<<<<< HEAD
bool menuPlayer() {
    char opcion;
    bool entro = false, aux;
    do {
=======
bool menuPlayer()
{
    system("clear");
    int opcion;
    bool entro = false, aux;
    do
    {
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        statusBar();
        cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
        cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
        cout << longTab << COLOR_SB << "║                   [Player]                   ║" << COLOR_RESET << endl;
        cout << longTab << "╠══════════════════════════════════════════════╣\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     1) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
<<<<<<< HEAD
        cout << longTab << "║     2) 🔴 Suscribirse a Videojuego           ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Iniciar Partida                    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Ver Información de Videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🟡 Asignar Puntaje a Videojuego       ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🟡 Cancelar Suscripción a Videojuego  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Buscar Videojuego por Categoría    ║\n";
=======
        cout << longTab << "║     2) 🔴 Suscribirse a videojuego           ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Iniciar Partida                    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Ver información de videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🟡 Asignar puntaje a videojuego       ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🟡 Cancelar suscripción a videojuego  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Buscar videojuego por categoría    ║\n";
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     0) 🚪 Salir                              ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> opcion;
        bool data = true;
<<<<<<< HEAD
        switch (opcion) {
            case '1':
                aux = menuCerrarSesion();
                if (aux) {
                    entro = true;
                    return entro;
                }
                break;
            case '2':
                menuSuscribirseAVideojuego();
                break;
            case '3':
                menuIniciarPartida();
                break;
            case '4':
                menuVerInfoVideojuego();
                break;
            case '5':
                menuAsignarPuntaje();
                break;
            case '6':
                menuCancelarSuscripcion();
                break;
            case '7':
                menuBuscarPorCategoria();
                break;
        }
    } while (opcion != '0' );
    return entro;
}

bool menuDev() {
    char opcion;
    bool entro = false, aux;
    do {
        statusBar();
        cout << longTab << "╔══════════════════════════════════════════════╗" << endl;
        cout << longTab << COLOR_SB << "║              ♦ MENU PRINCIPAL ♦              ║" << COLOR_RESET << endl;
        cout << longTab << COLOR_SB << "║                  [Developer]                 ║" << COLOR_RESET << endl;
        cout << longTab << "╠══════════════════════════════════════════════╣\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     1) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     2) 🔴 Agregar Categoría                  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Agregar Videojuego                 ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Ver Información de Videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🔴 Eliminar Videojuego                ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🟡 Buscar Videojuego por Categoría    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Ranking de Videojuegos             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     8) 🟡 Ver Partidas de un Videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     0) 🚪 Salir                              ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> opcion;
        switch (opcion) {
            case '1':
                aux = menuCerrarSesion();
                if (aux) {
                    entro = true;
                    return entro;
                }
                break;
            case '2':
                menuAgregarCategoria();
                break;
            case '3':
                menuAgregarVideojuego();
                break;
            case '4':
                menuVerInfoVideojuego();
                break;
            case '5':
                menuEliminarVideojuego();
                break;
            case '6':
                menuBuscarPorCategoria();
                break;
            case '7':
                menuRankingVideojuegos();
                break;
            case '8':
                menuVerPartidas();
                break;
        }
    } while (opcion != '0');
    return entro;
}

/********** Logica del Menu Principal **********/

int main() {
    cargarFabrica();
    welcomeBanner();
    menuDisplay();
    bool x;
    bool datos;
    datos = menuIniciarSesion1();
    do {
        do {
            if (datos == true) {
                menuIniciarSesion2();
            } else {
                datos = menuIniciarSesion1();
            }
        } while ((icIniciarSesion->signUp() == false) || (icAltaUsuario->hayUsuarios() == false));

        if (icIniciarSesion->usuarioConectado()) {
            x = menuDev();
        } else {
            x = menuPlayer();
        }
=======
        switch (opcion)
        {
        case 1:
            aux = menuCerrarSesion();
            if (aux)
            {
                entro = true;
                return entro;
            }
            break;
        case 2:
            menuSuscribirseAVideojuego();
            break;
        case 3:
            menuIniciarPartida();
            break;
        case 4:
            menuVerInfoVideojuego();
            break;
        case 5:
            menuAsignarPuntaje();
            break;
        case 6:
            menuCancelarSuscripcion();
            break;
        case 7:
            menuBuscarPorCategoria();
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
        cout << longTab << "║     1) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     2) 🔴 Agregar Categoría                  ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     3) 🔴 Agregar Videojuego                 ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     4) 🔴 Ver información de videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     5) 🔴 Eliminar videojuego                ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     6) 🟡 Buscar videojuego por categoría    ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     7) 🟡 Ranking de videojuegos             ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     8) 🟡 Ver partidas de un videojuego      ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "║     0) 🚪 Salir                              ║\n";
        cout << longTab << "║                                              ║\n";
        cout << longTab << "╚══════════════════════════════════════════════╝" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            aux = menuCerrarSesion();
            if (aux)
            {
                entro = true;
                return entro;
            }
            break;
        case 2:
            menuAgregarCategoria();
            break;
        case 3:
            menuAgregarVideojuego();
            break;
        case 4:
            menuVerInfoVideojuego();
            break;
        case 5:
            menuEliminarVideojuego();
            break;
        case 6:
            menuBuscarPorCategoria();
            break;
        case 7:
            menuRankingVideojuegos();
            break;
        case 8:
            menuVerPartidas();
            break;
        }
    } while (opcion != 0);
    return entro;
}

/********** Logica del Menu Principal **********/

int main()
{
    cargarFabrica();
    welcomeBanner();
    menuDisplay(); 
    bool x;
    bool datos;
    datos = menuIniciarSesion1();
    do
    {
        do
        {
            if(datos == true){
                menuIniciarSesion2();
            }else{
               datos = menuIniciarSesion1();
            }
        } while ((icIniciarSesion->signUp() == false) || (icAltaUsuario->hayUsuarios() == false));

        if (icIniciarSesion->usuarioConectado())
        {
            x = menuDev();
        }
        else
        {
            x = menuPlayer();
        }
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
    } while (x == true);

    exit();
}