#pragma once
#include <Windows.h>
#include <iostream>

class KeyEvent
{

private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;

public:
	KeyEvent::KeyEvent();

	int KeyEvent::getKey();

};