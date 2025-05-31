#include <iostream>
#include <windows.h>

using namespace std;

//-------------------------- gotoxy --------------------------

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//------------------------ textColor -------------------------

void textColor(int x)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}

//----------------------- cursorStatus -----------------------

void cursorStatus(bool status)
{
    HANDLE hStdOut = NULL;
    CONSOLE_CURSOR_INFO curInfo;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hStdOut, &curInfo);
    curInfo.bVisible = status;
    SetConsoleCursorInfo(hStdOut, &curInfo);
}






