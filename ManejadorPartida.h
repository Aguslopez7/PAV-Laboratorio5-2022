#ifndef MANEJADOR_PARTIDA
#define MANEJADOR_PARTIDA

#include <list>
#include <map>
#include "Partida.h"
#include "DtPartida.h"
#include "Juego.h"


class ManejadorPartida
{
	private:
		static ManejadorPartida *instancia;
		ManejadorPartida();
		map<string, Juego*> colPartidas;
	public:
		static ManejadorPartida* getInstancia();
        list<Partida*> listarVideoJuegosSuscripcionActiva();
		Juego* find(string nombre);
		void add(Partida* Partida);
		void erase(int id);
		void create(int id);
		virtual ~ManejadorPartida();
};

#endif 