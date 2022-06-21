#ifndef JUEGO
#define JUEGO

#include <iostream>
#include <list>
#include "Definiciones.h"
#include "DtJuego.h"
#include "DtCategoria.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Desarrollador.h"
#include "Categoria.h"
#include "Estadistica.h"
#include "Suscripcion.h"

using namespace std;

class Juego{
    private:
        string nombre;
        string descripcion;
        int costo;
        Desarrollador* dev;
        list<DtCategoria*> categorias;
        list<Partida*> partidas;
        list<Estadistica*> estadisticas;
        list<Suscripcion*> sub;
    public:
        Juego();
        Juego(string nombre, string descripcion,int costo, Desarrollador* dev, list<DtCategoria*> categorias);
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setDesarrollador(Desarrollador* dev);
        string getNombre();
        string getDescripcion();
        int getCosto();
        Desarrollador* getDesarrollador();
        list<DtCategoria*> getCategorias();   
        DtJuego* getDtVideojuego(); 
        bool tengoSuscripcionJugador(Jugador* jugador);
        void agregarSuscripcion(Suscripcion* suscripcion);
        void agregarPartida(Partida* partida);
        ~Juego();
};

#endif