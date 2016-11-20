#include "Game.h"
#include "KeyEvent.h"
#include <process.h>
#include <iostream>
#include <windows.h>
using namespace std;
Game* game = new Game();
unsigned int __stdcall mythread(void*)
{
	int i = 0;
	while (1)
	{
		//cout << GetCurrentThreadId() << ": " << i++ << endl;
		game->move();
		Sleep(300);
		i = 0;
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*)
{
	KeyEvent k;
	int i;
	while (1)
	{
		i = k.getKey();
		if (i != -1)
		{
			game->setDirection(i);
		}
	}
	return 0;
}

int main()
{
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);
}