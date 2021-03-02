/***********************************************************************
 * Module:  Arbol.cpp
 * Author:  aange
 * Modified: martes, 9 de febrero de 2021 21:58:57
 * Purpose: Implementation of the class Arbol
 ***********************************************************************/
#include <cstddef>
#include <iostream>
#include "Arbol.h"

bool Arbol::vacio(){ return (this->raiz == NULL)? true:false; }

Nodo* Arbol::getRaiz(void){ return this->raiz; }

void Arbol::setRaiz(Nodo* newRaiz){ this->raiz = newRaiz; }

void Arbol::eliminar(Nodo * aux,T dato){
	
	if (aux)
		if (dato < aux->getDato())
		{
			eliminar(aux->getIzq(), dato);
			aux->setIzq(raiz);
		}
		
		else if (dato > aux->getDato())
		{
			eliminar(aux->getDer(), dato);
			aux->setDer(raiz);
		}
		else
		{
			Nodo* aux1, * aux2, * aux3;
			aux3 = aux;
			if (!aux3->getDer())
				if (!aux3->getIzq())
					aux = NULL;
				else
					aux = aux3->getIzq();
				else if (!aux3->getIzq())
						aux = aux3->getDer();
				else
				{
					aux1 = aux3->getIzq();
					aux2 = aux3;
					while (aux1->getDer())
					{
						aux2 = aux1;
						aux1 = aux1->getDer();
					}
					aux3->setDato(aux1->getDato());
					if (aux3 == aux2)
						aux3->setIzq(NULL);
					else
						if (!aux1->getIzq())
							aux2->setDer(NULL);
						else
							aux2->setDer(aux1->getIzq());
					aux3 = aux1;
				}
				//delete(aux3);
			}
	raiz = aux;
	
		
}


void Arbol::insertar(T dato){

	if(raiz == NULL) 
		raiz = new Nodo(dato); 
	else
		insertar(raiz, dato);

}

void Arbol::insertar(Nodo * nodo,T dato){
	
	if(dato <= nodo->getDato())
	{
		if(nodo->getIzq() == NULL)
		{
			Nodo *novo_no = new Nodo(dato);
			nodo->setIzq(novo_no); 
		}
		else
		{
			insertar(nodo->getIzq(), dato);
		}
	}
	else if(dato >= nodo->getDato())
	{
		
		if(nodo->getDer() == NULL)
		{
			Nodo *novo_no = new Nodo(dato);
			nodo->setDer(novo_no); 
		}
		else
		{
			insertar(nodo->getDer(), dato);
		}
	}
	
}

void Arbol::inorder(Nodo* nodo){
	if(nodo != NULL)
		{
			inorder(nodo->getIzq());
			std::cout << nodo->getDato() << " ";
			inorder(nodo->getDer());
		}
}

Arbol::Arbol(){
	
	this->raiz = NULL;
	
}
