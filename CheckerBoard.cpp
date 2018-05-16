#include "CheckerBoard.h"
#include <iostream>

CheckerBoard::CheckerBoard()
{
	for(int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			if ( (y%2 == 0) && (x%2==0) )
			{
				//	Im too lazy just get this done
				//	Holy shit this works
				//	Im a bad programmer lol
				static int z = 1;
				_Board[y][x] = '0'+z;
				z++;
			}
			else if (y%2==1)
			{
				_Board[y][x] = '-';
			}
			else
			{
				_Board[y][x] = '|';
			}
		}
	}
}

void CheckerBoard::printBoard()
{
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cout << _Board[y][x];
			if (x == 4)
			{
				cout << endl;
			}
		}
	}
}

int CheckerBoard::yCheck(int tileNum)
{
	if (tileNum > 0 && tileNum < 4)
	{
		return 0;
	}
	else if (tileNum > 3 && tileNum < 7)
	{
		return 2;
	}
	else
	{
		return 4;
	}
}

int CheckerBoard::xCheck(int tileNum)
{
	if (tileNum % 3 == 1)
	{
		return 0;
	}
	else if (tileNum % 3 == 2)
	{
		return 2;
	}
	else
	{
		return 4;
	}
}

bool CheckerBoard::tileCheck(int tileNum)
{
	char holder = _Board[yCheck(tileNum)][xCheck(tileNum)];
	if (holder == 'X' || holder == 'O')
	{
		return true;
	}
	else
	{
		return false;
	}
}

char CheckerBoard::tileGet(int tileNum)
{
	return _Board[yCheck(tileNum)][xCheck(tileNum)];
}

void CheckerBoard::changeBoard(int tileNum,char Plyr)
{
	if (!tileCheck(tileNum))
	{
		_Board[yCheck(tileNum)][xCheck(tileNum)] = Plyr;
	}
}