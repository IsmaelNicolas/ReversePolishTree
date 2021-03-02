/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief Programa principal
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "postfix.h"
#include "infix.h"
#include "Menu.h"
#include "Arbol.h"
#include "Console.h"

void format_input(string input, string &output);

int main(void)
{
	
	Menu menu;
	int option;	
	Arbol bArbol;
	string in, out, expression;
	char *infix; 	
	char *postfix;
	double x = 0;
	do {
		option = menu.makeMenu(4,"Ingresar Expresion","Ver Infija","Ver Posfija","Salir");
		system("cls");
		switch (option) {
		case 1:{
			Console screen;
			screen.hideCursor(true);
			in = "";
			expression = "";
			x = 0;
			infix,postfix = NULL;

			cout << "Ingrese una expresion: ";
			getline(cin, in);
			format_input(in, expression);
			out.resize(expression.length() * 100);
			cout<<"Expresion ingresada-> "<<expression<<endl;
			infix = &expression[0];
			postfix = &out[0];
			infix2postfix(infix, postfix);
			x = eval_postfix(postfix);
			cout << "Resulatado: " << x << endl;
			system("pause");
			break;
		       }
		case 2:{
			cout << "\nInfija: " << infix << endl;
			system("pause");
			break;
		       }
		case 3:{
			infix2postfix(infix, postfix);
	
			cout << "\nPostfija: " <<  out << endl;
			system("pause");

			break;
		       }
		default:
		       break;

	}


	}while (option != 4);


	return EXIT_SUCCESS;
}

void format_input(string input, string &output){
	for(unsigned int i = 0; i < input.length(); i++){
		if(input[i] != ' '){
            if(input[i] == '^' || input[i] == '*' || input[i] == '/' || input[i] == '%' || input[i] == '+'){
				output.push_back(' ');
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == '-'){
				if((i != 0) && (*output.rbegin() != '^' && *output.rbegin() != '(' && *output.rbegin() != ' ' && *output.rbegin() != '*' && *output.rbegin() != '/' && *output.rbegin() != '/' && *output.rbegin() != '%' && *output.rbegin() != '+' && *output.rbegin() != '-')){
					output.push_back(' ');
					output.push_back(input[i]);
					output.push_back(' ');
				}
				else{
					output.push_back(input[i]);
				}	
			}
			else if(input[i] == '('){
				output.push_back(input[i]);
				output.push_back(' ');
			}
			else if(input[i] == ')'){
				output.push_back(' ');
				output.push_back(input[i]);
			}
			else
			{
				output.push_back(input[i]);
			}
		}
	}
}
