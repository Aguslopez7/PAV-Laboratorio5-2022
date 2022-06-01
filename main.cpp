#include <unistd.h>

#include <ctime>
#include <iostream>

#include "Definiciones.h"
#include "DtJugador.h"
#include "DtFechaHora.h"
#include "DtPartidaIndividual.h"
#include "DtPartidaMultijugador.h"
#include "DtPartida.h"
#include "Juego.h"
#include "Jugador.h"
#include "Sistema.h"
#include "TipoGenero.h"

using namespace std;

string longTab = "";
string longSpace = "";
string msg;             // mensaje - menuCargarPartida
float progress;         // tiempo de carga - closeBar

Sistema* sistema;
DtPartida* datos;

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

void closeBar(float progress) {
    float progressBar = 0;
    cout << "\n" << longTab << COLOR_BW << "\t\t   LOADING..." << COLOR_RESET << endl;
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

void welcomeBanner() {
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
    cout << longTab << COLOR_LG << "\t\t\t\t     Version 1.0" << COLOR_RESET << endl;
    loadBar();
}

/********** Menu Custom Display **********/

void menuCustomDisplay() {
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

void menuDisplay() {
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
    switch (type) {
        case 1:
            longTab = "";
            longSpace = "";
            break;
        case 2:
            longTab = "\t\t\t\t\t\t\t\t\t\t\t";
            longSpace = "\n\n\n\n\n\n\n\n\n\n";
            break;
        case 3: {
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
                            sleep(1);
                        } else if (longSpace.length() == 1) {
                            longSpace = "";
                        } else {
                            longSpace.erase(longSpace.length() - 2);  // removes last 2 characters;
                        }
                        break;
                    case 2:
                        longSpace.append(addSpace);
                        break;
                    case 3:
                        if (longTab.length() <= 0) {
                            cout << "\n"
                                 << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                            cout << longTab << "│ 🔔 Has Alcanzado el Limite de la Pantalla! │" << endl;
                            cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                            sleep(1);
                        } else if (longTab.length() == 1) {
                            longTab = "";
                        } else {
                            longTab.erase(longTab.length() - 2);  // removes last 2 characters
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

void initialization() {
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

/***************************************************
*                                                  *
*              Operaciones Principales             *
*                                                  *
***************************************************/

/*-------------------------------------------------*
*              0) Menu Agregar Datos               *
*--------------------------------------------------*/

void menuCargarDatos() {
    sistema->cargarDatosPredeterminados();
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
*              1) Menu Agregar Jugador               *
*----------------------------------------------------*/

void menuAgregarJugador() {
    system("clear");
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 👤 Agregar Jugador ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
    string nickname;
    int edad, password;
    cout << longTab << "♦ NickName: ";
    cin >> nickname;
    cout << longTab << "♦ Edad: ";
    cin >> edad;
    cout << longTab << "♦ Password: ";
    cin >> password;
    try {
        sistema->agregarJugador(password, edad, nickname);
    } catch (invalid_argument& e) {
        cout << "\n"
             << longTab << COLOR_Y << "┌─────────────────────────────────────────┐" << endl;
        cout << longTab << e.what() << endl;
        cout << longTab << "└─────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2");
    }
}

/*------------------------------------------------------*
*              2) Menu Agregar Videojuego               *
*-------------------------------------------------------*/

void menuAgregarVideojuego() {
    system("clear");
    TipoGenero genero;
    string nombre;
    string descripcion; 
    int puntaje; 
    int totalPartidas;
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ 👾 Agregar Videojuego ♦        ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
    cout << longTab << "♦ Nombre: ";
    cin >> nombre;
    cout << longTab << "┌────────────────────────────────────────────┐" << endl;
    cout << longTab << "│              Selecciona Genero             │" << endl;
    cout << longTab << "├────────────────────────────────────────────┤\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│               1. 💥 ACCION                 │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│               2. 💎 AVENTURA               │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│               3. ⚽ DEPORTE                │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "│               4. 🔰 OTRO                   │\n";
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    int type;
    cin >> type;
    switch (type) {
        case 1:
            genero = ACCION;
            break;
        case 2:
            genero = AVENTURA;
            break;
        case 3:
            genero = DEPORTE;
            break;
        case 4:
            genero = OTRO;
            break;
    }
    try {
        sistema->agregarVideoJuego(nombre, descripcion, puntaje, totalPartidas);
    } catch (invalid_argument& e) {
        cout << "\n"
             << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
        cout << longTab << e.what() << endl;
        cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2");
    }
}

/*-----------------------------------------------------*
*              3) Menu Obtener Jugadores               *
*------------------------------------------------------*/

void menuObtenerJugadores() {
    system("clear");
    cout << longSpace << longTab << "╔═════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║ 👥 Listado de Jugadores Registrados ║" << COLOR_RESET << endl;
    cout << longTab << "╚═════════════════════════════════════╝" << endl;
    int cantJ = sistema->getTopeJugadores();
    DtJugador** losJugadores = sistema->obtenerJugadores(cantJ);
    for (int i = 0; i < cantJ; i++) {
        cout << longTab << COLOR_LG << "┌─────────────────────────────────────┐" << endl;
        cout << longTab << "│ ❯ Player #" << i + 1 << "\t\t     ⦿ Online │" << endl;
        cout << longTab << "└─────────────────────────────────────┘" << COLOR_RESET << endl;
        cout << *losJugadores[i] << endl;
    }
    if (cantJ >= 1) {
        cout << longTab << COLOR_P << "┌─────────────────────────────────────┐" << endl;
        cout << longTab << "│         📢 Fin del Listado!         │" << endl;
        cout << longTab << "└─────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 5");
    } else {
        cout << longTab << COLOR_Y << "┌─────────────────────────────────────┐" << endl;
        cout << longTab << "│  🔔 No Hay Jugadores Registrados!   │" << endl;
        cout << longTab << "└─────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2");
    }
}

/*-------------------------------------------------------*
*              4) Menu Obtener Videojuegos               *
*--------------------------------------------------------*/

void menuObtenerVideoJuegos() {
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║ 🎮 Listado de Videouegos Registrados ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════╝" << endl;
    int cantVJ = sistema->getTopeJuegos();
    DtJuego** losVideoJuegos = sistema->obtenerVideoJuegos(cantVJ);
    for (int i = 0; i < cantVJ; i++) {
        cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
        cout << longTab << "│ ❯ Game #" << i + 1 << "\t\t\t       │" << endl;
        cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        cout << *losVideoJuegos[i] << endl;
    }
    if (cantVJ >= 1) {
        cout << longTab << COLOR_P << "┌──────────────────────────────────────┐" << endl;
        cout << longTab << "│          📢 Fin del Listado!         │" << endl;
        cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 5");
    } else {
        cout << longTab << COLOR_Y << "┌──────────────────────────────────────┐" << endl;
        cout << longTab << "│  🔔 No Hay Videojuegos Registrados!  │" << endl;
        cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2");
    }
}

/********** Menu Tipo de Partida **********/

void menuTipoDePartida() {
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

void menuCargarPartida(string msg) {
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

/*---------------------------------------------------*
*              5) Menu Obtener Partida               *
*----------------------------------------------------*/

void menuObtenerPartidas() {
    system("clear");
    cout << "╔═════════════════════════════════════════════╗\n";
    cout << COLOR_SB << "║           ♦ 🎯 Obtener Partidas: ♦          ║" << COLOR_RESET << endl;
    cout << "╚═════════════════════════════════════════════╝\n";
    string nombre;
    int cantPartidas=0;
    cout << "♦ Nombre del VideoJuego: ";
    cin >> nombre;  
    try {
        cout << "\n" << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
        cout << longTab << "│ ❯ Detalles  " << "\t\t\t       │" << endl;
        cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        DtPartida** lasPartida = sistema->obtenerPartidas(nombre, cantPartidas);
        cout << **lasPartida << endl;
        system("sleep 5");
    } catch (invalid_argument& e) {
        cout << "\n"
        << longTab << COLOR_R << "┌───────────────────────────────────────────────────────────────┐" << endl;
        cout << longTab << e.what() << endl;
        cout << longTab << "│                                                               │" << endl;
        cout << longTab << "│ ⛔ [ERROR] No Es Posible Iniciar una Partida.                 │" << endl;
        cout << longTab << "└───────────────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 3");
    }
}

/*---------------------------------------------------*
*              6) Menu Iniciar Partida               *
*----------------------------------------------------*/

void menuIniciarPartida() {   
    system("clear");
    DtFechaHora* f1 = new DtFechaHora(12,5,1993,16,37);
    int duracion = 15;
    int maxp = 50;
    bool tf = true;
    cout << "╔════════════════════════════════════════════╗\n";
    cout << COLOR_SB << "║           ♦ 🎯 Iniciar Partidas ♦          ║" << COLOR_RESET << endl;
    cout << "╚════════════════════════════════════════════╝\n";
    string nickname, nombre;
    cout << "♦ NickName: ";
    cin >> nickname;
    cout << "♦ Nombre del VideoJuego: ";
    cin>> nombre;
    int tipo;
    menuTipoDePartida();
    cin >> tipo;
    while (tipo != 1 && tipo != 2) {
        menuTipoDePartida();
        cin >> tipo;
    }
    switch (tipo) {
        case 1:
            datos = new DtPartidaIndividual(f1, duracion, tf);
            //datos = new DtPartida(f1, duracion);
            try {
                sistema->iniciarPartida(nickname, nombre, datos);
                msg = "\t💾 Cargando Archivos Locales...";
                menuCargarPartida(msg);
            } catch (invalid_argument& e) {
                cout << "\n"
                << longTab << COLOR_R << "┌───────────────────────────────────────────────────────────────┐" << endl;
                cout << longTab << e.what() << endl;
                cout << longTab << "│                                                               │" << endl;
                cout << longTab << "│ ⛔ [ERROR] No Es Posible Iniciar una Partida.                 │" << endl;
                cout << longTab << "└───────────────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 3");
            }           
        break;
        case 2:
            datos = new DtPartidaMultijugador(f1, duracion, tf, maxp); 
            //datos = new DtPartida(f1, duracion); 
            try {
                sistema->iniciarPartida(nickname, nombre, datos);
                msg = "\t📡 Conectando con el Servidor...";
                menuCargarPartida(msg);
            } catch (invalid_argument& e) {
                cout << "\n"
                << longTab << COLOR_R << "┌───────────────────────────────────────────────────────────────┐" << endl;
                cout << longTab << e.what() << endl;
                cout << longTab << "│                                                               │" << endl;
                cout << longTab << "│ ⛔ [ERROR] No Es Posible Iniciar una Partida.                 │" << endl;
                cout << longTab << "└───────────────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 3");
            }           
        break;
    }
}

/*------------------------------------------*
*              7) Exit Screen               *
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

void statusBar() {
    cout << longSpace << longTab << BG_GRAY << "                                     ➖ 🔲 ❌ " << COLOR_RESET << endl;
    time_t now = time(0);           // current date and time on the current system
    char* date_time = ctime(&now);  // convert now to string form
    cout << longTab << BG_BLACK << COLOR_LG << "⦿ Online              " << date_time << COLOR_RESET;
    cout << longTab << COLOR_G << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░█▀▀░▄▀█░█▀▄▀█░█▀▀░█░░░▄▀█░█▄ █░█▀▄░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_SB << "░░░░░░█▄█░█▀█░█░▀░█░██▄░█▄▄░█▀█░█░▀█░█▄▀░░░░░░" << COLOR_RESET << endl;
    cout << longTab << COLOR_P << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << COLOR_RESET << endl;
}

/********** Menu Principal (Consola) **********/

void menu() {
    system("clear");
    statusBar();
    cout << longTab << "╔════════════════════════════════════════════╗" << endl;
    cout << longTab << COLOR_SB << "║             ♦ MENU PRINCIPAL ♦             ║" << COLOR_RESET << endl;
    cout << longTab << "╠════════════════════════════════════════════╣\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     0) 🎲 Cargar Datos de Prueba           ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     1) 👤 Agregar Jugador                  ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     2) 👾 Agregar Videojuego               ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     3) 👥 Obtener jugadores                ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     4) 🎮 Obtener Videojuegos              ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     5) 🕹️  Obtener Partidas                 ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     6) 🎯 Iniciar Partidas                 ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "║     7) Salir                               ║\n";
    cout << longTab << "║                                            ║\n";
    cout << longTab << "╚════════════════════════════════════════════╝" << endl;
    cout << longTab << "❯ Opción: ";
}

/********** Logica del Menu Principal **********/

int main() {
    sistema = new Sistema();
    /*welcomeBanner();
    menuDisplay();
    initialization();*/
    menu();
    bool data = true;
    int opcion;
    cin >> opcion;
    while (opcion != 7) {
        switch (opcion) {
            case 0:
                if (data) {
                    menuCargarDatos();
                    data = false;
                } else {
                    cout << "\n"
                         << longTab << COLOR_Y << "┌────────────────────────────────────────────┐" << endl;
                    cout << longTab << "│   🔔 Ya Has Cargado los Datos de Prueba!   │" << endl;
                    cout << longTab << "└────────────────────────────────────────────┘" << COLOR_RESET << endl;
                    system("sleep 2");
                }
                break;
            case 1:
                menuAgregarJugador();
                break;
            case 2:
                menuAgregarVideojuego();
                break;
            case 3:
                menuObtenerJugadores();
                break;
            case 4:
                menuObtenerVideoJuegos();
                break;
            case 5:
                menuObtenerPartidas();
                break;
            case 6:
                menuIniciarPartida();
                break;
        }
        menu();
        cin >> opcion;
    }
    exit();
}