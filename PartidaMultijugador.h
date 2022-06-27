#ifndef PARTIDAIMULTIJUGADOR
#define PARTIDAIMULTIJUGADOR

#include "Partida.h"

using namespace std;

class PartidaMultijugador : public Partida{
  private:
    bool trasmitidaEnVivo;
    int cantJugadores;
  public:
    PartidaMultijugador ();
    PartidaMultijugador (int id,DtFechaHora* fecha, int duracion, Jugador* jugador, bool trasmitidaEnVivo, int cantJugadores);
    bool getTrasmitidaEnVivo();
    void setTrasmitidaEnVivo(bool trasmitidaEnVivo);
    int getCantidadJugadores();
    void setCantidadJugadores(int cantJugadores);
    int darTotalHorasParticipantes();
    ~PartidaMultijugador ();
    
};

#endif