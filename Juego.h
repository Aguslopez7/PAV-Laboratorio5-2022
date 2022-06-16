#ifndef JUEGO
#define JUEGO

#include <iostream>
#include <list>
#include "Definiciones.h"
#include "DtJuego.h"
#include "Partida.h"
#include "Usuario.h"
#include "Categoria.h"
<<<<<<< HEAD
#include "Suscripcion.h"
=======
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e


using namespace std;

class Juego{
    private:
        string nombre;
        string descripcion;
        int costo;
        Usuario* usuario;
<<<<<<< HEAD
        list<DtCategoria*> categorias;
        Suscripcion* sub;
        DtJuego* juego;
    public:
        Juego();
        Juego(string nombre, string descripcion,int costo, Usuario* usuario, list<DtCategoria*> categorias);
=======
        DtCategoria* categoria;
        DtJuego* juego;
    public:
        Juego();
        Juego(string nombre, string descripcion,int costo, Usuario* usuario, DtCategoria* categoria);
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setUsuario(Usuario* usuario);
<<<<<<< HEAD
=======
        void setCategoria(DtCategoria* categoria);
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        void setJuego(DtJuego* juego);
        string getNombre();
        string getDescripcion();
        int getCosto();
        Usuario* getUsuario();
<<<<<<< HEAD
        list<DtCategoria*> getCategorias();   
        DtJuego* getJuego();  
=======
        DtCategoria* getCategoria();   
        DtJuego* getJuego();     
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        ~Juego();
};

#endif