#ifndef IC_BUSCARPORCATEGORIA
#define IC_BUSCARPORCATEGORIA

#include <iostream> 

#include "DtJuego.h"

using namespace std;

class ICBuscarPorCategoria{
    public:
    virtual list<DtJuego*> buscarPorCategoria(int idCat) = 0;
};
#endif