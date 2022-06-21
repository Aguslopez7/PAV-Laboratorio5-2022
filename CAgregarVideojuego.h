#ifndef CAGREGARVIDEOJUEGO
#define CAGREGARVIDEOJUEGO

#include <iostream>
#include <list>
#include "DtJuego.h"
#include "ICAgregarVideojuego.h"
#include "Sesion.h"
#include "Juego.h"
#include "DtCategoria.h"



using namespace std;

class CAgregarVideojuego : public ICAgregarVideojuego {
    private:
        string nombre;
        string descripcion;
        int costo;
        list<DtCategoria*> listDtCategorias;
    public:
        void solicitarInfo(string nombre, string descripcion, int costo);
        void agregarCategoria(DtCategoria* dt);
        void mostrarInfo();
        void confirmarJuego();
        void cancelar();
};

#endif