#ifndef IC_BUSCARPORCATEGORIA
#define IC_BUSCARPORCATEGORIA

#include <iostream> 

#include "DtJuego.h"
#include "DtCategoria.h"

using namespace std;

class ICBuscarPorCategoria{
    public:
    virtual bool existeCategoria(int idCat) = 0;
    virtual Categoria* dameCategoria(int idCat) = 0;
    virtual list<DtJuego*> buscarPorCategoria(int idCat) = 0;
};
#endif