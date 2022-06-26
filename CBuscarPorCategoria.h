#ifndef C_BUSCARPORCATEGORIA
#define C_BUSCARPORCATEGORIA

#include <iostream>
#include <list>

#include "ICBuscarPorCategoria.h"
#include "DtJuego.h"

using namespace std;

class CBuscarPorCategoria : public ICBuscarPorCategoria {
    private:
        int catId;
    public:
        list<DtJuego*> buscarPorCategoria(int catId);
};

#endif