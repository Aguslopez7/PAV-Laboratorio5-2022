
main: Fabrica.o Sesion.o ManejadorCategoria.o ManejadorJuego.o ManejadorUsuario.o CAgregarCategoria.o CAgregarVideoJuego.o CAltaUsuario.o CCerrarSesion.o CInfoJuego.o CIniciarPartida.o CIniciarSesion.o CSuscribirseaVideojuego.o Jugador.o Juego.o Partida.o partidaIndividual.o partidaMultijugador.o Categoria.o Desarrollador.o Estadistica.o Suscripcion.o Usuario.o DtJuego.o DtFechaHora.o DtCategoria.o main.o
	g++ Fabrica.o Sesion.o ManejadorCategoria.o ManejadorJuego.o ManejadorUsuario.o CAgregarCategoria.o CAgregarVideoJuego.o CAltaUsuario.o CCerrarSesion.o CInfoJuego.o CIniciarPartida.o CIniciarSesion.o CSuscribirseaVideojuego.o Jugador.o Juego.o Partida.o partidaIndividual.o partidaMultijugador.o Categoria.o Desarrollador.o Estadistica.o Suscripcion.o Usuario.o DtJuego.o DtFechaHora.o DtCategoria.o main.o -g -o ejecutable

run: main
	./ejecutable

rundebug : debug
	./ejecutable

main.o : main.cpp
	g++ main.cpp -g -c

############### Singleton ###############

Fabrica.o : Fabrica.cpp
	g++ Fabrica.cpp -g -c

Sesion.o : Sesion.cpp
	g++ Sesion.cpp -g -c

############### Manejadores ###############

ManejadorCategoria.o : ManejadorCategoria.cpp
	g++ ManejadorCategoria.cpp -g -c

ManejadorJuego.o : ManejadorJuego.cpp
	g++ ManejadorJuego.cpp -g -c

ManejadorUsuario.o : ManejadorUsuario.cpp
	g++ ManejadorUsuario.cpp -g -c

############### Controladoers ###############

CAgregarCategoria.o : CAgregarCategoria.cpp
	g++ CAgregarCategoria.cpp -g -c

CAgregarVideoJuego.o : CAgregarVideoJuego.cpp
	g++ CAgregarVideoJuego.cpp -g -c

CAltaUsuario.o : CAltaUsuario.cpp
	g++ CAltaUsuario.cpp -g -c

CCerrarSesion.o : CCerrarSesion.cpp
	g++ CCerrarSesion.cpp -g -c

CInfoJuego.o : CInfoJuego.cpp
	g++ CInfoJuego.cpp -g -c

CIniciarPartida.o : CIniciarPartida.cpp
	g++ CIniciarPartida.cpp -g -c

CIniciarSesion.o : CIniciarSesion.cpp
	g++ CIniciarSesion.cpp -g -c

CSuscribirseaVideojuego.o : CSuscribirseaVideojuego.cpp
	g++ CSuscribirseaVideojuego.cpp -g -c

############### Clases Genericas ###############

Juego.o : Juego.cpp
	g++ Juego.cpp -g -c

Jugador.o : Jugador.cpp
	g++ Jugador.cpp -g -c

Partida.o : Partida.cpp
	g++ Partida.cpp -g -c

partidaIndividual.o : partidaIndividual.cpp
	g++ partidaIndividual.cpp -g -c

partidaMultijugador.o : partidaMultijugador.cpp
	g++ partidaMultijugador.cpp -g -c

Categoria.o : Categoria.cpp
	g++ Categoria.cpp -g -c

Desarrollador.o : Desarrollador.cpp	
	g++ Desarrollador.cpp -g -c

Estadistica.o : Estadistica.cpp
	g++ Estadistica.cpp -g -c

Suscripcion.o : Suscripcion.cpp
	g++ Suscripcion.cpp -g -c

Usuario.o : Usuario.cpp
	g++ Usuario.cpp -g -c

############### Data Types ###############

DtJuego.o : DtJuego.cpp
	g++ DtJuego.cpp -g -c

DtFechaHora.o : DtFechaHora.cpp
	g++ DtFechaHora.cpp -g -c

DtCategoria.o : DtCategoria.cpp
	g++ DtCategoria.cpp -g -c

clean :
	rm -rf *.o
	rm -f ejecutable
