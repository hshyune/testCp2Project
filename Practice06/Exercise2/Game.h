#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

enum
{
	BLACK, D_BLUE, D_GREEN, D_SKYBLUE, D_RED, D_VIOLET,
	D_YELLOW, GRAY, D_GRAY, BLUE, GREEN,
	SKYBLUE, RED, VIOLET, YELLOW, WHITE
};

class Game
{
private:
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y);

public:
	Game();
	void setDirection(int i);
	void move();
	void setColor(char color, char backGround);
	void clearConsole();
};