#ifndef _GAME_
#define _GAME_

#include "Board.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700

// ---------------------------------------------------------
//                     GAME CLASS
// ---------------------------------------------------------    
class Game
{
private:
	int mScreenHeight;
	int mNextPosX, mNextPosY, mNextPiece, mNextRotation;

	Board *mBoard;

	Pieces *mPieces;
	IO *mIO;

	int GetRand(int numA, int numB);
	void InitGame();
	void DrawBoard();
	void DrawPiece (int pX, int pY, int pPiece, int pRotation);

public:
	Game(Board *mBoard, Pieces *mPieces, IO *mIO, int mScreenHeight);

	void DrawScene();
	void CreateNewPiece();

	int mPosX, mPosY, mPiece, mRotation;
	~Game();
};

#endif