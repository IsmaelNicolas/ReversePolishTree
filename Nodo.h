/***********************************************************************
 * Module:  Nodo.h
 * Author:  aange
 * Modified: martes, 9 de febrero de 2021 21:59:13
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__ArbolesBinarios_Nodo_h)
#define __ArbolesBinarios_Nodo_h


#include <string>

typedef std::string T;
//#include "Arbol.h"
class Nodo
{
	
public:
   T getDato(void) const;
   void setDato(T newDato);
   Nodo* getIzq(void) const;
   void setIzq(Nodo* newIzq);
   Nodo* getDer(void) const;
   void setDer(Nodo* newDer);
   Nodo(T);
   ~Nodo();
   //Nodo(T dato, Nodo* izq, Nodo* der);
   
private:
   	T dato;
	Nodo* izq;
   	Nodo* der;


};

#endif
