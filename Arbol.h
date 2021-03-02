/***********************************************************************
 * Module:  Arbol.h
 * Author:  aange
 * Modified: martes, 9 de febrero de 2021 21:58:57
 * Purpose: Declaration of the class Arbol
 ***********************************************************************/

#include <string>
#if !defined(__ArbolesBinarios_Arbol_h)
#define __ArbolesBinarios_Arbol_h

typedef std::string T;

#include "Nodo.h"

class Arbol
{
public:

	Arbol();
   	void insertar(T);
   	void insertar(Nodo * , T);
   	bool vacio();
   	Nodo* getRaiz(void);
   	void setRaiz(Nodo* newRaiz);
   	void inorder(Nodo* nodo);
	void eliminar(Nodo * nodo, T );
	
private:
   Nodo * raiz;


};

#endif
