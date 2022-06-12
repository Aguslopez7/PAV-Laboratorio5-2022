#ifndef CAGREGARVIDEOJUEGO
#define CAGREGARVIDEOJUEGO

#include <iostream>
#include <list>

#include "DtJuego.h"
#include "ICAgregarVideojuego.h"

using namespace std;

class CAgregarVideojuego : public ICAgregarVideojuego {
    private:
        string nombre;
        string descripcion;
        int costo;
        DtCategoria* dtCategoria;
    public:
        void solicitarInfo(string nombre, string descripcion, int costo, DtCategoria* dtCategoria);
        list<DtJuego*> listJuegos();
        void confirmarJuego();
        void cancelar();
};

#endif