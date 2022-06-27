#ifndef C_BUSCARPORCATEGORIA
#define C_BUSCARPORCATEGORIA

#include <iostream>
#include <list>

#include "ICBuscarPorCategoria.h"
#include "DtJuego.h"
#include "DtCategoria.h"

using namespace std;

class CBuscarPorCategoria : public ICBuscarPorCategoria {
    private:
        int catId;
    public:
        bool existeCategoria(int idCat);
        Categoria* dameCategoria(int idCat);
        list<DtJuego*> buscarPorCategoria(int catId);
};

#endif