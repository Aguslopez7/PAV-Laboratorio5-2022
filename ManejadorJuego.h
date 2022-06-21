#ifndef MANEJADOR_JUEGO
#define MANEJADOR_JUEGO
#include "Juego.h"
#include <map>
#include <list>
#include <string>

using namespace std;

class ManejadorJuego{
    private:
        static ManejadorJuego* instancia;
        map<string,Juego*> colJuegos;   
        ManejadorJuego();
    public:
        static ManejadorJuego* getInstancia();
        list<Juego*> listarJuegos();
        Juego* find(string juego);
        void add(Juego* juego);
        void erase(string juego);
        bool exist(string nombre);
        virtual ~ManejadorJuego();
};
#endif