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
		int getBlockType(int pPiece, int pRotation, int pX, int pY);
		int getInitialPositionX(int pPiece, int pRotation);
		int getInitialPositionY(int pPiece, int pRotation);
		~Pieces();
};

#endif

/*========================================================
Returns type of block 
0 - no block
1 - yes block
3 - rotation block
========================================================*/
int Pieces::getBlockType(int pPiece, int pRotation, int pX, int pY)
{
	return mPieces[pPiece][pRotation][pX][pY];
}

/*=======================================================
Returns the X and Y initial positions of the piece 
========================================================*/
int Pieces::getInitialPositionX(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][0];
}
int Pieces::getInitialPositionY(int pPiece, int pRotation)
{
	return mPiecesInitialPosition[pPiece][pRotation][1];
}