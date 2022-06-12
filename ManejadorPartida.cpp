#include "ManejadorPartida.h"

Juego* ManejadorPartida::find(string nombre)
{
	map<string, Juego*>::iterator it = this->colJuegos.find(nombre);
	return (it != colJuegos.end())? it->second : NULL;
}

void ManejadorPartida::add(Partida* Partida)
{
	this->colPartidas.insert(pair<int, Partida*>(Partida->getId(), Partida));
}

void ManejadorPartida::erase(int id)
{
	this->colPartidas.erase(id);
}