/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  aange
 * Modified: martes, 9 de febrero de 2021 21:59:13
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/
#include <cstddef>
#include "Nodo.h"

T Nodo::getDato(void) const{ return this ->dato;}

void Nodo::setDato(T newDato) {this->dato = newDato;}

Nodo* Nodo::getIzq(void) const {return this->izq; }

void Nodo::setIzq(Nodo* newIzq) { this->izq = newIzq; }

Nodo* Nodo::getDer(void) const { return this->der; }

void Nodo::setDer(Nodo* newDer) {this->der = newDer; }

Nodo::Nodo(T dato){
	
	this->dato = dato;
	this->izq = NULL;
	this->der = NULL;
	
}
