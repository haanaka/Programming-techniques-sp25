#include "Figures\CSquare.h"
#include "CSquare.h"
#define r2  1.4142135623731

bool CSquare::IsPointInside(int x, int y) const
{
	return(x >= Center.x - 37.5 &&x <= Center.x + 37.5 &&y >= Center.y - 37.5 &&y <= Center.y + 37.5) ;

}