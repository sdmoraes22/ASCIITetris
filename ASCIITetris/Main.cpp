#include <iostream>
#include <Windows.h>

std::wstring tetrimino[7];

int nFieldWidth = 12;
int nFieldHeight = 18;

int nScreenWidth = 80;
int nScreenHeight = 30;

unsigned char* pField = nullptr;

int rotate(int px, int py, int r)
{
	switch (r % 4)
	{
	case 0: return py * 4 + px; //0 Degrees
	case 1: return 12 * py - (px * 4); //90 Degrees
	case 2: return 15 - (py * 4) - px; //180 Degrees
	case 3: return 3 - py + (px * 4); //270 Degrees
	}
	return 0;
}

int main()
{
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");
	tetrimino[0].append(L"..X.");

	tetrimino[1].append(L"..X.");
	tetrimino[1].append(L".XX.");
	tetrimino[1].append(L".X..");
	tetrimino[1].append(L"....");

	tetrimino[2].append(L".X..");
	tetrimino[2].append(L".XX.");
	tetrimino[2].append(L"..X.");
	tetrimino[2].append(L"....");

	tetrimino[3].append(L"....");
	tetrimino[3].append(L".XX.");
	tetrimino[3].append(L".XX.");
	tetrimino[3].append(L"....");

	tetrimino[4].append(L"..X.");
	tetrimino[4].append(L".XX.");
	tetrimino[4].append(L"..X.");
	tetrimino[4].append(L"....");
	
	tetrimino[5].append(L"....");
	tetrimino[5].append(L".XX.");
	tetrimino[5].append(L"..X.");
	tetrimino[5].append(L"..X.");

	tetrimino[6].append(L"....");
	tetrimino[6].append(L".XX.");
	tetrimino[6].append(L".X..");
	tetrimino[6].append(L".X..");

	pField = new unsigned char[nFieldWidth * nFieldHeight];
	
	for (int x = 0; x < nFieldWidth; x++)
		for (int y = 0; y < nFieldHeight; y++)
			pField[y * nFieldWidth + x] = (x == 0 || x == nFieldWidth - 1 || y == nFieldHeight - 1) ? 9 : 0;

	wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
	
	for (int i = 0; i < nScreenWidth * nScreenHeight; i++) screen[i] = L' ';

	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	DWORD dwBytesWritten = 0;

	bool gameOver = false;

	while (!gameOver)
	{
		// Game Timing

		// Input

		// Game Logic

		// Render Output

		// Draw Field
		for (int x = 0; x < nFieldWidth; x++)
			for (int y = 0; y < nFieldHeight; y++)
				screen[(y + 2) * nScreenWidth + (x + 2)] = L" ABCDEFG=#"[pField[y * nFieldWidth + x]];

		
		WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
	}
	

	return 0;

}