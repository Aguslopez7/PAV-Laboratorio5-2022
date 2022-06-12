#ifndef JUEGO
#define JUEGO

#include <iostream>
#include "Definiciones.h"
#include "DtJuego.h"
#include "Partida.h"
#include "Usuario.h"
#include "Categoria.h"


using namespace std;

class Juego{
    private:
        string nombre;
        string descripcion;
        int costo;
        Usuario* usuario;
        DtCategoria* categoria;
        DtJuego* juego;
    public:
        Juego();
        Juego(string nombre, string descripcion,int costo, Usuario* usuario, DtCategoria* categoria);
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setUsuario(Usuario* usuario);
        void setCategoria(DtCategoria* categoria);
        void setJuego(DtJuego* juego);
        string getNombre();
        string getDescripcion();
        int getCosto();
        Usuario* getUsuario();
        DtCategoria* getCategoria();   
        DtJuego* getJuego();     
        ~Juego();
};

#endif