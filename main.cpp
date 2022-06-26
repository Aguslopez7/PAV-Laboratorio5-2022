#include <ctime>
#include <iostream>
#include <string>
#include <list>

#include "Fabrica.h"
#include "Definiciones.h"
#include "DtFechaHora.h"
#include "DtPartida.h"
#include "DtPartidaIndi.h"
#include "DtPartidaMulti.h"
#include "DtCategoria.h"
#include "Categoria.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Juego.h"
#include "Jugador.h"
#include "TipoPago.h"
#include "Estadistica.h"
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
ICEliminarVideojuego *icEliminarVideojuego;
ICAsignarPuntaje *icAsignarPuntaje;
ICCancelarSuscripcion *icCancelarSuscripcion;
ICBuscarPorCategoria *icBuscarPorCategoria;
ICRankingVideojuego *icRankingVideojuego;
ICVerPartidas *icVerPartidas;

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
    icEliminarVideojuego = fabrica->getICEliminarVideojuego();
    icAsignarPuntaje = fabrica->getICAsignarPuntaje();
    icCancelarSuscripcion = fabrica->getICCancelarSuscripcion();
    icBuscarPorCategoria = fabrica->getICBuscarPorCategoria();
    icRankingVideojuego = fabrica->getICRankingVideojuego();
    icVerPartidas = fabrica->getICVerPartidas();
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

/********** Welcome Banner **********/

void welcomeBanner()
{
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

void menuCustomDisplay()
{
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

void menuDisplay()
{
    system("clear");
    longTab = "\t\t\t\t\t\t\t\t\t\t\t";
    cout << longSpace << longTab << "╔═══════════════════════════╗" << endl;
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
    system("sleep 2.5");
}

// No Existen Viedeojuegos
void WarningMessage()
{
    cout << "\n"
         << longTab << COLOR_Y << "┌──────────────────────────────────────────┐" << endl;
    cout << longTab << "│  🔔 No Existen Videojuegos en el Sitema  │" << endl;
    cout << longTab << "└──────────────────────────────────────────┘" << COLOR_RESET << endl;
    system("sleep 2.5");
}

void menuCargarPartida()
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

bool menuCargarDatos()
{
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
    cout << longTab << "│                                            │\n"; //✅✅🔁
    cout << longTab << "│                                            │\n";
    cout << longTab << "└────────────────────────────────────────────┘" << endl;
    cout << longTab << "❯ Opción: ";
    cin >> valor;
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
void pressEnter(){  
    std::ios_base::sync_with_stdio(false);
    std::cin.ignore(std::cin.rdbuf()->in_avail());
    cout << "\n" << longTab << COLOR_P << "┌────────────────────────────────────┐" << endl;
    cout << longTab << "│  📢 Presiona Enter para continuar  │" << endl;
    cout << longTab << "└────────────────────────────────────┘" << COLOR_RESET << endl;
    std::cin.ignore();
}

void mostrarDatosDePrueba(){
    system("clear");
    string salida;
    cout << longSpace << longTab << "╔════════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Datos Predefinidos ♦           ║" << COLOR_RESET << endl;
    cout << longTab << "╚════════════════════════════════════════════╝\n";
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
    pressEnter();
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
    string nomEmp = "";
    char num, num2;
    cout << longTab << "♦ Ingrese su Email: ";
    cin >> email;
    if (!(icAltaUsuario->checkUser(email)))
    {
        cout << longTab << "♦ Ingrese su Password: ";
        cin >> pass;
        icAltaUsuario->datosComunes(email, pass);
        system("clear");
        cout << longTab << "┌────────────────────────────────────────────┐" << endl;
        cout << longTab << "│               Seleccione Rol               │" << endl;
        cout << longTab << "├────────────────────────────────────────────┤\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│             1. 🔧 Desarrollador            │\n";
        cout << longTab << "│                                            │\n";
        cout << longTab << "│             2. 🎮 Jugador                  │\n";
        cout << longTab << "│                                            │\n"; 
        cout << longTab << "│                                            │\n";
        cout << longTab << "└────────────────────────────────────────────┘" << endl;
        cout << longTab << "❯ Opción: ";
        cin >> num;
        bool cond = true;
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
    }
}

/*------------------------------------------------------*
 *                 Menu Iniciar Sesion 1                 *
 *-------------------------------------------------------*/

bool menuIniciarSesion1()
{
    icIniciarSesion = fabrica->getICIniciarSesion();
    system("clear");
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
    }
}

/*-----------------------------------------------------*
 *               Menu Cerrar Sesion                     *
 *------------------------------------------------------*/

bool menuCerrarSesion()
{
    icCerrarSesion = fabrica->getICCerrarSesion();
    system("clear");
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
    }
    return retorno;
}

/*-------------------------------------------------------*
 *               Menu Agregar Categoria                   *
 *--------------------------------------------------------*/

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
            cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
            cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
            cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
        }
        pressEnter();
    }
    cout << longTab << "♦ Ingrese una breve descripcion: ";
    cin >> desc;
    cout << longTab << "♦ Ingrese su genero: ";
    cin >> genero;
    cout << longTab << "♦ Ingrese la plataforma: ";
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
    int costo = 0, x = 2, id = 0;
    char cond;
    string nombre, desc;
    cout << longTab << "♦ Ingrese el nombre del videojuego: ";
    cin >> nombre;
    cout << longTab << "♦ Ingrese la descripcion del videojuego: ";
    cin >> desc;
    cout << longTab << "♦ Ingrese el costo de la suscripcion: ";
    cin >> costo;
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
                cout << longTab << COLOR_LG << "┌──────────────────────────────────────┐" << endl;
                cout << longTab << "│ ❯ #id: " << (*it)->getId() << " -> " << (*it)->getGenero() << " / " << (*it)->getPlataforma() << endl;
                cout << longTab << "└──────────────────────────────────────┘" << COLOR_RESET << endl;
            }
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

