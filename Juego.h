#ifndef JUEGO
#define JUEGO

#include <iostream>
#include "Definiciones.h"
#include "TipoGenero.h"
#include "DtJuego.h"
#include "Partida.h"

using namespace std;

class Juego{
    private:
        string nombre;
        string descripcion;
        int puntaje;            // Calcular puntaje promedio
        int totalPartidas;      // Calcular total horas juegos
        int topePartidaVJ = 0;
        Partida* partidas[MAX_PARTIDAS]; 
    public:
        Juego();
        Juego(string nombre, string descripcion, int puntaje, int totalPartidas);
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setPuntaje(int puntaje);
        void setTotalPartidas(int totalPartidas);
        string getNombre();
        string getDescripcion();
        int getPuntaje();
        int getTotalPartidas();
        int getTopePartidaVJ();
        DtJuego* getDtVideoJuego();
        Partida** getPartida(int& cantidadPartidas);
        void addPartida(Partida* p);    // Se debe aplicar un Manejador
        ~Juego();
};

#endif