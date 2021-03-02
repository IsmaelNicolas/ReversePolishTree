/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file Menu.cpp
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief Implementacion del menu con cantidad varialble de argumentos
*/
#include "Menu.h"
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <cstdarg>
#include <vadefs.h>
#include <stdarg.h>
#include <string>
//template<class... Args>


int Menu::makeMenu(int nargs,...){

	int selection = 1;
	int key;
	bool flag = true;
	screen.hideCursor(false);
	//auto v = {args...};

	do {
		
		va_list args;
		va_start(args,nargs);

		system("cls");
		screen.gotoXY(20,12);
		std::cout<< fg::BGreen<< bg::Black <<" <[ M e n u ]>"<<std::endl;
		std::cout<<fg::BWhite<<bg::Black; 
		for(int i = 0 ;i < nargs ; i++)
		{
			if (selection == i+1) {
				screen.gotoXY(20,14+i);
				std::cout<<fg::BGreen<<"->"<<fg::BWhite<<va_arg(args,char *)<<std::endl;
			}else{
				screen.gotoXY(21,14+i);
				std::cout<<va_arg(args,char *)<<std::endl;
			}
		}
		va_end(args);

		do {
			key = _getch();
		}while (key != UP && key != DOWN && key != ENTER);

		switch (key) {
			case UP:
				selection--;
				if (selection <= 0) {
					selection = nargs;
				}
				break;
			case DOWN:
				selection++;
				if (selection > nargs) {
					selection = 1;
				}
				break;
			case ENTER:
				flag = false;
				break;
		}	


	}while (flag);


	return selection;
}
