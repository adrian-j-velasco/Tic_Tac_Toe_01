#include <iostream>
#include <string>
#include "CheckerBoard.h"

using namespace std;

void die(const string & msg);
bool boardWin(CheckerBoard board);
void endGame(char plyr, bool draw);

int main()
{
	bool gameFlag = true, draw = false;
	int holder;
	CheckerBoard Board;
	int turn = 0;
	char plyr;

	while (gameFlag)
	{
		Board.printBoard();
		cin >> holder;
		if (!Board.tileCheck(holder))
		{
			if (turn % 2 == 0)
			{
				plyr = 'X';
			}
			else
			{
				plyr = 'O';
			}
			Board.changeBoard(holder,plyr);
			turn++;
		}
		if (turn == 9 || boardWin(Board) )
		{
			gameFlag = false;
			if (turn == 9 && !boardWin(Board))
			{
				draw = true;
			}
		}
	}
	Board.printBoard();
	endGame(plyr, draw);

	system("PAUSE");
	return 0;
}

void endGame(char plyr, bool draw)
{
	if (draw)
	{
		cout << "DRAW!\n";
	}
	else
	{
		cout << "Player " << plyr << " Wins!\n";
	}
}

bool boardWin(CheckerBoard board)
{
	bool ret = false;
	bool flag = true;

	/*	
		THIS IS WHAT I GET FOR NOT WRITING STUFF DOWN LOL
	 	Winning combination: 123,456,789,147,258,369,357,159
		
		MY GOD IM SO BAD
	 */

	while (flag)
	{
		if (board.tileGet(1) == board.tileGet(2) && board.tileGet(1) == board.tileGet(3))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(4) == board.tileGet(5) && board.tileGet(4) == board.tileGet(6))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(7) == board.tileGet(8) && board.tileGet(7) == board.tileGet(9))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(1) == board.tileGet(4) && board.tileGet(1) == board.tileGet(7))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(2) == board.tileGet(5) && board.tileGet(2) == board.tileGet(8))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(3) == board.tileGet(6) && board.tileGet(3) == board.tileGet(9))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(3) == board.tileGet(5) && board.tileGet(3) == board.tileGet(7))
		{
			flag = false;
			ret = true;
		}
		if (board.tileGet(1) == board.tileGet(5) && board.tileGet(1) == board.tileGet(9))
		{
			flag = false;
			ret = true;
		}
		else
		{
			flag = false;
		}
	}

	return ret;
}

void die(const string & msg)
{
	cerr << "Fatal Error:\n" << msg << endl;
	exit(EXIT_FAILURE);
}