/**
 * UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
* @file main.cpp
* @author Ismael Cedillo y Angel Castillo
* @date 2/3/2021
* @brief control de la Consola
*/

#include "Console.h"


void Console::hideCursor(bool value)
{
	CONSOLE_CURSOR_INFO cci = { 100, value }; // El segundo miembro de la estructura indica si se muestra el cursor o no.
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Console::changeSize(int width ,int heigth)
{
	   
	_COORD size;
	_SMALL_RECT rect;
	size.X = width;
	size.Y = heigth;

	rect.Top = 0;
	rect.Left = 0;
	rect.Right = width - 1;
	rect.Bottom = heigth - 1;

	HANDLE _console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(_console, size);
	SetConsoleWindowInfo(_console, TRUE, &rect);
						      
}


void Console::gotoXY(int x ,int y)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
