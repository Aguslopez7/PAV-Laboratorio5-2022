#ifndef IAGREGARVIDEOJUEGO
#define IAGREGARVIDEOJUEGO

#include <iostream> 
using namespace std;

class IAgregarVideojuego{
    public:
    virtual void solicitarInfo(string nombre,string descripcion,int costo)=0;
    virtual void listarCategorias(/*DtCategoria*/)=0;
    virtual void seleccionCategoria(string categoria)=0;
    virtual void mostrarInformacion(/*DtVideojuego*/)=0;
    virtual void confirmarVideojuego()=0;
    virtual void cancelar()=0;
};
#endif