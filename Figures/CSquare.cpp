
#include "CSquare.h"
#define r2  1.4142135623731
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;
}
void CSquare::Draw(Output* pOut) const
{
	pOut->Drawsquare(Center, FigGfxInfo, Selected);
}
bool CSquare::IsPointInside(int x, int y) const
{
	return(x >= Center.x - 37.5 &&x <= Center.x + 37.5 &&y >= Center.y - 37.5 &&y <= Center.y + 37.5) ;

}