#ifndef _PIECES_
#define _PIECES_

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