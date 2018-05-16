#pragma once

using namespace std;

class CheckerBoard
{
public:
	CheckerBoard();
	void printBoard();
	int yCheck(int tileNum);
	int xCheck(int tileNum);
	bool tileCheck(int tileNum);
	char tileGet(int tileNum);
	void changeBoard(int tileNum, char Plyr);
private:
	char _Board[5][5];
};