void menuIniciarPartida()
{
    icIniciarPartida = fabrica->getICIniciarPartida();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║           ♦ Iniciar Partida ♦            ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝";
    char cond;
    string nom;
    bool cont = false;
    int cond2, dur, jug;
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
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *            Menu Suscribirse a Videojuego           *
 *----------------------------------------------------*/

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
                cout << "\n"
                     << longTab << COLOR_Y << "┌─────────────────────────────────────────────────┐" << endl;
                cout << longTab << "│   🔔 Ya se encuentra Suscripto al Videojuego!   │" << endl;
                cout << longTab << "└─────────────────────────────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2.5");
            }
        }
        else
        {
            cout << "\n"
                 << longTab << COLOR_R << "┌────────────────────────────────┐" << endl;
            cout << longTab << "│  ⛔ No Existe ese Videojuego   │" << endl;
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
        }
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
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *               Menu Eliminar Videojuego             *
 *----------------------------------------------------*/

void menuEliminarVideojuego()
{
    icEliminarVideojuego = fabrica->getICEliminarVideojuego();
    system("clear");
    cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
    cout << longTab << COLOR_SB << "║          ♦ Eliminar Videojuego ♦         ║" << COLOR_RESET << endl;
    cout << longTab << "╚══════════════════════════════════════════╝\n";
    string nombre;
    char cond;
    Sesion *s = Sesion::getInstancia();
    Usuario *u = s->getUsuario();
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
        WarningMessage();
    }
}

/*---------------------------------------------------*
 *               Menu Asignar Puntaje                 *
 *----------------------------------------------------*/

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
            if ((puntaje <= 5) && (puntaje >= 1))
            {
                icAsignarPuntaje->asignarPuntaje(nombre, puntaje);
                DoneMessage();
                system("clear");
                cond = false;
            }
            else
            {
                cout << COLOR_R << "┌──────────────────────────┐" << endl;
                cout << "│  ⛔ Puntaje Inapropiado  |" << endl;
                cout << longTab << "└──────────────────────────┘" << COLOR_RESET << endl;
                system("sleep 2.5");
                system("clear");
                cond = true;
            }
        } while (cond == true);
    }
    else
    {
        WarningMessage();
        system("clear");
    }
}

/*---------------------------------------------------*
 *              Menu Cancelar Suscripcion             *
 *----------------------------------------------------*/

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
        cout << longTab << "│ 🔔 No tienes ninguna suscripcion a un videojuego   │" << endl;
        cout << longTab << "└────────────────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
    }
}

/*---------------------------------------------------*
 *              Menu Buscar por Categoria             *
 *----------------------------------------------------*/

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
        cout << longTab << "│  ⛔ No Existen categorias en el sistema   │" << endl;
        cout << longTab << "└───────────────────────────────────────────┘" << COLOR_RESET << endl;
        system("sleep 2.5");
        system("clear");
    }
}

/*---------------------------------------------------*
 *             Menu Ranking de Videojuegos            *
 *----------------------------------------------------*/

void menuRankingVideojuegos()
{
    icRankingVideojuego = fabrica->getICRankingVideojuego();
    system("clear");
     if (icInfoJuego->hayJuegos()){
        char cond;
        cout << longSpace << longTab << "╔══════════════════════════════════════════╗\n";
        cout << longTab << COLOR_SB << "║           ♦ Ranking de Juegos ♦          ║" << COLOR_RESET << endl;
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
        WarningMessage();
        system("clear");
    }
}

/*---------------------------------------------------*
 *         Menu Ver Partidas de un Videojuego        *
 *----------------------------------------------------*/

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
            cout << longTab << "└────────────────────────────────┘" << COLOR_RESET << endl;
            system("sleep 2.5");
            system("clear");
        }
    }
    else
    {
        WarningMessage();
        system("clear");
    }
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
    system("clear");
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
        cout << longTab << "║     1) 🔴 Cerrar Sesion                      ║\n";
        cout << longTab << "║                                              ║\n";
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
    } while (x == true);

    exit();
}