#ifndef CAGREGARVIDEOJUEGO
#define CAGREGARVIDEOJUEGO

#include <iostream>
#include <list>
<<<<<<< HEAD
#include "DtJuego.h"
#include "ICAgregarVideojuego.h"
#include "Sesion.h"
=======

#include "DtJuego.h"
#include "ICAgregarVideojuego.h"
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e

using namespace std;

class CAgregarVideojuego : public ICAgregarVideojuego {
    private:
        string nombre;
        string descripcion;
        int costo;
<<<<<<< HEAD
        list<DtCategoria*> listDtCategorias;
    public:
        void solicitarInfo(string nombre, string descripcion, int costo);
        //list<DtJuego*> listarDtJuegos();
        void agregarCategoria(DtCategoria* dt);
        void mostrarInfo();
=======
        DtCategoria* dtCategoria;
    public:
        void solicitarInfo(string nombre, string descripcion, int costo, DtCategoria* dtCategoria);
        list<DtJuego*> listJuegos();
>>>>>>> b105ec8d5d80d53fcc2cdfb9363238e4f9eef99e
        void confirmarJuego();
        void cancelar();
};

#endif