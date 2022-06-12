#ifndef MANEJADOR_CATEGORIA
#define MANEJADOR_CATEGORIA

#include <list>
#include <map>
#include "Categoria.h"
#include "DtCategoria.h"

class ManejadorCategoria
{
	private:
		static ManejadorCategoria *instancia;
		ManejadorCategoria();
		map<int, Categoria*> colCategorias; // string, string (genero , plataforma)
	public:
		static ManejadorCategoria* getInstancia();
        list<DtCategoria*> listarCategorias(); // Verificar
		Categoria* find(int id); // Verificar
		void add(Categoria* categoria);
		void erase(int id);
		virtual ~ManejadorCategoria();
};

#endif 