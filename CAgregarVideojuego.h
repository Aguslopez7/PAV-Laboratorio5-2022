#ifndef C_AGREGARVIDEOJUEGO
#define C_AGREGARVIDEOJUEGO

#include <iostream>
#include <list>

#include "DtJuego.h"
#include "ICAgregarVideojuego.h"
#include "Sesion.h"
#include "Juego.h"
#include "DtCategoria.h"
#include "Categoria.h"

using namespace std;

class CAgregarVideojuego : public ICAgregarVideojuego {
    private:
        string nombre;
        string descripcion;
        int costo;
        list<Categoria*> listCategorias;
    public:
        void solicitarInfo(string nombre, string descripcion, int costo);
        void agregarCategoria(Categoria* cat);
        list<DtCategoria*> mostrarCat();
        void confirmarJuego();
        void cancelar();
};

#endif