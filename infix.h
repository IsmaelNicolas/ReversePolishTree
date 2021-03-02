/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file infix.h
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief Declaracion de infix.xpp
*/
#ifndef INFIX_H
#define INFIX_H

#include "stack.h"

//! assigns precedence to operators
int precedence(char x);

//! converts infix expression to postfix expression.
void infix2postfix(char* infix, char* postfix);

#endif
