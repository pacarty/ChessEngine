#include <iostream>

#define WHITE false
#define BLACK true

typedef bool Colour;

using namespace std;

struct Square
{
	char File;
	unsigned __int8 Rank;
	bool HasPiece;
	Colour ColourOfPiece;
	char NameOfPiece;

	Square(char file, unsigned __int8 rank, bool hasPiece, Colour colourOfPiece, char nameOfPiece)
	{
		File = file;
		Rank = rank;
		HasPiece = hasPiece;
		ColourOfPiece = colourOfPiece;
		NameOfPiece = nameOfPiece;
	}
};

struct Piece
{
	char Name;
	unsigned __int8 CoordX;
	unsigned __int8 CoordY;

	Piece(char name, unsigned __int8 coordX, __int8 coordY)
	{
		Name = name;
		CoordX = coordX;
		CoordY = coordY;
	}
};

struct Engine
{
	void Run()
	{
		cout << "Running..." << endl;

		// May not need this or the Piece struct at all
		Piece pieces[2][16] =
		{
			{
				Piece('p', 0, 1),
				Piece('p', 1, 1),
				Piece('p', 2, 1),
				Piece('p', 3, 1),
				Piece('p', 4, 1),
				Piece('p', 5, 1),
				Piece('p', 6, 1),
				Piece('p', 7, 1),
				Piece('r', 0, 0),
				Piece('r', 7, 0),
				Piece('n', 1, 0),
				Piece('n', 6, 0),
				Piece('b', 2, 0),
				Piece('b', 5, 0),
				Piece('q', 3, 0),
				Piece('k', 4, 0)
			},
			{
				Piece('p', 0, 6),
				Piece('p', 1, 6),
				Piece('p', 2, 6),
				Piece('p', 3, 6),
				Piece('p', 4, 6),
				Piece('p', 5, 6),
				Piece('p', 6, 6),
				Piece('p', 7, 6),
				Piece('r', 0, 7),
				Piece('r', 7, 7),
				Piece('n', 1, 7),
				Piece('n', 6, 7),
				Piece('b', 2, 7),
				Piece('b', 5, 7),
				Piece('q', 3, 7),
				Piece('k', 4, 7)
			}
		};

		Square squares[8][8] =
		{
			{
				Square('a', 1, true, WHITE, 'r'),
				Square('a', 2, true, WHITE, 'p'),
				Square('a', 3, false, false, 'e'),
				Square('a', 4, false, false, 'e'),
				Square('a', 5, false, false, 'e'),
				Square('a', 6, false, false, 'e'),
				Square('a', 7, true, BLACK, 'p'),
				Square('a', 8, true, BLACK, 'r')
			},
			{
				Square('b', 1, true, WHITE, 'n'),
				Square('b', 2, true, WHITE, 'p'),
				Square('b', 3, false, false, 'e'),
				Square('b', 4, false, false, 'e'),
				Square('b', 5, false, false, 'e'),
				Square('b', 6, false, false, 'e'),
				Square('b', 7, true, BLACK, 'p'),
				Square('b', 8, true, BLACK, 'n')
			},
			{
				Square('c', 1, true, WHITE, 'b'),
				Square('c', 2, true, WHITE, 'p'),
				Square('c', 3, false, false, 'e'),
				Square('c', 4, false, false, 'e'),
				Square('c', 5, false, false, 'e'),
				Square('c', 6, false, false, 'e'),
				Square('c', 7, true, BLACK, 'p'),
				Square('c', 8, true, BLACK, 'b')
			},
			{
				Square('d', 1, true, WHITE, 'q'),
				Square('d', 2, true, WHITE, 'p'),
				Square('d', 3, false, false, 'e'),
				Square('d', 4, false, false, 'e'),
				Square('d', 5, false, false, 'e'),
				Square('d', 6, false, false, 'e'),
				Square('d', 7, true, BLACK, 'p'),
				Square('d', 8, true, BLACK, 'q')
			},
			{
				Square('e', 1, true, WHITE, 'k'),
				Square('e', 2, true, WHITE, 'p'),
				Square('e', 3, false, false, 'e'),
				Square('e', 4, false, false, 'e'),
				Square('e', 5, false, false, 'e'),
				Square('e', 6, false, false, 'e'),
				Square('e', 7, true, BLACK, 'p'),
				Square('e', 8, true, BLACK, 'k')
			},
			{
				Square('f', 1, true, WHITE, 'b'),
				Square('f', 2, true, WHITE, 'p'),
				Square('f', 3, false, false, 'e'),
				Square('f', 4, false, false, 'e'),
				Square('f', 5, false, false, 'e'),
				Square('f', 6, false, false, 'e'),
				Square('f', 7, true, BLACK, 'p'),
				Square('f', 8, true, BLACK, 'b')
			},
			{
				Square('g', 1, true, WHITE, 'n'),
				Square('g', 2, true, WHITE, 'p'),
				Square('g', 3, false, false, 'e'),
				Square('g', 4, false, false, 'e'),
				Square('g', 5, false, false, 'e'),
				Square('g', 6, false, false, 'e'),
				Square('g', 7, true, BLACK, 'p'),
				Square('g', 8, true, BLACK, 'n')
			},
			{
				Square('h', 1, true, WHITE, 'r'),
				Square('h', 2, true, WHITE, 'p'),
				Square('h', 3, false, false, 'e'),
				Square('h', 4, false, false, 'e'),
				Square('h', 5, false, false, 'e'),
				Square('h', 6, false, false, 'e'),
				Square('h', 7, true, BLACK, 'p'),
				Square('h', 8, true, BLACK, 'r')
			}
		};

		cout << endl;
		PrintBoard(squares);
		cout << endl;

		bool turnColour = WHITE;

		char inputStartPosX, inputStartPosY, inputEndPosX, inputEndPosY;

		cin >> inputStartPosX;
		cin >> inputStartPosY;
		cin >> inputEndPosX;
		cin >> inputEndPosY;

		int startPosX = (int)inputStartPosX - 97;
		int startPosY = (int)inputStartPosY - 49;
		int endPosX = (int)inputEndPosX - 97;
		int endPosY = (int)inputEndPosY - 49;

		// check if squares[startX][startY] has turnColour piece on it
		// if not: invalid move, try again
		
		// check if squares[endX][endY] has turnColour piece on it
		// if yes: invalid move, try again

		// perform valid move check
		// if fail: invalid move, try again

		// once at this point everything has succeeded

		squares[endPosX][endPosY].HasPiece = true;
		squares[endPosX][endPosY].ColourOfPiece = turnColour;
		squares[endPosX][endPosY].NameOfPiece = squares[startPosX][startPosY].NameOfPiece;

		squares[startPosX][startPosY].HasPiece = false;
		squares[startPosX][startPosY].ColourOfPiece = false; // doesn't matter if true/false.
		squares[startPosX][startPosY].NameOfPiece = 'e';

		cout << endl;
		PrintBoard(squares);
		cout << endl;
	}

	void PrintBoard(Square squares[8][8])
	{
		for (int j = 7; j >= 0; j--)
		{
			for (int i = 0; i < 8; i++)
			{
				cout << "||";

				if (squares[i][j].HasPiece)
				{
					if (!squares[i][j].ColourOfPiece)
					{
						cout << "W";
					}
					else
					{
						cout << "B";
					}
					cout << squares[i][j].NameOfPiece;
				}
				else
				{
					cout << "--";
				}
			}
			cout << "||";
			cout << endl;
		}
	}
};

int main()
{
	Engine engine;
	engine.Run();

	return 0;
}