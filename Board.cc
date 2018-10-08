#include "Board.h"

/*----------------------
Initialises the Board
Free all the blocks 
---------------------*/
void Board::InitBoard()
{
	for (int i = 0; i < BOARD_WIDTH; ++i)
		for (int j = 0; j < BOARD_HEIGHT; ++j)
			mBoard[i][j] = POS_FREE;
}

/*---------------------
Deletes a line - shift all the above lines down by one unit
----------------------*/
void Board::DeleteLine(int pY)
{
	for(int j = pY; j>0; --j)
		for (int i = 0; i < BOARD_WIDTH; ++i)
			mBoard[i][j] = mBoard[i][j-1];
}

/* --------------------------
Getting the pixel coordinate 
----------------------------*/
int Board::GetXPosInPixels (int pPos)
{
	return (BOARD_POSITION - BLOCK_SIZE*(BOARD_WIDTH/2)) + pPos*BLOCK_SIZE;
}
int Board::GetYPosInPixels (int pPos)
{
	return (mScreenHeight - BLOCK_SIZE*(BOARD_HEIGHT)) + pPos*BLOCK_SIZE;
}

/*----------------------------
Checking whether a block is free
-----------------------------*/
bool Board::IsFreeBlock(int pX, int pY)
{
	return mBoard[pX][pY] == POS_FREE;
}

/* --------------------------
Checks the possibility of movement of Block to position (pX, pY)
-------------------------------*/
bool Board::IsPossibleMovement	(int pX, int pY, int pPiece, int pRotation)
{
	// for all blocks in a piece
	for (int i = pX; i < pX + PIECE_BLOCKS; ++i)
		for (int j = pY; j < pY + PIECE_BLOCKS; ++j)
		{
			// checks if the piece goes out of bounds of the game area
			if(i < 0 || i > BOARD_WIDTH -1 || j > BOARD_HEIGHT -1)
				if(mPieces->GetBlockType(pPiece, pRotation, i-pX, j-pY) != 0)
					return false;
			// checks collisions with other blocks
			if(j>=0)
				if(mPieces->GetBlockType(pPiece, pRotation, i-pX, j-pY) != 0 && !(IsFreeBlock(i,j)))
					return false;
		}
	// passed all conditions
	return true;
}

/* ----------------------------------
Assigns POS_FILLED to selected box
------------------------------------*/
void Board::StorePiece (int pX, int pY, int pPiece, int pRotation)
{
	for (int i = pX; i < pX + PIECE_BLOCKS; ++i)
		for(int j = pY; j < pY + PIECE_BLOCKS; ++j)
			// if the block is filled in the piece, fill it on the board also
			if(mPieces->GetBlockType(pPiece, pRotation, i-pX, j-pY) != 0)
				mBoard[i][j] = POS_FILLED;
}

/*--------------------------------
Deletes line when a row is fully occupied
---------------------------------*/
void Board::DeletePossibleLines()
{
	for (int j = BOARD_HEIGHT; j > 0; --j)
	{
		int flag = 1;
		// check for the filling of a row
		for (int i = 0; i < BOARD_WIDTH; ++i)
			if(mBoard[i][j] == POS_FREE)
			{
				flag = 0;
				break;
			}
		// if filled, delete the row using the deleteline function
		if(flag == 1)
			Board::DeleteLine(j);
	}
}

/*=---------------------------------
Checks whether the game is over
------------------------------------*/
bool Board::IsGameOver()
{
	// check if the first row is filled
	for(int i = 0; i < BOARD_WIDTH; ++i)
		if(mBoard[i][0] == POS_FILLED)	return true;
	return false;
}