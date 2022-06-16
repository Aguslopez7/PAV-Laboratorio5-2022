#ifndef C_INFOJUEGO
#define C_INFOJUEGO

#include <iostream> 
#include "DtJuego.h"
#include "Usuario.h"
#include "Juego.h"
#include <list>
#include <string>
#include "ICInfoJuego.h"

using namespace std;

class CInfoJuego: public ICInfoJuego {
    private:
		string nombre;
    public:
    list<string> listarJuegos();
	  DtJuego* selectJuego(string nombre);
};

#endif