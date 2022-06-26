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
        Juego* getJuego(string juego);
        void add(Juego* juego);
        void erase(string nombre);
        bool exist(string nombre);
        void removerJuego(Juego* juego);
        virtual ~ManejadorJuego();
};
#endif