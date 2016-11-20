#include <windows.h>
#include <iostream>
#include "Game.h"
using namespace std;

void Game::gotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Game::Game()
{
	x = 5;
	y = 5;
	direction = 0;
}

void Game::setDirection(int i)
{
	direction = i;
}

void Game::move()
{
	if (direction == 37)
	{
		if (this->x < 1)
		{
			setColor(WHITE, D_RED);
			x = x;
		}
		else
		x--;
	}
	else if (direction == 38)
	{
		if (this->y < 1)
		{
			setColor(WHITE, D_RED);
			y = y;
		}
		else
		y--;
	}
	else if (direction == 39)
	{
		x++;
	}
	else if (direction == 40)
	{
		y++;
	}
	system("cls");
	this->gotoXY(x, y);
	cout << x << " " << y << "бс";
	setColor(WHITE, BLACK);
	direction = 0;
}

void Game::setColor(char color, char backGround)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backGround << 4) + color);
}

void Game::clearConsole()
{
	system("cls");
}

