#ifndef _PIECES_
#define _PIECES_
#include "dictionary.h"

/*-----------------------------------------------------------
                    the PIECES Class
-------------------------------------------------------------*/

class Pieces
{
	public:
		Pieces();
		int GetBlockType(int pPiece, int pRotation, int pX, int pY);
		int GetInitialPositionX(int pPiece, int pRotation);
		int GetInitialPositionY(int pPiece, int pRotation);
		~Pieces();
};

#endif

/*========================================================
Returns type of block 
0 - no block
1 - yes block
3 - rotation block
========================================================*/
int Pieces::GetBlockType(int pPiece, int pRotation, int pX, int pY)
{
	return mPieces[pPiece][pRotation][pX][pY];
}

/*=======================================================
Returns the X and Y initial positions of the piece 
========================================================*/
int Pieces::GetInitialPositionX(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][0];
}
int Pieces::GetInitialPositionY(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][1];
}