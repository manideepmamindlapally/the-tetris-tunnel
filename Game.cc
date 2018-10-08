#include "Game.h"

/*---------------------------------------------------------
                    Get Rand Function
-----------------------------------------------------------*/
int Game::GetRand(int numA, int numB)
{
	return rand()*(numB - numA + 1) + numA;
}

/*---------------------------------------------------------
                    InitGame
-----------------------------------------------------------*/
void Game::InitGame()
{
	// Init random numbers
	srand((unsigned int) time(NULL));

	//First Piece
	mPiece = GetRand (0,6);
	mRotation = GetRand (0,3);
	mPosX = BOARD_POSITION + mPieces->GetInitialPositionX( mPiece, mRotation);
	mPosY = mPieces->GetInitialPositionY( mPiece, mRotation);

	//Next Piece
	mNextPiece = GetRand (0,6);
	mNextRotation = GetRand(0,3);
	mNextPosX = BOARD_WIDTH + 5;
	mNextPosY = 5;
}

/*-----------------------------------------------------------
                    Draw Game
------------------------------------------------------------*/
void Game::DrawBoard()
{
	// draw the limits or boundaries
	int mX1 = BOARD_POSITION - (BOARD_WIDTH * BLOCK_SIZE)/2 - 1;
	int mX2 = BOARD_POSITION + (BOARD_WIDTH * BLOCK_SIZE)/2;
	int mY  = mScreenHeight - BOARD_HEIGHT * BLOCK_SIZE;

	mIO->DrawRectangle (mX1 - BOARD_LINE_WIDTH, mY, mX1, mScreenHeight - 1, BLUE);
	mIO->DrawRectangle (mX2, mY, mX2 + BOARD_LINE_WIDTH, mScreenHeight - 1, BLUE);

	//draw the filled pieces
	for( int i = 0; i < BOARD_WIDTH; ++i)
		for( int j = 0; j < BOARD_HEIGHT; ++j)
			if(!mBoard->IsFreeBlock(i,j))
				mIO->DrawRectangle (mX1 + i*BLOCK_SIZE, mY + j*BLOCK_SIZE, mX1 + (i+1)*BLOCK_SIZE -1, mY + (j+1)*BLOCK_SIZE -1, MAGENTA);
}

/*------------------------------------------------------------
                   Draw Piece
-------------------------------------------------------------*/
void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation)
{
	int mPixelsX = mBoard->GetXPosInPixels (pX);
	int mPixelsY = mBoard->GetYPosInPixels (pY);
	int fillValue;
	color mColor;

	for( int i = 0; i < PIECE_BLOCKS; ++i)
		for ( int j = 0; j < PIECE_BLOCKS; ++j)
		{
			fillValue = mPieces->GetBlockType (pPiece, pRotation, pX, pY);
			if(fillValue == 0)	break;
			switch(fillValue)
			{
				case 1: mColor = YELLOW; break;
				case 2: mColor = GREEN; break;
			}
			mIO->DrawRectangle(mPixelsX, mPixelsY, mPixelsX + i * BLOCK_SIZE - 1, mPixelsY + j * BLOCK_SIZE - 1, mColor);
		}
}                   

/* -------------------------------------------
                   DRAWING scene
---------------------------------------------*/                   
void Game::DrawScene()
{
	DrawBoard();
	DrawPiece(mPosX, mPosY, mPiece, mRotation);
	DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation);
}

/*--------------------------------------------
                  Creating New piece
--------------------------------------------*/
void Game::CreateNewPiece()
{
	//bring the next piecce from side screen to main screen
	mPiece = mNextPiece;
	mRotation = mNextRotation;
	mPosX = BOARD_WIDTH/2 + mPieces->GetInitialPositionX (mPiece, mRotation);
	mPosY = mPieces->GetInitialPositionY (mPiece, mRotation);

	//bring a new next piece
	mNextPiece = GetRand( 0, 6);
	mNextRotation = GetRand( 0, 3);
}