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
<<<<<<< HEAD
        void agregarCategoria(Categoria* cat);
=======
        void agregarCategoria(Categoria* dt);
>>>>>>> 5388b3a81213b52523464c3c4c954157649dddca
        list<DtCategoria*> mostrarCat();
        void confirmarJuego();
        void cancelar();
};

#endif