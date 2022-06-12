#ifndef ICAGREGARVIDEOJUEGO
#define ICAGREGARVIDEOJUEGO

#include <iostream> 
#include "DtJuego.h"
using namespace std;

class ICAgregarVideojuego{
    public:
    virtual void solicitarInfo(string nombre,string descripcion,int costo, DtCategoria* dtCategoria)=0;
    virtual list<DtJuego*> listarJuegos()=0;
    virtual void confirmarJuego()=0;
    virtual void cancelar()=0;
};
#endif