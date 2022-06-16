#ifndef JUEGO
#define JUEGO

#include <iostream>
#include <list>
#include "Definiciones.h"
#include "DtJuego.h"
#include "Partida.h"
#include "Usuario.h"
#include "Categoria.h"
#include "Suscripcion.h"


using namespace std;

class Juego{
    private:
        string nombre;
        string descripcion;
        int costo;
        Usuario* usuario;
        list<DtCategoria*> categorias;
        Suscripcion* sub;
        DtJuego* juego;
    public:
        Juego();
        Juego(string nombre, string descripcion,int costo, Usuario* usuario, list<DtCategoria*> categorias);
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setUsuario(Usuario* usuario);
        void setJuego(DtJuego* juego);
        string getNombre();
        string getDescripcion();
        int getCosto();
        Usuario* getUsuario();
        list<DtCategoria*> getCategorias();   
        DtJuego* getJuego();  
        ~Juego();
};

#endif