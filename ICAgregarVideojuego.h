#ifndef IC_AGREGARVIDEOJUEGO
#define IC_AGREGARVIDEOJUEGO

#include <iostream> 

#include "DtCategoria.h"
#include "Categoria.h"

using namespace std;

class ICAgregarVideojuego{
    public:
    virtual void solicitarInfo(string nombre,string descripcion,int costo) = 0;
    virtual void agregarCategoria(Categoria* cat) = 0;
    virtual list<DtCategoria*> mostrarCat() = 0;
    virtual void confirmarJuego() = 0;
    virtual void cancelar() = 0;
};
#endif